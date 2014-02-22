import QtQuick 2.0
import Sailfish.Silica 1.0
import "pages"


ApplicationWindow
{
         id:app

    initialPage: Page {

        //ID i nazwa obiektu FirstPage
        id: pol
        property string formatedTime : "100";
        property bool timerWork: false;
        property int minutes: 0;
        property int seconds: 0;

        objectName:  "pol3"
        //Sygnały zdefiniowane w celu obłsugi przycisków
        signal qmlSignal(string msg)                //sygnał wykorzystwany przy wysłaniu wiadomosci.
        signal qmlSignalStartClock ()               //sygnał wykorzystywany przy starcie zegara.
        signal qmlSignalTimerChange(string msg)     //sygnał wykorzystywany przy zmianie czasu zegara.



     SilicaFlickable {

        objectName: "flick"
        anchors.fill: parent

        PullDownMenu {
            MenuItem {
                text: "Ustaw czas"
                onClicked: pageStack.push(pag)
            }
        }


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

        //Przycisk odpowiedzialny za start zegara.
        Button
        {
            id:startClock

            objectName: "startClock"
            scale:1.5
            x : 110
            y : 800
            text : "Rozpocznij prezentację" //LabelClock.btnName

            MouseArea {

                anchors.fill: parent
                onClicked: {
                    pol.timerWork = !pol.timerWork;
                    //pol.qmlSignalStartClock()
                    if(pol.timerWork == true)
                    {
                        mainTimer.start();
                        parent.text =  "Zakończ prezentację"
                    }
                    else
                        parent.text = "Rozpocznij prezentację"
                }
            }

        }

        //Etykiety interfejsu

        Rectangle
        {
            width:parent.width;
            height:30
            x:0
            y:40
            color:"transparent"
        Label
        {
            id:clock
            objectName: "clock"
            scale : 2.0
            anchors.centerIn: parent
            text: pol.formatedTime // LabelClock.time
            color : "lightgreen"

        }
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

/*
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
*/

        Item {

            scale : 2.0
            x: 200
            y: 20

            Timer {
                id:mainTimer
                interval: 1000; repeat: true
                onTriggered:
                {
                    if(pol.timerWork == true)
                    {
                        pol.seconds = pol.seconds - 1;
                        if(pol.seconds <0)
                        {
                            pol.minutes = pol.minutes -1;
                            pol.seconds = 59;
                        }
                        if(pol.minutes<0)
                        {
                            pol.seconds = 0;
                            pol.minutes = 0;

                            startClock.text = "Rozpocznij prezentację"
                            pol.timerWork = false;
                            mainTimer.stop();
                        }
                        pol.formatedTime = pol.minutes.toString() + " min. "+pol.seconds.toString()+" sek.";


                    }
                }
            }

            Text { id: time }
        }
    }
  }

   Page{

        id: pag
        objectName: "SetTimePage"
        signal qmlSignal(string msg)                //sygnał wykorzystwany przy wysłaniu wiadomosci.

        Rectangle
        {
            width:parent.width;
            height:30
            x:0
            y:140
            color:"transparent"
            Label
            {
                id:clockSet
                objectName: "clockSet"
                anchors.centerIn: parent
                scale : 2.0
                y: 20
                text: pol.formatedTime
                color : "lightgreen"
            }
        }

        Rectangle
        {
            width:parent.width;
            height:30
            x:0
            y:200
            color:"transparent"
            Label
            {
                scale:1.5
                anchors.centerIn: parent
                color : "lightblue"
                text: "Ustaw czas prezentacji"
            }
        }
        TimePicker {

            id:timeSet
            hour: 0
            minute: 0
            x:60
            y:300

            property int lastValue: 0;
            property int roznica: 0;
            property int curValue: 0
            property int round: 0
            onTimeChanged:
            {
                pol.minutes = timeSet.hour;
                pol.seconds = timeSet.minute;
                pol.formatedTime =  pol.minutes.toString() + " min. "+pol.seconds.toString()+" sek.";

            }

    }


        Rectangle
        {
            width:parent.width;
            height:30
            x:0
            y:800
            color:"transparent"
            Button
            {
                id: acceptTime

                objectName: "acceptTime"
                scale:1.5
                text : "Ustaw czas"
                anchors.centerIn: parent

                MouseArea
                {
                    anchors.fill: parent
                    onClicked: {
                        pageStack.pop();

                    }
                }

            }
        }

  }


    cover: Qt.resolvedUrl("cover/CoverPage.qml")
}


