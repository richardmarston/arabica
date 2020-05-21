#!/bin/sh

echo commit ${INPUT_COMMIT} version ${INPUT_VERSION}
echo commit $1 version $2
cd /github/workspace
mkdir build
cd build
cmake -DBUILD_SHARED_LIBS=ON ..
cpack
echo $(pwd)
RPM=$(find build -maxdepth 1 -iname '*.rpm')
DEB=$(find build -maxdepth 1 -iname '*.deb')
echo "rpm: ${RPM}"
echo "deb: ${DEB}"
