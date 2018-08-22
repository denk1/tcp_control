#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    workDB(ui)
{
    ui->setupUi(this);
    connect(&server, SIGNAL(commandRecieve(QString)), this, SLOT(handleCommand(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleButton()
{
    workDB.refresh_data("");
}

void MainWindow::handleCommand(QString data)
{
    qDebug() << "handleComand:" << data;
    workDB.refresh_data(data);
}
