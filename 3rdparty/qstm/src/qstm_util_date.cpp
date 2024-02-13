#include "./qstm_util_date.h"
#include <QCoreApplication>
#include <QStringList>
#include <QVariantList>

namespace QStm {

Q_GLOBAL_STATIC_WITH_ARGS(QTime, static_minTime , ({00,00,00,000}))//
Q_GLOBAL_STATIC_WITH_ARGS(QTime, static_maxTime , ({23,59,59,999}))//
Q_GLOBAL_STATIC_WITH_ARGS(QStringList, static_paramDelimiter , ({",","|"}))//


class DateUtilPvt{
public:
    DateUtil*parent=nullptr;
    explicit DateUtilPvt(DateUtil*parent):parent{parent}
    {
    }
    virtual ~DateUtilPvt()
    {
    }

    void clear()
    {
        this->parent->setValue({});
    }

    static const QVariant getAlpha(const QVariant &v)
    {
        static const auto num=QStringLiteral("0123456789,.");
        QString r,ss;
        switch (v.typeId()) {
        case QMetaType::Double:
            ss=QString::number(v.toDouble(),'f',6);
            break;
        case QMetaType::ULongLong:
        case QMetaType::LongLong:
        case QMetaType::Int:
        case QMetaType::UInt:
            ss=QString::number(v.toLongLong(),'f',0);
            break;
        default:
            ss=v.toString();
            break;
        }
        for(auto &c:ss){
            if(!num.contains(c))
                r+=c;
        }
        return r;
    }

    static const QVariant getNumber(const QVariant &v)
    {
        static const auto num=QStringLiteral("0123456789,.");
        QString r,ss;

        switch (v.typeId()) {
        case QMetaType::Double:
            ss=QString::number(v.toDouble(),'f',6);
            break;
        case QMetaType::ULongLong:
        case QMetaType::LongLong:
        case QMetaType::Int:
        case QMetaType::UInt:
            ss=QString::number(v.toLongLong(),'f',0);
            break;
        default:
            ss=v.toString();
            break;
        }

        for(auto &c:ss){
            if(num.contains(c))
                r+=c;
        }
        return r;
    }

