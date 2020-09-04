import GreenHouse 1.0
import QtQuick 2.6
import GreenHouse.Theming 1.0
import Decorative 1.0 as DecorativeSet
import Components 1.0 as ComponentsSet


//USES DecorativeSet.DecoratedItem
//USES ComponentsSet.Label
//USES MouseArea


//EDITABLE TRUE
Item {
    id: root
    
    //Exposed properties----------------------------------------------------------------------------
    //TEXTHAL 4
    property alias fi_Number_Label_horizontalAlignment: fi_Number_Label.horizontalAlignment
    //COLOR Figma::255_0_0_0
    property alias fi_Number_Label_labelColor: fi_Number_Label.textColor
    //REAL 1
    property alias fi_Number_Label_opacity: fi_Number_Label.opacity
    //TRANSLATABLE #
    property alias fi_Number_Label_text: fi_Number_Label.text
    //TEXTVAL 128
    property alias fi_Number_Label_verticalAlignment: fi_Number_Label.verticalAlignment
    
    //----------------------------------------------------------------------------------------------
    
    //Exposed signals-------------------------------------------------------------------------------
    signal clicked() /*__mouseArea.clicked*/
    signal pressed() /*__mouseArea.pressed*/
    signal released() /*__mouseArea.released*/
    
    //----------------------------------------------------------------------------------------------
    
    //Local bindings--------------------------------------------------------------------------------
    width: 47
    height: 34
    
    //----------------------------------------------------------------------------------------------
    
    //Children--------------------------------------------------------------------------------------
    DecorativeSet.DecoratedItem {
        id: fi_Outline
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        source: GreenHouseThemeManager.theme.asset("/19_7.png")
        verticalCenterOffset: 4
        
        
        
        
        
    }
    ComponentsSet.Label {
        id: fi_Number_Label
        anchors.left: parent.left
        anchors.leftMargin: -1
        anchors.right: parent.right
        anchors.rightMargin: -1
        anchors.top: parent.top
        anchors.topMargin: -1
        anchors.bottom: parent.bottom
        anchors.bottomMargin: -1
        z: 1
        text: qsTr("#")
        font: GreenHouseThemeManager.theme.font("Figma::Digital Numbers_DigitalNumbers-Regular_12_50_0_0")
        textColor: GreenHouseThemeManager.theme.color("Figma::255_0_0_0")
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        wrapMode: Text.WordWrap
        
        
        
        
        
    }
    MouseArea {
        id: __mouseArea
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        z: -1
        
        
        
        
        onClicked: {
            root.clicked();
        }
        onPressed: {
            root.pressed();
        }
        onReleased: {
            root.released();
        }
        
    }
    
    //----------------------------------------------------------------------------------------------
    
    //States----------------------------------------------------------------------------------------
    
    //----------------------------------------------------------------------------------------------
}
