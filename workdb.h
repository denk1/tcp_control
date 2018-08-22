#ifndef WORKDB_H
#define WORKDB_H

#include "ui_mainwindow.h"

#include <QSqlDatabase>
#include <QDebug>
#include <QSql>
#include <QSqlQueryModel>

#include "subject.h"

class WorkDB : public QObject
{
    Q_OBJECT
public:
    explicit WorkDB(Ui::MainWindow* ptrUi, QObject *parent = 0);
    ~WorkDB();
    bool refresh_data(QString strData);
    bool query_db(QString str, QSqlQuery& sqlQuery);
    void get_parameters(const QString &strData, QVector<QString>& vStr);
public slots:
    void commandProcessing();


private:
    QString getValue(QSqlQuery& sqlQuery, uint idx);
    void output_subject(Subject& subject);
    bool init_db();
    QSqlDatabase db;
    Ui::MainWindow* ptr_Ui_;
    QSqlQueryModel model_;
};

#endif // WORKDB_H
