#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "client.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public:
    Ui::MainWindow *ui;
    Client client;
    bool loud;
    bool quit;
    bool fast;
    bool slow;
    bool next;

private slots:
    void on_buttonGlosniej_clicked();
    void on_buttonCiszej_clicked();
    void on_buttonSzybciej_clicked();
    void on_buttonWolniej_clicked();
    void on_buttonZmienTemat_clicked();
    void on_pushButton_clicked();
    void on_label_linkActivated(const QString &link);
    void on_textEdit_3_textChanged();
};

#endif // MAINWINDOW_H
