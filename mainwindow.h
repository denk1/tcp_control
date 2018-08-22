#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "workdb.h"
#include "serverthread.h"
#include "myserver.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void handleButton();
    void handleCommand(QString data);


private:
    Ui::MainWindow *ui;
    WorkDB workDB;
    MyServer server;

};

#endif // MAINWINDOW_H
