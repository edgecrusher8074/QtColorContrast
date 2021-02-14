QT += testlib gui
CONFIG += qt warn_on depend_includepath testcase c++1z sdk_no_version_check

TEMPLATE = app

SOURCES +=  \
    ../Desktop/colorcontrastmodel.cpp \
    ../Desktop/colorcontrastpresenter.cpp \
    ../Desktop/colorcontrastviewbase.cpp \
    ../Desktop/colorfactormodel.cpp \
    ../Desktop/colorfactorpresenter.cpp \
    ../Desktop/colorfactorviewbase.cpp \
    ../Desktop/contrastcalculator.cpp \
    ../Desktop/contrastcalculatormodel.cpp \
    main.cpp

HEADERS += \
    ../Desktop/colorcontrastmodel.h \
    ../Desktop/colorcontrastpresenter.h \
    ../Desktop/colorcontrastviewbase.h \
    ../Desktop/colorfactormodel.h \
    ../Desktop/colorfactorpresenter.h \
    ../Desktop/colorfactorviewbase.h \
    ../Desktop/contrastcalculator.h \
    ../Desktop/contrastcalculatormodel.h \
    colorcontrastviewmock.h \
    colorfactorviewmock.h \
    tst_colorcontrastpresenter.h \
    tst_colorfactorpresenter.h \
    tst_contrastcalculator.h

INCLUDEPATH += ../Desktop
