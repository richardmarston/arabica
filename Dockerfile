
from alpine:latest


run apk update
run apk add boost-dev g++ make
run apk add cmake expat-dev rpm

workdir /github/workspace

entrypoint [ "./entrypoint.sh" ]
