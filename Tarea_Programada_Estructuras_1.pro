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
    threadMezcladora.cpp

HEADERS  += ventanaprincipal.h \
    almacenprima.h \
    planificador.h \
    listagalletas.h \
    mezcladorachocolate.h \
    banda.h \
    ensambladora.h \
    threadmezcladoramasa1.h \
    supervisor.h \
    horno.h \
    empacadora.h \
    almacenterminal.h \
    carritoentrega.h \
    carritosalida.h \
    mezcladoramasa.h \
    prototipos.h

FORMS    += ventanaprincipal.ui

RESOURCES += \
    imagenes.qrc
