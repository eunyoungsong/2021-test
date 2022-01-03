import QtQuick              2.3
import QtQuick.Controls     1.2
import QtQuick.Dialogs      1.2
import QtQuick.Layouts      1.2

Dialog {
    title: "SM Mission"
    width: 300
    //parent: Overlay.overlay // 배경흐리게
    //focus: true
    //modal: true
    standardButtons: Dialog.Save | Dialog.Cancel

    ColumnLayout {
        anchors.fill: parent

        RowLayout{
            Label {
                elide: Label.ElideRight
                text: "Mission title :"
                Layout.fillWidth: true
            }
            TextField {
                focus: true
                //placeholderText: "Missiontitle"
                Layout.fillWidth: true
            }
        }

        RowLayout{
            Label {
                elide: Label.ElideRight
                text: "File Path :"
                Layout.fillWidth: true
            }
            TextField {
                id: filePath
                //focus: true
                readOnly: true
                //placeholderText: "..."
                Layout.fillWidth: true
            }
            Button {
                text: qsTr("Open...")
                onClicked: fileDialog.open()
            }
        }
    }

    FileDialog {
        id: fileDialog
        title: "Please choose a file"
        folder: shortcuts.home

        onAccepted: {
            filePath.text = fileDialog.fileUrl
            console.log("You chose: " + fileDialog.fileUrls)
            //Qt.quit()
        }
        onRejected: {
            console.log("Canceled")
            Qt.quit()
        }
        //Component.onCompleted: visible = true

    }


}
