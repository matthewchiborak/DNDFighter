QT -= core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

LIBS+ = -lGL -lGLU

SOURCES += \
        src/controller/gamecontroller.cpp \
        src/controller/gamestatefactoryabstract.cpp \
        src/controller/gamestatefactoryconcrete.cpp \
        src/controller/userinputstate.cpp \
        src/controller/userinputstatebattle.cpp \
        src/main.cpp \
        src/model/gamemodel.cpp \
        src/model/gamemodelconcrete.cpp \
        src/view/abstractview.cpp \
        src/view/drawitem.cpp \
        src/view/gameview.cpp \
        src/view/viewdrawingstrat.cpp \
        src/view/viewdrawingstratbattle.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    src/controller/gamecontroller.h \
    src/controller/gamestatefactoryabstract.h \
    src/controller/gamestatefactoryconcrete.h \
    src/controller/userinputstate.h \
    src/controller/userinputstatebattle.h \
    src/model/gamemodel.h \
    src/model/gamemodelconcrete.h \
    src/view/abstractview.h \
    src/view/drawitem.h \
    src/view/gameview.h \
    src/view/viewdrawingstrat.h \
    src/view/viewdrawingstratbattle.h

LIBS += -lOpenGL32

LIBS += -lGlU32
