import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Window
import QtQml
import QtQuick.Dialogs
 
ToolBar {
    id: myheader
    //anchors.fill: parent
    property string school
    property string program
    property string semester
    RowLayout {
        anchors.fill: parent
        Label {
            text: "Ecole : "+myheader.school
            //elide: Label.ElideRight
            Layout.fillHeight: true ; Layout.preferredWidth: parent.width / 3
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: parent.height*0.6
        }
        Label {
            text: "Programme : "+myheader.program
            //elide: Label.ElideRight
            Layout.fillHeight: true ; Layout.preferredWidth: parent.width / 3
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: parent.height*0.6
        }
        Label {
            text: "Session : "+myheader.semester
            //elide: Label.ElideRight
            Layout.fillHeight: true ; Layout.preferredWidth: parent.width / 3
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: parent.height*0.6
        }
    }
}