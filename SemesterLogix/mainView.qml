import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.12

Page {
  id: mainView
  width: parent.width
  height: parent.height
  Column {
      spacing: 10
      anchors.centerIn: parent

      Button {
          text: "Créer mon horaire"
          onClicked: {mainHeader.opacity=1 ; stack.push("SelectionView.qml")}
          anchors.horizontalCenter: parent.horizontalCenter
      }
      Button {
          text: "Paramètre"
          anchors.horizontalCenter: parent.horizontalCenter
      }
      Button {
          text: "À propos"
          anchors.horizontalCenter: parent.horizontalCenter
      }
  }
  //PageStatus.Active:{mainHeader.school=mainHeader.opacity=0//"test"}
  onVisibleChanged: {if (visible) {mainHeader.opacity=0}}
  //Component.onCompleted: {
  //mainHeader.school=mainHeader.opacity=0//"test"
  //}
  
}