import QtQuick          2.3
import QtQuick.Controls 1.2
import QtQuick.Dialogs  1.2
import QtLocation       5.3
import QtPositioning    5.3
import QtQuick.Layouts  1.2
import QtQuick.Window   2.2

ApplicationWindow{
    Dialog{
        id: smMissionLists
        visible: true
        title: qsTr("SM Mission Lists")
        width: 350

        property string title

       standardButtons: Dialog.Close

        ColumnLayout {
            id: mainLayout
            anchors.fill: parent
            //anchors.margins: smMission.margin

            Button {
                id: edit
                text: qsTr("Edit")
                anchors.right: parent.right
            }

            // 1행
            Label {
                //elide: Label.ElideRight
                text: "Mission Lists"
                Layout.fillWidth: true
            }

            TableView {
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
                        MissionTitle: "aaa"
                    }

                }
            }

            /*
            function ListModelFunc(){
                if( sizeof(smMission.title) > 0 ){

                }
            }
            */

            // 2행
            RowLayout {
                //Layout.fillWidth: true
                anchors.right: parent.right
                Button {
                    text: qsTr("+")
                    onClicked: smMission.open()
                }
                Button {
                    text: qsTr("-")
                    //onClicked:
                }
            }

        }

        Dialog{
            id: smMission
            title: "SM Mission"
            width: 300
            //parent: Overlay.overlay

            property string title
            property string path

            standardButtons: Dialog.Save | Dialog.Cancel

            onAccepted: {
                smMission.title = smMissionTitle.text
                smMission.path = smFilePath.text
            }

            GridLayout {
                id: grid
                Layout.alignment: Qt.AlignCenter
                anchors.fill: parent
                rows: 2
                columns: 3
                rowSpacing: 3
                columnSpacing: 8
                //Layout.fillHeight: true
                //Layout.fillWidth: true

                Label {
                    Layout.alignment: Qt.AlignRight
                    text: "Mission Title :"
                    //Layout.fillWidth: true
                    //elide: Label.ElideRight // 글자 생략
                }
                TextField {
                    id: smMissionTitle
                    focus: true
                    Layout.columnSpan: 2
                    //placeholderText: "Missiontitle"
                    Layout.fillWidth: true
                }

                Label {
                    Layout.alignment: Qt.AlignRight
                    text: "File Path :"
                }
                TextField {
                    id: smFilePath
                    //focus: true
                    readOnly: true
                    placeholderText: fileUrls
                    Layout.fillWidth: true
                }
                Button {
                    text:               qsTr("Open...")
                    //enabled:            !_planMasterController.syncInProgress
                    onClicked: {
                        smFileDialog.open()
                    }
                }
            } //GridLayout

            FileDialog {
                id: smFileDialog
                title: "Please choose a file"
                folder: shortcuts.home

                onAccepted: {
                    smFilePath.text = smFileDialog.fileUrl
                }

               /*
                onRejected: {
                    console.log("Canceled")
                    Qt.quit()
                }
               */

            } // FileDialog
        } // Dialog

    } //Dialog

    // -----------------------------------------



/*
    onSave : {
        smMission.title = smMissionTitle.text
        smMission.path = smFilePath.text
    }

    // caller
    onAdd: () {
        smMission.title = ""
        smMission.path = ""
        if (dialog.show() == ID_accept) {
            ListItem item;
            item.title = smMission.title
            item.path = smMission.path
            list.add(item)
        }
}

    onEdit: () {
        smMission.title = "aaa"
        smMission.path = "bbb"
        if (dialog.show() == ID_accept) {
            ListItem item;
            item.title = smMission.title
            item.path = smMission.path
            list.add(item)
        }
    }
*/
     // -----------------------------------------

}
