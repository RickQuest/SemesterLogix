import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.15

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
