QT += charts qml quick

SOURCES += \
    main.cpp \
    queryrow.cpp \
    sqlite/sqlite3.c

RESOURCES += \
    resources.qrc

DISTFILES += \
    qml/qmlchart/*

target.path = $$[QT_INSTALL_EXAMPLES]/charts/qmlchart
INSTALLS += target

HEADERS += \
    potato.h \
    queryrow.h \
    sqlite/sqlite3.h
