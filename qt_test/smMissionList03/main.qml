import QtQuick              2.3
import QtQuick.Controls     1.2
import QtQuick.Dialogs      1.2
import QtQuick.Layouts      1.2
import Qt.labs.qmlmodels 1.0 // delegate

ApplicationWindow {
    /*
    property int margin: 10
    width: mainLayout.implicitWidth + 5 * margin
    height: mainLayout.implicitHeight + 2 * margin
    minimumWidth: mainLayout.Layout.minimumWidth + 2 * margin
    minimumHeight: mainLayout.Layout.minimumHeight + 2 * margin
    */

    Dialog{

        id: smMissionLists
        visible: true
        title: qsTr("SM Mission Lists")
        width: 350

        //property int currentContact: -1

        standardButtons: Dialog.Close
        onButtonClicked: Qt.quit()

        SmMissionDialog {
            id: smMissionDialog
        }

        ColumnLayout {
            id: mainLayout
            anchors.fill: parent
            //anchors.margins: smMission.margin

            CheckBox {
                id: edit
                text: qsTr("Edit")
                anchors.right: parent.right
                checked: false
            }

            // 1행
            Label {
                //elide: Label.ElideRight
                text: "Mission Lists"
                Layout.fillWidth: true
            }

            TableView {
                id: tableView
                Layout.fillHeight: true
                Layout.fillWidth: true

                TableViewColumn {
                    role: "title"
                    title: qsTr("Title")
                }

                model: missionLists

                MissionLists {
                    id: missionLists
                }

                //Component.onCompleted: missionLists.selection
                /*
                MouseArea {
                    id: ma
                    anchors.fill: parent
                    onPressed: {
                        tableView.currentRow = styleData.row
                        tableView.selection.select(styleData.row) // <-- select here.
                    }
                }
                */

            } // TableView

            // 2행
            RowLayout {
                id: rowlayout
                //Layout.fillWidth: true
                anchors.right: parent.right
                enabled: edit.checked
                Button {
                    id: addButton
                    text: qsTr("+")
                    onClicked: smMissionDialog.open()
                }
                Button {
                    id: delButton
                    enabled: tableView.currentRow !== -1
                    text: qsTr("-")
                    //onClicked: missionLists.clear()
                    onClicked: missionLists.remove(tableView.currentRow)
                }
            }
            // 2행끝

        } // ColumnLayout
    } // Dialog
} // ApplicationWindow
