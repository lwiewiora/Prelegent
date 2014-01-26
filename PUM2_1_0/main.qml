import QtQuick 2.0
import Sailfish.Silica 1.0
import "pages"


ApplicationWindow
{
    initialPage: Page {

        //ID i nazwa obiektu FirstPage
        id: pol
        objectName:  "pol3"
        //Sygnały zdefiniowane w celu obłsugi przycisków
        signal qmlSignal(string msg)                //sygnał wykorzystwany przy wysłaniu wiadomosci.
        signal qmlSignalStartClock ()               //sygnał wykorzystywany przy starcie zegara.
        signal qmlSignalTimerChange(string msg)     //sygnał wykorzystywany przy zmianie czasu zegara.


     SilicaFlickable {

        objectName: "flick"
        anchors.fill: parent

        //Przycisk umozliwiajcy wyslanie wiadomosci na serwer.
        Button
        {

            signal qmlSignal(string msg)
            id: item3
            objectName: "item3"
            text: "Wyślij wiadomość"

            x:150
            y:700

            MouseArea {
                anchors.fill: parent
                onClicked: pol.qmlSignal(txt1.text)
            }
        }

        //Pole tekstowe umożliwiające wpisanie wiadomosci do wysłania
        TextField
        {
            id: txt1
            objectName: "txtSend"
            scale: 1.0
            x:50
            y:630
            text: "Wyslij"
            color: "white"
        }


        //Pole tekstowe wyświetlające informacje z serwera.
        TextField
        {
            id:txt2
            objectName: "lblMsg"
            scale: 1.0
            x:50
            y:500
            text : LabelClass.msg
            color: "white"
            enabled: false
        }

        //Przycisk odpowiedzialny za start aplikacji.
        Button
        {
            id:startClock

            objectName: "startClock"
            scale:1.5
            x : 110
            y : 800
            text : LabelClock.btnName

            MouseArea {
                anchors.fill: parent
                onClicked: pol.qmlSignalStartClock()
            }

        }

        //Etykiety interfejsu
        Label
        {
            id:clock
            objectName: "clock"
            scale : 2.0
            x: 200
            y: 20
            text: LabelClock.time
            color : "lightgreen"

        }

        Label
        {
            text:"Komunikaty: "
            x:30
            y:460
        }

        Label
        {
            text:"Wyslij wiadomość: "
            x:30
            y:600
        }
        Label
        {
            id:lblLoud
            objectName: "lblLoud"
            x:60
            y:100
            text:"Głośniej"
            scale :2.0
        }
        Label
        {
            id:lblQuit
            objectName: "lblQuit"
            x:350
            y:100
            text:"Ciszej"
            scale :2.0
        }
        Label
        {
            id:lblFast
            objectName: "lblFast"
            x:60
            y:250
            text:"Szybciej"
            scale :2.0
        }
        Label
        {
            id:lblSlow
            objectName: "lblSlow"
            x:350
            y:250
            text:"Wolniej"
            scale :2.0
        }
        Label
        {
            id:lblNext
            objectName: "lblNext"
            x:180
            y:350
            text:"Zmień temat"
            scale :2.0
        }


        //Przycisk zmniejszania ustawionego czasu
        IconButton {

            id: decreaseTime;
            x: 30; y: 10;
            scale :0.5
            icon.source:  "image://theme/icon-cover-next";
            rotation: 180
            onClicked: {
                  pol.qmlSignalTimerChange("TimeDown")

            }
        }
        //Przycisk zwiekszania ustawionego czasu
        IconButton {

            id: increaseTime;
            x: 380; y: 10;
            scale :0.5 
            icon.source:  "image://theme/icon-cover-next";
            onClicked: {
                pol.qmlSignalTimerChange("TimeUp")
            }
        }

    }
  }
    cover: Qt.resolvedUrl("cover/CoverPage.qml")
}


