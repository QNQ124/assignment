import QtQuick
import QtQuick.Controls
import Qt.labs.platform 1.0
import QtQuick.Window
import Qt.labs.folderlistmodel

Window {

    width: 1120
    height: 520

    visible: true
    title: qsTr("PicMagic")

    function addFrame(inputfile, type, color) {
        imageProcessor20.applyFrame(inputfile, type, color)
        second_image.cache = true
        second_image.imageSource = temporaryFile
        second_image.cache = false
    }

    property bool isFirst: false
    property bool isFirst1: false
    property bool isFirst2: false
    property string filename: ""
    property color baseColor12: "white"
    property string temporaryFile: "file:///C:/Users/Domain/OneDrive - techno mix/Documents/First_GUI/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg"
    property alias fileone: fileOpenDialog.currentFile
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

            Text {
                id: versiontext1
                x: 55
                y: -29
                width: 140
                height: 27
                color: "#666666"
                text: "Load Any Image!"
                anchors.verticalCenter: mainSection.verticalCenter
                anchors.left: mainSection.right
                anchors.right: mainSection.left
                anchors.top: mainSection.bottom
                anchors.bottom: mainSection.top
                anchors.leftMargin: -1099
                anchors.rightMargin: -72
                anchors.topMargin: -289
                anchors.bottomMargin: -265
                font.pixelSize: 19
                font.italic: true
                anchors.horizontalCenterOffset: -427
                anchors.horizontalCenter: mainSection.horizontalCenter
            }

            imageSource1: "assets/images/log.jpg"
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
        }

        Image {
            id: logo
            x: 9
            width: 64
            height: 50
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: emptyBox.right
            source: "assets/images/image1.png"
            anchors.verticalCenterOffset: -234
        }
    }

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
        id: bottombar
        y: 497

        anchors {
            bottom: parent.bottom
            left: parent.left
            right: parent.right
        }

        height: 23
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
            leftMargin: -1057
            rightMargin: -1124
            topMargin: -50
            bottomMargin: -55
        }
        Text {
            id: mainTitle1
            x: 1

            anchors {
                verticalCenter: topbartitle.verticalCenter
            }

            text: "Pic"
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

            text: "Magic"
            color: "#A18DC6"

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
                italic: true
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
                if (fileOpenDialog.currentFile != "") {
                    if (!isFirst) {
                        imageProcessor1.applyGrayScale(
                                    fileOpenDialog.currentFile)
                        second_image.cache = true
                        second_image.imageSource = temporaryFile
                        second_image.cache = false
                        isFirst = true
                    } else {
                        imageProcessor1.applyGrayScale(temporaryFile)
                        second_image.cache = true
                        second_image.imageSource = temporaryFile
                        second_image.cache = false
                    }
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
            font.italic: true
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
                if (fileOpenDialog.currentFile != "") {
                    if (!isFirst) {
                        imageProcessor2.applyBlackAndWhite(
                                    fileOpenDialog.currentFile)
                        second_image.cache = true
                        second_image.imageSource = temporaryFile
                        second_image.cache = false
                        isFirst = true
                    } else {
                        imageProcessor2.applyBlackAndWhite(temporaryFile)
                        second_image.cache = true
                        second_image.imageSource = temporaryFile
                        second_image.cache = false
                    }
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
            font.italic: true
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
                if (fileOpenDialog.currentFile != "") {
                    if (!isFirst) {
                        imageProcessor3.applyPurple(fileOpenDialog.currentFile)
                        second_image.cache = true
                        second_image.imageSource = temporaryFile
                        second_image.cache = false
                        isFirst = true
                    } else {
                        imageProcessor3.applyPurple(temporaryFile)
                        second_image.cache = true
                        second_image.imageSource = temporaryFile
                        second_image.cache = false
                    }
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
            font.italic: true
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
                if (fileOpenDialog.currentFile != "") {
                    if (!isFirst) {
                        imageProcessor4.applyInvert(fileOpenDialog.currentFile)
                        second_image.cache = true
                        second_image.imageSource = temporaryFile
                        second_image.cache = false
                        isFirst = true
                    } else {
                        imageProcessor4.applyInvert(temporaryFile)
                        second_image.cache = true
                        second_image.imageSource = temporaryFile
                        second_image.cache = false
                    }
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
            font.italic: true
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
                if (fileOpenDialog.currentFile != "") {
                    if (!isFirst) {
                        imageProcessor5.applyInfrared(
                                    fileOpenDialog.currentFile)
                        second_image.cache = true
                        second_image.imageSource = temporaryFile
                        second_image.cache = false
                        isFirst = true
                    } else {
                        imageProcessor5.applyInfrared(temporaryFile)
                        second_image.cache = true
                        second_image.imageSource = temporaryFile
                        second_image.cache = false
                    }
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
            font.italic: true
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
                if (fileOpenDialog.currentFile != "") {
                    if (!isFirst) {
                        imageProcessor6.applyNoise(fileOpenDialog.currentFile)
                        second_image.cache = true
                        second_image.imageSource = temporaryFile
                        second_image.cache = false
                        isFirst = true
                    } else {
                        imageProcessor6.applyNoise(temporaryFile)
                        second_image.cache = true
                        second_image.imageSource = temporaryFile
                        second_image.cache = false
                    }
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
            font.italic: true
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
                if (fileOpenDialog.currentFile != "") {
                    if (!isFirst) {
                        imageProcessor7.applyNightVision(
                                    fileOpenDialog.currentFile)
                        second_image.cache = true
                        second_image.imageSource = temporaryFile
                        second_image.cache = false
                        isFirst = true
                    } else {
                        imageProcessor7.applyNightVision(temporaryFile)
                        second_image.cache = true
                        second_image.imageSource = temporaryFile
                        second_image.cache = false
                    }
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
            font.italic: true
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
                if (fileOpenDialog.currentFile != "") {
                    if (!isFirst) {
                        imageProcessor8.applyDetectEdges(
                                    fileOpenDialog.currentFile)
                        second_image.cache = true
                        second_image.imageSource = temporaryFile
                        second_image.cache = false
                        isFirst = true
                    } else {
                        imageProcessor8.applyDetectEdges(temporaryFile)
                        second_image.cache = true
                        second_image.imageSource = temporaryFile
                        second_image.cache = false
                    }
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
            font.italic: true
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
                if (fileOpenDialog.currentFile != "") {
                    if (!isFirst) {
                        imageProcessor9.applyOilPainting(
                                    fileOpenDialog.currentFile)
                        second_image.cache = true
                        second_image.imageSource = temporaryFile
                        second_image.cache = false
                        isFirst = true
                    } else {
                        imageProcessor9.applyOilPainting(temporaryFile)
                        second_image.cache = true
                        second_image.imageSource = temporaryFile
                        second_image.cache = false
                    }
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
            font.italic: true
            anchors.horizontalCenterOffset: -3
            anchors.horizontalCenter: filter10.horizontalCenter
        }

        MouseArea {
            id: buttonMouseArea10

            anchors.fill: parent
            anchors.leftMargin: -2
            anchors.rightMargin: 2
            anchors.topMargin: -2
            anchors.bottomMargin: 0
            hoverEnabled: true

            onClicked: {
                if (fileOpenDialog.currentFile != "") {
                    if (!isFirst) {
                        imageProcessor10.applySunlight(
                                    fileOpenDialog.currentFile)
                        second_image.cache = true
                        second_image.imageSource = temporaryFile
                        second_image.cache = false
                        isFirst = true
                    } else {
                        imageProcessor10.applySunlight(temporaryFile)
                        second_image.cache = true
                        second_image.imageSource = temporaryFile
                        second_image.cache = false
                    }
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
            font.italic: true
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
                if (fileOpenDialog.currentFile != "") {
                    if (!isFirst) {
                        imageProcessor11.applyOldTV(fileOpenDialog.currentFile)
                        second_image.cache = true
                        second_image.imageSource = temporaryFile

                        second_image.cache = false
                        isFirst = true
                    } else {
                        imageProcessor11.applyOldTV(temporaryFile)
                        second_image.cache = true
                        second_image.imageSource = temporaryFile
                        second_image.cache = false
                    }
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
            font.italic: true
            anchors.horizontalCenterOffset: 3
            anchors.horizontalCenter: filter12.horizontalCenter
        }

        MouseArea {
            id: buttonMouseArea12
            width: 84
            height: 38
            anchors.verticalCenter: resizeing_filter.verticalCenter
            anchors.left: resizeing_filter.right
            anchors.right: resizeing_filter.left
            anchors.top: resizeing_filter.bottom
            anchors.bottom: resizeing_filter.top
            anchors.leftMargin: -77
            anchors.rightMargin: -75
            anchors.topMargin: -24
            anchors.bottomMargin: -27
            anchors.verticalCenterOffset: 0
            anchors.horizontalCenterOffset: 2
            anchors.horizontalCenter: resizeing_filter.horizontalCenter
            hoverEnabled: true

            onClicked: {
                if (fileOpenDialog.currentFile != "") {
                    popup1.open()
                }
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
                                second_image.imageSource = temporaryFile
                                second_image.cache = false
                                isFirst = true
                            } else {
                                imageProcessor14.applyResize(temporaryFile,
                                                             widthInput,
                                                             heightInput)
                                second_image.cache = true
                                second_image.imageSource = temporaryFile
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
            font.italic: true
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
                            second_image.imageSource = temporaryFile
                            second_image.cache = false
                            isFirst = true
                        } else {
                            imageProcessor13.applyMerge(temporaryFile,
                                                        filename, 1)
                            second_image.cache = true
                            second_image.imageSource = temporaryFile
                            second_image.cache = false
                        }
                    }
                }
                MenuItem {
                    id: menu1_choice2
                    text: "Merge the common area"
                    onTriggered: {
                        if (!isFirst) {
                            console.log(imageProcessor13.applyMerge(
                                            fileOpenDialog.currentFile,
                                            filename, 2))
                            second_image.cache = true
                            second_image.imageSource = temporaryFile
                            second_image.cache = false
                            isFirst = true
                        } else {
                            imageProcessor13.applyMerge(temporaryFile,
                                                        filename, 2)
                            second_image.cache = true
                            second_image.imageSource = temporaryFile
                            second_image.cache = false
                        }
                    }
                }
                MenuItem {
                    id: menu1_choice3
                    text: "Choose another image"
                    onTriggered: {
                        fileOpenDialog1.open()
                        filter13.color = "#44BD58"
                        filename = fileOpenDialog1.currentFile
                    }
                }
            }

            onClicked: {
                if (fileOpenDialog.currentFile != "") {
                    if (filename === "") {
                        fileOpenDialog1.open()
                        filter13.color = "#ae58ff"
                    } else {
                        menu1.open()
                        filter13.color = "white"
                    }
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
            font.italic: true
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
                if (fileOpenDialog.currentFile != "") {
                    popup2.open()
                }
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
                                second_image.imageSource = temporaryFile
                                second_image.cache = false
                                isFirst = true
                            } else {
                                imageProcessor16.applySkewing(temporaryFile,
                                                              angleInput)
                                second_image.cache = true
                                second_image.imageSource = temporaryFile
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

        property color baseColor56: "white"

        color: if (buttonMouseArea24.containsMouse) {
                   return Qt.darker(baseColor56)
               } else if (buttonMouseArea24.containsPress) {
                   return Qt.darker(baseColor56)
               } else {
                   return baseColor56
               }

        anchors.verticalCenter: topbar.verticalCenter
        anchors.left: topbar.right

        width: 90
        height: 36
        anchors.right: topbar.left
        anchors.top: topbar.bottom
        anchors.bottom: topbar.top
        anchors.leftMargin: -344
        anchors.rightMargin: -780
        anchors.topMargin: 179
        anchors.bottomMargin: -268
        anchors.verticalCenterOffset: 222
        anchors.horizontalCenterOffset: 217
        anchors.horizontalCenter: topbar.horizontalCenter

        Text {
            id: crop_Filter
            y: 9
            color: "#101010"
            text: "Crop image"
            font.pixelSize: 12
            font.italic: true
            anchors.horizontalCenterOffset: 0
            anchors.horizontalCenter: filter15.horizontalCenter
        }

        MouseArea {
            id: buttonMouseArea24
            width: 0
            height: 44
            anchors.verticalCenter: crop_Filter.verticalCenter
            anchors.left: crop_Filter.right
            anchors.right: crop_Filter.left
            anchors.top: crop_Filter.bottom
            anchors.bottom: crop_Filter.top
            anchors.leftMargin: -76
            anchors.rightMargin: -76
            anchors.topMargin: -28
            anchors.bottomMargin: -30
            hoverEnabled: true

            onClicked: {
                if (fileOpenDialog.currentFile != "") {
                    popup3.open()
                }
            }

            Popup {
                id: popup3
                width: 195
                height: 160
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
                            id: widthField1
                            width: parent.width
                            placeholderText: "New Width..."
                        }

                        TextField {
                            id: heightField1
                            width: parent.width
                            placeholderText: "New Height..."
                        }

                        TextField {
                            id: startPointField1
                            width: parent.width
                            placeholderText: "Start Point on x axis.."
                        }

                        TextField {
                            id: startPointField2
                            width: parent.width
                            placeholderText: "Start Point on y axis.."
                        }

                        Text {
                            id: errorText3
                            visible: false
                            color: "#ff0000"
                            text: "Error: out of Width, Height Bounds"
                        }
                    }

                    Button {
                        text: "Submit"
                        anchors.bottom: parent.bottom
                        anchors.bottomMargin: 5
                        onClicked: {

                            var widthInput1 = parseFloat(widthField1.text)
                            var heightInput1 = parseFloat(heightField1.text)
                            var xpoint = parseFloat(startPointField1.text)
                            var ypoint = parseFloat(startPointField2.text)

                            if (!isFirst2) {
                                var original_width = imageProcessor21.checkCropWidth(
                                            fileOpenDialog.currentFile)
                                var original_height = imageProcessor22.checkCropHeight(
                                            fileOpenDialog.currentFile)
                                isFirst2 = true
                            } else {
                                original_width = imageProcessor21.checkCropWidth(
                                            temporaryFile)
                                original_height = imageProcessor22.checkCropHeight(
                                            temporaryFile)
                            }

                            if (widthInput1 <= 0 || heightInput1 <= 0 || isNaN(
                                        heightInput1) || isNaN(
                                        widthInput1) || isNaN(xpoint) || isNaN(
                                        ypoint) || (widthInput1 > original_width) || (heightInput1 > original_height) || ((xpoint + widthInput1) > original_width)
                                    || ((ypoint + heightInput1) > original_height)) {
                                errorText3.visible = true
                                return
                            }

                            errorText3.visible = false

                            if (!isFirst) {
                                imageProcessor23.applyCrop(
                                            fileOpenDialog.currentFile,
                                            widthInput1, heightInput1,
                                            xpoint, ypoint)
                                second_image.cache = true
                                second_image.imageSource = temporaryFile
                                second_image.cache = false
                                isFirst = true
                            } else {
                                imageProcessor23.applyCrop(temporaryFile,
                                                           widthInput1,
                                                           heightInput1,
                                                           xpoint, ypoint)
                                second_image.cache = true
                                second_image.imageSource = temporaryFile
                                second_image.cache = false
                            }
                            popup3.close()
                        }
                        anchors.horizontalCenter: parent.horizontalCenter
                    }
                }
            }

            anchors.verticalCenterOffset: 1
            anchors.horizontalCenterOffset: 0
            anchors.horizontalCenter: crop_Filter.horizontalCenter
        }
    }

    Rectangle {
        id: filter16

        property color baseColor55: "white"

        color: if (buttonMouseArea21.containsMouse) {
                   return Qt.darker(baseColor55)
               } else if (buttonMouseArea21.containsPress) {
                   return Qt.darker(baseColor55)
               } else {
                   return baseColor55
               }
        anchors.verticalCenter: topbar.verticalCenter
        anchors.left: topbar.right

        width: 94
        height: 42
        anchors.right: topbar.left
        anchors.top: topbar.bottom
        anchors.bottom: topbar.top
        anchors.leftMargin: -345
        anchors.rightMargin: -782
        anchors.topMargin: 230
        anchors.bottomMargin: -319
        anchors.verticalCenterOffset: 276
        anchors.horizontalCenterOffset: 217
        anchors.horizontalCenter: topbar.horizontalCenter
        Text {
            id: frame_to_image
            y: 9
            color: "#101010"
            text: "Frame Filter"
            font.pixelSize: 12
            font.italic: true
            anchors.horizontalCenterOffset: 0
            anchors.horizontalCenter: filter16.horizontalCenter
        }

        MouseArea {
            id: buttonMouseArea21
            x: 0
            y: 2
            width: 88
            height: 38
            hoverEnabled: true

            Menu {
                id: menu6

                Menu {
                    id: submenu6_1
                    title: "Simple Frame"

                    MenuItem {
                        id: submenu6_1choice1
                        text: "Black"

                        onTriggered: {
                            if (!isFirst) {
                                addFrame(fileOpenDialog.currentFile, 1, 1)
                                isFirst = true
                            } else {
                                addFrame(temporaryFile, 1, 1)
                            }
                        }
                    }
                    MenuItem {
                        id: submenu6_1choice2
                        text: "Red"

                        onTriggered: {
                            if (!isFirst) {
                                addFrame(fileOpenDialog.currentFile, 1, 2)
                                isFirst = true
                            } else {
                                addFrame(temporaryFile, 1, 2)
                            }
                        }
                    }
                    MenuItem {
                        id: submenu6_1choice3
                        text: "Green"

                        onTriggered: {
                            if (!isFirst) {
                                addFrame(fileOpenDialog.currentFile, 1, 3)
                                isFirst = true
                            } else {
                                addFrame(temporaryFile, 1, 3)
                            }
                        }
                    }
                    MenuItem {
                        id: submenu6_1choice4
                        text: "Blue"

                        onTriggered: {
                            if (!isFirst) {
                                addFrame(fileOpenDialog.currentFile, 1, 4)
                                isFirst = true
                            } else {
                                addFrame(temporaryFile, 1, 4)
                            }
                        }
                    }

                    MenuItem {
                        id: submenu6_choice5
                        text: "White"

                        onTriggered: {
                            if (!isFirst) {
                                addFrame(fileOpenDialog.currentFile, 1, 5)
                                isFirst = true
                            } else {
                                addFrame(temporaryFile, 1, 5)
                            }
                        }
                    }
                }

                Menu {
                    id: submenu6_2

                    title: "Fancy Frame"
                    MenuItem {
                        id: submenu6_2choice1
                        text: "Black"

                        onTriggered: {
                            if (!isFirst) {
                                addFrame(fileOpenDialog.currentFile, 2, 1)
                                isFirst = true
                            } else {
                                addFrame(temporaryFile, 2, 1)
                            }
                        }
                    }
                    MenuItem {
                        id: submenu6_2choice2
                        text: "Red"

                        onTriggered: {
                            if (!isFirst) {
                                addFrame(fileOpenDialog.currentFile, 2, 2)
                                isFirst = true
                            } else {
                                addFrame(temporaryFile, 2, 2)
                            }
                        }
                    }
                    MenuItem {
                        id: submenu6_2choice3
                        text: "Green"

                        onTriggered: {
                            if (!isFirst) {
                                addFrame(fileOpenDialog.currentFile, 2, 3)
                                isFirst = true
                            } else {
                                addFrame(temporaryFile, 2, 3)
                            }
                        }
                    }
                    MenuItem {
                        id: submenu6_2choice4
                        text: "Blue"

                        onTriggered: {
                            if (!isFirst) {
                                addFrame(fileOpenDialog.currentFile, 2, 4)
                                isFirst = true
                            } else {
                                addFrame(temporaryFile, 2, 4)
                            }
                        }
                    }
                    MenuItem {
                        id: submenu6_2choice5
                        text: "White"

                        onTriggered: {
                            if (!isFirst) {
                                addFrame(fileOpenDialog.currentFile, 2, 5)
                                isFirst = true
                            } else {
                                addFrame(temporaryFile, 2, 5)
                            }
                        }
                    }
                }
            }

            onClicked: {
                if (fileOpenDialog.currentFile != "") {
                    menu6.open()
                }
            }
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
            font.italic: true
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
                            second_image.imageSource = temporaryFile
                            second_image.cache = false
                            isFirst = true
                        } else {
                            imageProcessor18.applyBlur(temporaryFile, 1)
                            second_image.cache = true
                            second_image.imageSource = temporaryFile
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
                            second_image.imageSource = temporaryFile
                            second_image.cache = false
                            isFirst = true
                        } else {
                            imageProcessor18.applyBlur(temporaryFile, 2)
                            second_image.cache = true
                            second_image.imageSource = temporaryFile
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
                            second_image.imageSource = temporaryFile
                            second_image.cache = false
                            isFirst = true
                        } else {
                            imageProcessor18.applyBlur(temporaryFile, 3)
                            second_image.cache = true
                            second_image.imageSource = temporaryFile
                            second_image.cache = false
                        }
                    }
                }
            }
            anchors.horizontalCenter: blur_filter.horizontalCenter

            onClicked: {
                if (fileOpenDialog.currentFile != "") {
                    menu4.open()
                }
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
            id: darkenAndLighten
            y: 9
            color: "#101010"
            text: "Darken&Lighten"
            font.pixelSize: 12
            font.italic: true
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
                                second_image.imageSource = temporaryFile
                                second_image.cache = false
                                isFirst = true
                            } else {
                                imageProcessor19.applyBrightness(temporaryFile,
                                                                 degree1, 1)
                                second_image.cache = true
                                second_image.imageSource = temporaryFile
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
                                second_image.imageSource = temporaryFile
                                second_image.cache = false
                                isFirst = true
                            } else {
                                imageProcessor19.applyBrightness(temporaryFile,
                                                                 degree2, 2)
                                second_image.cache = true
                                second_image.imageSource = temporaryFile
                                second_image.cache = false
                            }

                            errorText_submenu2.visible = false
                            submenu2.close()
                        }
                    }
                }
            }

            onClicked: {
                if (fileOpenDialog.currentFile != "") {
                    menu5.open()
                }
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
            font.italic: true
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
                            second_image.imageSource = temporaryFile
                            second_image.cache = false
                            isFirst = true
                        } else {
                            imageProcessor15.applyFlip(temporaryFile, 1)
                            second_image.cache = true
                            second_image.imageSource = temporaryFile
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
                            second_image.imageSource = temporaryFile
                            second_image.cache = false
                            isFirst = true
                        } else {
                            imageProcessor15.applyFlip(temporaryFile, 2)
                            second_image.cache = true
                            second_image.imageSource = temporaryFile
                            second_image.cache = false
                        }
                    }
                }
            }

            onClicked: {
                if (fileOpenDialog.currentFile != "") {
                    menu2.open()
                }
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
            font.italic: true
            anchors.horizontalCenterOffset: 0
            anchors.horizontalCenter: filter20.horizontalCenter
        }

        MouseArea {
            id: buttonMouseArea18
            x: 0
            y: 0
            width: 88
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
                            second_image.imageSource = temporaryFile
                            second_image.cache = false
                            isFirst = true
                        } else {
                            imageProcessor17.applyRotate(temporaryFile, 90)
                            second_image.cache = true
                            second_image.imageSource = temporaryFile
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
                            second_image.imageSource = temporaryFile
                            second_image.cache = false
                            isFirst = true
                        } else {
                            imageProcessor17.applyRotate(temporaryFile, 180)
                            second_image.cache = true
                            second_image.imageSource = temporaryFile
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
                            second_image.imageSource = temporaryFile
                            second_image.cache = false
                            isFirst = true
                        } else {
                            imageProcessor17.applyRotate(temporaryFile, 270)
                            second_image.cache = true
                            second_image.imageSource = temporaryFile
                            second_image.cache = false
                        }
                    }
                }
            }
            anchors.horizontalCenter: old_Tv_Filter9.horizontalCenter

            onClicked: {
                if (fileOpenDialog.currentFile != "") {
                    menu3.open()
                }
            }
        }
    }

    Rectangle {
        id: emptyBox
        x: 974
        width: 1
        height: 260
        color: "#a18dc6"
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: -8
    }

    Rectangle {
        id: emptyBox4
        x: 673
        y: 167
        width: 406
        height: 0.5
        color: "#a18dc6"
    }

    Rectangle {
        id: emptyBox5
        x: 673
        y: 220
        width: 406
        height: 1
        color: "#a18dc6"
    }

    Rectangle {
        id: emptyBox6
        x: 673
        y: 274
        width: 406
        height: 1
        color: "#a18dc6"
    }

    Rectangle {
        id: emptyBox7
        x: 673
        y: 327
        width: 406
        height: 0.5
        color: "#a18dc6"
    }

    Rectangle {
        id: emptyBox12
        x: 1080
        width: 40
        height: 76
        color: "#F2F2F2"
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: albumImage1.right
        anchors.verticalCenterOffset: -248
    }

    Rectangle {
        id: emptyBox13
        x: 1080
        width: 40
        height: 23
        color: "#dddddd"
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: 249
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
            font.italic: true
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
                isFirst = false
            }
        }
    }

    Rectangle {
        id: emptyBox10
        x: 927
        width: 2
        height: 37
        color: "#a18dc6"
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: albumImage1.right
        anchors.verticalCenterOffset: -232
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
            font.italic: true
            anchors.horizontalCenterOffset: 0
            anchors.horizontalCenter: save.horizontalCenter
        }

        property string selectedFileName: ""

        MouseArea {
            id: buttonMouseArea13

            anchors.fill: parent
            anchors.leftMargin: 0
            anchors.rightMargin: 0
            anchors.topMargin: 0
            anchors.bottomMargin: 0
            hoverEnabled: true

            onClicked: {
                if (fileOpenDialog.currentFile != "") {
                    console.log(fileOpenDialog.currentFile)
                    popup4.open()
                    return
                }
            }

            Popup {
                id: popup4
                width: 310
                height: 85
                modal: true
                focus: true
                visible: false
                x: parent.width - 200 - 20
                y: 20
                Rectangle {
                    id: subpopup4
                    width: parent.width
                    height: parent.height
                    color: "white"
                    border.color: "white"
                    border.width: 0.5
                    Column {
                        anchors.fill: parent
                        spacing: 3

                        TextField {
                            id: savefilename
                            width: parent.width
                            placeholderText: "Enter the new filename [.jpg, .bmp, .jpeg, .png]"
                        }

                        Text {
                            id: errorexist
                            visible: false
                            color: "red"
                            text: "Error: file already exists. please enter a new name"
                        }

                        Text {
                            id: errorexist2
                            visible: false
                            color: "red"
                            text: "Error: Invalid file extention. [.jpg, .bmp, .jpeg, .png]"
                        }

                        Text {
                            id: errorexist3
                            visible: false
                            color: "red"
                            text: "Error: Invalid file name. Don't include [/, \, :, *, ?, >, <, |, \"]"
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
                            var return1 = imageProcessor12.savingImage(
                                        fileOpenDialog.currentFile,
                                        savefilename.text)
                            if (return1 === 1) {
                                errorexist2.visible = false
                                errorexist3.visible = false
                                errorexist.visible = true
                                return
                            } else if (return1 === 2) {
                                errorexist.visible = false
                                errorexist3.visible = false
                                errorexist2.visible = true
                                return
                            } else if (return1 === 3) {
                                errorexist.visible = false
                                errorexist2.visible = false
                                errorexist3.visible = true
                                return
                            }
                            isFirst = false
                            errorexist.visible = false
                            errorexist2.visible = false
                            errorexist3.visible = false
                            second_image.source = ""
                            popup4.close()
                        }
                    }
                }
            }
        }
    }

    Rectangle {
        id: emptyBox14
        x: 827
        width: 2
        height: 37
        color: "#a18dc6"
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: albumImage1.right
        anchors.verticalCenterOffset: -232
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
            font.italic: true
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
                    second_image.source = ""
                } else {
                    first_image.source = "assets/images/log.jpg"
                }
            }
        }
    }

    Rectangle {
        id: beforeBox
        x: 40
        y: 98
        width: 102
        height: 32
        anchors.right: emptyBox3.left
        anchors.top: emptyBox3.top
        anchors.rightMargin: 938
        anchors.topMargin: 116
        Text {
            id: imageText1
            x: 3
            y: 11
            width: 46.825
            height: 23
            color: "#a18dc6"
            text: "Before"
            font.pixelSize: 18
            font.italic: true
            anchors.horizontalCenterOffset: -28
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
            color: "#a18dc6"
            text: "After"
            font.italic: true
            font.pixelSize: 18
            anchors.horizontalCenterOffset: -32
            anchors.horizontalCenter: afterBox.horizontalCenter
        }
    }

    Rectangle {
        id: imagePathBox

        x: 39
        y: 418
        width: 486
        height: 32
        anchors.right: emptyBox3.left
        anchors.top: emptyBox3.top
        anchors.rightMargin: 555
        anchors.topMargin: 434
        Text {
            id: imageText3
            width: 58
            height: 23
            color: "#000000"
            text: "Image_Path: "
            anchors.verticalCenter: imageText4.verticalCenter
            anchors.left: imageText4.right
            anchors.right: imageText4.left
            anchors.bottom: imageText4.top
            anchors.leftMargin: -473
            anchors.rightMargin: -2
            anchors.bottomMargin: -23
            font.pixelSize: 10
            font.italic: true
            anchors.verticalCenterOffset: 0
            anchors.horizontalCenterOffset: -210
            anchors.horizontalCenter: imageText4.horizontalCenter
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
            font.italic: true
            anchors.horizontalCenterOffset: 35
            anchors.horizontalCenter: imagePathBox.horizontalCenter
        }
    }

    Rectangle {
        id: emptyBox1
        x: 870
        width: 0.5
        height: 260
        color: "#a18dc6"
        anchors.verticalCenter: mainSection.verticalCenter
        anchors.left: albumImage1.right
        anchors.verticalCenterOffset: -8
    }

    Rectangle {
        id: emptyBox2
        x: 767
        width: 0.5
        height: 260
        color: "#a18dc6"
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: albumImage1.right
        anchors.verticalCenterOffset: -8
    }

    Rectangle {
        id: imagePathBox1
        x: 38
        y: 443
        width: 486
        height: 32
        anchors.right: emptyBox3.left
        anchors.top: emptyBox3.top
        anchors.rightMargin: 556
        anchors.topMargin: 470

        Text {
            id: imageText6
            x: 62
            y: 5
            width: 416
            height: 23
            color: "#000000"
            text: "Saved Image will be saved in the same Folder"
            font.pixelSize: 10
            font.italic: true
            anchors.horizontalCenterOffset: -22
            anchors.horizontalCenter: imagePathBox1.horizontalCenter
        }
    }

    Text {
        id: versiontext
        x: 15
        y: 495
        width: 47
        height: 19
        color: "#666666"
        text: "V1.0"
        font.pixelSize: 19
        font.italic: true
        anchors.horizontalCenterOffset: -28
    }
}

