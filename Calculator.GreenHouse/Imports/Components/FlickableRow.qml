import QtQuick 2.0

//PREVIEW IMAGE qrc:/DefaultComponentSet/PreviewAssets/row.png
//CONTAINER Row
//CONTENT MOVABLE
Flickable {
    id: root

    width: 120
    height: 40

    property bool flickable: true
    property bool stopAtBounds: false
    //INT 0
    property alias spacing: row.spacing
    //LAYOUTDIR 0
    property alias layoutDirection: row.layoutDirection
    property int currentIndex: -1
    onCurrentIndexChanged: {
        if (currentIndex >= 0 && currentIndex < row.children.length) {
            var child = row.children[currentIndex];
            root.contentX = Math.max(0, Math.min(row.width - root.width, child.x))
        }
    }

    contentWidth: row.width
    contentHeight: height
    boundsBehavior: stopAtBounds ? Flickable.StopAtBounds : Flickable.DragAndOvershootBounds
    interactive: flickable
    clip: true

    default property alias rowContents: row.data
    Row {
        id: row
        anchors.top: parent.top
        anchors.bottom: parent.bottom
    }
}
