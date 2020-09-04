import QtQuick 2.0

//PREVIEW IMAGE qrc:/DefaultComponentSet/PreviewAssets/column.png
//CONTAINER Column
//CONTENT MOVABLE
Flickable {
    id: root

    width: 40
    height: 120

    property bool flickable: true
    property bool stopAtBounds: false
    //INT 0
    property alias spacing: column.spacing
    property int currentIndex: -1
    onCurrentIndexChanged: {
        if (currentIndex >= 0 && currentIndex < column.children.length) {
            var child = row.children[currentIndex];
            root.contentY = Math.max(0, Math.min(column.height - root.height, child.y))
        }
    }

    contentWidth: width
    contentHeight: column.height
    boundsBehavior: stopAtBounds ? Flickable.StopAtBounds : Flickable.DragAndOvershootBounds
    interactive: flickable
    clip: true

    default property alias columnContents: column.data
    Column {
        id: column
        anchors.left: parent.left
        anchors.right: parent.right
    }
}
