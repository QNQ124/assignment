import QtQuick
import QtQuick.Controls
import Qt.labs.platform
import QtQuick.Window
import Qt.labs.folderlistmodel

Window {

    width: 1120
    height: 520

    visible: true
    title: qsTr("Baby Photoshop")

    property bool isFirst: false
    property bool isFirst1: false
    property string filename: ""
    property color baseColor12: "white"

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
            cache: false
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

            imageSource2: "assets/images/Monument+Grey.jpeg"
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
        anchors.verticalCenter: topbar.verticalCenter
        anchors.horizontalCenterOffset: 0
        anchors {
            bottom: topbar.top
            leftMargin: -1121
            rightMargin: -1119
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
                if (!isFirst) {
                    imageProcessor1.applyGrayScale(fileOpenDialog.currentFile)
                    second_image.cache = true
                    second_image.imageSource = "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg"
                    second_image.cache = false
                    isFirst = true
                } else {
                    imageProcessor1.applyGrayScale(
                                "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg")
                    second_image.cache = true
                    second_image.imageSource = "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg"
                    second_image.cache = false
                }
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
            anchors.left: blackAndwhite.right
            anchors.right: blackAndwhite.left
            anchors.top: blackAndwhite.bottom
            anchors.bottom: blackAndwhite.top
            anchors.leftMargin: -83

            anchors.rightMargin: -84
            anchors.topMargin: -26
            anchors.bottomMargin: -29
            anchors.verticalCenterOffset: 1
            anchors.horizontalCenterOffset: 1
            anchors.horizontalCenter: blackAndwhite.horizontalCenter
            hoverEnabled: true

            onClicked: {
                // Call the C++ slot to apply the grayscale filter
                if (!isFirst) {
                    imageProcessor2.applyBlackAndWhite(
                                fileOpenDialog.currentFile)
                    second_image.cache = true
                    second_image.imageSource = "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg"
                    second_image.cache = false
                    isFirst = true
                } else {
                    imageProcessor2.applyBlackAndWhite(
                                "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg")
                    second_image.cache = true
                    second_image.imageSource = "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg"
                    second_image.cache = false
                }
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

            onClicked: {
                // Call the C++ slot to apply the grayscale filter
                if (!isFirst) {
                    imageProcessor3.applyPurple(fileOpenDialog.currentFile)
                    second_image.cache = true
                    second_image.imageSource = "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg"
                    second_image.cache = false
                    isFirst = true
                } else {
                    imageProcessor3.applyPurple(
                                "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg")
                    second_image.cache = true
                    second_image.imageSource = "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg"
                    second_image.cache = false
                }
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
                if (!isFirst) {
                    imageProcessor4.applyInvert(fileOpenDialog.currentFile)
                    second_image.cache = true
                    second_image.imageSource = "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg"
                    second_image.cache = false
                    isFirst = true
                } else {
                    imageProcessor4.applyInvert(
                                "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg")
                    second_image.cache = true
                    second_image.imageSource = "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg"
                    second_image.cache = false
                }
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
                if (!isFirst) {
                    imageProcessor5.applyInfrared(fileOpenDialog.currentFile)
                    second_image.cache = true
                    second_image.imageSource = "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg"
                    second_image.cache = false
                    isFirst = true
                } else {
                    imageProcessor5.applyInfrared(
                                "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg")
                    second_image.cache = true
                    second_image.imageSource = "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg"
                    second_image.cache = false
                }
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
                if (!isFirst) {
                    imageProcessor6.applyNoise(fileOpenDialog.currentFile)
                    second_image.cache = true
                    second_image.imageSource = "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg"
                    second_image.cache = false
                    isFirst = true
                } else {
                    imageProcessor6.applyNoise(
                                "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg")
                    second_image.cache = true
                    second_image.imageSource = "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg"
                    second_image.cache = false
                }
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
                if (!isFirst) {
                    imageProcessor7.applyNightVision(fileOpenDialog.currentFile)
                    second_image.cache = true
                    second_image.imageSource = "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg"
                    second_image.cache = false
                    isFirst = true
                } else {
                    imageProcessor7.applyNightVision(
                                "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg")
                    second_image.cache = true
                    second_image.imageSource = "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg"
                    second_image.cache = false
                }
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
                if (!isFirst) {
                    imageProcessor8.applyDetectEdges(fileOpenDialog.currentFile)
                    second_image.cache = true
                    second_image.imageSource = "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg"
                    second_image.cache = false
                    isFirst = true
                } else {
                    imageProcessor8.applyDetectEdges(
                                "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg")
                    second_image.cache = true
                    second_image.imageSource = "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg"
                    second_image.cache = false
                }
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
                if (!isFirst) {
                    imageProcessor9.applyOilPainting(fileOpenDialog.currentFile)
                    second_image.cache = true
                    second_image.imageSource = "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg"
                    second_image.cache = false
                    isFirst = true
                } else {
                    imageProcessor9.applyOilPainting(
                                "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg")
                    second_image.cache = true
                    second_image.imageSource = "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg"
                    second_image.cache = false
                }
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
                if (!isFirst) {
                    imageProcessor10.applySunlight(fileOpenDialog.currentFile)
                    second_image.cache = true
                    second_image.imageSource = "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg"
                    second_image.cache = false
                    isFirst = true
                } else {
                    imageProcessor10.applySunlight(
                                "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg")
                    second_image.cache = true
                    second_image.imageSource = "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg"
                    second_image.cache = false
                }
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
                if (!isFirst) {
                    imageProcessor11.applyOldTV(fileOpenDialog.currentFile)
                    second_image.cache = true
                    second_image.imageSource = "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg"

                    second_image.cache = false
                    isFirst = true
                } else {
                    imageProcessor11.applyOldTV(
                                "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg")
                    second_image.cache = true
                    second_image.imageSource = "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg"
                    second_image.cache = false
                }
            }
        }
    }

    Rectangle {
        id: filter12

        property color baseColor12: "white"

        color: if (buttonMouseArea12.containsMouse) {
                   return Qt.darker(baseColor12)
               } else if (buttonMouseArea12.containsPress) {
                   return Qt.darker(baseColor12)
               } else {
                   return baseColor12
               }

        width: 92
        height: 34
        anchors.verticalCenter: topbar.verticalCenter
        anchors.left: topbar.right
        anchors.right: topbar.left
        anchors.top: topbar.bottom
        anchors.bottom: topbar.top
        anchors.leftMargin: -447
        anchors.rightMargin: -677
        anchors.topMargin: 77
        anchors.bottomMargin: -162
        anchors.verticalCenterOffset: 119
        anchors.horizontalCenterOffset: 113
        anchors.horizontalCenter: topbar.horizontalCenter

        Text {
            id: resizeing_filter
            y: 8
            color: "#101010"
            text: "Resizing Filter"
            font.pixelSize: 12
            anchors.horizontalCenterOffset: 1
            anchors.horizontalCenter: filter12.horizontalCenter
        }

        MouseArea {
            id: buttonMouseArea12
            width: 86
            height: 38
            anchors.verticalCenter: resizeing_filter.verticalCenter
            anchors.left: resizeing_filter.right
            anchors.right: resizeing_filter.left
            anchors.top: resizeing_filter.bottom
            anchors.bottom: resizeing_filter.top
            anchors.leftMargin: -78
            anchors.rightMargin: -78
            anchors.topMargin: -24
            anchors.bottomMargin: -27
            anchors.verticalCenterOffset: 0
            anchors.horizontalCenterOffset: -1
            anchors.horizontalCenter: resizeing_filter.horizontalCenter
            hoverEnabled: true

            onClicked: {
                popup1.open()
            }

            Popup {
                id: popup1
                width: 170
                height: 115
                modal: true
                focus: true
                visible: false

                Rectangle {
                    width: parent.width
                    height: parent.height
                    color: "white"
                    border.color: "white"
                    border.width: 0.5

                    Column {
                        anchors.fill: parent
                        spacing: 4

                        TextField {
                            id: widthField
                            width: parent.width
                            placeholderText: "Width..."
                        }

                        TextField {
                            id: heightField
                            width: parent.width
                            placeholderText: "Height..."
                        }

                        Text {
                            id: errorText
                            visible: false
                            color: "red"
                            text: "Error: Width, Height not <= 0"
                        }
                    }

                    Button {
                        text: "Submit"
                        anchors {
                            horizontalCenter: parent.horizontalCenter
                            bottom: parent.bottom
                            bottomMargin: 5
                        }

                        onClicked: {
                            var widthInput = parseFloat(widthField.text)
                            var heightInput = parseFloat(heightField.text)
                            console.log(widthInput)
                            if (widthInput <= 0 || heightInput <= 0 || isNaN(
                                        heightInput) || isNaN(widthInput)) {
                                errorText.visible = true
                                return
                            }

                            errorText.visible = false

                            if (!isFirst) {
                                imageProcessor14.applyResize(
                                            fileOpenDialog.currentFile,
                                            widthInput, heightInput)
                                second_image.cache = true
                                second_image.imageSource = "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg"
                                second_image.cache = false
                                isFirst = true
                            } else {
                                imageProcessor14.applyResize(
                                            "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg",
                                            widthInput, heightInput)
                                second_image.cache = true
                                second_image.imageSource = "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg"
                                second_image.cache = false
                            }
                            popup1.close()
                        }
                    }
                }
            }
        }
    }

    Rectangle {
        id: filter13

        property color baseColor12: "white"

        color: if (buttonMouseArea15.containsMouse) {
                   return Qt.darker(baseColor12)
               } else if (buttonMouseArea15.containsPress) {
                   return Qt.darker(baseColor12)
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
            id: merge_2_Image
            y: 9
            color: "#101010"
            text: "Merge 2 images"
            font.pixelSize: 12
            anchors.horizontalCenterOffset: 0
            anchors.horizontalCenter: filter13.horizontalCenter
        }

        MouseArea {
            id: buttonMouseArea15
            width: 88
            height: 38
            anchors.verticalCenter: merge_2_Image.verticalCenter
            anchors.left: merge_2_Image.right
            anchors.right: merge_2_Image.left
            anchors.top: merge_2_Image.bottom
            anchors.bottom: merge_2_Image.top
            anchors.leftMargin: -86
            anchors.rightMargin: -87
            anchors.topMargin: -25
            anchors.bottomMargin: -29
            anchors.horizontalCenter: merge_2_Image.horizontalCenter
            hoverEnabled: true

            Menu {
                id: menu1
                MenuItem {
                    id: menu1_choice1
                    text: "Resize both images"
                    onTriggered: {
                        if (!isFirst) {
                            imageProcessor13.applyMerge(
                                        fileOpenDialog.currentFile, filename, 1)
                            second_image.cache = true
                            second_image.imageSource = "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg"
                            second_image.cache = false
                            isFirst = true
                        } else {
                            imageProcessor13.applyMerge(
                                        "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg",
                                        filename, 1)
                            second_image.cache = true
                            second_image.imageSource = "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg"
                            second_image.cache = false
                        }
                    }
                }
                MenuItem {
                    id: menu1_choice2
                    text: "Merge the common area"
                    onTriggered: {
                        if (!isFirst) {
                            imageProcessor13.applyMerge(
                                        fileOpenDialog.currentFile, filename, 2)
                            second_image.cache = true
                            second_image.imageSource = "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg"
                            second_image.cache = false
                            isFirst = true
                        } else {
                            imageProcessor13.applyMerge(
                                        "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg",
                                        filename, 2)
                            second_image.cache = true
                            second_image.imageSource = "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg"
                            second_image.cache = false
                        }
                    }
                }
                MenuItem {
                    id: menu1_choice3
                    text: "Choose another image"
                    onTriggered: {
                        fileOpenDialog1.open()
                        filename = fileOpenDialog1.currentFile
                    }
                }
            }

            onClicked: {
                if (filename === "") {
                    fileOpenDialog1.open()
                    filter13.color = "#"
                } else {
                    menu1.open()
                    filter13.color = "white"
                }
            }

            FileDialog {
                id: fileOpenDialog1

                folder: StandardPaths.writableLocation(
                            StandardPaths.HomeLocation)

                nameFilters: ["Image files (*.png *.jpeg *.jpg *.bmp)"]

                onAccepted: {
                    filename = fileOpenDialog1.currentFile
                }
            }
        }
    }

    Rectangle {
        id: filter14

        property color baseColor50: "white"

        color: if (buttonMouseArea17.containsMouse) {
                   return Qt.darker(baseColor50)
               } else if (buttonMouseArea17.containsPress) {
                   return Qt.darker(baseColor50)
               } else {
                   return baseColor50
               }

        anchors.verticalCenter: topbar.verticalCenter
        anchors.left: topbar.right

        width: 88
        height: 40
        anchors.right: topbar.left
        anchors.top: topbar.bottom
        anchors.bottom: topbar.top
        anchors.leftMargin: -345
        anchors.rightMargin: -781
        anchors.topMargin: 126
        anchors.bottomMargin: -214
        anchors.verticalCenterOffset: 171
        anchors.horizontalCenterOffset: 218
        anchors.horizontalCenter: topbar.horizontalCenter

        Text {
            id: skewing_filter
            y: 9
            color: "#101010"
            text: "Skewing Filter"
            font.pixelSize: 12
            anchors.horizontalCenterOffset: 0
            anchors.horizontalCenter: filter14.horizontalCenter
        }

        MouseArea {
            id: buttonMouseArea17
            x: 1
            y: 0
            width: 86
            height: 38
            anchors.verticalCenter: resizeing_filter.verticalCenter
            anchors.left: resizeing_filter.right
            anchors.right: resizeing_filter.left
            anchors.top: resizeing_filter.bottom
            anchors.bottom: resizeing_filter.top
            anchors.leftMargin: -78
            anchors.rightMargin: -78
            anchors.topMargin: -24
            anchors.bottomMargin: -27
            hoverEnabled: true

            onClicked: {
                popup2.open()
            }

            Popup {
                id: popup2
                width: 160
                height: 90
                visible: false
                modal: true
                focus: true
                Rectangle {
                    width: parent.width
                    height: parent.height
                    color: "#ffffff"
                    border.color: "#ffffff"
                    border.width: 0.5
                    Column {
                        anchors.fill: parent
                        spacing: 4
                        TextField {
                            id: angleField
                            width: parent.width
                            placeholderText: "Angle [0, 90]..."
                        }

                        Text {
                            id: errorText1
                            visible: false
                            color: "#ff0000"
                            text: "Error: Angle from 0 to 90"
                        }
                    }

                    Button {
                        text: "Submit"
                        anchors.bottom: parent.bottom
                        anchors.bottomMargin: 5
                        onClicked: {
                            var angleInput = parseFloat(angleField.text)
                            if (angleInput > 90 || isNaN(angleInput)
                                    || angleInput < 0) {
                                errorText1.visible = true
                                return
                            }
                            errorText1.visible = false

                            if (!isFirst) {
                                imageProcessor16.applySkewing(
                                            fileOpenDialog.currentFile,
                                            angleInput)
                                second_image.cache = true
                                second_image.imageSource = "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg"
                                second_image.cache = false
                                isFirst = true
                            } else {
                                imageProcessor16.applySkewing(
                                            "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg",
                                            angleInput)
                                second_image.cache = true
                                second_image.imageSource = "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg"
                                second_image.cache = false
                            }

                            popup2.close()
                        }
                        anchors.horizontalCenter: parent.horizontalCenter
                    }
                }
            }
            anchors.verticalCenterOffset: 0
            anchors.horizontalCenterOffset: -1
            anchors.horizontalCenter: resizeing_filter.horizontalCenter
        }
    }

    Rectangle {
        id: filter15

        property color baseColor12: "white"

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
            text: "Crop image"
            font.pixelSize: 12
            anchors.horizontalCenterOffset: 0
            anchors.horizontalCenter: filter15.horizontalCenter
        }
    }

    Rectangle {
        id: filter16

        property color baseColor12: "white"

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
            text: "Frame Filter"
            font.pixelSize: 12
            anchors.horizontalCenterOffset: 0
            anchors.horizontalCenter: filter16.horizontalCenter
        }
    }

    Rectangle {
        id: filter17

        property color baseColor53: "white"

        color: if (buttonMouseArea19.containsMouse) {
                   return Qt.darker(baseColor53)
               } else if (buttonMouseArea19.containsPress) {
                   return Qt.darker(baseColor53)
               } else {
                   return baseColor53
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
            id: blur_filter
            y: 9
            color: "#101010"
            text: "Blur Filter"
            font.pixelSize: 12
            anchors.horizontalCenterOffset: 0
            anchors.horizontalCenter: filter17.horizontalCenter
        }

        MouseArea {
            id: buttonMouseArea19
            width: 0
            height: 42
            anchors.verticalCenter: blur_filter.verticalCenter
            anchors.left: blur_filter.right
            anchors.right: blur_filter.left
            anchors.top: blur_filter.bottom
            anchors.bottom: blur_filter.top
            anchors.leftMargin: -65
            anchors.rightMargin: -69
            anchors.topMargin: -25
            anchors.bottomMargin: -29
            anchors.horizontalCenterOffset: 0
            hoverEnabled: true

            Menu {
                id: menu4
                MenuItem {
                    id: menu4_choice1
                    text: "Blur Level [1]"
                    onTriggered: {
                        if (!isFirst) {
                            imageProcessor18.applyBlur(
                                        fileOpenDialog.currentFile, 1)
                            second_image.cache = true
                            second_image.imageSource = "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg"
                            second_image.cache = false
                            isFirst = true
                        } else {
                            imageProcessor18.applyBlur(
                                        "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg",
                                        1)
                            second_image.cache = true
                            second_image.imageSource = "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg"
                            second_image.cache = false
                        }
                    }
                }

                MenuItem {
                    id: menu4_choice2
                    text: "Blur Level [2]"
                    onTriggered: {
                        if (!isFirst) {
                            imageProcessor18.applyBlur(
                                        fileOpenDialog.currentFile, 2)
                            second_image.cache = true
                            second_image.imageSource = "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg"
                            second_image.cache = false
                            isFirst = true
                        } else {
                            imageProcessor18.applyBlur(
                                        "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg",
                                        2)
                            second_image.cache = true
                            second_image.imageSource = "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg"
                            second_image.cache = false
                        }
                    }
                }

                MenuItem {
                    id: menu4_choice3
                    text: "Blur Level [3]"
                    onTriggered: {
                        if (!isFirst) {
                            imageProcessor18.applyBlur(
                                        fileOpenDialog.currentFile, 3)
                            second_image.cache = true
                            second_image.imageSource = "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg"
                            second_image.cache = false
                            isFirst = true
                        } else {
                            imageProcessor18.applyBlur(
                                        "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg",
                                        3)
                            second_image.cache = true
                            second_image.imageSource = "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg"
                            second_image.cache = false
                        }
                    }
                }
            }
            anchors.horizontalCenter: blur_filter.horizontalCenter

            onClicked: {
                menu4.open()
            }
        }
    }

    Rectangle {
        id: filter18

        property color baseColor54: "white"

        color: if (buttonMouseArea20.containsMouse) {
                   return Qt.darker(baseColor54)
               } else if (buttonMouseArea20.containsPress) {
                   return Qt.darker(baseColor54)
               } else {
                   return baseColor54
               }
        anchors.verticalCenter: topbar.verticalCenter
        anchors.left: topbar.right

        width: 92
        height: 40
        anchors.right: topbar.left
        anchors.top: topbar.bottom
        anchors.bottom: topbar.top
        anchors.leftMargin: -447
        anchors.rightMargin: -680
        anchors.topMargin: 125
        anchors.bottomMargin: -214
        anchors.verticalCenterOffset: 170
        anchors.horizontalCenterOffset: 116
        anchors.horizontalCenter: topbar.horizontalCenter
        Text {
            id: old_Tv_Filter7
            y: 9
            color: "#101010"
            text: "Darken&Lighten"
            font.pixelSize: 12
            anchors.horizontalCenterOffset: 0
            anchors.horizontalCenter: filter18.horizontalCenter
        }

        MouseArea {
            id: buttonMouseArea20
            x: -1
            y: 0
            width: 92
            height: 38
            anchors.verticalCenter: filp_Filter.verticalCenter
            anchors.left: filp_Filter.right
            anchors.right: filp_Filter.left
            anchors.top: filp_Filter.bottom
            anchors.bottom: filp_Filter.top
            anchors.leftMargin: -62
            anchors.rightMargin: -79
            anchors.topMargin: -27
            anchors.bottomMargin: -27
            hoverEnabled: true

            Popup {
                id: submenu1
                width: 170
                height: 90
                modal: true
                focus: true
                visible: false

                Rectangle {
                    width: parent.width
                    height: parent.height
                    color: "white"
                    border.color: "white"
                    border.width: 0.5

                    Column {
                        anchors.fill: parent
                        spacing: 4

                        TextField {
                            id: brightness1
                            width: parent.width
                            placeholderText: "Darken's Degree [0, 255]"
                        }

                        Text {
                            id: errorText_submenu1
                            visible: false
                            color: "red"
                            text: "Error: Degree [0, 255]"
                        }
                    }

                    Button {
                        text: "Submit"
                        anchors {
                            horizontalCenter: parent.horizontalCenter
                            bottom: parent.bottom
                            bottomMargin: 5
                        }

                        onClicked: {
                            var degree1 = parseFloat(brightness1.text)
                            if (degree1 < 0 || isNaN(degree1)
                                    || degree1 > 255) {
                                errorText_submenu1.visible = true
                                return
                            }

                            if (!isFirst) {
                                imageProcessor19.applyBrightness(
                                            fileOpenDialog.currentFile,
                                            degree1, 1)
                                second_image.cache = true
                                second_image.imageSource = "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg"
                                second_image.cache = false
                                isFirst = true
                            } else {
                                imageProcessor19.applyBrightness(
                                            "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg",
                                            degree1, 1)
                                second_image.cache = true
                                second_image.imageSource = "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg"
                                second_image.cache = false
                            }

                            errorText_submenu1.visible = false

                            submenu1.close()
                        }
                    }
                }
            }

            Popup {
                id: submenu2
                width: 170
                height: 90
                modal: true
                focus: true
                visible: false

                Rectangle {
                    width: parent.width
                    height: parent.height
                    color: "white"
                    border.color: "white"
                    border.width: 0.5

                    Column {
                        anchors.fill: parent
                        spacing: 4

                        TextField {
                            id: brightness2
                            width: parent.width
                            placeholderText: "Lighten's Degree [0, 255]"
                        }

                        Text {
                            id: errorText_submenu2
                            visible: false
                            color: "red"
                            text: "Error: Degree [0, 255]"
                        }
                    }

                    Button {
                        text: "Submit"
                        anchors {
                            horizontalCenter: parent.horizontalCenter
                            bottom: parent.bottom
                            bottomMargin: 5
                        }

                        onClicked: {
                            var degree2 = parseFloat(brightness2.text)
                            if (degree2 < 0 || isNaN(degree2)
                                    || degree2 > 255) {
                                errorText_submenu2.visible = true
                                return
                            }

                            if (!isFirst) {
                                imageProcessor19.applyBrightness(
                                            fileOpenDialog.currentFile,
                                            degree2, 2)
                                second_image.cache = true
                                second_image.imageSource = "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg"
                                second_image.cache = false
                                isFirst = true
                            } else {
                                imageProcessor19.applyBrightness(
                                            "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg",
                                            degree2, 2)
                                second_image.cache = true
                                second_image.imageSource = "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg"
                                second_image.cache = false
                            }

                            errorText_submenu2.visible = false
                            submenu2.close()
                        }
                    }
                }
            }

            onClicked: {
                menu5.open()
            }

            Menu {
                id: menu5
                MenuItem {
                    id: menu5_choice1
                    text: "Darken Filter"
                    onTriggered: {
                        submenu1.open()
                    }
                }

                MenuItem {
                    id: menu5_choice2
                    text: "Lighten Filter"
                    onTriggered: {
                        submenu2.open()
                    }
                }
            }
            anchors.horizontalCenter: filp_Filter.horizontalCenter
        }
    }

    Rectangle {
        id: filter19

        property color baseColor51: "white"

        color: if (buttonMouseArea16.containsMouse) {
                   return Qt.darker(baseColor51)
               } else if (buttonMouseArea16.containsPress) {
                   return Qt.darker(baseColor51)
               } else {
                   return baseColor51
               }

        width: 70
        height: 34
        anchors.verticalCenter: topbar.verticalCenter
        anchors.left: topbar.right
        anchors.right: topbar.left
        anchors.top: emptyBox3.top
        anchors.leftMargin: -447
        anchors.rightMargin: -670
        anchors.topMargin: 251
        anchors.verticalCenterOffset: 223
        anchors.horizontalCenterOffset: 117
        anchors.horizontalCenter: topbar.horizontalCenter

        Text {
            id: filp_Filter
            y: 9
            color: "#101010"
            text: "Flip Filter"
            font.pixelSize: 12
            anchors.horizontalCenterOffset: 0
            anchors.horizontalCenter: filter19.horizontalCenter
        }

        MouseArea {
            id: buttonMouseArea16
            width: 76
            height: 38
            anchors.verticalCenter: filp_Filter.verticalCenter
            anchors.left: filp_Filter.right
            anchors.right: filp_Filter.left
            anchors.top: filp_Filter.bottom
            anchors.bottom: filp_Filter.top
            anchors.leftMargin: -62
            anchors.rightMargin: -79
            anchors.topMargin: -27
            anchors.bottomMargin: -27
            anchors.horizontalCenter: filp_Filter.horizontalCenter
            hoverEnabled: true

            Menu {
                id: menu2
                MenuItem {
                    id: menu2_choice1
                    text: "Flip Horizontally"
                    onTriggered: {
                        if (!isFirst) {
                            imageProcessor15.applyFlip(
                                        fileOpenDialog.currentFile, 1)
                            second_image.cache = true
                            second_image.imageSource = "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg"
                            second_image.cache = false
                            isFirst = true
                        } else {
                            imageProcessor15.applyFlip(
                                        "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg",
                                        1)
                            second_image.cache = true
                            second_image.imageSource = "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg"
                            second_image.cache = false
                        }
                    }
                }

                MenuItem {
                    id: menu2_choice2
                    text: "Flip Vertically"
                    onTriggered: {
                        if (!isFirst) {
                            imageProcessor15.applyFlip(
                                        fileOpenDialog.currentFile, 2)
                            second_image.cache = true
                            second_image.imageSource = "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg"
                            second_image.cache = false
                            isFirst = true
                        } else {
                            imageProcessor15.applyFlip(
                                        "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg",
                                        2)
                            second_image.cache = true
                            second_image.imageSource = "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg"
                            second_image.cache = false
                        }
                    }
                }
            }

            onClicked: {
                menu2.open()
            }
        }
    }

    Rectangle {
        id: filter20

        property color baseColor52: "white"

        color: if (buttonMouseArea18.containsMouse) {
                   return Qt.darker(baseColor52)
               } else if (buttonMouseArea18.containsPress) {
                   return Qt.darker(baseColor52)
               } else {
                   return baseColor52
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
            id: rotate_Filter
            y: 9
            color: "#101010"
            text: "Rotate Filter"
            font.pixelSize: 12
            anchors.horizontalCenterOffset: 0
            anchors.horizontalCenter: filter20.horizontalCenter
        }

        MouseArea {
            id: buttonMouseArea18
            width: 76
            height: 38
            anchors.verticalCenter: old_Tv_Filter9.verticalCenter
            anchors.left: old_Tv_Filter9.right
            anchors.right: old_Tv_Filter9.left
            anchors.top: old_Tv_Filter9.bottom
            anchors.bottom: old_Tv_Filter9.top
            anchors.leftMargin: -69
            anchors.rightMargin: -71
            anchors.topMargin: -25
            anchors.bottomMargin: -29
            hoverEnabled: true

            Menu {
                id: menu3
                MenuItem {
                    id: menu3_choice1
                    text: "Rotate 90' "
                    onTriggered: {
                        if (!isFirst) {
                            imageProcessor17.applyRotate(
                                        fileOpenDialog.currentFile, 90)
                            second_image.cache = true
                            second_image.imageSource = "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg"
                            second_image.cache = false
                            isFirst = true
                        } else {
                            imageProcessor17.applyRotate(
                                        "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg",
                                        90)
                            second_image.cache = true
                            second_image.imageSource = "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg"
                            second_image.cache = false
                        }
                    }
                }

                MenuItem {
                    id: menu3_choice2
                    text: "Rotate 180' "
                    onTriggered: {
                        if (!isFirst) {
                            imageProcessor17.applyRotate(
                                        fileOpenDialog.currentFile, 180)
                            second_image.cache = true
                            second_image.imageSource = "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg"
                            second_image.cache = false
                            isFirst = true
                        } else {
                            imageProcessor17.applyRotate(
                                        "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg",
                                        180)
                            second_image.cache = true
                            second_image.imageSource = "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg"
                            second_image.cache = false
                        }
                    }
                }
                MenuItem {
                    id: menu3_choice3
                    text: "Rotate 270' "
                    onTriggered: {
                        if (!isFirst) {
                            imageProcessor17.applyRotate(
                                        fileOpenDialog.currentFile, 270)
                            second_image.cache = true
                            second_image.imageSource = "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg"
                            second_image.cache = false
                            isFirst = true
                        } else {
                            imageProcessor17.applyRotate(
                                        "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg",
                                        270)
                            second_image.cache = true
                            second_image.imageSource = "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg"
                            second_image.cache = false
                        }
                    }
                }
            }
            anchors.horizontalCenter: old_Tv_Filter9.horizontalCenter

            onClicked: {
                menu3.open()
            }
        }
    }

    Rectangle {
        id: emptyBox
        x: 974
        width: 1
        height: 260
        color: "#ae58ff"
        anchors.verticalCenter: parent.verticalCenter
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
        anchors.verticalCenterOffset: 250
    }

    Rectangle {
        id: clear

        property color baseColor21: "#F2F2F2"
        color: buttonMouseArea14.pressed ? Qt.darker(
                                               baseColor21) : buttonMouseArea14.containsMouse ? Qt.lighter(baseColor21) : baseColor21
        x: 935
        y: 16
        width: 79
        height: 34

        anchors.right: emptyBox3.left
        anchors.top: emptyBox3.top
        anchors.rightMargin: 66
        anchors.topMargin: 31

        Text {
            id: clearOption
            y: 9
            color: "#101010"
            text: "Clear"
            font.pixelSize: 12
            anchors.horizontalCenterOffset: 0
            anchors.horizontalCenter: clear.horizontalCenter
        }

        MouseArea {
            id: buttonMouseArea14
            anchors.fill: parent
            anchors.leftMargin: 0
            anchors.rightMargin: 0
            anchors.topMargin: 0
            anchors.bottomMargin: 0
            hoverEnabled: true

            onClicked: {
                second_image.source = ""
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
                fileSaveDialog.open()
                first_image.source = ""
                second_image.source = ""
            }

            FileDialog {
                id: fileSaveDialog

                folder: StandardPaths.writableLocation(
                            StandardPaths.HomeLocation)

                nameFilters: ["Image files (*.png *.jpeg *.jpg *.bmp)"]

                onAccepted: {
                    imageProcessor12.savingImage(fileSaveDialog.currentFile)
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
                isFirst = false
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
            anchors.horizontalCenterOffset: -20
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

/*##^##
Designer {
    D{i:0}D{i:1;locked:true}D{i:2;locked:true}D{i:5;locked:true}D{i:9;locked:true}D{i:10;locked:true}
D{i:12;locked:true}D{i:18;locked:true}D{i:21;locked:true}D{i:24;locked:true}D{i:27;locked:true}
D{i:30;locked:true}D{i:33;locked:true}D{i:36;locked:true}D{i:39;locked:true}D{i:42;locked:true}
D{i:48;locked:true}D{i:50;locked:true}D{i:54;locked:true}D{i:64;locked:true}D{i:65;locked:true}
D{i:66;locked:true}D{i:67;locked:true}D{i:68;locked:true}D{i:69;locked:true}D{i:70;locked:true}
D{i:71;locked:true}D{i:74;locked:true}D{i:78;locked:true}D{i:82}D{i:86}D{i:97;locked:true}
}
##^##*/

