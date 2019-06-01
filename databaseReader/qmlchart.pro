QT += charts qml quick

SOURCES += \
    main.cpp \
    sqlite/sqlite3.c

RESOURCES += \
    resources.qrc

DISTFILES += \
    qml/qmlchart/*

target.path = $$[QT_INSTALL_EXAMPLES]/charts/qmlchart
INSTALLS += target

HEADERS += \
    sqlite/sqlite3.h
