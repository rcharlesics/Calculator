import GreenHouse 1.0
import QtQuick 2.6
import GreenHouse.Theming 1.0
import Decorative 1.0 as DecorativeSet


//USES DecorativeSet.DecoratedItem
//USES MouseArea


//EDITABLE TRUE
Item {
    id: root
    
    //Exposed properties----------------------------------------------------------------------------
    
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
        id: fi_Filling
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        source: GreenHouseThemeManager.theme.asset("/26_64.png")
        verticalCenterOffset: 4
        
        
        
        
        
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
