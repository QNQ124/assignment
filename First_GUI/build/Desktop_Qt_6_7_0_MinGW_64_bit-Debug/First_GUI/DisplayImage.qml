import QtQuick

Item {
    id: root2

    property int count: 0
    property alias imageSource2: albumImage_2.source

    Image {
        id: albumImage_2
        x: 227

        anchors {
            verticalCenter: parent.verticalCenter
        }
        width: 250
        height: 250
        anchors.leftMargin: 14
        anchors.verticalCenterOffset: -15
        cache: false
    }

}
