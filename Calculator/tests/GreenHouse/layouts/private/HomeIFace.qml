import QtQuick 2.0
import GreenHouse 1.0
Displayable {
    id: root

    //Properties
    property int activationCounter: 0
    property real activationCounterReal: 0.0
    property double activationCounterDouble: 0.0
    property string activationCounterString: "0"

    //Signals
    signal homeViewActivated();
}
