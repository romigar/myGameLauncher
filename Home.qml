import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.1

import Engine 1.0

Page {
    id: homepage
    visible: true
    width: 640
    height: 480
    title: qsTr("Home")
    HomeForm {
        buttonNewGame.onClicked: {
            myEngine.onButtonNewGameClicked(comboBoxContinent.currentText)
            stackView.push("countryGuess.qml")
            drawer.close()
        }
    }



}
