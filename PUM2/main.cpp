#include "mainwindow.h"
#include <QApplication>
#include "client.h"
#include "server.h"
#include "ui_mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   // Client c;
    //c.connectToServer();

    MainWindow w;
    Server s(0,&w);
    s.listen();
    w.show();
    //Ui::MainWindow * t = w.ui;
    //w.ui->textEdit_3->setText("Sailfish");

    return a.exec();
}
