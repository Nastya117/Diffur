#!/bin/sh

qmake
make
macdeployqt Differ.app
zip Differ.zip Differ.app
