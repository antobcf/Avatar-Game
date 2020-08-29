QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    GUI/controller.cpp \
    GUI/creaavatar.cpp \
    GUI/elencoavatar.cpp \
    Gerarchia/gerarchia.cpp \
    GUI/infosistema.cpp \
    GUI/item.cpp \
    GUI/listaavatar.cpp \
    main.cpp \
    GUI/avatarhome.cpp \
    GUI/menu.cpp \
    modello.cpp \
    GUI/modificaavatar.cpp \
    GUI/scontro.cpp \
    GUI/sviluppatori.cpp

HEADERS += \
    GUI/avatarhome.h \
    Gerarchia/container.h \
    GUI/controller.h \
    GUI/creaavatar.h \
    GUI/elencoavatar.h \
    Gerarchia/gerarchia.h \
    GUI/infosistema.h \
    GUI/item.h \
    GUI/listaavatar.h \
    GUI/menu.h \
    modello.h \
    GUI/modificaavatar.h \
    GUI/scontro.h \
    GUI/sviluppatori.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    risorse.qrc

DISTFILES +=
