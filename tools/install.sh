#!/usr/bin/bash

echo "Coping Files"

cp -r include/ /usr/include/dsc
cp bin/Release/libdsc-lib.so /usr/lib

echo "Done!"