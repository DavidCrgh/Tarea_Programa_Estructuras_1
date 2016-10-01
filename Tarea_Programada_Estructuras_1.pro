#-------------------------------------------------
#
# Project created by QtCreator 2016-09-19T20:06:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Tarea_Programada_Estructuras_1
TEMPLATE = app


SOURCES += main.cpp\
        ventanaprincipal.cpp \
    threadMezcladora.cpp \
    hilointerfaz.cpp \
    ventanacarritoentrega.cpp \
    ventanamezcladoras.cpp \
    ventanaensambladora.cpp \
    ventanaalmacenprima.cpp \
    ventanahorno.cpp \
    hilocarritoentrega.cpp \
    simulacion.cpp \
    hilomezcladoramasa.cpp \
    hilomezcladorachocolate.cpp \
    ventanabanda.cpp

HEADERS  += ventanaprincipal.h \
    almacenprima.h \
    listagalletas.h \
    mezcladorachocolate.h \
    banda.h \
    ensambladora.h \
    threadmezcladoramasa1.h \
    horno.h \
    empacadora.h \
    almacenterminal.h \
    carritoentrega.h \
    carritosalida.h \
    mezcladoramasa.h \
    prototipos.h \
    bandainspectores.h \
    monticulosempaques.h \
    listarangos.h \
    hilointerfaz.h \
    simulacion.h \
    ventanacarritoentrega.h \
    ventanamezcladoras.h \
    ventanaensambladora.h \
    ventanaalmacenprima.h \
    ventanahorno.h \
    hilocarritoentrega.h \
    hilomezcladoramasa.h \
    hilomezcladorachocolate.h \
    ventanabanda.h

FORMS    += ventanaprincipal.ui \
    ventanacarritoentrega.ui \
    ventanamezcladoras.ui \
    ventanaensambladora.ui \
    ventanaalmacenprima.ui \
    ventanahorno.ui \
    ventanabanda.ui

RESOURCES += \
    imagenes.qrc
