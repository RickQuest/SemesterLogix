import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Window
import QtQml
import QtQuick.Dialogs

Page {
  id: courseView
  width: parent.width
  height: parent.height
  footer: CustomFooter{
     nextEnable:true ; backEnable:true
     onButtonClicked: {
          ScheduleViewModel.GenSchedulesData(courseNumberGrid.currentIndex+1)
          ScheduleViewModel.GenSchedulesTables();
          stack.push("ScheduleView.qml") 
       }
  }
  ColumnLayout {
      anchors.fill: parent

      GroupBox {
          id: courseSelectionGr
          title: qsTr("Choix de cours")
          Layout.preferredHeight : parent.height*0.6 ; Layout.preferredWidth : parent.width*0.8
          Layout.alignment : Qt.AlignHCenter
              GridView {
                  id : selectedCourseGrid
                  cellHeight: selectedCourseGrid.height/8 ; cellWidth: selectedCourseGrid.width/6
                  width: parent.width ; height: parent.height*0.8
                  anchors.centerIn: parent
                  Component {
                      id: courseDelegate
                      Rectangle {
                          id: wrapper
                          width: selectedCourseGrid.cellWidth*0.8 ; height: selectedCourseGrid.cellHeight*0.8
                          color: "lightsteelblue"; radius: 5 ; opacity:0.5+model.modelData.Selected * 0.5
                          Text {text: model.modelData.Code ; anchors.fill: parent; horizontalAlignment: Text.AlignHCenter ; verticalAlignment:Text.AlignVCenter ; font.pixelSize: selectedCourseGrid.cellHeight*0.8}
                          MouseArea {
                             anchors.fill: parent
                             onClicked: {model.modelData.Selected = !model.modelData.Selected}
                          }
                      }
                  }
                  model: CourseViewModel.Courses
                  delegate: courseDelegate
              }
      }
      GroupBox {
          title: qsTr("Nombre de cours par horaire")
          Layout.preferredHeight : parent.height*0.1 ; Layout.preferredWidth : parent.width*0.8
          Layout.alignment : Qt.AlignHCenter
           
          GridView {
              id: courseNumberGrid
              cellWidth: courseNumberGrid.width/6 ; cellHeight: courseNumberGrid.height
              width: parent.width ; height: parent.height
              model: ListModel {
                  id: nameModel
                  ListElement { name: "1"; value: 1 }
                  ListElement { name: "2"; value: 2 }
                  ListElement { name: "3"; value: 3}
                  ListElement { name: "4"; value: 4 }
                  ListElement { name: "5"; value: 5 }
                  ListElement { name: "6"; value: 6 }

              }
              delegate: Component {
                  Item {
                      width: courseNumberGrid.cellWidth ; height: courseNumberGrid.cellHeight
                      Text {text: name ; anchors.fill: parent; horizontalAlignment: Text.AlignHCenter ; verticalAlignment:Text.AlignVCenter ; font.pixelSize: courseNumberGrid.cellHeight*0.8}
                      MouseArea {
                         anchors.fill: parent
                         onClicked: courseNumberGrid.currentIndex = index
                      }
                  }
              }
              highlight: Rectangle { color: "lightsteelblue"; radius: 5 }
              focus: true
          }
      }
  }
}   
