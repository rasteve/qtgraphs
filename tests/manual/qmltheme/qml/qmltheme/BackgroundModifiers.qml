// Copyright (C) 2024 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Fusion
import QtQuick.Dialogs
import QtGraphs

ColumnLayout {
    spacing: 10

    property alias testgridChange: testgridChange

    Label {
        visible: testgridChange.checked
        text: "Grid Width"
        color: "gray"
    }
    Slider {
        visible: testgridChange.checked
        from: 0.0
        to: 1.0
        value: customTheme.gridMainWidth
        onValueChanged: {
            if (testgridChange.checked) {
                customTheme.gridMainWidth = value
            }
        }
    }

    Row {
        Label {
            text: "Label text color"
            color: "gray"
        }

        Button {
            height: 25
            width: 25

            Rectangle {
                anchors.fill: parent
                anchors.margins: 5
                color: customTheme.labelTextColor
            }

            onClicked: textCol.open()
        }
    }
    ColorDialog {
        id: textCol
        selectedColor: customTheme.labelTextColor
        onAccepted: customTheme.labelTextColor = selectedColor
    }

        Row {
        Label {
            text: "Axis label text color"
            color: "gray"
        }
        Button {
            height: 25
            width: 25

            Rectangle {
                anchors.fill: parent
                anchors.margins: 5
                color: customTheme.axisXLabelColor
            }

            onClicked: axisLabelTextCol.open()
        }
    }
    ColorDialog {
        id: axisLabelTextCol
        selectedColor: customTheme.axisXLabelColor
        onAccepted: {
            customTheme.axisXLabelColor = selectedColor
            customTheme.axisYLabelColor = selectedColor
            customTheme.axisZLabelColor = selectedColor
        }
    }

    Row {
        Label {
            text: "Background color"
            color: "gray"
        }

        Button {
            height: 25
            width: 25

            Rectangle {
                anchors.fill: parent
                anchors.margins: 5
                color: customTheme.backgroundColor
            }

            onClicked: backgroundCol.open()
        }
    }
    ColorDialog {
        id: backgroundCol
        selectedColor: customTheme.backgroundColor
        onAccepted: customTheme.backgroundColor = selectedColor
    }

    Row {
        Label {
            text: "Plot area color"
            color: "gray"
        }

        Button {
            height: 25
            width: 25

            Rectangle {
                anchors.fill: parent
                anchors.margins: 5
                color: customTheme.plotAreaBackgroundColor
            }

            onClicked: plotareaCol.open()
        }
    }
    ColorDialog {
        id: plotareaCol
        selectedColor: customTheme.plotAreaBackgroundColor
        onAccepted: customTheme.plotAreaBackgroundColor = selectedColor
    }

    Row {
        Label {
            text: "Grid color"
            color: "gray"
        }

        Button {
            height: 25
            width: 25

            Rectangle {
                anchors.fill: parent
                anchors.margins: 5
                color: customTheme.gridMainColor
            }

            onClicked: gridlineCol.open()
        }
    }
    ColorDialog {
        id: gridlineCol
        selectedColor: customTheme.gridMainColor
        onAccepted: customTheme.gridMainColor = selectedColor
    }

    Row {
        Label {
            text: "Subgrid color"
            color: "gray"
        }

        Button {
            height: 25
            width: 25

            Rectangle {
                anchors.fill: parent
                anchors.margins: 5
                color: customTheme.gridSubColor
            }

            onClicked: subgridlineCol.open()
        }
    }
    ColorDialog {
        id: subgridlineCol
        selectedColor: customTheme.gridSubColor
        onAccepted: customTheme.gridSubColor = selectedColor
    }

    Label {
        text: "Subsegments"
        color: "gray"
    }
    Slider {
        from: 1
        to: 5
        stepSize: 1
        snapMode: Slider.SnapAlways
        value: bars.visible? bars.valueAxis.subSegmentCount : surface.axisX.subSegmentCount
        onValueChanged: {
            surface.axisX.subSegmentCount = value
            surface.axisY.subSegmentCount = value
            surface.axisZ.subSegmentCount = value
            bars.valueAxis.subSegmentCount = value
        }
    }

    Row {
        Label {
            text: "Background"
            color: "gray"
        }
        CheckBox {
            checked: customTheme.backgroundEnabled
            onCheckedChanged: {
                customTheme.backgroundEnabled = checked
            }
        }
    }

    Row {
        Label {
            text: "Plot area"
            color: "gray"
        }
        CheckBox {
            checked: customTheme.plotAreaBackgroundEnabled
            onCheckedChanged: {
                customTheme.plotAreaBackgroundEnabled = checked
            }
        }
    }

    Row {
        Label {
            text: "Grid"
            color: "gray"
        }
        CheckBox {
            checked: customTheme.gridEnabled
            onCheckedChanged: {
                customTheme.gridEnabled = checked
            }
        }
    }

    Row {
        Label {
            text: "Geometry/Shader Grid"
            color: "gray"
        }
        CheckBox {
            id: testgridChange
            checked: false
        }
    }

    Row {
        Label {
            text: "Labels"
            color: "gray"
        }
        CheckBox {
            checked: customTheme.labelsEnabled
            onCheckedChanged: {
                customTheme.labelsEnabled = checked
            }
        }
    }

    Row {
        Label {
            text: "Label Background"
            color: "gray"
        }
        CheckBox {
            checked: customTheme.labelBackgroundEnabled
            onCheckedChanged: {
                customTheme.labelBackgroundEnabled = checked
            }
        }
    }

    Row {
        Label {
            text: "Label Border"
            color: "gray"
        }
        CheckBox {
            checked: customTheme.labelBorderEnabled
            onCheckedChanged: {
                customTheme.labelBorderEnabled = checked
            }
        }
    }
}
