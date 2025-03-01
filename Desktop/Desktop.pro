QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++1z
CONFIG += sdk_no_version_check

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    colorcontrast.cpp \
    colorcontrastmodel.cpp \
    colorcontrastpresenter.cpp \
    colorcontrastview.cpp \
    colorcontrastviewbase.cpp \
    colorcontrastwidget.cpp \
    colorfactormodel.cpp \
    colorfactorpresenter.cpp \
    colorfactorview.cpp \
    colorfactorviewbase.cpp \
    colorfactorwidget.cpp \
    contrastcalculator.cpp \
    contrastcalculatormodel.cpp \
    main.cpp

HEADERS += \
    colorcontrast.h \
    colorcontrastmodel.h \
    colorcontrastpresenter.h \
    colorcontrastview.h \
    colorcontrastviewbase.h \
    colorcontrastwidget.h \
    colorfactormodel.h \
    colorfactorpresenter.h \
    colorfactorview.h \
    colorfactorviewbase.h \
    colorfactorwidget.h \
    contrastcalculator.h \
    contrastcalculatormodel.h \
    luminancecoefficients.h \
    wcagdefinitions.h

FORMS += \
    colorcontrast.ui \
    colorcontrastview.ui \
    colorfactorview.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=
