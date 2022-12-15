import QtQuick 2.9
import QtQuick.Controls 2.2
import Engine 1.0

Page {
    width: 600
    height: 400

    title: qsTr("Home")

    property alias buttonNewGame: buttonNewGame
    property alias comboBoxContinent: comboBoxContinent

    Label {
        text: qsTr("You are on the home page.")
        anchors.centerIn: parent
    }

    Button {
        id: buttonNewGame
        text: qsTr("Nouvelle partie")
        anchors.top: parent.top
        anchors.topMargin: 63
        anchors.left: parent.left
        anchors.leftMargin: 8
    }

    ComboBox {
        id: comboBoxContinent
        anchors.top: parent.top
        anchors.topMargin: 17
        anchors.left: parent.left
        anchors.leftMargin: 8
        model: ListModel {
            id: model
            ListElement {
                text: "Monde"
            }
            ListElement {
                text: "Asie"
            }
            ListElement {
                text: "Afrique"
            }
            ListElement {
                text: "Amérique"
            }
            ListElement {
                text: "Europe"
            }
            ListElement {
                text: "Océanie"
            }
        }
    }
}
