import QtQuick 2.0

SequentialAnimation {
    id: root

    property Item target

    ScriptAction {
        script: {
        }
    }

    PropertyAction { target: root.target; property: "visible"; value: false }
    ScriptAction {
        script: {
        }
    }

    onStopped: {
    }
}
