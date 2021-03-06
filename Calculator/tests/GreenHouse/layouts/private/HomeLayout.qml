import QtQuick 2.0
import GreenHouse 1.0
Item {
    id: root

    readonly property bool __statesLayout: true
    readonly property HomeIFace itemInterface: HomeIFace { }
    Connections {
        target: root.itemInterface
        onInit: { root.initFunc(); }
        onShow: {
            if (root.itemInterface.allowedToDisplay)
                root.showFunc();
            else
                root.itemInterface.allowedToDisplay = true;
        }
        onHide: {
            if (!root.itemInterface.allowedToDisplay)
                root.hideFunc();
            else
                root.itemInterface.allowedToDisplay = false;
        }
        onAllowedToDisplayChanged: {
            if (root.itemInterface.allowedToDisplay)
                root.showFunc();
            else
                root.hideFunc();
        }
    }

    property SequentialAnimation showAnimation
    property SequentialAnimation hideAnimation
    property SequentialAnimation initAction

    signal extraShowAction()
    property var showFunc: function () {
        if (hideAnimation)
            hideAnimation.stop();
        if (showAnimation)
            showAnimation.restart();
        else
            root.visible = true;
        root.extraShowAction()
    }

    signal extraHideAction()
    property var hideFunc: function () {
        if (showAnimation)
            showAnimation.stop();
        if (hideAnimation)
            hideAnimation.restart();
        else
            root.visible = false;
        root.extraHideAction()
    }

    signal extraInitAction()
    property var initFunc: function() {
        if (hideAnimation)
            hideAnimation.stop();
        if (showAnimation)
            showAnimation.stop();
        if (initAction)
            initAction.restart();
        else
            root.visible = false;
        root.extraInitAction()
    }

    property alias inputFallthroughBlocked: inputFallthroughBlocker.enabled
    MouseArea {
        id: inputFallthroughBlocker

        anchors.fill: parent
        z: -999
    }
}
