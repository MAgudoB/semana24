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
#include "queryrow.h"
#include <iostream>
#include <list>
#include <vector>
#include <QtCharts>
#include <QQuickItem>
#include <QtCharts/QBarCategoryAxis>

using namespace std;

vector<queryRow*> dbRows;

static int callback(void *data, int argc, char **argv, char **azColName){
    int i;
    fprintf(stderr, "%s: ", (const char*)data);
    printf("%i",argc);

    queryRow* row = new queryRow(argv[0],atoi(argv[1]),atoi(argv[3]),atoi(argv[2]));
    dbRows.push_back(row);

    printf("\n");
    return 0;
}

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    dbRows = vector<queryRow*>();
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

    QBarSeries *series = new QBarSeries();
    for (int i = 0; i < dbRows.size();i++) {
       QBarSet *newSet = new QBarSet(dbRows[i]->getName());
       *newSet << dbRows[i]->getGames() << dbRows[i]->getFails();
       series->append(newSet);
    }


    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Lazy chart");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories;
    categories << "Games" << "Tries";
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0,1000);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QMainWindow window;
    window.setCentralWidget(chartView);
    window.resize(420, 300);
    window.show();
    return app.exec();
}
