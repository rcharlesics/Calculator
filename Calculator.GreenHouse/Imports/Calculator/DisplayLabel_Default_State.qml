import GreenHouse 1.0
import QtQuick 2.6
import GreenHouse.Theming 1.0
import Components 1.0 as ComponentsSet


//USES Rectangle
//USES ComponentsSet.Label


//EDITABLE TRUE
Item {
    id: root
    
    //Exposed properties----------------------------------------------------------------------------
    //TEXTHAL 2
    property alias fi_EntryText_horizontalAlignment: fi_EntryText.horizontalAlignment
    //COLOR Figma::255_0_0_0
    property alias fi_EntryText_labelColor: fi_EntryText.textColor
    //REAL 1
    property alias fi_EntryText_opacity: fi_EntryText.opacity
    //TRANSLATABLE 0.
    property alias fi_EntryText_text: fi_EntryText.text
    //TEXTVAL 128
    property alias fi_EntryText_verticalAlignment: fi_EntryText.verticalAlignment
    //COLOR buttonAltTextColor
    property alias fi_Outline_color: fi_Outline.color
    //REAL 1
    property alias fi_Outline_opacity: fi_Outline.opacity
    
    //----------------------------------------------------------------------------------------------
    
    //Exposed signals-------------------------------------------------------------------------------
    
    //----------------------------------------------------------------------------------------------
    
    //Local bindings--------------------------------------------------------------------------------
    width: 340
    height: 41
    
    //----------------------------------------------------------------------------------------------
    
    //Children--------------------------------------------------------------------------------------
    Rectangle {
        id: fi_Outline
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        color: GreenHouseThemeManager.theme.color("buttonAltTextColor")
        border.color: GreenHouseThemeManager.theme.color("Figma::255_51_51_51")
        border.width: 1
        
        
        
        
        
    }
    ComponentsSet.Label {
        id: fi_EntryText
        anchors.left: parent.left
        anchors.leftMargin: 7
        anchors.right: parent.right
        anchors.rightMargin: 5
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 5
        z: 1
        height: 26
        text: qsTr("0.")
        font: GreenHouseThemeManager.theme.font("Figma::Digital Numbers_DigitalNumbers-Regular_12_50_0_0")
        textColor: GreenHouseThemeManager.theme.color("Figma::255_0_0_0")
        horizontalAlignment: Text.AlignRight
        verticalAlignment: Text.AlignVCenter
        wrapMode: Text.WordWrap
        backgroundColor: fi_Outline.color
        
        
        
        
        
    }
    
    //----------------------------------------------------------------------------------------------
    
    //States----------------------------------------------------------------------------------------
    
    //----------------------------------------------------------------------------------------------
}
