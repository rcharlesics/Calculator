import QtQuick 2.0
import GreenHouse.Theming 1.0


//PREVIEW IMAGE qrc:/DefaultComponentSet/PreviewAssets/spinBox.png
//PARENTING FALSE
Item {
    id: root

    //ASSET /placeholders/spin-background.png
    property alias backgroundAsset: background.source
    //ASSETFILLM Stretch
    property alias fillMode: background.fillMode

    width: 300
    height: 128

    QtObject {
        id: internal

        function incrValue() {
            if (root.value + root.step <= root.max)
                return root.value + root.step
            else
                return root.max
        }

        function decrValue() {
            if (root.value - root.step >= root.min)
                return root.value - root.step
            else
                return root.min
        }
    }

    Image {
        id: background

        anchors.fill: parent

        source: GreenHouseThemeManager.theme.asset("/placeholders/spin-background.png")
    }

    //FONT spinBoxFont
    property alias font: label.font
    //COLOR spinBoxTextColor
    property alias textColor: label.color
    //TEXTHAL 4
    property alias horizontalAlignment: label.horizontalAlignment
    //TEXTVAL 128
    property alias verticalAlignment: label.verticalAlignment

    property int repeatInterval: 250
    property int decimals: 2
    property real min: 0.0
    property real max: 100.0
    property real value: 25.0
    property real step: 0.05
    signal valueChangeRequest(real wantedValue)

    function increment() {
        valueChangeRequest(internal.incrValue())
    }

    function decrement() {
        valueChangeRequest(internal.decrValue())
    }

    Text {
        id: label

        anchors.fill: parent

        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter

        text: root.value.toFixed(root.decimals)
        color: GreenHouseThemeManager.theme.color("textColor")
        font: GreenHouseThemeManager.theme.font("spinBoxFont")
    }

    //ASSET /placeholders/spin-up.png
    property string upArrowAsset: GreenHouseThemeManager.theme.asset("/placeholders/spin-up.png")
    //ASSET /placeholders/spin-up-disabled.png
    property string upArrowDisabledAsset: GreenHouseThemeManager.theme.asset("/placeholders/spin-up-disabled.png")
    Image {
        id: up

        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: parent.verticalCenter

        fillMode: Image.PreserveAspectFit
        source: enabled ? root.upArrowAsset : root.upArrowDisabledAsset
        enabled: root.value < root.max

        MouseArea {
            id: upMa

            anchors.fill: parent

            onClicked: {
                root.increment()
            }

            Timer {
                id: upTimer

                repeat: true
                interval: root.repeatInterval
                running: upMa.pressed && upMa.enabled
                onTriggered: {
                    root.increment()
                }
            }
        }
    }

    //ASSET /placeholders/spin-down.png
    property string downArrowAsset: GreenHouseThemeManager.theme.asset("/placeholders/spin-down-disabled.png")
    //ASSET /placeholders/spin-down-disabled.png
    property string downArrowDisabledAsset: GreenHouseThemeManager.theme.asset("/placeholders/spin-down.png")
    Image {
        id: down

        anchors.right: parent.right
        anchors.top: parent.verticalCenter
        anchors.bottom: parent.bottom

        fillMode: Image.PreserveAspectFit
        source: enabled ? root.downArrowAsset : root.downArrowDisabledAsset
        enabled: root.value > root.min

        MouseArea {
            id: downMa

            anchors.fill: parent

            onClicked: {
                root.decrement()
            }

            Timer {
                id: downTimer

                repeat: true
                interval: 250
                running: downMa.pressed && downMa.enabled
                onTriggered: {
                    root.decrement()
                }
            }
        }
    }
}
