import QtQuick 2.12
import QtQuick.Layouts 1.2
import QtQuick.Controls 2.12
import QtQuick.Dialogs 1.2

Dialog{
    id: smMissionDialog
    title: "SM Mission"
    //width: 400
    standardButtons: "NoButton"

    property int currentRow : -1
/*
    MessageDialog {
        id: undefinedMsg
        icon: StandardIcon.Information
        title: qsTr("About")
        text: "SM Mission about"
        informativeText: qsTr("Please enter the Mission Title or choose a file.")
    }
    onAccepted: {
        if ( 0 < smMissionTitle.text.length || 0 < smFilePath.length ) {
            undefinedMsg.open()
        }
        if ( 0 < smMissionTitle.text.length && 0 < smFilePath.length ) {
            undefinedMsg.open()
        } else {
            smMissionLists.append({title: smMissionTitle.text})
            smMissionTitle.text = ""
            smFilePath.text = ""
        }
        smMissionLists.append({title: smMissionTitle.text})
        smMissionTitle.text = ""
        smFilePath.text = ""
    }
*/

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
            //Layout.fillWidth: true
            //elide: Label.ElideRight // 글자 생략
        }
        TextField {
            id: smMissionTitle
            focus: true
            Layout.columnSpan: 2
            //placeholderText: "Missiontitle"
            Layout.fillWidth: true
            validator: RegExpValidator { regExp: /^[a-zA-Z0-9]+$/ }
            /*
            onTextChanged: {
                console.debug("onTextChanged")
                buttons.standardButton(Dialog.Ok).enabled = acceptableInput
            }
            */
            //text: tableView.currentRow == -1 ? "" : smMissionLists.get(currentRow).title
            text: {
                if(smMissionDialog.currentRow === -1) {
                    ""
                }else{
                    smMissionLists.get(smMissionDialog.currentRow).title
                }
            }

        }

        //2행
        Label {
            Layout.alignment: Qt.AlignRight
            text: "File Path :"
        }
        TextField {
            id: smFilePath
            //focus: true
            //readOnly: true
            placeholderText: fileUrls
            Layout.fillWidth: true
            text: {
                if(smMissionDialog.currentRow === -1) {
                    ""
                }else{
                    smMissionLists.get(smMissionDialog.currentRow).path
                }
            }

        }
        Button {
            text:               qsTr("Open...")
            //enabled:            !_planMasterController.syncInProgress
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
                        if(smMissionDialog.currentRow === -1) {
                            smMissionLists.set(tableView.currentRow, {"title": smMissionTitle.text})
                        } else {
                            smMissionLists.append({"title": smMissionTitle.text})
                            smMissionTitle.text = ""
                            smFilePath.text = ""
                            smMissionDialog.close()
                        }
                    } //onClicked
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
                smMissionLists.append({title: smMissionTitle.text})
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
            smFilePath.text = smFileDialog.fileUrl
        }
    } // FileDialog
} // Dialog
