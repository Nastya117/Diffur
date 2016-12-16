#!/bin/sh

qmake
make -j6
macdeployqt Differ.app
zip differ-mac-$1.zip -r Differ.app
