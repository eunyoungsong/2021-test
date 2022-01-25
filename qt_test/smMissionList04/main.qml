import QtQuick 2.12
import QtQuick.Controls 1.4  //TableViewColumn
import QtQuick.Dialogs      1.2
import QtQuick.Layouts      1.2

ApplicationWindow {

    Dialog{
        visible: true
        title: qsTr("SM Mission List")
        width: 350
        standardButtons: Dialog.Close
        onButtonClicked: Qt.quit() // test에서만 사용

        SmMissionDialog {
            id: smMissionDialog
        }

        ColumnLayout {
            id: mainLayout
            anchors.fill: parent

            CheckBox {
                id: editMode
                text: qsTr("Edit Mode")
                anchors.right: parent.right
                checked: false
            }

            //1행
            Label {
                text: "Mission List"
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

                model: smMissionList

                SmMissionList {
                    id: smMissionList
                }

                onDoubleClicked: {
                    console.log("index: " + currentRow + ", path: " + smMissionList.get(currentRow).path)
                    _planMasterController.loadFromSelectedFile()

                }

            } // TableView
            //1행끝

            //2행
            RowLayout {
                id: rowlayout
                anchors.right: parent.right
                enabled: editMode.checked
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
                    onClicked: removeListCheckPopup.open()
                }
                Button {
                    id: editButton
                    enabled: tableView.currentRow !== -1
                    text: qsTr("Edit")
                    onClicked: smMissionDialog.open()
                }
            }
            // 2행끝
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
                    anchors.bottom: parent.bottom
                    anchors.right: parent.right
                    Button {
                        text: qsTr("Yes")
                        onClicked: {
                            smMissionList.remove(tableView.currentRow)
                            tableView.currentRow = -1
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
