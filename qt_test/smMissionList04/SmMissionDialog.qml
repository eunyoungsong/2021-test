import QtQuick 2.12
import QtQuick.Layouts 1.2
import QtQuick.Controls 2.12
import QtQuick.Dialogs 1.2

Dialog{
    id: smMissionDialog
    title: "SM Mission"
    //width: 400

    standardButtons: "NoButton"

    GridLayout {
        id: grid
        Layout.alignment: Qt.AlignCenter
        //anchors.fill: parent
        columns: 3
        rowSpacing: 3
        columnSpacing: 10
        //Layout.fillHeight: true
        //Layout.fillWidth: true
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.right: parent.right
        anchors.left: parent.left

        //1행
        Label {
            Layout.alignment: Qt.AlignRight
            text: "Mission Title :"
        }
        TextField {
            id: smMissionTitle
            focus: true
            Layout.columnSpan: 2
            //placeholderText: "Missiontitle"
            Layout.fillWidth: true
            validator: RegExpValidator { regExp: /^[a-zA-Z0-9]+$/ }
            /*
            text: {
                if(smMissionDialog.currentRow === -1) {
                    ""
                }else{
                    smMissionList.get(smMissionDialog.currentRow).title
                }
            }
            */
        }

        //2행
        Label {
            Layout.alignment: Qt.AlignRight
            text: "File Path :"
        }
        TextField {
            id: smFilePath
            placeholderText: fileUrls
            Layout.fillWidth: true
            /*
            text: {
                if(smMissionDialog.currentRow === -1) {
                    ""
                }else{
                    smMissionList.get(smMissionDialog.currentRow).path
                }
            }
            */

        }
        Button {
            text: qsTr("Open...")
            onClicked: {
                smFileDialog.open()
            }
        }

        //3행
        RowLayout {
            Layout.columnSpan: 3
            anchors.right: parent.right
            anchors.bottom: parent.bottom
                Button {
                    text: qsTr("Save")
                    enabled: 0 < smMissionTitle.text.length && 0 < smFilePath.text.length ? true : false
                    onClicked: {
                        smMissionList.append({title: smMissionTitle.text})
                        smMissionTitle.text = ""
                        smFilePath.text = ""
                        smMissionDialog.close()
                    }
                }
                /*
                Button {
                    text: qsTr("Clear")
                    onClicked: {
                        smMissionTitle.text = ""
                        smFilePath.text = ""
                    }
                }
                */
                Button {
                    text: qsTr("Cancel")
                    onClicked: {
                        smMissionDialog.close()
                    }
                }
        } //RowLayout
    } //GridLayout

/*
    RowLayout {
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        //3행
        Button {
            text: qsTr("save")
            anchors.right: ColumnLayout.right
            enabled: 0 < smMissionTitle.text.length && 0 < smFilePath.text.length ? true : false
            onClicked: {
                smMissionList.append({title: smMissionTitle.text})
                smMissionTitle.text = ""
                smFilePath.text = ""
                dialog.close()
            }
        }
        Button {
            text: qsTr("Clear")
            onClicked: {
                smMissionTitle.text = ""
                smFilePath.text = ""
            }
        }
*/

    FileDialog {
        id: smFileDialog
        title: "Please choose a file"
        folder: shortcuts.home
        onAccepted: {
            smFilePath.text = smFileDialog.fileUrl  // file:///home/eunyoung/Documents/00000000.plan
        }

    } // FileDialog
} // Dialog
