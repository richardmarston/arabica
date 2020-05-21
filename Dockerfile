
from alpine:latest


run apk update
run apk add boost-dev g++ make

copy . /arabica
run mkdir /arabica/build
workdir /arabica/build
run apk add cmake expat-dev rpm

entrypoint [ "/bin/sh", "-c", "echo commit ${INPUT_COMMIT} version ${INPUT_VERSION} && cmake -DBUILD_SHARED_LIBS=ON .. && cpack" ]
