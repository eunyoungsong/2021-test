import QtQuick              2.3
import QtQuick.Controls     1.2
import QtQuick.Dialogs      1.2
import QtQuick.Layouts      1.2

ApplicationWindow {
    id: appWindow

    visible: true
    title: qsTr("SM Mission Lists")
    /*
    property int margin: 10
    width: mainLayout.implicitWidth + 5 * margin
    height: mainLayout.implicitHeight + 2 * margin
    minimumWidth: mainLayout.Layout.minimumWidth + 2 * margin
    minimumHeight: mainLayout.Layout.minimumHeight + 2 * margin
    */

    SmMissionDialog{
        id: myDlg
    }

    //TableView.model: MissionLists
    //Component.onCompleted: MissionLists.selection = tableView.selection

    ColumnLayout {
        id: mainLayout
        anchors.fill: parent
        anchors.margins: appWindow.margin

        // 1행
        GroupBox {
            id: missionLists
            title: "Mission Lists"
            Layout.fillWidth: true

            ColumnLayout {
                anchors.fill: parent

                TableView {
                    id: tableView
                    Layout.fillHeight: true
                    Layout.fillWidth: true

                    TableViewColumn {
                        role: "MissionTitle"
                        title: qsTr("Title")
                    }

                    model: listModel
                    ListModel {
                        id: listModel
                        ListElement {
                            MissionTitle: "aaaa"
                        }
                        ListElement {
                            MissionTitle: "bbb"
                        }
                        ListElement {
                            MissionTitle: "cccc"
                        }
                        ListElement {
                            MissionTitle: "dddd"
                        }
                    }
                }
            }
        }
        //2행
        //GroupBox {
          //  Layout.fillWidth: true

            RowLayout {
                id: editLayout
                //anchors.fill: parent
                //anchors.verticalCenter: parent

                Button {
                    text: qsTr("Add")
                    //anchors.fill: parent
                    onClicked: myDlg.open()
                }
                Button {
                    id: edit
                    text: qsTr("Edit")
                }
                Button {
                    id: del
                    text: qsTr("Del")
                }
            }
        //}
    }
}


