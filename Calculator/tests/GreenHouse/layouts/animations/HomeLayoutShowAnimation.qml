import QtQuick 2.0

SequentialAnimation {
    id: root

    property Item target

    ScriptAction {
        script: {
        }
    }
    PropertyAction { target: root.target; property: "visible"; value: true }
    ParallelAnimation {
        PropertyAnimation {
            target: root.target.homeIconAnimationItem
            duration: 650
            property: "scale"
            from: 0.05
            to: 1
            easing.type: Easing.OutBounce
        }
        PropertyAnimation {
            target: root.target.poweredTextAnimationItem
            duration: 800
            property: "opacity"
            from: 0
            to: 1
            easing.type: Easing.Linear
        }
    }

    ScriptAction {
        script: {
        }
    }

    onStopped: {
    }
}
