import QtQuick 2.0
import QtQuick.Controls 2.0


Item {
    property string title: ""
    property string color_shadow: "#dad8d8"
    property string color_panel: "#f9f9f9"
    property string color_line: "#6e6e6e"
    property string color_label: "#6e6e6e"
    property string text: text_input.text

    Rectangle {
        id: rect_shadow
        x: 0
        y: 0
        visible: true
        width: parent.width
        height: parent.height
        color: color_shadow
        radius: 3
    }

    Rectangle {
        id: rect_panel
        x: rect_shadow.x + 2
        y: rect_shadow.y - 2
        width: parent.width
        height: parent.height
        color: color_panel
        radius: 3
    }

    Rectangle {
        id: text_line
        x: rect_panel.x + 10
        y: rect_panel.height / 2 + rect_panel.y + 10
        width: rect_panel.width - 20
        height: 1
        color: color_line
    }

    TextInput {
        id: text_input
        x: text_line.x + 5
        width: text_line.width - 5
        height: 20
        anchors.bottom: text_line.top
        anchors.margins: 1
        text: qsTr("")
        font.pixelSize: 15
    }

    Label {
        id: label
        x: text_line.x + 5
        y: text_line.y
        color: "#6e6e6e"
        text: qsTr(title)
        font.italic: true
        font.pixelSize: 12
    }
}
