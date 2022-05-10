QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../../Documents/CS1C/ShapeShifters/Shapes/circle.cpp \
    ../../Documents/CS1C/ShapeShifters/Shapes/ellipse.cpp \
    ../../Documents/CS1C/ShapeShifters/Shapes/line.cpp \
    ../../Documents/CS1C/ShapeShifters/Shapes/main.cpp \
    ../../Documents/CS1C/ShapeShifters/Shapes/polygon.cpp \
    ../../Documents/CS1C/ShapeShifters/Shapes/polyline.cpp \
    ../../Documents/CS1C/ShapeShifters/Shapes/rectangle.cpp \
    ../../Documents/CS1C/ShapeShifters/Shapes/renderarea.cpp \
    ../../Documents/CS1C/ShapeShifters/Shapes/shape.cpp \
    ../../Documents/CS1C/ShapeShifters/Shapes/square.cpp \
    ../../Documents/CS1C/ShapeShifters/Shapes/text.cpp \
    canvas.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    ../../Documents/CS1C/ShapeShifters/Shapes/circle.h \
    ../../Documents/CS1C/ShapeShifters/Shapes/ellipse.h \
    ../../Documents/CS1C/ShapeShifters/Shapes/line.h \
    ../../Documents/CS1C/ShapeShifters/Shapes/polygon.h \
    ../../Documents/CS1C/ShapeShifters/Shapes/polyline.h \
    ../../Documents/CS1C/ShapeShifters/Shapes/rectangle.h \
    ../../Documents/CS1C/ShapeShifters/Shapes/renderarea.h \
    ../../Documents/CS1C/ShapeShifters/Shapes/shape.h \
    ../../Documents/CS1C/ShapeShifters/Shapes/square.h \
    ../../Documents/CS1C/ShapeShifters/Shapes/text.h \
    ../../Documents/CS1C/ShapeShifters/Shapes/vector.h \
    canvas.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
