import QtQuick 2.0
import QtQuick.Window 2.0
import QtQuick.Controls 2.15 as Controls
import org.kde.kirigami 2.4 as Kirigami

Kirigami.ApplicationWindow
{
    color: "black"

    Controls.Label {
        text: "Test text"
        font.pointSize: 40
    }
}
