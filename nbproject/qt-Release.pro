# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = dist/Release/MinGW-Windows
TARGET = DGCApp
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += release 
QT = core gui
SOURCES += Pyramid.cpp RevObj.cpp main.cpp Layer.cpp Cube.cpp dgcapp.cpp Escalation.cpp Object.cpp Edge.cpp Canvas.cpp Subject.cpp Translation.cpp Rotation.cpp Face.cpp
HEADERS += Layer.h Translation.h Sup_Revolucion.h iObj.h Face.h RevObj.h Edge.h punto3d.h Observer.h iCmd.h Cube.h Normal.h Pyramid.h Rotation.h Canvas.h Escalation.h Object.h Subject.h dgcapp.h
FORMS += dgcUi.ui
RESOURCES +=
TRANSLATIONS +=
OBJECTS_DIR = build/Release/MinGW-Windows
MOC_DIR = 
RCC_DIR = 
UI_DIR = 
QMAKE_CC = gcc.exe
QMAKE_CXX = g++.exe
DEFINES += 
INCLUDEPATH += 
LIBS += 
