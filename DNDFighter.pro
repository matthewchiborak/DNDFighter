QT -= core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

LIBS+ = -lGL -lGLU

SOURCES += \
        src/controller/battlebuilder.cpp \
        src/controller/battlebuilderconcrete.cpp \
        src/controller/buttoncommand.cpp \
        src/controller/buttoncommandcrouch.cpp \
        src/controller/buttoncommandjump.cpp \
        src/controller/buttoncommandkick.cpp \
        src/controller/buttoncommandmoveforward.cpp \
        src/controller/buttoncommandpunch.cpp \
        src/controller/gamecontroller.cpp \
        src/controller/gamestatefactoryabstract.cpp \
        src/controller/gamestatefactoryconcrete.cpp \
        src/controller/userinputcommandfactory.cpp \
        src/controller/userinputcommandfactoryconcrete.cpp \
        src/controller/userinputhandler.cpp \
        src/filemanagment/fileReader.cpp \
        src/filemanagment/filewriter.cpp \
        src/main.cpp \
        src/model/battlecharacter.cpp \
        src/model/battlecharacterplayercontrol.cpp \
        src/model/gamemodel.cpp \
        src/model/gamemodelconcrete.cpp \
        src/view/abstractview.cpp \
        src/view/drawitem.cpp \
        src/view/gameview.cpp \
        src/view/spriteflyweight.cpp \
        src/view/spriteflyweightfactory.cpp \
        src/view/spriteflyweightfactoryabstract.cpp \
        src/view/stb_image.c \
        src/view/viewdrawingstrat.cpp \
        src/view/viewdrawingstratbattle.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    src/controller/battlebuilder.h \
    src/controller/battlebuilderconcrete.h \
    src/controller/buttoncommand.h \
    src/controller/buttoncommandcrouch.h \
    src/controller/buttoncommandjump.h \
    src/controller/buttoncommandkick.h \
    src/controller/buttoncommandmoveforward.h \
    src/controller/buttoncommandpunch.h \
    src/controller/gamecontroller.h \
    src/controller/gamestatefactoryabstract.h \
    src/controller/gamestatefactoryconcrete.h \
    src/controller/userinputcommandfactory.h \
    src/controller/userinputcommandfactoryconcrete.h \
    src/controller/userinputhandler.h \
    src/filemanagment/fileReader.h \
    src/filemanagment/filewriter.h \
    src/model/battlecharacter.h \
    src/model/battlecharacterplayercontrol.h \
    src/model/gamemodel.h \
    src/model/gamemodelconcrete.h \
    src/view/abstractview.h \
    src/view/drawitem.h \
    src/view/gameview.h \
    src/view/spriteflyweight.h \
    src/view/spriteflyweightfactory.h \
    src/view/spriteflyweightfactoryabstract.h \
    src/view/stb_image.h \
    src/view/viewdrawingstrat.h \
    src/view/viewdrawingstratbattle.h

LIBS += -lOpenGL32

LIBS += -lGlU32
