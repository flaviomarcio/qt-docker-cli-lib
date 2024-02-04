ROOT_DIR=$PWD

cd ${ROOT_DIR}
git checkout master
git checkout release/1.0.0

cd ${ROOT_DIR}/3rdparty/qstm
git checkout master
git pull
git checkout release/1.0.0

cd ${ROOT_DIR}/3rdparty/qtrequestclient
git checkout master
git pull
git checkout release/1.0.0

cd ${ROOT_DIR}