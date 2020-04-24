import QtQuick 2.0
import QtQuick.Controls 2.0


Rectangle {
    id: dictionary_manager
    width: 640
    height: 320
    color: "#ffffff"
    visible: true

    signal signal_dict_insert(string p_word, string p_translation)

    Item {
        id: color_button

        property var color_mouse_out: "#86e47d"
        property var color_mouse_in: "#70d965"
        property var color_mouse_press: "#44bb37"
    }

    Rectangle {
        id: button_insert
        width: 40
        height: 40
        color: color_button.color_mouse_out
        radius: 10
        border.width: 0
        anchors.left: input_value.right
        anchors.verticalCenter: input_value.verticalCenter
        anchors.margins: 20

        Text {
            text: "+"
            verticalAlignment: Text.AlignTop
            horizontalAlignment: Text.AlignHCenter
            color: "#ffffff"
            smooth: true
            font.pixelSize: parent.width * 0.75
            anchors.fill: parent
        }

        MouseArea {
            property string state_mouse_in: "MouseIn"
            property string state_mouse_out: "MouseOut"
            property string state_mouse: state_mouse_out

            anchors.fill: parent
            hoverEnabled: true
            onEntered: {
                state_mouse = state_mouse_in
                parent.color = color_button.color_mouse_in
            }
            onExited: {
                state_mouse = state_mouse_out
                parent.color = color_button.color_mouse_out
            }
            onPressed: {
                parent.color = color_button.color_mouse_press
            }
            onReleased: {
                if (state_mouse == state_mouse_in) {
                    onEntered()
                }
                else if (state_mouse == state_mouse_out) {
                    onExited()
                }
            }
            onClicked: {
                if (input_key.text.trim().length == 0) {
                    return
                }

                if (input_value.text.trim().length == 0) {
                    return
                }

                dictionary_manager.signal_dict_insert(input_key.text, input_value.text)
            }
        }
    }

    InputWordLine {
        id: input_key
        x: 10
        y: 10
        width: 270
        height: 70
        title: "Dutch Word"
    }

    InputWordLine {
        id: input_value
        width: 270
        height: 70
        title: "Tranlation"

        anchors.left: input_key.right
        anchors.verticalCenter: input_key.verticalCenter
        anchors.margins: 10
    }
}
