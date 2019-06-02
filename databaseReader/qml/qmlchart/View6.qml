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

import QtQuick 2.0
import QtCharts 2.0

Item {
    anchors.fill: parent
    objectName: "parentItem"

    //![1]
    ChartView {
        title: "Bar series"
        objectName: "charView"
        anchors.fill: parent
        legend.alignment: Qt.AlignBottom
        antialiasing: true

        /*BarSeries {
            id: mySeries
            objectName: "mySeries"
            name: "mySeries"
            axisX: BarCategoryAxis { categories: ["Games", "Tries", "Average"] }
            BarSet { label: msg.row_Name; values: [100, 805, 805/100] }
            BarSet { label: msg.row_Name; values: [100, 793, 793/100] }
            BarSet { label: msg.row_Name; values: [100, 798, 798/100] }
        }*/
    }
    //![1]
}
