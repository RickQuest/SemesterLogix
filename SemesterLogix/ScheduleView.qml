import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Window
import QtQml
import QtQuick.Dialogs
import TableModel 0.1

Page {
  id: scheduleView
  width: parent.width
  height: parent.height
  footer: CustomFooter{
      nextEnable:false ; backEnable:true
  }

  GridView {
      id : schedulesGrid
      cellHeight: schedulesGrid.height/2
      cellWidth: schedulesGrid.width/3
      anchors.fill: parent
      Component {
          id: scheduleDelegate
          Item{
              width: schedulesGrid.cellWidth ; height: schedulesGrid.cellHeight
              Text {
              text: "Horaire "+index
              width:parent.width*0.9
              anchors.bottom: table.top
              anchors.horizontalCenter: parent.horizontalCenter
              font.pixelSize: parent.height*0.05
              horizontalAlignment: Text.AlignHCenter}
              TableView {
                  id: table
                  width: parent.width*0.9
                  height: parent.height*0.9
                  anchors.horizontalCenter: parent.horizontalCenter
                  anchors.bottom: parent.bottom
                  clip: true
                  model: schedulesGrid.model[index]
                  delegate: Rectangle {
                      implicitWidth: 70
                      implicitHeight: 15
                      color: tablecolor
                      Text {
                          text: tabledata
                      }
                  }
              }
          } 
      }
      model: ScheduleViewModel.schedulesTables
      delegate: scheduleDelegate
  }
    
}