import GreenHouse 1.0
import QtQuick 2.6
import GreenHouse.Theming 1.0

import "../private/"
import "../animations/"

HomeLayout {
    id: root

    property bool fillParent: false
    x: fillParent ? 0 : 0
    y: fillParent ? 0 : 100
    width: fillParent ? (parent ? parent.width : 0) : 800
    height: fillParent ? (parent ? parent.height : 0) : 500

    inputFallthroughBlocked: true

    Image {
        id: homeIcon
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.horizontalCenterOffset: 0
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: 0
        z: 0
        width: 256
        height: 256
        source: GreenHouseThemeManager.theme.asset("/GHLogoBig.png")
        fillMode: Image.Stretch
        opacity: 1
        enabled: true
        visible: true
        clip: false
        rotation: 0
        scale: 1
    }

    Text {
        id: poweredText
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.top: homeIcon.bottom
        anchors.topMargin: 5
        z: 0
        height: 29
        text: qsTr("Powered by GreenHouse")
        font: GreenHouseThemeManager.theme.font("textFont")
        opacity: 1
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        elide: Text.ElideNone
        wrapMode: Text.NoWrap
        enabled: true
        visible: true
        clip: false

        focus: root.visible
        onActiveFocusChanged: if (activeFocus) {
            GreenHouseFocusManager.registerFocus(null, null)
        }
    }

    property Item homeIconAnimationItem: homeIcon
    property Item poweredTextAnimationItem: poweredText

    showAnimation: HomeLayoutShowAnimation { target: root }
    hideAnimation: HomeLayoutHideAnimation { target: root }
    initAction: HomeLayoutInitAnimation { target: root }

    Connections {
        target: root.itemInterface
        onAllowedToDisplayChanged: {
            if (root.itemInterface.allowedToDisplay) {
                GreenHouseFocusManager.requestFocus(null, null)
                GreenHouseFocusManager.registerFocus(null, null)
            } else {
                GreenHouseFocusManager.releaseFocus(null)
            }
        }
    }
}
