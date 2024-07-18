import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Window
import QtQml
import QtQuick.Dialogs
 
ToolBar {
    id: footer
    property bool nextEnable
    property bool backEnable
    signal buttonClicked()
    RowLayout {
        anchors.fill: parent
        ToolButton {
            text: qsTr("Précédent")
            enabled: backEnable
            onClicked: stack.pop()
            Layout.leftMargin: parent.width/40
            Layout.preferredWidth: parent.width/12
            Layout.alignment: Qt.AlignLeft
            background: Rectangle {
                radius:5
                anchors.fill: parent
                color : "dimgrey"
            }
        }
        Label {
            text: ""
            Layout.fillWidth: true
            elide: Label.ElideRight
            horizontalAlignment: Qt.AlignHCenter
            verticalAlignment: Qt.AlignVCenter
        }
        ToolButton {
            id: nextbutton
            text: qsTr("Suivant")
            enabled: nextEnable
            //onClicked: stack.push(footer.page)
            onClicked: footer.buttonClicked()
            Layout.rightMargin: parent.width/40
            Layout.preferredWidth: parent.width/12
            Layout.alignment: Qt.AlignRight
            background: Rectangle {
                radius:5
                anchors.fill: parent
                color : "dimgrey"
            }
        }
    }
}
