import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.1

import Engine 1.0

Page {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Engine {
        id: myEngine
    }

    Text {
        id: textBestScore
        x: 579
        y: 0
        width: 61
        height: 15
        text: qsTr("Best Score")
        font.pixelSize: 12
    }

    Text {
        id: textScore
        x: 308
        y: 0
        text: qsTr("Score")
        anchors.horizontalCenter: parent.horizontalCenter
        font.pixelSize: 12
    }

    Text {
        id: textChrono
        x: 0
        y: 0
        text: myEngine.chrono
        font.pixelSize: 12
    }

    Text {
        id: textQuestion
        x: 291
        y: 97
        color: colorResult.color
        text: myEngine.question
        anchors.horizontalCenterOffset: 3
        anchors.horizontalCenter: parent.horizontalCenter
        font.pixelSize: 20
    }

    Button {
        id: buttonValidate
        x: 248
        y: 252
        width: 150
        height: 32
        text: qsTr("Valider")
        onClicked: myEngine.onButtonAnswerClicked(textFieldAnswer.text)
        anchors.horizontalCenter: parent.horizontalCenter
        visible: (!myEngine.questionFinished) && (!myEngine.squareJokerActivated)
    }

    Button {
        id: buttonNext
        x: 248
        y: 252
        width: 150
        height: 32
        text: qsTr("Question suivante")
        onClicked: myEngine.onButtonNextClicked()
        anchors.horizontalCenter: parent.horizontalCenter
        visible: myEngine.questionFinished
    }


    Button {
        id: buttonSquare
        x: 38
        y: 318
        width: 147
        height: 27
        onClicked: myEngine.onJokerAsked()
        text: qsTr("Carré")
        anchors.horizontalCenter: parent.horizontalCenter
        visible: (!myEngine.questionFinished) && (!myEngine.squareJokerActivated)
    }

    Text {
        id: textBestScoreDisplay
        x: 548
        y: 15
        text: myEngine.bestScore
        font.pixelSize: 12
    }

    Text {
        id: textScoreDisplay
        x: 287
        y: 15
        text: myEngine.score
        anchors.horizontalCenter: parent.horizontalCenter
        lineHeight: 1
        font.pixelSize: 30
    }

    Text {
        id: textRightAnswer
        x: 314
        y: 132
        text: myEngine.rightAnswer
        color: colorResult.color
        anchors.horizontalCenterOffset: 0
        anchors.horizontalCenter: parent.horizontalCenter
        font.pixelSize: 20
        visible: myEngine.questionFinished
    }

    TextField {
        id: textFieldAnswer
        x: 199
        y: 176
        width: 248
        height: 25
        text: if (!myEngine.questionFinished) {qsTr("")}
        maximumLength: 40
        anchors.horizontalCenter: parent.horizontalCenter
        placeholderText: qsTr("Capitale")
        visible: !myEngine.squareJokerActivated
    }

    Text {
        id: colorResult
        color: if (myEngine.questionFinished) {
                   if( myEngine.displayGood)
                       "#00cc00"
                   else "#cc0000"
               } else
                   "#000000"

        visible: false
    }

    Text {
        id: testResult
        x: 308
        y: 219
        text: if( myEngine.displayGood)
                  qsTr("Bonne réponse")
              else qsTr("Mauvaise réponse")
        anchors.horizontalCenterOffset: 0
        color: colorResult.color
        anchors.horizontalCenter: parent.horizontalCenter
        font.pixelSize: 16
        visible: myEngine.questionFinished
    }

    Button {
        id: buttonSquare1
        x: 108
        y: 176
        anchors.verticalCenterOffset: -52
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenterOffset: -160
        anchors.horizontalCenter: parent.horizontalCenter
        visible: myEngine.squareJokerActivated
        onClicked: onSquareClicked(this)
        enabled: !myEngine.questionFinished
        contentItem: Text {
                text: myEngine.squareAnswer1
                color: if (buttonSquare1.enabled) {"black"}
                       else { if(buttonSquare1.contentItem.text === myEngine.rightAnswer){"#00cc00"}
                           else "#cc0000" }
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                elide: Text.ElideRight
                anchors.fill: parent
            }
    }

    Button {
        id: buttonSquare2
        y: 378
        anchors.verticalCenterOffset: -52
        anchors.horizontalCenterOffset: 160
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        visible: myEngine.squareJokerActivated
        onClicked: onSquareClicked(this)
        enabled: !myEngine.questionFinished
        contentItem: Text {
                text: myEngine.squareAnswer2
                color: if (buttonSquare2.enabled) {"black"}
                       else { if(buttonSquare2.contentItem.text === myEngine.rightAnswer){"#00cc00"}
                           else "#cc0000" }
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                elide: Text.ElideRight
                anchors.fill: parent
            }
    }

    Button {
        id: buttonSquare3
        x: 349
        y: 219
        anchors.verticalCenterOffset: -7
        anchors.horizontalCenterOffset: -160
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        visible: myEngine.squareJokerActivated
        onClicked: myEngine.onButtonAnswerClicked(myEngine.squareAnswer3)
        enabled: !myEngine.questionFinished
        contentItem: Text {
                text: myEngine.squareAnswer3
                color: if (buttonSquare3.enabled) {"black"}
                       else { if(buttonSquare3.contentItem.text === myEngine.rightAnswer){"#00cc00"}
                           else "#cc0000" }
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                elide: Text.ElideRight
                anchors.fill: parent
            }
    }

    Button {
        id: buttonSquare4
        x: 360
        y: 411
        text: myEngine.squareAnswer4
        anchors.verticalCenterOffset: -7
        anchors.horizontalCenterOffset: 160
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        visible: myEngine.squareJokerActivated
        onClicked: myEngine.onButtonAnswerClicked(myEngine.squareAnswer4)
        enabled: !myEngine.questionFinished
        contentItem: Text {
                text: myEngine.squareAnswer4
                color: if (buttonSquare4.enabled) {"black"}
                       else { if(buttonSquare4.contentItem.text === myEngine.rightAnswer){"#00cc00"}
                           else "#cc0000" }
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                elide: Text.ElideRight
                anchors.fill: parent
        }
    }

    Button {
        id: buttonNewGame
        text: qsTr("Nouvelle partie")
        anchors.top: parent.top
        anchors.topMargin: 63
        anchors.left: parent.left
        anchors.leftMargin: 8
        onClicked: myEngine.onButtonNewGameClicked(comboBoxContinent.currentText)
    }

    ComboBox {
        id: comboBoxContinent
        anchors.top: parent.top
        anchors.topMargin: 17
        anchors.left: parent.left
        anchors.leftMargin: 8
        model: ListModel {
            id: model
            ListElement { text: "Monde" }
            ListElement { text: "Asie" }
            ListElement { text: "Afrique" }
            ListElement { text: "Amérique" }
            ListElement { text: "Europe" }
            ListElement { text: "Océanie" }
        }
    }

    function onSquareClicked(item){
        myEngine.onButtonAnswerClicked(item.contentItem.text)
    }

}








/*##^## Designer {
    D{i:23;anchors_x:8;anchors_y:63}D{i:24;anchors_x:8;anchors_y:17}
}
 ##^##*/
