import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls     1.2
import QtQuick.Dialogs      1.2
import QtQuick.Layouts      1.2

Rectangle {
    width: 200; height: 200

    ListView {
        anchors.fill: parent
        model: fruitModel
        delegate: Row {
            Text { text: "Fruit: " + name }
            Text { text: "Cost: $" + cost }
        }
    }

    ListModel {
        id: fruitModel

        ListElement {
            name: "Apple"
            cost: 2.45
        }
        ListElement {
            name: "Orange"
            cost: 3.25
        }
        ListElement {
            name: "Banana"
            cost: 1.95
        }
    }



}

