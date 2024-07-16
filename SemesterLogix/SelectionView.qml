import QtQuick 2.9
import QtQuick.Layouts 1.1
import QtQuick.Controls 2.12
import QtQuick.Dialogs 1.3

Page {
  id: selectionView
  width: parent.width
  height: parent.height
  footer: CustomFooter{
      nextEnable:true ; backEnable:true
      onButtonClicked: {
          CourseViewModel.Courses = SelectionViewModel.Courses
          stack.push("CourseView.qml") 
      }
  }


  ColumnLayout {
        //Layout.alignment : AlignVCenter
        anchors.centerIn: parent
        Layout.preferredWidth: parent.width*0.8
        Layout.preferredHeight: parent.height/2
        spacing: 2
       
        GroupBox {
            title: qsTr("Sélectionner l'école")
            //Layout.alignment: Qt.AlignVCenter
            Layout.fillWidth: true

            ComboBox {
                width: parent.width
                //horizontalAlignment: displayText.AlignHCenter
                // When an item is selected, update the backend.
                onActivated: SelectionViewModel.selectedSchool = currentIndex
                // Set the initial currentIndex to the value stored in the backend.
                Component.onCompleted: currentIndex = SelectionViewModel.selectedSchool
                model: SelectionViewModel.SchoolMapValues
                
            }
        }
      
        GroupBox {
            title: qsTr("Sélectionner le PDF contenant l'horaire")
            RowLayout {
                Layout.fillWidth: true
                TextField {
                    id: pathtext
                    onTextChanged: {SelectionViewModel.pdfFilepath =pathtext.text}
                }
                Button {
                    text: "..."
                    onClicked: fileDialog.open();
                }
            }
        }
        

    }
   
    FileDialog {
        id: fileDialog
        folder: shortcuts.home
        onAccepted: {
            var path = fileDialog.fileUrl.toString();
            // remove prefixed "file:///"
            path = path.replace(/^(file:\/{3})/,"");
            // unescape html codes like '%23' for '#'
            pathtext.text = decodeURIComponent(path);
        }
    }

}
