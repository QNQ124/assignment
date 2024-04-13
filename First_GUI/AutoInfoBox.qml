import QtQuick

Item {
    id: root

    property alias imageSource1: albumImage1.source

    // property alias imageSource2: albumImage2.source
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

    // Image {
    //     id: albumImage2

    //     anchors {
    //         verticalCenter: parent.verticalCenter
    //         left: emptyBox.right
    //     }
    //     width: 250
    //     height: 250
    //     anchors.leftMargin: 2

    //     source: "assets/images/Monument+Grey.jpeg"
    //     anchors.verticalCenterOffset: 0
    // }
}
