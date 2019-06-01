/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the Qt Charts module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:GPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 or (at your option) any later version
** approved by the KDE Free Qt Foundation. The licenses are as published by
** the Free Software Foundation and appearing in the file LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <QtWidgets/QApplication>
#include <QtQuick/QQuickView>
#include <QQmlContext>
#include <QtCore/QDir>
#include <QtQml/QQmlEngine>
#include <sqlite/sqlite3.h>
#include <queryrow.h>
#include <iostream>
#include <list>

std::list<queryRow *> dbRows;

static int callback(void *data, int argc, char **argv, char **azColName){
    int i;
    fprintf(stderr, "%s: ", (const char*)data);
    printf("%i",argc);

    for(i = 0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    queryRow row;
    char *ptr;
    row.setName("patata");
    row.setSuccess(10);
    row.setFails(0);
    row.setGames(10);
    dbRows.push_back(&row);
    printf("\n");
    return 0;
}

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    char *msgError = 0;
    int connection;
    sqlite3 *database;
    char *sql;
    const char* data = "Callback function called\n";
    sql = "select * from Success";

    //Connect to the database
    connection = sqlite3_open("..\\botGuessTheNumber\\results.db", &database);

    //Execute the query
    connection = sqlite3_exec(database, sql, callback,(void*)data,&msgError);

    if(connection != SQLITE_OK){
        printf(msgError);
        sqlite3_free(msgError);
    }else{
        printf("Datos insertados correctamente\n");
    }
    sqlite3_close(database);

    // Qt Charts uses Qt Graphics View Framework for drawing, therefore QApplication must be used.
    QApplication app(argc, argv);

    QQuickView viewer;
    // The following are needed to make examples run without having to install the module
    // in desktop environments.
#ifdef Q_OS_WIN
    QString extraImportPath(QStringLiteral("%1/../../../../%2"));
#else
    QString extraImportPath(QStringLiteral("%1/../../../%2"));
#endif
    viewer.engine()->addImportPath(extraImportPath.arg(QGuiApplication::applicationDirPath(),
                                      QString::fromLatin1("qml")));
    QObject::connect(viewer.engine(), &QQmlEngine::quit, &viewer, &QWindow::close);

    viewer.setTitle(QStringLiteral("Bot stadistics"));
    for (int i = 0;dbRows.size();i++) {
        viewer.engine()->rootContext()->setContextProperty("msg", dbRows.front());
        dbRows.pop_front();
    }
    viewer.setSource(QUrl("qrc:/qml/qmlchart/main.qml"));
    viewer.setResizeMode(QQuickView::SizeRootObjectToView);
    viewer.show();

    return app.exec();
}
