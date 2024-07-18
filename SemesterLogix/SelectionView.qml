import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Window
import QtQml
import QtQuick.Dialogs

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
                model: SelectionViewModel.schoolMapKeys
                
                
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
            title: "Choisir la grille horaire PDF"
            currentFolder: SelectionViewModel.downloadsPath // Use the exposed downloadsPath
            nameFilters: ["PDF files (*.pdf)"]
            onAccepted: {
                var fileUrl = fileDialog.selectedFile.toString(); // Ensure it's a string
                console.log("Selected file URL:", fileUrl); // Log the URL to the console
                // Convert URL to string and remove "file:///" prefix
                var path = fileUrl.startsWith("file:///") ? fileUrl.substring(8) : fileUrl;
                console.log("Processed file path:", path); // Log the processed path to the console
                pathtext.text = decodeURIComponent(path);
                console.log("Final file path:", pathtext.text); // Log the final path to the console
            }
        }


}
