#include <QString>
#include <QSqlQuery>
#include "workdb.h"
#include "subject.h"

WorkDB::WorkDB(Ui::MainWindow *ptrUi, QObject *parent):QObject(parent),
    db(QSqlDatabase::addDatabase("QPSQL", "localhost")),
    ptr_Ui_(ptrUi)
{
    if(!init_db())
    {
        qDebug() << "error initialization of database connection";
        exit(-1);
    }
}

WorkDB::~WorkDB()
{

}


bool WorkDB::refresh_data(QString strData)
{
    Subject subject;
    QVector<QString> vecString;
    get_parameters(strData, vecString);
    const QString sQueryInsert = "insert into subject(length, height, width, property_id, type_id)"
                             "values(" + vecString[0] + ","
                               + vecString[1] + ","
                               + vecString[2] + ","
                               + vecString[3] + ","
                               + vecString[4] + ")";
    subject.setHeght(vecString[0].toUInt());
    subject.setLength(vecString[1].toUInt());
    subject.setWidth(vecString[2].toUInt());

    // inserting new data
    QSqlQuery queryInsert(db);
    query_db(sQueryInsert, queryInsert);

    // selecting type
    QSqlQuery querySelectType(db);
    query_db("SELECT type_name FROM type_subject WHERE type_id=" + vecString[3], querySelectType);
    subject.setType(getValue(querySelectType, 0));

    // selecting property
    QSqlQuery querySelectProperty(db);
    query_db("SELECT name FROM properties WHERE property_id=" + vecString[4], querySelectProperty);
    subject.setProperty(getValue(querySelectProperty, 0));

    // observing refresh data
    QSqlQuery querySelect(db);
    query_db("SELECT * FROM subject", querySelect);
    model_.setQuery(querySelect);
    ptr_Ui_->tableView->setModel(&model_);
    output_subject(subject);
    return true;
}

bool WorkDB::query_db(QString str, QSqlQuery &sqlQuery)
{
    sqlQuery.prepare(str);
    if(sqlQuery.exec())
    {
        qDebug() << str << " : " << " - ok ";
    }
    else
    {
        qDebug() << str << " : " << " - error ";
    }
}

void WorkDB::get_parameters(const QString& strData, QVector<QString> &vStr)
{
    QStringList list = strData.split(QRegExp("\\s+"), QString::SkipEmptyParts);
    QVector<QString> vecString;
    foreach( QString str, list)
    {
      vStr.push_back(str);
    }
}

void WorkDB::commandProcessing()
{
    refresh_data("");
}

QString WorkDB::getValue(QSqlQuery &sqlQuery, uint idx)
{
    QString strRes;
    while (sqlQuery.next())
    {
        strRes = sqlQuery.value(0).toString();
    }
    return strRes;
}

void WorkDB::output_subject(Subject &subject)
{
    ptr_Ui_->label_height->setText(QString::number(subject.getHeight()));
    ptr_Ui_->label_length->setText(QString::number(subject.getLength()));
    ptr_Ui_->label_width->setText(QString::number(subject.getWidth()));
    ptr_Ui_->label_property->setText(subject.getProperty());
    ptr_Ui_->label_type->setText(subject.getType());
}

bool WorkDB::init_db()
{
    db.setHostName("localhost");
    db.setDatabaseName("test_nami_db");
    db.setUserName("postgres");
    db.setPassword("123123");
    bool ok = db.open();
    qDebug() << ok;
    return ok;
}
