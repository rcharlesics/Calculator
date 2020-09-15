import QtQuick 2.0

//PREVIEW IMAGE qrc:/DefaultComponentSet/PreviewAssets/mouse.png
MouseArea {
    id: root

    property int repeateInterval: 1000
    property int minimumRepeatInterval: 100
    signal repeatingTriggered

    QtObject {
        id: internal

        property int repeateInterval: 1000
    }

    Timer {
        id: repeatTimer

        running: root.containsMouse && root.pressed
        interval: internal.repeateInterval
        triggeredOnStart: true
        repeat: true
        onTriggered: {
            root.repeatingTriggered()
            if (internal.repeateInterval > root.minimumRepeatInterval) {
                var delta = Math.max((internal.repeateInterval - root.minimumRepeatInterval)/2, root.minimumRepeatInterval)
                internal.repeateInterval = Math.max(internal.repeateInterval - delta, root.minimumRepeatInterval)
            }
        }
    }

    onPressed: {
        internal.repeateInterval = root.repeateInterval
    }
}