/*##^##
Designer {
    D{i:0}D{i:3}D{i:5}D{i:6}D{i:7;locked:true}D{i:8;locked:true}D{i:9;locked:true}D{i:10;locked:true}
D{i:11;locked:true}D{i:12;locked:true}D{i:13;locked:true}D{i:14;locked:true}D{i:15;locked:true}
D{i:16;locked:true}D{i:17;locked:true}D{i:18;locked:true}D{i:19;locked:true}D{i:20;locked:true}
D{i:21;locked:true}D{i:22;locked:true}D{i:23;locked:true}D{i:24;locked:true}D{i:25;locked:true}
D{i:26;locked:true}D{i:27;locked:true}D{i:28;locked:true}D{i:29;locked:true}D{i:30;locked:true}
D{i:31;locked:true}D{i:32;locked:true}D{i:33;locked:true}D{i:34;locked:true}D{i:35;locked:true}
D{i:36;locked:true}D{i:37;locked:true}D{i:38;locked:true}D{i:39;locked:true}D{i:40;locked:true}
D{i:41;locked:true}D{i:42;locked:true}D{i:43;locked:true}D{i:44;locked:true}D{i:45;locked:true}
D{i:46;locked:true}D{i:47;locked:true}D{i:48;locked:true}D{i:49;locked:true}D{i:50;locked:true}
D{i:51;locked:true}D{i:52;locked:true}D{i:54;locked:true}D{i:58;locked:true}D{i:59;locked:true}
D{i:60;locked:true}D{i:61;locked:true}D{i:67;locked:true}D{i:68;locked:true}D{i:69;locked:true}
D{i:70;locked:true}D{i:71;locked:true}D{i:72;locked:true}D{i:73;locked:true}D{i:74;locked:true}
D{i:75;locked:true}D{i:76;locked:true}D{i:77;locked:true}D{i:78;locked:true}D{i:82;locked:true}
D{i:88;locked:true}D{i:89;locked:true}D{i:90;locked:true}D{i:94;locked:true}D{i:96;locked:true}
D{i:101;locked:true}D{i:104;locked:true}D{i:105;locked:true}D{i:106;locked:true}D{i:111;locked:true}
D{i:112;locked:true}D{i:113;locked:true}D{i:119;locked:true}D{i:121;locked:true}D{i:125;locked:true}
D{i:127;locked:true}D{i:129;locked:true}D{i:130;locked:true}D{i:131;locked:true}D{i:135;locked:true}
D{i:136;locked:true}D{i:137;locked:true}D{i:142;locked:true}D{i:143;locked:true}D{i:144;locked:true}
D{i:145;locked:true}D{i:146;locked:true}D{i:147;locked:true}D{i:148;locked:true}D{i:149;locked:true}
D{i:150;locked:true}D{i:151;locked:true}D{i:152;locked:true}D{i:153;locked:true}D{i:154;locked:true}
D{i:155;locked:true}D{i:158;locked:true}D{i:164;locked:true}D{i:165;locked:true}D{i:166;locked:true}
D{i:167;locked:true}D{i:168;locked:true}D{i:170;locked:true}D{i:171;locked:true}D{i:172;locked:true}
D{i:173;locked:true}D{i:174;locked:true}D{i:175;locked:true}D{i:176;locked:true}D{i:177;locked:true}
D{i:178;locked:true}D{i:179;locked:true}D{i:180;locked:true}D{i:181;locked:true}
}
##^##*/

