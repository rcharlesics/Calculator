import QtQuick 2.0
import GreenHouse.Theming 1.0

//PREVIEW IMAGE qrc:/DefaultComponentSet/PreviewAssets/imageAssetButton.png
ImageAsset {
    id: root

    property string buttonText: ""
    //FONT buttonFont
    property alias font: label.font
    //COLOR buttonTextColor
    property color textColor: GreenHouseThemeManager.theme.color("buttonTextColor")
    //ASSET
    property string pressedAsset: ""
    //TEXTHAL 4
    property alias horizontalAlignment: label.horizontalAlignment
    //TEXTVAL 128
    property alias verticalAlignment: label.verticalAlignment
    signal triggered()

    MouseArea {
        id: ma

        anchors.fill: parent
        onClicked: root.triggered()
    }

    Text {
        id: label

        anchors.fill: parent

        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter

        elide: Text.ElideRight

        font: GreenHouseThemeManager.theme.font("buttonFont")
        color: root.textColor

        text: root.buttonText
    }

    //HIDE property source
    source: ma.pressed && pressedAsset !== "" ? pressedAsset : asset
}
