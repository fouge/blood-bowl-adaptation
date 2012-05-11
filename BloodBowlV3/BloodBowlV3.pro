#-------------------------------------------------
#
# Project created by QtCreator 2012-04-26T16:30:32
#
#-------------------------------------------------

QT       += core gui

TARGET = BloodbowlV3
TEMPLATE = app


SOURCES += main.cpp\
        fenetreprincipale.cpp \
    equipe.cpp \
    joueur.cpp \
    tablemodel.cpp \
    match.cpp \
    ballon.cpp \
    sceneterrain.cpp

HEADERS  += fenetreprincipale.h \
    equipe.h \
    tablemodel.h \
    enum.h \
    joueur.h \
    match.h \
    ballon.h \
    sceneterrain.h


# -> mettre a jour apres turnover : score et remise en place sur le terrain
#           voir dans match::turnover
