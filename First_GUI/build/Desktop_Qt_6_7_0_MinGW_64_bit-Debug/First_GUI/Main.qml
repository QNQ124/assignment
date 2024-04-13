import QtQuick
import QtQuick.Controls
import Qt.labs.platform

Window {

    width: 1120
    height: 520

    visible: true
    title: qsTr("Baby Photoshop")

    Rectangle {
        id: topbar

        anchors {
            top: parent.top
            left: parent.left
            right: parent.right
        }

        height: 50
        color: "#F2F2F2"
        anchors.leftMargin: 84
        anchors.rightMargin: 0
        anchors.topMargin: 0
    }
    Rectangle {
        id: mainSection

        anchors {
            top: topbar.top
            bottom: topbar.top
            left: topbar.right
            right: topbar.left
        }

        color: "#ffffff"
        anchors.verticalCenter: topbar.verticalCenter
        anchors.leftMargin: -1130
        anchors.rightMargin: -1110
        anchors.topMargin: -1
        anchors.bottomMargin: -519
        anchors.horizontalCenterOffset: -10
        anchors.horizontalCenter: topbar.horizontalCenter

        AutoInfoBox {
            id: firstimage

            anchors {
                verticalCenter: parent.verticalCenter
                left: parent.left
                right: parent.right
                margins: 50
            }

            imageSource1: "assets/images/Monument+Grey.jpeg"
        }

        Image {
            id: second_image

            property alias imageSource: second_image.source
            x: 332

            anchors {
                verticalCenter: parent.verticalCenter
                left: emptyBox.right
            }
            width: 250
            height: 250
            anchors.leftMargin: -653
            anchors.verticalCenterOffset: 0
        }

        Rectangle {
            id: emptybox0

            anchors {
                verticalCenter: parent.vertiacalCenter
                left: firstimage.right
            }

            width: 30
            height: 250
            color: "white"
        }

        AutoInfoBox {
            id: secondimage

            anchors {
                verticalCenter: parent.verticalCenter
                left: emptybox0.right
                margins: 50
            }

            // imageSource2: "assets/images/Monument+Grey.jpeg"
        }
    }

    Rectangle {
        id: bottombar

        anchors {
            bottom: parent.bottom
            left: parent.left
            right: parent.right
        }

        height: 20
        color: "#DDDDDD"
    }

    Rectangle {
        id: topbartitle
        width: 1141

        anchors {
            top: topbar.bottom
            left: topbar.right
            right: topbar.left
        }

        height: 50
        color: "#F2F2F2"
        anchors.horizontalCenterOffset: 0
        anchors {
            bottom: topbar.top
            leftMargin: -1120
            rightMargin: -1120
            topMargin: -50
            bottomMargin: -55
        }
        Text {
            id: mainTitle1
            x: 27

            anchors {
                verticalCenter: topbartitle.verticalCenter
            }

            text: "Baby"
            anchors.verticalCenterOffset: -1
            color: "black"

            font {
                pixelSize: 28
            }
        }

        Text {
            id: mainTitle2

            anchors {
                left: mainTitle1.right
                verticalCenter: topbartitle.verticalCenter
            }

            text: "Photoshop"
            color: "#A458FF"

            font {
                pixelSize: 32
                bold: true
            }
        }
    }

    Rectangle {
        id: emptyBox3
        x: 1080

        anchors {
            verticalCenter: parent.verticalCenter
            right: parent.right
        }

        width: 40
        height: 560
        visible: true
        anchors.rightMargin: 0
        anchors.verticalCenterOffset: 0
    }

    Rectangle {
        id: filter1

        property color baseColor1: "white"

        anchors {
            top: emptyBox3.top
            right: emptyBox3.left
        }

        color: if (buttonMouseArea1.containPress) {
                   return Qt.darker(baseColor1)
               } else if (buttonMouseArea1.containsMouse) {
                   return Qt.darker(baseColor1)
               } else {
                   return baseColor1
               }

        x: 983
        width: 91
        height: 39
        anchors.rightMargin: 6
        anchors.topMargin: 145

        Text {
            id: grayScale
            y: 9
            anchors.horizontalCenter: filter1.horizontalCenter
            text: "Gray scale"
            anchors.horizontalCenterOffset: 0
            color: "#101010"
            font {
                pixelSize: 12
            }
        }

        MouseArea {
            id: buttonMouseArea1

            anchors.fill: parent
            anchors.leftMargin: 8
            anchors.rightMargin: 4
            anchors.topMargin: 3
            anchors.bottomMargin: 8
            hoverEnabled: true

            onClicked: {
                // Call the C++ slot to apply the grayscale filter
                var result = Qt.file.remove(
                            "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg")
                imageProcessor1.applyGrayScale(fileOpenDialog.currentFile)
                second_image.imageSource = "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg"
            }
        }
    }

    Rectangle {
        id: filter2

        property color baseColor2: "white"

        color: if (buttonMouseArea2.containPress) {
                   return Qt.darker(baseColor2)
               } else if (buttonMouseArea2.containsMouse) {
                   return Qt.darker(baseColor2)
               } else {
                   return baseColor2
               }

        x: 982
        y: 162
        width: 91
        height: 42
        anchors.right: emptyBox3.left
        anchors.top: emptyBox3.top
        anchors.rightMargin: 7
        anchors.topMargin: 194

        Text {
            id: blackAndwhite
            y: 13
            color: "#101010"
            text: "Black & White"
            font.pixelSize: 12
            anchors.horizontalCenterOffset: -1
            anchors.horizontalCenter: filter2.horizontalCenter
        }

        MouseArea {
            id: buttonMouseArea2
            width: 94
            height: 40
            anchors.verticalCenter: blackAndwhite.verticalCenter
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: blackAndwhite.bottom
            anchors.bottom: parent.bottom
            anchors.leftMargin: 0

            anchors.rightMargin: -90
            anchors.topMargin: -26
            anchors.bottomMargin: 0
            anchors.verticalCenterOffset: 1
            anchors.horizontalCenterOffset: 1
            anchors.horizontalCenter: blackAndwhite.horizontalCenter
            hoverEnabled: true

            onClicked: {
                // Call the C++ slot to apply the grayscale filter
                imageProcessor2.applyBlackAndWhite(fileOpenDialog.currentFile)
                second_image.imageSource = "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg"
            }
        }
    }

    Rectangle {
        id: filter3

        property color baseColor3: "white"

        color: if (buttonMouseArea3.containPress) {
                   return Qt.darker(baseColor3)
               } else if (buttonMouseArea3.containsMouse) {
                   return Qt.darker(baseColor3)
               } else {
                   return baseColor3
               }

        x: 985
        y: 217
        width: 88
        height: 38
        anchors.right: emptyBox3.left
        anchors.top: emptyBox3.top
        anchors.rightMargin: 7
        anchors.topMargin: 249

        Text {
            id: purple_Filter
            y: 10
            color: "#101010"
            text: "Purple Filter"
            font.pixelSize: 12
            anchors.horizontalCenterOffset: -1
            anchors.horizontalCenter: filter3.horizontalCenter
        }

        MouseArea {
            id: buttonMouseArea3

            anchors.fill: parent
            anchors.leftMargin: 0
            anchors.rightMargin: 0
            anchors.topMargin: 0
            anchors.bottomMargin: 0
            hoverEnabled: true

            property int counter: -1

            onClicked: {
                // Call the C++ slot to apply the grayscale filter
                imageProcessor3.applyPurple(fileOpenDialog.currentFile)
                second_image.imageSource = "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg"
            }
        }
    }

    Rectangle {
        id: filter4

        property color baseColor4: "white"

        color: if (buttonMouseArea4.containPress) {
                   return Qt.darker(baseColor4)
               } else if (buttonMouseArea4.containsMouse) {
                   return Qt.darker(baseColor4)
               } else {
                   return baseColor4
               }

        x: 985
        y: 277
        width: 88
        height: 38
        anchors.right: emptyBox3.left
        anchors.top: emptyBox3.top
        anchors.rightMargin: 7
        anchors.topMargin: 303

        Text {
            id: invert_Filter
            y: 8
            color: "#101010"
            text: "Invert Filter"
            font.pixelSize: 12
            anchors.horizontalCenterOffset: 0
            anchors.horizontalCenter: filter4.horizontalCenter
        }

        MouseArea {
            id: buttonMouseArea4

            anchors.fill: parent
            anchors.leftMargin: 0
            anchors.rightMargin: 0
            anchors.topMargin: -1
            anchors.bottomMargin: 1
            hoverEnabled: true

            onClicked: {
                // Call the C++ slot to apply the grayscale filter
                imageProcessor4.applyInvert(fileOpenDialog.currentFile).source
                        = "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg"
            }
        }
    }

    Rectangle {
        id: filter5

        property color baseColor5: "white"

        color: if (buttonMouseArea5.containPress) {
                   return Qt.darker(baseColor5)
               } else if (buttonMouseArea5.containsMouse) {
                   return Qt.darker(baseColor5)
               } else {
                   return baseColor5
               }

        x: 985
        y: 333
        width: 88
        height: 38
        anchors.right: emptyBox3.left
        anchors.top: emptyBox3.top
        anchors.rightMargin: 7
        anchors.topMargin: 358

        Text {
            id: infrared_Filter
            y: 9
            color: "#101010"
            text: "Infrared Filter"
            font.pixelSize: 12
            anchors.horizontalCenterOffset: 0
            anchors.horizontalCenter: filter5.horizontalCenter
        }

        MouseArea {
            id: buttonMouseArea5
            x: -6
            width: 91
            height: 44

            anchors.fill: parent
            anchors.leftMargin: -3
            anchors.rightMargin: -1
            anchors.topMargin: -3
            anchors.bottomMargin: -3
            hoverEnabled: true

            onClicked: {
                imageProcessor5.applyInfrared(fileOpenDialog.currentFile)
                second_image5.source = "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg"
            }
        }
    }

    Rectangle {
        id: filter6

        property color baseColor6: "white"

        color: if (buttonMouseArea6.containPress) {
                   return Qt.darker(baseColor6)
               } else if (buttonMouseArea6.containsMouse) {
                   return Qt.darker(baseColor6)
               } else {
                   return baseColor6
               }

        x: 880
        y: 390
        width: 88
        height: 38
        anchors.right: emptyBox3.left
        anchors.top: emptyBox3.top
        anchors.rightMargin: 112
        anchors.topMargin: 301

        Text {
            id: noise_Filter
            y: 8
            color: "#101010"
            text: "Noise Filter"
            font.pixelSize: 12
            anchors.horizontalCenterOffset: -1
            anchors.horizontalCenter: filter6.horizontalCenter
        }

        MouseArea {
            id: buttonMouseArea6
            y: -5
            height: 43

            anchors.fill: parent
            anchors.leftMargin: -4
            anchors.rightMargin: -2
            anchors.topMargin: -2
            anchors.bottomMargin: -3
            hoverEnabled: true

            onClicked: {
                imageProcessor6.applyNoise(fileOpenDialog.currentFile)
                second_image6.source = "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg"
            }
        }
    }

    Rectangle {
        id: filter7

        property color baseColor7: "white"

        color: if (buttonMouseArea7.containPress) {
                   return Qt.darker(baseColor7)
               } else if (buttonMouseArea7.containsMouse) {
                   return Qt.darker(baseColor7)
               } else {
                   return baseColor7
               }

        x: 673
        y: 107
        width: 88
        height: 38
        anchors.right: emptyBox3.left
        anchors.top: emptyBox3.top
        anchors.rightMargin: 319
        anchors.topMargin: 358

        Text {
            id: night_Vision
            y: 7
            color: "#101010"
            text: "Night Vision"
            font.pixelSize: 12
            anchors.horizontalCenterOffset: -1
            anchors.horizontalCenter: filter7.horizontalCenter
        }

        MouseArea {
            id: buttonMouseArea7

            anchors.fill: parent
            anchors.leftMargin: 0
            anchors.rightMargin: 0
            anchors.topMargin: -2
            anchors.bottomMargin: -2
            hoverEnabled: true

            onClicked: {
                imageProcessor7.applyNightVision(fileOpenDialog.currentFile)
                second_image7.source = "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg"
            }
        }
    }

    Rectangle {
        id: filter8

        property color baseColor8: "white"

        color: if (buttonMouseArea8.containPress) {
                   return Qt.darker(baseColor8)
               } else if (buttonMouseArea8.containsMouse) {
                   return Qt.darker(baseColor8)
               } else {
                   return baseColor8
               }

        x: 880
        y: 162
        width: 88
        height: 38
        anchors.right: emptyBox3.left
        anchors.top: emptyBox3.top
        anchors.rightMargin: 112
        anchors.topMargin: 143

        Text {
            id: detect_Edges
            y: 9
            color: "#101010"
            text: "Detect Edges"
            font.pixelSize: 12
            anchors.horizontalCenterOffset: 0
            anchors.horizontalCenter: filter8.horizontalCenter
        }

        MouseArea {
            id: buttonMouseArea8

            anchors.fill: parent
            anchors.leftMargin: 0
            anchors.rightMargin: 0
            anchors.topMargin: 0
            anchors.bottomMargin: 0
            hoverEnabled: true

            onClicked: {
                imageProcessor8.applyDetectEdges(fileOpenDialog.currentFile)
                second_image8.source = "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg"
            }
        }
    }

    Rectangle {
        id: filter9

        property color baseColor9: "white"

        color: if (buttonMouseArea9.containPress) {
                   return Qt.darker(baseColor9)
               } else if (buttonMouseArea9.containsMouse) {
                   return Qt.darker(baseColor9)
               } else {
                   return baseColor9
               }

        x: 880
        y: 217
        width: 88
        height: 38
        anchors.right: emptyBox3.left
        anchors.top: emptyBox3.top
        anchors.rightMargin: 112
        anchors.topMargin: 196

        Text {
            id: oil_Painting
            y: 9
            color: "#101010"
            text: "Oil Painting"
            font.pixelSize: 12
            anchors.horizontalCenterOffset: 0
            anchors.horizontalCenter: filter9.horizontalCenter
        }

        MouseArea {
            id: buttonMouseArea9

            anchors.fill: parent
            anchors.leftMargin: -1
            anchors.rightMargin: 1
            anchors.topMargin: 1
            anchors.bottomMargin: -1
            hoverEnabled: true

            onClicked: {
                imageProcessor9.applyOilPainting(fileOpenDialog.currentFile)
                second_image9.source = fileOpenDialog.currentFiles
            }
        }
    }

    Rectangle {
        id: filter10

        property color baseColor10: "white"

        color: if (buttonMouseArea10.containPress) {
                   return Qt.darker(baseColor10)
               } else if (buttonMouseArea10.containsMouse) {
                   return Qt.darker(baseColor10)
               } else {
                   return baseColor10
               }

        x: 880
        y: 277
        width: 88
        height: 38
        anchors.right: emptyBox3.left
        anchors.top: emptyBox3.top
        anchors.rightMargin: 112
        anchors.topMargin: 250

        Text {
            id: sunlight_Filter
            y: 9
            color: "#101010"
            text: "Sunlight Filter"
            font.pixelSize: 12
            anchors.horizontalCenterOffset: -3
            anchors.horizontalCenter: filter10.horizontalCenter
        }

        MouseArea {
            id: buttonMouseArea10

            anchors.fill: parent
            anchors.leftMargin: -6
            anchors.rightMargin: 0
            anchors.topMargin: -5
            anchors.bottomMargin: -2
            hoverEnabled: true

            onClicked: {
                imageProcessor10.applySunlight(fileOpenDialog.currentFile)
                second_image10.source = "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg"
            }
        }
    }

    Rectangle {
        id: filter11

        property color baseColor11: "white"

        color: if (buttonMouseArea11.containPress) {
                   return Qt.darker(baseColor11)
               } else if (buttonMouseArea11.containsMouse) {
                   return Qt.darker(baseColor11)
               } else {
                   return baseColor11
               }

        x: 880
        y: 338
        width: 88
        height: 38
        anchors.right: emptyBox3.left
        anchors.top: emptyBox3.top
        anchors.rightMargin: 112
        anchors.topMargin: 358

        Text {
            id: old_Tv_Filter
            y: 8
            color: "#101010"
            text: "Old_TV Filter"
            font.pixelSize: 12
            anchors.horizontalCenterOffset: -1
            anchors.horizontalCenter: filter11.horizontalCenter
        }

        MouseArea {
            id: buttonMouseArea11

            anchors.fill: parent
            anchors.leftMargin: -2
            anchors.rightMargin: 2
            anchors.topMargin: -4
            anchors.bottomMargin: -1
            hoverEnabled: true

            onClicked: {
                imageProcessor11.applyOldTV(fileOpenDialog.currentFile)
                second_image11.source = "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg"
            }
        }
    }

    Rectangle {
        id: filter12

        property color baseColor12: "white"

        color: if (buttonMouseArea12.containPress) {
                   return Qt.darker(baseColor12)
               } else if (buttonMouseArea12.containsMouse) {
                   return Qt.darker(baseColor12)
               } else {
                   return baseColor12
               }

        x: 673
        y: 394
        width: 88
        height: 38
        anchors.right: emptyBox3.left
        anchors.top: emptyBox3.top
        anchors.rightMargin: 319
        anchors.topMargin: 144
        Text {
            id: old_Tv_Filter1
            y: 8
            color: "#101010"
            text: "Old_TV Filter"
            font.pixelSize: 12
            anchors.horizontalCenterOffset: 0
            anchors.horizontalCenter: filter12.horizontalCenter
        }
    }

    Rectangle {
        id: filter13

        property color baseColor12: "white"

        color: if (buttonMouseArea12.containPress) {
                   return Qt.darker(baseColor12)
               } else if (buttonMouseArea12.containsMouse) {
                   return Qt.lighter(baseColor12)
               } else {
                   return baseColor12
               }

        x: 775
        y: 394
        width: 88
        height: 38
        anchors.right: emptyBox3.left
        anchors.top: emptyBox3.top
        anchors.rightMargin: 217
        anchors.topMargin: 143
        Text {
            id: old_Tv_Filter2
            y: 9
            color: "#101010"
            text: "Old_TV Filter"
            font.pixelSize: 12
            anchors.horizontalCenterOffset: 0
            anchors.horizontalCenter: filter13.horizontalCenter
        }
    }

    Rectangle {
        id: filter14

        property color baseColor12: "white"

        color: if (buttonMouseArea12.containPress) {
                   return Qt.darker(baseColor12)
               } else if (buttonMouseArea12.containsMouse) {
                   return Qt.lighter(baseColor12)
               } else {
                   return baseColor12
               }

        x: 775
        y: 123
        width: 88
        height: 38
        anchors.right: emptyBox3.left
        anchors.top: emptyBox3.top
        anchors.rightMargin: 217
        anchors.topMargin: 196
        Text {
            id: old_Tv_Filter3
            y: 9
            color: "#101010"
            text: "Old_TV Filter"
            font.pixelSize: 12
            anchors.horizontalCenterOffset: 0
            anchors.horizontalCenter: filter14.horizontalCenter
        }
    }

    Rectangle {
        id: filter15

        property color baseColor12: "white"

        color: if (buttonMouseArea12.containPress) {
                   return Qt.darker(baseColor12)
               } else if (buttonMouseArea12.containsMouse) {
                   return Qt.lighter(baseColor12)
               } else {
                   return baseColor12
               }

        x: 776
        y: 230
        width: 86
        height: 38
        anchors.right: emptyBox3.left
        anchors.top: emptyBox3.top
        anchors.rightMargin: 218
        anchors.topMargin: 250
        Text {
            id: old_Tv_Filter4
            y: 9
            color: "#101010"
            text: "Old_TV Filter"
            font.pixelSize: 12
            anchors.horizontalCenterOffset: 0
            anchors.horizontalCenter: filter15.horizontalCenter
        }
    }

    Rectangle {
        id: filter16

        property color baseColor12: "white"

        color: if (buttonMouseArea12.containPress) {
                   return Qt.darker(baseColor12)
               } else if (buttonMouseArea12.containsMouse) {
                   return Qt.lighter(baseColor12)
               } else {
                   return baseColor12
               }

        x: 775
        y: 281
        width: 88
        height: 38
        anchors.right: emptyBox3.left
        anchors.top: emptyBox3.top
        anchors.rightMargin: 217
        anchors.topMargin: 301
        Text {
            id: old_Tv_Filter5
            y: 9
            color: "#101010"
            text: "Old_TV Filter"
            font.pixelSize: 12
            anchors.horizontalCenterOffset: 0
            anchors.horizontalCenter: filter16.horizontalCenter
        }
    }

    Rectangle {
        id: filter17

        property color baseColor12: "white"

        color: if (buttonMouseArea12.containPress) {
                   return Qt.darker(baseColor12)
               } else if (buttonMouseArea12.containsMouse) {
                   return Qt.lighter(baseColor12)
               } else {
                   return baseColor12
               }

        x: 776
        y: 338
        width: 88
        height: 38
        anchors.right: emptyBox3.left
        anchors.top: emptyBox3.top
        anchors.rightMargin: 216
        anchors.topMargin: 358
        Text {
            id: old_Tv_Filter6
            y: 9
            color: "#101010"
            text: "Old_TV Filter"
            font.pixelSize: 12
            anchors.horizontalCenterOffset: 0
            anchors.horizontalCenter: filter17.horizontalCenter
        }
    }

    Rectangle {
        id: filter18

        property color baseColor12: "white"

        color: if (buttonMouseArea12.containPress) {
                   return Qt.darker(baseColor12)
               } else if (buttonMouseArea12.containsMouse) {
                   return Qt.lighter(baseColor12)
               } else {
                   return baseColor12
               }

        x: 673
        y: 394
        width: 88
        height: 38
        anchors.right: emptyBox3.left
        anchors.top: emptyBox3.top
        anchors.rightMargin: 319
        anchors.topMargin: 196
        Text {
            id: old_Tv_Filter7
            y: 9
            color: "#101010"
            text: "Old_TV Filter"
            font.pixelSize: 12
            anchors.horizontalCenterOffset: 0
            anchors.horizontalCenter: filter18.horizontalCenter
        }
    }

    Rectangle {
        id: filter19

        property color baseColor12: "white"

        color: if (buttonMouseArea12.containPress) {
                   return Qt.darker(baseColor12)
               } else if (buttonMouseArea12.containsMouse) {
                   return Qt.lighter(baseColor12)
               } else {
                   return baseColor12
               }

        x: 673
        y: 230
        width: 88
        height: 38
        anchors.right: emptyBox3.left
        anchors.top: emptyBox3.top
        anchors.rightMargin: 319
        anchors.topMargin: 250

        Text {
            id: old_Tv_Filter8
            y: 9
            color: "#101010"
            text: "Old_TV Filter"
            font.pixelSize: 12
            anchors.horizontalCenterOffset: 0
            anchors.horizontalCenter: filter19.horizontalCenter
        }
    }

    Rectangle {
        id: filter20

        property color baseColor12: "white"

        color: if (buttonMouseArea12.containPress) {
                   return Qt.darker(baseColor12)
               } else if (buttonMouseArea12.containsMouse) {
                   return Qt.lighter(baseColor12)
               } else {
                   return baseColor12
               }

        x: 673
        y: 283
        width: 88
        height: 38
        anchors.right: emptyBox3.left
        anchors.top: emptyBox3.top
        anchors.rightMargin: 319
        anchors.topMargin: 303
        Text {
            id: old_Tv_Filter9
            y: 9
            color: "#101010"
            text: "Old_TV Filter"
            font.pixelSize: 12
            anchors.horizontalCenterOffset: 0
            anchors.horizontalCenter: filter20.horizontalCenter
        }
    }

    Rectangle {
        id: emptyBox
        x: 974
        width: 1
        height: 260
        color: "#ae58ff"
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: albumImage1.right
        anchors.verticalCenterOffset: -8
    }

    Rectangle {
        id: emptyBox4
        x: 673
        y: 167
        width: 406
        height: 0.5
        color: "#ae58ff"
    }

    Rectangle {
        id: emptyBox5
        x: 673
        y: 220
        width: 406
        height: 1
        color: "#ae58ff"
    }

    Rectangle {
        id: emptyBox6
        x: 673
        y: 274
        width: 406
        height: 1
        color: "#ae58ff"
    }

    Rectangle {
        id: emptyBox7
        x: 673
        y: 327
        width: 406
        height: 0.5
        color: "#ae58ff"
    }

    Rectangle {
        id: emptyBox12
        x: 1080
        width: 40
        height: 76
        color: "#F2F2F2"
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: albumImage1.right
        anchors.verticalCenterOffset: -243
    }

    Rectangle {
        id: emptyBox13
        x: 1080
        width: 40
        height: 20
        color: "#dddddd"
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: albumImage1.right
        anchors.verticalCenterOffset: 250
    }

    Rectangle {
        id: clear

        property color baseColor21: "#F8F8F8"
        color: "#F2F2F2"
        x: 935
        y: 16
        width: 79
        height: 34

        anchors.right: emptyBox3.left
        anchors.top: emptyBox3.top
        anchors.rightMargin: 66
        anchors.topMargin: 31
        Text {
            id: detect_Edges1
            y: 9
            color: "#101010"
            text: "Clear"
            font.pixelSize: 12
            anchors.horizontalCenterOffset: 0
            anchors.horizontalCenter: clear.horizontalCenter
        }

        MouseArea {
            id: buttonMouseArea12
            anchors.fill: parent
            anchors.leftMargin: 0
            anchors.rightMargin: -8
            anchors.topMargin: -2
            anchors.bottomMargin: -2
            hoverEnabled: true

            onClicked: {

            }
        }
    }

    Rectangle {
        id: emptyBox10
        x: 924
        width: 2
        height: 37
        color: "#ae58ff"
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: albumImage1.right
        anchors.verticalCenterOffset: -231
    }

    Rectangle {
        id: save

        property color baseColor22: "#F2F2F2"
        color: buttonMouseArea13.pressed ? Qt.darker(
                                               baseColor22) : buttonMouseArea13.containsMouse ? Qt.lighter(baseColor22) : baseColor22

        x: 837
        y: 11
        width: 78
        height: 34
        anchors.right: emptyBox3.left
        anchors.top: emptyBox3.top
        anchors.rightMargin: 165
        anchors.topMargin: 31

        Text {
            id: saveOption
            y: 9
            color: "#101010"
            text: "Save"
            font.pixelSize: 12
            anchors.horizontalCenterOffset: 0
            anchors.horizontalCenter: save.horizontalCenter
        }

        MouseArea {
            id: buttonMouseArea13

            anchors.fill: parent
            anchors.leftMargin: 0
            anchors.rightMargin: 0
            anchors.topMargin: 0
            anchors.bottomMargin: 0
            hoverEnabled: true

            onClicked: {
                var filePath = Qt.platform.openFileDialog("Save File", "",
                                                          "All Files (*)")
                if (filePath !== "") {

                }
            }
        }
    }

    Rectangle {
        id: emptyBox14
        x: 826
        width: 2
        height: 37
        color: "#ae58ff"
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: albumImage1.right
        anchors.verticalCenterOffset: -231
    }

    Rectangle {
        id: load
        property alias imageSource: first_image.source
        property color baseColor: "#F2F2F2"

        color: buttonMouseArea23.pressed ? Qt.darker(
                                               baseColor) : buttonMouseArea23.containsMouse ? Qt.lighter(baseColor) : baseColor

        x: 738
        y: 11
        width: 78
        height: 34
        anchors.right: emptyBox3.left
        anchors.top: emptyBox3.top
        anchors.rightMargin: 264
        anchors.topMargin: 31

        Image {
            id: first_image

            anchors {
                verticalCenter: parent.verticalCenter
                left: parent.left
                margins: 50
            }
            width: 250
            height: 250
            anchors.leftMargin: -698
            anchors.verticalCenterOffset: 231
        }

        Text {
            id: image_Before
            y: 9
            color: "#101010"
            text: "Load"
            font.pixelSize: 12
            anchors.horizontalCenterOffset: 0
            anchors.horizontalCenter: load.horizontalCenter
        }

        MouseArea {
            id: buttonMouseArea23
            anchors.fill: parent
            hoverEnabled: true

            onClicked: {
                fileOpenDialog.open()
            }
        }

        FileDialog {
            id: fileOpenDialog

            folder: StandardPaths.writableLocation(StandardPaths.HomeLocation)

            nameFilters: ["Image files (*.png *.jpeg *.jpg *.bmp)"]

            onAccepted: {
                if (fileOpenDialog.currentFile !== undefined) {
                    var fileName = fileOpenDialog.currentFile
                    first_image.source = fileName
                } else {
                    first_image.source = "assets/images/Monument+Grey.jpeg"
                }
            }
        }
    }

    Rectangle {
        id: beforeBox
        x: 50
        y: 98
        width: 102
        height: 32
        anchors.right: emptyBox3.left
        anchors.top: emptyBox3.top
        anchors.rightMargin: 928
        anchors.topMargin: 116
        Text {
            id: imageText1
            x: 3
            y: 11
            width: 46.825
            height: 23
            color: "black"
            text: "Before"
            font.pixelSize: 16
            anchors.horizontalCenterOffset: -16
            anchors.horizontalCenter: beforeBox.horizontalCenter
        }
    }

    Rectangle {
        id: afterBox
        x: 323
        y: 97
        width: 102
        height: 32
        anchors.right: emptyBox3.left
        anchors.top: emptyBox3.top
        anchors.rightMargin: 655
        anchors.topMargin: 116

        Text {
            id: imageText2
            x: 0
            y: 9
            color: "black"
            text: "After"
            font.pixelSize: 16
            anchors.horizontalCenterOffset: -23
            anchors.horizontalCenter: afterBox.horizontalCenter
        }
    }

    Rectangle {
        id: imagePathBox

        x: 50
        y: 418
        width: 486
        height: 32
        anchors.right: emptyBox3.left
        anchors.top: emptyBox3.top
        anchors.rightMargin: 544
        anchors.topMargin: 434
        Text {
            id: imageText3
            x: 7
            y: 5
            width: 58
            height: 23
            color: "#000000"
            text: "Image_Path: "
            font.pixelSize: 10
            anchors.horizontalCenterOffset: -209
            anchors.horizontalCenter: imagePathBox.horizontalCenter
        }

        Text {
            id: imageText4
            x: 62
            y: 5
            width: 416
            height: 23
            text: fileOpenDialog.currentFile
            color: "#000000"
            font.pixelSize: 10
            anchors.horizontalCenterOffset: 26
            anchors.horizontalCenter: imagePathBox.horizontalCenter
        }
    }

    Rectangle {
        id: emptyBox1
        x: 870
        width: 0.5
        height: 260
        color: "#ae58ff"
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: albumImage1.right
        anchors.verticalCenterOffset: -8
    }

    Rectangle {
        id: emptyBox2
        x: 767
        width: 0.5
        height: 260
        color: "#ae58ff"
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: albumImage1.right
        anchors.verticalCenterOffset: -8
    }
}
