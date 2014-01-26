#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     client.connectToServer();
  //  ui->label->setText("SDASDSA");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_buttonGlosniej_clicked()
{
    //client.connectToServer();

    if(loud)
    {
        client.Send("#0");
        loud = false;
    }
    else
    {
        client.Send("#1");
        loud = true;
    }
}

void MainWindow::on_buttonCiszej_clicked()
{
    //client.connectToServer();

    if(quit)
    {
        client.Send("#2");
        quit = false;
    }
    else
    {
        client.Send("#3");
        quit = true;
    }
}

void MainWindow::on_buttonSzybciej_clicked()
{
    //client.connectToServer();

    if(fast)
    {
        client.Send("#5");
        fast = false;
    }
    else
    {
        client.Send("#4");
        fast = true;
    }
}

void MainWindow::on_buttonWolniej_clicked()
{
    //client.connectToServer();

    if(slow)
    {
        client.Send("#7");
        slow = false;
    }
    else
    {
        client.Send("#6");
        slow = true;
    }
}

void MainWindow::on_buttonZmienTemat_clicked()
{
    //client.connectToServer();

    if(next)
    {
        client.Send("#9");
        next = false;
    }
    else
    {
        client.Send("#8");
        next = true;
    }
}

void MainWindow::on_pushButton_clicked()
{
     client.connectToServer();
     QString msg = this->ui->textEdit->toPlainText();
     QString history  = this->ui->textEdit_2->toPlainText();
     history += "Desktop>> " + msg + "\r\n";
     this->ui->textEdit_2->setText(history);
     client.Send(msg);


}

void MainWindow::on_label_linkActivated(const QString &link)
{

}

void MainWindow::on_textEdit_3_textChanged()
{
    QString history  = this->ui->textEdit_2->toPlainText();
    history += "Sailfish>> " + this->ui->textEdit_3->toPlainText();
    this->ui->textEdit_2->setText(history);
}
