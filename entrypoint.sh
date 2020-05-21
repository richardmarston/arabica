#!/bin/sh

echo commit ${INPUT_COMMITSHA} version ${INPUT_VERSIONNUM}
echo commit ${GITHUB_SHA} version $2
echo commit ${commitsha} version ${versionnum}
cd /github/workspace
mkdir build
cd build
cmake -DBUILD_SHARED_LIBS=ON ..
cpack