    QVariant parseInterval(const QVariant &v, const QVariant &defaultV={})
    {
        if(v.isNull() || !v.isValid() || v.toLongLong()<0)
            return defaultV;

        switch (v.typeId()) {
        case QMetaType::Int:
        case QMetaType::UInt:
        case QMetaType::LongLong:
        case QMetaType::ULongLong:
        case QMetaType::Long:
        case QMetaType::ULong:
        case QMetaType::Double:
            return v.toInt();
        default:
            break;
        }

        double scale=1;
        auto a=getAlpha(v).toString().toLower();
        if(a==QStringLiteral("ms") || a==QStringLiteral("millisecond"))
            scale=1;
        else{
            if(a==QStringLiteral("s") || a==QStringLiteral("sc") || a==QStringLiteral("second"))
                scale=1;
            else if(a==QStringLiteral("m") || a==QStringLiteral("mn") || a==QStringLiteral("minute"))
                scale=60;
            else if(a==QStringLiteral("h") || a==QStringLiteral("hr") || a==QStringLiteral("hour"))
                scale=60*60;
            else if(a==QStringLiteral("d") || a==QStringLiteral("dd") || a==QStringLiteral("day"))
                scale=60*60*24;
            else if(a==QStringLiteral("mo")|| a==QStringLiteral("mo") || a==QStringLiteral("month"))
                scale=(60*60*24*30);
            else if(a==QStringLiteral("y") || a==QStringLiteral("yy") || a==QStringLiteral("year"))
                scale=(60*60*24*30*12);
            else
                scale=1;//seconds
            scale*=1000;
        }
        auto iN=getNumber(v);
        auto i=iN.toDouble();
        i*=scale;
        if(i<=0)
            i=parseInterval(defaultV).toLongLong();
        return i;
    }


};

DateUtil::DateUtil(const QVariant &v):QVariant{v}, p{new DateUtilPvt{this}}
{
}

DateUtil::~DateUtil()
{
    delete p;
}

DateUtil&DateUtil::operator=(const QVariant &v)
{
    this->setValue(v);
    return *this;
}

QDateTime DateUtil::firstMonthDate(const QVariant &v) const
{
    auto vv=v.isValid()?v:*this;
    QDate d;
    switch (vv.typeId()) {
    case QMetaType::QDate:
        d=vv.toDate();
        break;
    case QMetaType::QDateTime:
        d=vv.toDateTime().date();
        break;
    case QMetaType::QString:
    case QMetaType::QByteArray:
    {
        auto v=QDateTime::fromString(QVariant::toString(), Qt::ISODate);
        if(v.isNull()){
            v=QDateTime::fromString(QVariant::toString(), Qt::ISODateWithMs);
            if(v.isNull())
                v=QDateTime::fromString(QVariant::toString(), Qt::TextDate);
        }
        d=v.date();
        break;
    }
    default:
        d=QDate::currentDate();
    }
    return {QDate{d.year(), d.month(), 1}, *static_minTime};
}

QDateTime DateUtil::lastMonthDate(const QVariant &v) const
{
    auto vv=v.isValid()?v:*this;
    QDate d;
    switch (vv.typeId()) {
    case QMetaType::QDate:
        d=vv.toDate();
        break;
    case QMetaType::QDateTime:
        d=vv.toDateTime().date();
        break;
    case QMetaType::QString:
    case QMetaType::QByteArray:
    {
        auto v=QDateTime::fromString(QVariant::toString(), Qt::ISODate);
        if(v.isNull()){
            v=QDateTime::fromString(QVariant::toString(), Qt::ISODateWithMs);
            if(v.isNull())
                v=QDateTime::fromString(QVariant::toString(), Qt::TextDate);
        }
        d=v.date();
        break;
    }
    default:
        d=QDate::currentDate();
    }
    d=QDate{d.year(), d.month(), 1}.addMonths(1).addDays(-1);
    return QDateTime{d, *static_maxTime};
}

QDateTime DateUtil::firstYearDate(const QVariant &v) const
{
    auto vv=v.isValid()?v:*this;
    QDate d;
    switch (vv.typeId()) {
    case QMetaType::QDate:
        d=vv.toDate();
        break;
    case QMetaType::QDateTime:
        d=vv.toDateTime().date();
        break;
    case QMetaType::QString:
    case QMetaType::QByteArray:
    {
        auto v=QDateTime::fromString(QVariant::toString(), Qt::ISODate);
        if(v.isNull()){
            v=QDateTime::fromString(QVariant::toString(), Qt::ISODateWithMs);
            if(v.isNull())
                v=QDateTime::fromString(QVariant::toString(), Qt::TextDate);
        }
        d=v.date();
        break;
    }
    default:
        d=QDate::currentDate();
    }
    return QDateTime{QDate{d.year(),1,1}, *static_minTime};
}

QDateTime DateUtil::lastYearDate(const QVariant &v) const
{
    auto vv=v.isValid()?v:*this;
    QDate d;
    switch (vv.typeId()) {
    case QMetaType::QDate:
        d=vv.toDate();
        break;
    case QMetaType::QDateTime:
        d=vv.toDateTime().date();
        break;
    case QMetaType::QString:
    case QMetaType::QByteArray:
    {
        auto v=QDateTime::fromString(QVariant::toString(), Qt::ISODate);
        if(v.isNull()){
            v=QDateTime::fromString(QVariant::toString(), Qt::ISODateWithMs);
            if(v.isNull())
                v=QDateTime::fromString(QVariant::toString(), Qt::TextDate);
        }
        d=v.date();
        break;
    }
    default:
        d=QDate::currentDate();
    }
    return QDateTime{QDate{d.year(),12,31}, *static_maxTime};
}

QVariantList DateUtil::listMonthDaysToDate(const QVariant &v) const
{
    QVariantList list;
    auto d=v.toDate();
    if(!d.isValid())
        d=QDate::currentDate();
    auto start=QDate{d.year(), d.month(), 1};
    auto finish=v.toDate();
    while(start<=finish){
        list<<start;
        start=start.addDays(1);
    }
    return list;
}

QVariantList DateUtil::listMonthDays(const QVariant &v)const
{
    QVariantList list;
    auto d=v.toDate();
    if(!d.isValid())
        d=QDate::currentDate();
    auto start=QDate{d.year(), d.month(), 1};
    auto finish=start.addMonths(1).addDays(-1);
    while(start<=finish){
        list<<start;
        start=start.addDays(1);
    }
    return list;
}

QVariantList DateUtil::listYearDaysToDate(const QVariant &v) const
{
    QVariantList list;
    auto d=v.toDate();
    if(!d.isValid())
        d=QDate::currentDate();
    auto start=QDate{d.year(), 1, 1};
    auto finish=v.toDate();
    while(start<=finish){
        list<<start;
        start=start.addDays(1);
    }
    return list;
}

QVariantList DateUtil::listYearDays(const QVariant &v) const
{
    QVariantList list;
    int year=0;
    switch (v.typeId()) {
    case QMetaType::QDate:
        year=v.toDate().year();
        break;
    case QMetaType::QDateTime:
        year=v.toDateTime().date().year();
        break;
    case QMetaType::ULongLong:
    case QMetaType::LongLong:
    case QMetaType::UInt:
    case QMetaType::Int:
        year=v.toInt();
        break;
    default:
        auto d=QDateTime{QDate::fromString(v.toString(), Qt::ISODate), {}};
        if(d.isValid()){
            year=d.date().year();
            break;
        }
        d=QDateTime::fromString(v.toString(), Qt::ISODateWithMs);
        if(d.isValid()){
            year=d.date().year();
            break;
        }

        year=v.toInt();
        if(year>0)
            break;

        year=QDate::currentDate().year();
        break;
    }

    auto start=QDate{year, 1, 1};
    auto finish=start.addYears(1).addDays(-1);
    while(start<=finish){
        list<<start;
        start=start.addDays(1);
    }
    return list;
}

const QTime&DateUtil::minTime()
{
    return *static_minTime;
}

const QTime&DateUtil::maxTime()
{
    return *static_maxTime;
}

QDateTime DateUtil::minDateTime()
{
    auto d=QDate::currentDate();
    return QDateTime{d, *static_minTime};
}

QDateTime DateUtil::minDateTime(const QVariant &dt)
{
    auto d=dt.typeId()==QMetaType::QDateTime?dt.toDateTime().date():dt.toDate();
    return QDateTime{d, *static_minTime};
}

QDateTime DateUtil::maxDateTime()
{
    auto d=QDate::currentDate();
    return QDateTime{d, *static_maxTime};
}

QDateTime DateUtil::maxDateTime(const QVariant &dt)
{
    auto d=dt.typeId()==QMetaType::QDateTime?dt.toDateTime().date():dt.toDate();
    return QDateTime{d, *static_maxTime};
}

QDateTime DateUtil::minMonthDateTime()
{
    auto d=QDate::currentDate();
    return QDateTime{d, *static_minTime};
}

QDateTime DateUtil::minMonthDateTime(const QDate &dt)
{
    QDate d(dt);
    d=QDate(d.year(), d.month(),1);
    return QDateTime{d, *static_minTime};
}

QDateTime DateUtil::minMonthDateTime(int year, int month)
{
    auto d=QDate(year, month,1);
    return QDateTime{d, *static_minTime};
}

QDateTime DateUtil::maxMonthDateTime()
{
    auto d=QDate::currentDate();
    d=QDate(d.year(), d.month(),1).addMonths(1).addDays(-1);
    return QDateTime{d, *static_maxTime};
}

QDateTime DateUtil::maxMonthDateTime(const QDate &dt)
{
    QDate d(dt);
    d=QDate(d.year(), d.month(),1).addMonths(1).addDays(-1);
    return QDateTime{d, *static_maxTime};
}

QDateTime DateUtil::maxMonthDateTime(int year, int month)
{
    auto d=QDate(year, month,1).addMonths(1).addDays(-1);
    return QDateTime{d, *static_maxTime};
}

const QDateTime DateUtil::toDateTime(const QVariant &v)
{
    if(v.isValid())
        QVariant::setValue(v);

    QDateTime dt;
    switch (this->typeId()) {
    case QMetaType::QDateTime:
        dt=QVariant::toDateTime();
        break;
    case QMetaType::QDate:
        dt=QDateTime{QVariant::toDate(), {}};
        break;
    case QMetaType::QTime:
        dt=QDateTime{QDate{}, QVariant::toTime()};
        break;
    case QMetaType::QString:
    case QMetaType::QByteArray:
    {
        auto v=QDateTime::fromString(QVariant::toString(), Qt::ISODateWithMs).toUTC();
        if(v.isNull()){
            v=QDateTime::fromString(QVariant::toString(), Qt::ISODate);
            if(v.isNull())
                v=QDateTime::fromString(QVariant::toString(), Qt::TextDate);
        }
        dt=v;
        break;
    }
    default:
        dt=QVariant::toDateTime();
    }
//    if(dt.time().isNull() || !dt.time().isValid())
//        dt.setTime(*static_minTime);
    return dt;
}

const QDate DateUtil::toDate(const QVariant &v)
{
    if(v.isValid())
        QVariant::setValue(v);

    switch (this->typeId()) {
    case QMetaType::QDateTime:
        return QVariant::toDateTime().date();
    case QMetaType::QDate:
        return QVariant::toDate();
    case QMetaType::QTime:
        return {};
    case QMetaType::QString:
    case QMetaType::QByteArray:
    {
        auto v=QDate::fromString(QVariant::toString(), Qt::ISODate);
        if(v.isNull()){
            v=QDate::fromString(QVariant::toString(), Qt::ISODateWithMs);
            if(v.isNull())
                v=QDate::fromString(QVariant::toString(), Qt::TextDate);
        }
        return v;
    }
    default:
        return QVariant::toDate();
    }
}

const QTime DateUtil::toTime(const QVariant &v)
{
    if(v.isValid())
        QVariant::setValue(v);

    QTime __return;
    switch (this->typeId()) {
    case QMetaType::QDateTime:
        __return=QVariant::toDateTime().time();
        break;
    case QMetaType::QDate:
        __return={};//*static_minTime;
        break;
    case QMetaType::QTime:
    {
        __return=QVariant::toTime();
        break;
    }
    case QMetaType::QString:
    case QMetaType::QByteArray:
    {
        auto text=QVariant::toString();
        if(!text.contains(":"))
            break;
        __return=QTime::fromString(text, Qt::ISODateWithMs);
        if(__return.isNull() || !__return.isValid()){
            __return=QDateTime::fromString(text, Qt::ISODateWithMs).time();
        }
        break;
    }
    default:
        __return=QVariant::toTime();
        break;
    }
    if(__return.isNull() || !__return.isValid())
        return {};
//        __return=*static_minTime;
    return __return;
}

bool DateUtil::setNow(QTime &v)
{
    v=QDateTime::currentDateTime().time();
    Q_ASSERT(v.isValid()); // Fails!
    return v.isValid();
}

bool DateUtil::setNow(QDate &v)
{
    v=QDateTime::currentDateTime().date();
    Q_ASSERT(v.isValid()); // Fails!
    return v.isValid();
}

bool DateUtil::setNow(QDateTime &v)
{
    v=QDateTime::currentDateTime();
    Q_ASSERT(v.isValid()); // Fails!
    return v.isValid();
}

bool DateUtil::setNow(QDateTime &dtA, QDateTime &dtB)
{
    dtA=QDateTime::currentDateTime();
    dtB=dtA;
    dtA.setTime(*static_minTime);
    dtB.setTime(*static_maxTime);
    Q_ASSERT(dtA.isValid()); // Fails!
    return dtA.isValid();
}

bool DateUtil::setMax(QTime &vA)
{
    vA=*static_maxTime;
    Q_ASSERT(vA.isValid()); // Fails!
    return vA.isValid();
}

bool DateUtil::setMax(QDateTime &vA)
{
    if(!vA.isValid())
        vA=QDateTime::currentDateTime();

    vA=QDateTime{vA.date(), *static_maxTime};
    Q_ASSERT(vA.isValid()); // Fails!
    return vA.isValid();
}

bool DateUtil::setMax(QTime &vA, QTime &vB)
{
//    if(vA>vB){
//        auto v=vA;
//        vA=vB;
//        vB=v;
//    }
    vA=*static_minTime;
    vB=*static_maxTime;
    return vA.isValid() && vB.isValid();
}

bool DateUtil::setMax(QDateTime &vA, QDateTime &vB)
{
    if(!vA.isValid() || vA.isNull())
        vA=QDateTime::currentDateTime();
    if(!vB.isValid() || vB.isNull())
        vB=QDateTime::currentDateTime();
    if(vA>vB){
        auto v=vA;
        vA=vB;
        vB=v;
    }
    vA=QDateTime(vA.date(),*static_minTime);
    vB=QDateTime(vB.date(),*static_maxTime);
    return vA.isValid() && vB.isValid();
}

bool DateUtil::setMonthRange(QDate &vA, QDate &vB)
{
    if(vA>vB){
        auto v=vA;
        vA=vB;
        vB=v;
    }
    const auto curDate=QVariant::toDate();
    if(!curDate.isValid())
        QDate::currentDate();
    const auto year=curDate.year();
    const auto month=curDate.month();
    vA=QDate(year, month, 1);
    vB=vA.addMonths(1).addDays(-1);
    return vA<vB;
}

bool DateUtil::setMonthRange(QDateTime &vA, QDateTime &vB)
{
    if(vA>vB){
        auto v=vA;
        vA=vB;
        vB=v;
    }
    QDate a=vA.date(),b=vB.date();
    vA={};
    vB={};
    if(setMonthRange(a,b)){
        vA=QDateTime{a,*static_minTime};
        vB=QDateTime{b,*static_maxTime};
    }
    return vA<vB;
}

bool DateUtil::setYearRange(QDate &vA, QDate &vB)
{
    QDate d;
    if(vA.isValid())
        d=vA;

    if(vB.isValid())
        d=vB;

    if(!d.isValid())
        d=QVariant::toDate();

    if(!d.isValid())
        d=QDate::currentDate();

    const auto year=d.year();
    vA=QDate{year,1,1};
    vB=vA.addYears(1).addDays(-1);
    return vA<vB;
}

bool DateUtil::setYearRange(QDateTime &vA, QDateTime &vB)
{
    if(vA>vB){
        auto v=vA;
        vA=vB;
        vB=v;
    }
    QDate a=vA.date(),b=vB.date();
    vA={};
    vB={};
    if(setYearRange(a,b)){
        vA=QDateTime{a,*static_minTime};
        vB=QDateTime{b,*static_maxTime};
    }
    return vA<vB;
}

bool DateUtil::setDistantRange(QDate &vA, QDate &vB)
{
    vA=QDate{1901,1,1};
    vB=QDate{2500,1,1};
    return vA<vB;
}

bool DateUtil::setDistantRange(QDateTime &vA, QDateTime &vB)
{
    vA=QDateTime{QDate{1901,1,1}, *static_minTime};
    vB=QDateTime{QDate{2500,1,1}, *static_maxTime};
    return vA<vB;
}

bool DateUtil::validBetween(const QDateTime &vVal, const QDateTime &vMin, const QDateTime &vMax)
{
    QDateTime vMax__(vMax);

    if(vMax__.time().isNull() || !vMax__.time().isValid() || vMax__.time()==*static_minTime)
        vMax__.setTime(*static_maxTime);

    if(vVal.isNull() || vMin.isNull() || vMax__.isNull())
        return false;

    if(vVal<vMin)
        return false;

    if(vVal>vMax__)
        return false;

    return true;
}

bool DateUtil::checkBetween(const QVariant &v, QDateTime &vMin, QDateTime &vMax)
{
    if(!v.isValid() || v.isNull())
        return false;

    auto vv=v;
    switch (vv.typeId()) {
    case QMetaType::QVariantList:
    case QMetaType::QStringList:
    {
        auto l=vv.toList();
        if(l.isEmpty())
            vv={};
        else if(l.size()==1)
            vv=l.first();
        else
            vv=QVariantList{l[0], l[1]};
        break;
    }
    case QMetaType::QString:
    case QMetaType::QByteArray:
    {
        auto s=v.toString().trimmed();
        for(auto &c:*static_paramDelimiter){
            if(s.contains(c)){
                vv=s.split(c);
                break;
            }
        }
        break;
    }
    default:
        break;
    }

    switch (vv.typeId()) {
    case QMetaType::QVariantList:
    case QMetaType::QStringList:
    {
        auto l=vv.toList();
        for(auto &v:l){
            v=v.toString().replace(QStringLiteral("\""), "").replace(QStringLiteral("'"),"").replace(QStringLiteral(";"),"");
        }
        vMin=l.size()<=0?QDateTime{}:l[0].toDateTime();
        vMax=l.size()<=1?QDateTime{}:l[1].toDateTime();
        break;
    }
    case QMetaType::QDate:
    case QMetaType::QDateTime:
    {
        vMin=QDateTime{vv.toDateTime().date(), {}};
        vMax=QDateTime{vv.toDateTime().date(), {}};
        break;
    }
    default:
        break;
    }


    if(!vMax.isValid()){
        if(vMin.isValid()){
            vMax=QDateTime{vMin.date(), {}};
        }
    }

    if(vMin>vMax){
        auto aux=vMin;
        vMin=vMax;
        vMax=aux;
    }

    if(vMin.isValid())
        vMin.setTime(*static_minTime);

    if(vMax.isValid())
        vMax.setTime(*static_maxTime);

    return vMin.isValid() && vMax.isValid();
}

bool DateUtil::checkBetween(QDateTime &vMin, QDateTime &vMax)
{
    if(vMin>vMax){
        auto aux=vMin;
        vMin=vMax;
        vMax=aux;
    }
    vMin=QDateTime{vMin.date(), *static_minTime};
    vMax=QDateTime{vMax.date(), *static_maxTime};
    return vMin.isValid() && vMax.isValid();
}

bool DateUtil::checkBetween(QDate &vMin, QDate &vMax)
{
    if(vMin>vMax){
        auto aux=vMin;
        vMin=vMax;
        vMax=aux;
    }
    return vMin.isValid() && vMax.isValid();
}

bool DateUtil::checkBetween(QTime &vMin, QTime &vMax)
{
    if(vMin>vMax){
        auto aux=vMin;
        vMin=vMax;
        vMax=aux;
    }
    return vMin.isValid() && vMax.isValid();
}

QVariant DateUtil::parseInterval()
{

    auto __return = p->parseInterval(*this);
    return __return;
}

QVariant DateUtil::parseInterval(const QVariant &v, const QVariant &defaultV)
{

    if(v.isValid())
        QVariant::setValue(v);
    auto __return = p->parseInterval(*this, defaultV);
    return __return;
}

}
