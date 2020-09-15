import QtQuick 2.0
import QtQuick.Window 2.2

//PREVIEW IMAGE qrc:/DefaultComponentSet/PreviewAssets/dropDownContainer.png
Item {
    id: root

    width: 128
    height: 128

    property int delegateHeight: 56
    property int maximumItemsVisible: 0
    //ITEMREF
    property Item dropDownItem: null

    function _topLevelParent(itemParent) {
        if (Window.contentItem)
            return Window.contentItem;
        var topLevelParent = itemParent;
        while (topLevelParent && topLevelParent.parent)
            topLevelParent = topLevelParent.parent
        return topLevelParent;
    }

    Binding {
        target: root
        when: root.dropDownItem !== null
        property: "height"
        value: {
            var h = 0;
            if (root.dropDownItem) {
                root.dropDownItem.clip = true
                if (root.dropDownItem.count !== undefined) {
                    if (root.maximumItemsVisible > 0)
                        h = Math.min(root.dropDownItem.count, root.maximumItemsVisible) * root.delegateHeight;
                    else
                        h = root.dropDownItem.count * root.delegateHeight
                } else if (root.dropDownItem.contentHeight !== undefined) {
                    h = root.dropDownItem.contentHeight;
                }
                h += root.dropDownItem.anchors.topMargin;
            }

            var topLevelParent = root._topLevelParent(root.parent);
            var minRequiredHeight = root.delegateHeight + root.dropDownItem.anchors.topMargin;
            var availableExtraSpace = Math.max(0, topLevelParent.height - root.mapToItem(topLevelParent, 0, 0).y
                                               - minRequiredHeight);

            // NOTE: Calculating the maximum allowed height that also ensures no delegates get cutoff
            var maxAllowedHeight = minRequiredHeight + (root.delegateHeight
                                                        * Math.floor(availableExtraSpace / root.delegateHeight))

            return Math.min(Math.max(h, root.delegateHeight + root.dropDownItem.anchors.topMargin), maxAllowedHeight);
        }
    }

    // NOTE: The drop down needs to ensure that its renderd on top of all siblings
    // the code below goes up the drop down's parent tree and sets the z value of
    // parenting items to 999 when visible, all the way up to the main layout.
    property var __oldZValues: []
    onVisibleChanged: {
        if (visible) {
            __oldZValues = []
            var parent = root.parent
            while (parent) {
                __oldZValues.push(parent.z)
                parent.z = 999
                parent = parent.parent
                if (parent && parent.itemInterface)
                    parent = null
            }
        } else {
            var item = root.parent
            for (var i = 0; i < __oldZValues.length; ++i) {
                if (item) {
                    item.z = __oldZValues[i]
                    item = item.parent
                }
            }
        }
    }
}
