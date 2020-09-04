import QtQuick 2.0
import QtGraphicalEffects 1.0
import GreenHouse.Theming 1.0

Item {
    id: root

    property Item source

    anchors.fill: parent

    InnerShadow {
        id: innerShadow

        anchors.centerIn: parent
        width: root.source ? root.source.width : 0
        height: root.source ? root.source.height : 0

        horizontalOffset: root.source ? root.source.horizontalOffset : 0
        verticalOffset: root.source ? root.source.verticalOffset : 0
        samples: root.source ? root.source.samples : 0

        radius: root.source ? root.source.shadowRadius : 0.0
        spread: root.source ? root.source.spread : 0.0

        color: root.source ? root.source.shadowColor : "black"

        source: root.source ? root.source.__sourceItem : null
    }

    property string cacheName: root.source ? root.source.__shadowAssetName : ""
    onCacheNameChanged: {
        if (cacheName !== "" && GreenHouseThemeManager.theme.cacheEffects)
            cacheTimer.start()
    }
    Timer {
        id: cacheTimer
        repeat: false
        interval: 500
        onTriggered: {
            if (root.cacheName !== "")
                GreenHouseThemeManager.theme.itemCacher.cacheItem(root, root.cacheName)
        }
    }
}
