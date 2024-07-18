import QtQuick
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Layouts
import QtQml
import QtQuick.Dialogs

ApplicationWindow {
    id: window
    width: 1344
    height: 756
    visible: true
    title: qsTr("SemesterLogix")
    objectName: "app"
    header: CustomHeader{
                id: mainHeader
                opacity:0
            }
   

  StackView {
       id: stack
       initialItem: "MainView.qml"
       anchors.fill: parent
  }
  

}
