#!/bin/sh

qmake
make
macdeployqt Differ.app
zip differ-mac-$1.zip Differ.app
