import QtQuick 2.6

//PREVIEW IMAGE qrc:/DefaultComponentSet/PreviewAssets/circular-clockwise-arrow.png
Item {
    id: root

    width: 88
    height: 88

    property int min: 0
    property int max: 100
    property int value: 25
    property bool clockwise: true
    property bool drawBackground: false
    property bool roundedStroke: false
    //COLOR circularProgressColor
    property color barColor: GreenHouseThemeManager.theme.color("circularProgressColor")
    //COLOR circularProgressBackgroundColor
    property color backgroundColor: GreenHouseThemeManager.theme.color("circularProgressBackgroundColor")
    property int barWidth: 20
    property int startOffset: 0
    property int span: 360

    onMinChanged: progressCanvas.requestPaint()
    onMaxChanged: progressCanvas.requestPaint()
    onValueChanged: progressCanvas.requestPaint()
    onClockwiseChanged: progressCanvas.requestPaint()
    onDrawBackgroundChanged: progressCanvas.requestPaint()
    onRoundedStrokeChanged: progressCanvas.requestPaint()
    onBarColorChanged: progressCanvas.requestPaint()
    onBarWidthChanged: progressCanvas.requestPaint()
    onSpanChanged: progressCanvas.requestPaint()

    Canvas {
        id: progressCanvas

        anchors.centerIn: parent
        width: Math.min(root.height, root.width)
        height: width
        rotation: root.startOffset

        onPaint: {
            var ctx = progressCanvas.getContext("2d")
            ctx.clearRect(0, 0, width, height)
            ctx.lineCap = root.roundedStroke ? "round" : "butt"
            ctx.lineWidth = root.barWidth
            if (root.drawBackground) {
                ctx.strokeStyle = root.backgroundColor
                ctx.beginPath()
                ctx.arc(width * 0.5, height * 0.5, (width - root.barWidth) * 0.5, 0, root.span * (2 * Math.PI) / 360.)
                ctx.stroke()
            }
            ctx.strokeStyle = root.barColor
            ctx.beginPath()
            var val = Math.min(1.0, (Math.max(0, root.value - root.min)/Math.max(1, root.max - root.min)))
            const startAngle = 0
            var endAngle = ( root.span * 2. * Math.PI / 360. ) * val
            if (!root.clockwise) {
                endAngle = -endAngle
            }
            ctx.arc(width * 0.5, height * 0.5, (width - root.barWidth) * 0.5,
                    startAngle, endAngle, !root.clockwise)
            ctx.stroke()
        }
    }

    //BOOL false
    property alias labelVisible: label.visible
    //COLOR textColor
    property alias textColor: label.color
    //FONT textFont
    property alias textFont: label.font
    property bool parentBackground: false
    property bool parentIndicator: false
    property bool labelAnchorTop: false
    property bool labelAnchorVCenter: false
    property bool labelAnchorHCenter: false
    property bool labelAnchorBottom: false
    property bool labelAnchorLeft: false
    property bool labelAnchorRight: false

    //TRANSLATABLE
    property string valuePrefix: ""
    //TRANSLATABLE
    property string valueSuffix: ""

    Text {
        id: label

        anchors.bottom: root.labelAnchorTop ? parent.top : undefined
        anchors.top: root.labelAnchorBottom ? parent.bottom : undefined
        anchors.right: root.labelAnchorRight ? parent.left : undefined
        anchors.left: root.labelAnchorLeft ? parent.right : undefined
        anchors.verticalCenter: root.labelAnchorVCenter ? parent.verticalCenter : undefined
        anchors.horizontalCenter: root.labelAnchorHCenter ? parent.horizontalCenter : undefined

        parent: {
            if (root.parentBackground)
                return background
            else if (root.parentIndicator)
                return indicator
            return root
        }

        opacity: {
            if ( (root.labelAnchorTop && root.labelAnchorBottom && root.labelAnchorHCenter)
                    || (root.labelAnchorRight && root.labelAnchorLeft && root.labelAnchorVCenter)
                    || (root.labelAnchorHCenter && root.labelAnchorVCenter))
                if (parent.width < fm.advanceWidth(label.text) || parent.height < fm.height)
                    return 0.0
            return 1.0
        }
        text: root.valuePrefix + root.value + root.valueSuffix
        visible: false

        color: GreenHouseThemeManager.theme.color("textColor")
        font: GreenHouseThemeManager.theme.font("textFont")
    }

    FontMetrics {
        id: fm
        font: label.font
    }
}
