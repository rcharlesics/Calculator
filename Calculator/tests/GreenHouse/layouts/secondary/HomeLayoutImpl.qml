import QtQuick 2.6

HomeBase {
    id: root

    Connections {
        target: root.showAnimation
        onFinished: {
            root.itemInterface.activationCounter += 1
            root.itemInterface.homeViewActivated()
        }
    }
}
