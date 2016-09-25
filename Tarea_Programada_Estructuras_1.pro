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
    simulacion.cpp \
    ventanacarritoentrega.cpp \
    ventanamezcladoras.cpp \
    ventanaensambladora.cpp \
    ventanaalmacenprima.cpp

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
    Estructuras/almacenprima.h \
    Estructuras/almacenterminal.h \
    Estructuras/banda.h \
    Estructuras/bandainspectores.h \
    Estructuras/carritoentrega.h \
    Estructuras/carritosalida.h \
    Estructuras/empacadora.h \
    Estructuras/ensambladora.h \
    Estructuras/horno.h \
    Estructuras/listagalletas.h \
    Estructuras/listarangos.h \
    Estructuras/mezcladorachocolate.h \
    Estructuras/mezcladoramasa.h \
    Estructuras/monticulosempaques.h \
    Estructuras/prototipos.h \
    ventanamezcladoras.h \
    ventanaensambladora.h \
    ventanaalmacenprima.h

FORMS    += ventanaprincipal.ui \
    ventanacarritoentrega.ui \
    ventanamezcladoras.ui \
    ventanaensambladora.ui \
    ventanaalmacenprima.ui

RESOURCES += \
    imagenes.qrc
