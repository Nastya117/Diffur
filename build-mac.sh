#!/bin/sh

qmake
make -j6
#macdeployqt Differ.app
tar -zcvf differ-mac-$1.tar.gz Differ.app
