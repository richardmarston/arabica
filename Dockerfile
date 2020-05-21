
from alpine:latest

echo "commit $1"
echo "version $2"

run apk update
run apk add boost-dev g++ make

copy . /arabica
run mkdir /arabica/build
workdir /arabica/build
run apk add cmake expat-dev rpm
run cmake -DBUILD_SHARED_LIBS=ON ..
run cpack
