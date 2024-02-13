QT += core
QT += network

#INCLUDEPATH+=$$PWD

HEADERS += \
    $$PWD/qstm_global.h \
    $$PWD/qstm_meta_enum.h \
    $$PWD/qstm_meta_items.h \
    $$PWD/qstm_object_wrapper.h \
    $$PWD/qstm_util_date.h \
    $$PWD/qstm_util_double.h \
    $$PWD/qstm_util_hash.h \
    $$PWD/qstm_util_map.h \
    $$PWD/qstm_util_meta_object.h \
    $$PWD/qstm_util_path.h \
    $$PWD/qstm_util_variant.h


SOURCES += \
    $$PWD/qstm_meta_items.cpp \
    $$PWD/qstm_object_wrapper.cpp \
    $$PWD/qstm_util_date.cpp \
    $$PWD/qstm_util_double.cpp \
    $$PWD/qstm_util_hash.cpp \
    $$PWD/qstm_util_map.cpp \
    $$PWD/qstm_util_meta_object.cpp \
    $$PWD/qstm_util_path.cpp \
    $$PWD/qstm_util_variant.cpp

