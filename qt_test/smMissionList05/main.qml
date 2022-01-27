import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.12
import Qt.labs.qmlmodels 1.0

import smsoft.mission 1.0

ApplicationWindow {

    Dialog{
        id: _dialog
        visible: true
        title: qsTr("SM Mission Lists")
        width: 400
        height: 200
        standardButtons: Dialog.Close
        onButtonClicked: Qt.quit() // test에서만 사용

        MouseArea {
            anchors.fill: parent
            onClicked: {
                _tableView.currentRow = -1;
            }
        }

        SmMissionDialog {
            id: smMissionDialog
        }

        ColumnLayout {
            id: mainLayout
            anchors.left: parent.left
            anchors.right: parent.right
            //anchors.top: parent.top
            anchors.centerIn: parent
            spacing: 1

            CheckBox {
                id: editMode
                text: qsTr("Edit Mode")
                Layout.alignment: Qt.AlignRight
                checked: false
                onClicked: {
                    console.log(_tableView.crruntRow)
                }
            }

            Label {
                text: "Mission Lists"
                Layout.fillWidth: true
            }

            Row {
                id: columnsHeader
//                y: _tableView.contentY
//                z: 2
                spacing: 1
                Repeater {
                    model: ["Title", "Path"]
                    Label {
                        width: 180
                        height: 25
                        text: modelData
                        font.bold: true
                        //font.pixelSize: 20
                        //padding: 10
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        background: Rectangle { color: "silver" }
                    }
                }
            }

            // /*
            TableView {
                id: _tableView
                columnSpacing: 1
                rowSpacing: 1
                //Layout.fillHeight: true
                implicitHeight: contentHeight
                Layout.fillWidth: true
                clip: true
                flickableDirection: Flickable.VerticalFlick

                property int currentRow : -1

//                TableViewColumn {
//                    role: "title"
//                    title: qsTr("Title")
//                }

                model: _missionTableModel

                SmMissionTableModel {
                    id: _missionTableModel
                    missionManager: _missionManager
                }

                SmMissionManager {
                     id: _missionManager
                }

                delegate: Rectangle {
                    id: rectangle
                    implicitWidth: 180
                    implicitHeight: 25
                    color: _tableView.currentRow  === row ? "#1569C7" : "#FFFFFF"

                    Text {
                        id: text
                        text: display
                        anchors.centerIn: parent
                        color: _tableView.currentRow  === row ? "#FFFFFF" : "#000000"
                    }

                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            if (_tableView.currentRow  === row)
                                _tableView.currentRow  = -1
                            else
                                _tableView.currentRow  = row
                            //console.log("currentRow : " + _tableView.currentRow  + " clicked test")
                        }
                    } // MouseArea
                } //Rectangle

//                onDoubleClicked: {
//                    console.log("index: " + currentRow + ", path: " + smMissionList.get(currentRow).path)
//                 }

            } // TableView
            // */

            Rectangle {
                implicitHeight: 32
                color: "transparent"
            }

            RowLayout {
                id: rowlayout
                Layout.alignment: Qt.AlignRight
                enabled: editMode.checked
                Button {
                    id: addButton
                    text: qsTr("+")
                    onClicked: smMissionDialog.open()
                }
                Button {
                    id: delButton
                    enabled: _tableView.currentRow != -1
                    text: qsTr("-")
                    //onClicked: missionLists.clear()
                    onClicked: removeListCheckPopup.open()
                }
                Button {
                    id: editButton
                    enabled: _tableView.currentRow != -1
                    text: qsTr("Edit")
                    onClicked: smMissionDialog.open()
                }
            }
        } // ColumnLayout

        Dialog {
            id: removeListCheckPopup
            title: qsTr("removeListCheckPopup")
            standardButtons: "NoButton" // Dialog 버튼 없애기

            ColumnLayout {
                spacing: 20
                anchors.horizontalCenter: parent.horizontalCenter

                Text { text: "Are you sure you want to delete this List?" }

                RowLayout {                    
                    //Layout.bottom: parent.bottom
                    //Layout.right: parent.right
                    Button {
                        text: qsTr("Yes")
                        onClicked: {
                            smMissionList.remove(_tableView.currentRow)
                            _tableView.currentRow = -1
                            removeListCheckPopup.close()
                        }
                    }
                    Button {
                        text: qsTr("No")
                        onClicked: removeListCheckPopup.close()
                    }
                } //RowLayout
            } //ColumnLayout
        } //Dialog
    } // Dialog
} // ApplicationWindow
