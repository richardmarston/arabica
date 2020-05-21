#!/bin/sh

echo commit ${INPUT_COMMIT} version ${INPUT_VERSION}
echo commit ${GITHUB_SHA} version $2
cd /github/workspace
mkdir build
cd build
cmake -DBUILD_SHARED_LIBS=ON ..
cpack
