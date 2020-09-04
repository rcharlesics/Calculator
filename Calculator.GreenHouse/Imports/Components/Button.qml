import QtQuick 2.0
import GreenHouse.Theming 1.0

//PREVIEW IMAGE qrc:/DefaultComponentSet/PreviewAssets/button.png
MouseArea {
    id: root

    //TRANSLATABLE Button
    property string buttonText: "Button"
    //FONT buttonFont
    property alias font: label.font
    //TEXTHAL 4
    property alias horizontalAlignment: label.horizontalAlignment
    //TEXTVAL 128
    property alias verticalAlignment: label.verticalAlignment

    //ASSET /placeholders/button/default.png
    property string defaultBackgroundAsset: GreenHouseThemeManager.theme.asset("/placeholders/button/default.png")
    //ASSET /placeholders/button/disabled.png
    property string disabledBackgroundAsset: GreenHouseThemeManager.theme.asset("/placeholders/button/disabled.png")
    //ASSET /placeholders/button/hover.png
    property string hoverBackgroundAsset: GreenHouseThemeManager.theme.asset("/placeholders/button/hover.png")
    //ASSET /placeholders/button/pressed.png
    property string pressedBackgroundAsset: GreenHouseThemeManager.theme.asset("/placeholders/button/pressed.png")
    //ASSET /placeholders/button/pressedselected.png
    property string pressedSelectedBackgroundAsset: GreenHouseThemeManager.theme.asset("/placeholders/button/pressedselected.png")
    //ASSET /placeholders/button/selected.png
    property string selectedBackgroundAsset: GreenHouseThemeManager.theme.asset("/placeholders/button/selected.png")

    //COLOR buttonTextColor
    property color textColor: GreenHouseThemeManager.theme.color("buttonTextColor")
    //COLOR buttonDisabledTextColor
    property color disabledTextColor: GreenHouseThemeManager.theme.color("buttonDisabledTextColor")
    //COLOR buttonAltTextColor
    property color hoveredTextColor: GreenHouseThemeManager.theme.color("buttonAltTextColor")
    //COLOR buttonAltTextColor
    property color pressedTextColor: GreenHouseThemeManager.theme.color("buttonAltTextColor")
    //COLOR buttonAltTextColor
    property color pressedSelectedTextColor: GreenHouseThemeManager.theme.color("buttonAltTextColor")
    //COLOR buttonTextColor
    property color selectedTextColor: GreenHouseThemeManager.theme.color("buttonTextColor")

    property int itemIndex: 0
    property int selectionIndex: -1

    property int leftAssetBorder: 5
    property int rightAssetBorder: 5
    property int topAssetBorder: 5
    property int bottomAssetBorder: 5

    width: 150
    height: 50

    //HIDE property hoverEnabled
    hoverEnabled: true

    signal triggered()
    onClicked: root.triggered()

    BorderImage {
        id: bg

        anchors.fill: parent

        border {
            left: root.leftAssetBorder
            right: root.rightAssetBorder
            top: root.topAssetBorder
            bottom: root.bottomAssetBorder
        }

        source: root.defaultBackgroundAsset

        states: [
            State {
                name: "defaultState"
                when: root.enabled && !(root.containsMouse && root.pressed) && root.selectionIndex != root.itemIndex
                PropertyChanges {
                    target: bg
                    source: root.defaultBackgroundAsset
                }
                PropertyChanges {
                    target: label
                    color: root.textColor
                }
            },
            State {
                name: "disabled"
                when: !root.enabled
                PropertyChanges {
                    target: bg
                    source: root.disabledBackgroundAsset
                }
                PropertyChanges {
                    target: label
                    color: root.disabledTextColor
                }
            },
            State {
                name: "hovered"
                when: root.enabled && root.containsMouse && !root.pressed && root.selectionIndex != root.itemIndex
                PropertyChanges {
                    target: bg
                    source: root.hoverBackgroundAsset
                }
                PropertyChanges {
                    target: label
                    color: root.hoveredTextColor
                }
            },
            State {
                name: "pressed"
                when: root.enabled && root.containsMouse && root.pressed && root.selectionIndex != root.itemIndex
                PropertyChanges {
                    target: bg
                    source: root.pressedBackgroundAsset
                }
                PropertyChanges {
                    target: label
                    color: root.pressedTextColor
                }
            },
            State {
                name: "pressedSelected"
                when: root.enabled && root.containsMouse && root.pressed && root.selectionIndex == root.itemIndex
                PropertyChanges {
                    target: bg
                    source: root.pressedSelectedBackgroundAsset
                }
                PropertyChanges {
                    target: label
                    color: root.pressedSelectedTextColor
                }
            },
            State {
                name: "selected"
                when: root.enabled && !root.pressed && root.selectionIndex == root.itemIndex
                PropertyChanges {
                    target: bg
                    source: root.pressedSelectedBackgroundAsset
                }
                PropertyChanges {
                    target: label
                    color: root.selectedTextColor
                }
            }
        ]

        Text {
            id: label

            anchors.fill: parent

            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter

            elide: Text.ElideRight

            font: GreenHouseThemeManager.theme.font("buttonFont")

            text: root.buttonText
        }
    }
}
