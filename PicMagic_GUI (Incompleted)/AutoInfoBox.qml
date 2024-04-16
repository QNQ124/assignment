import QtQuick

Item {
    id: root

    property alias imageSource1: albumImage1.source
    property alias imageSource2: albumImage2.source

    Image {
        id: albumImage1

        anchors {
            verticalCenter: parent.verticalCenter
            left: parent.left
        }
        width: 250
        height: 250
    }

    Rectangle {
        id: emptyBox

        anchors {
            verticalCenter: parent.verticalCenter
            left: albumImage1.right
        }
        width: 30
        height: 250
        color: "white"
    }

    Image {
        id: albumImage2

        anchors {
            verticalCenter: parent.verticalCenter
            left: emptyBox.right
        }

        Text {
            id: versiontext2
            x: 51
            y: 110
            width: 148
            height: 27
            color: "#666666"
            text: "To See The Result!"
            anchors.verticalCenter: mainSection.verticalCenter
            anchors.left: mainSection.right
            anchors.right: mainSection.left
            anchors.top: mainSection.bottom
            anchors.bottom: mainSection.top
            anchors.leftMargin: -822
            anchors.rightMargin: -72
            anchors.topMargin: -274
            anchors.bottomMargin: -276
            font.pixelSize: 19
            anchors.horizontalCenter: mainSection.horizontalCenter
            font.italic: true
            anchors.horizontalCenterOffset: -146
        }

        Text {
            id: versiontext4
            x: 69
            y: 84
            width: 112
            height: 27
            color: "#666666"
            text: "Apply a Filter"
            anchors.verticalCenter: mainSection.verticalCenter
            anchors.left: mainSection.right
            anchors.right: mainSection.left
            anchors.top: mainSection.bottom
            anchors.bottom: mainSection.top
            anchors.leftMargin: -805
            anchors.rightMargin: -72
            anchors.topMargin: -304
            anchors.bottomMargin: -246
            font.pixelSize: 19
            anchors.horizontalCenter: mainSection.horizontalCenter
            font.italic: true
            anchors.horizontalCenterOffset: -147
        }
        width: 250
        height: 250
        anchors.leftMargin: 2

        source: "assets/images/log.jpg"
        anchors.verticalCenterOffset: 0
    }
}

/*##^##
Designer {
    D{i:0}D{i:1;locked:true}D{i:2;locked:true}D{i:3;locked:true}D{i:4;locked:true}D{i:5;locked:true}
}
##^##*/
