import QtQuick              2.3
import QtQuick.Controls     1.2
import QtQuick.Dialogs      1.2
import QtQuick.Layouts      1.2

Dialog{
    id: dialog
    title: "SM Mission"
    //width: 400
    //parent: Overlay.overlay

    //property string title
    //property string path

    standardButtons: Dialog.Save | Dialog.Cancel

    onAccepted: {
        //dialog.title = smMissionTitle.text
        //dialog.path = smFilePath.text
        missionLists.append({title: smMissionTitle.text})
        smMissionTitle.text = ""
    }

    GridLayout {
        id: grid
        Layout.alignment: Qt.AlignCenter
        //anchors.fill: parent
        rows: 2
        columns: 3
        rowSpacing: 3
        columnSpacing: 10
        //Layout.fillHeight: true
        //Layout.fillWidth: true
        anchors.horizontalCenter: parent.horizontalCenter

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

    } // FileDialog
} // Dialog
