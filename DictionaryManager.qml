import QtQuick 2.0
import QtQuick.Controls 2.0


ApplicationWindow {
    id: dictionary_manager
    width: 640
    height: 320
    color: "#ffffff"
    visible: true

    Rectangle {
        id: button_insert
        x: 581
        y: 35
        width: 40
        height: 40
        color: "#86e47d"
        radius: 10
        border.width: 0
        border.color: "#86e47d"

        Text {
            text: "+"
            verticalAlignment: Text.AlignTop
            horizontalAlignment: Text.AlignHCenter
            color: "#ffffff"
            smooth: true
            font.pixelSize: parent.width * 0.75
            anchors.fill: parent
        }
    }

    Rectangle {
        id: text_key_shadow
        x: 15
        y: 20
        width: 270
        height: 70
        color: "#dad8d8"
        radius: 3

        Rectangle {
            id: text_key_panel
            x: 2
            y: -2
            width: 270
            height: 70
            color: "#f9f9f9"
            radius: 3

            Rectangle {
                id: text_key_line
                x: 10
                y: parent.height / 2 + 10
                width: parent.width - x * 2
                height: 1
                color: "#6e6e6e"
            }

            TextInput {
                id: text_key
                x: text_key_line.x + 5
                width: text_key_line.width - 5
                height: 20
                anchors.bottom: text_key_line.top
                anchors.margins: 1
                text: qsTr("")
                font.pixelSize: 15
            }

            Label {
                id: label_key
                x: text_key_line.x + 5
                y: text_key_line.y
                color: "#6e6e6e"
                text: qsTr("Ducth Word")
                font.italic: true
                font.pixelSize: 12
            }
        }
    }

    Rectangle {
        id: text_value_shadow
        anchors.left: text_key_shadow.right
        anchors.leftMargin: 10
        y: text_key_shadow.y
        width: 270
        height: 70
        color: "#dad8d8"
        radius: 3

        Rectangle {
            id: text_value_panel
            x: 2
            y: -2
            width: 270
            height: 70
            color: "#f9f9f9"
            radius: 3

            Rectangle {
                id: text_value_line
                x: 10
                y: parent.height / 2 + 10
                width: parent.width - x * 2
                height: 1
                color: "#6e6e6e"
            }

            TextInput {
                id: text_value
                x: text_value_line.x + 5
                width: text_key_line.width - 5
                height: 20
                anchors.bottom: text_value_line.top
                anchors.margins: 1
                text: qsTr("")
                font.pixelSize: 15
            }

            Label {
                id: label_value
                x: text_value_line.x + 5
                y: text_value_line.y
                color: "#6e6e6e"
                text: qsTr("Tranlation")
                font.italic: true
                font.pixelSize: 12
            }
        }
    }
}
