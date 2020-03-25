#include "history.h"
#include "ui_history.h"
#include <QSqlQueryModel>
#include <QTableView>
#include <register.h>

history::history(QWidget *parent,QString username) :
    QDialog(parent),
    ui(new Ui::history)
{
    ui->setupUi(this);
    this->username = username;
    this->show_data();
}

history::~history()
{
    delete ui;
}

void history::show_data(){
    Register db;
    db.openDB();
    QSqlQueryModel *modal = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT *FROM order_history where username='"+ this->username+ "'");
    query.exec();
    qDebug() << "SELECT *FROM order_history where username='"+ this->username+ "'";
    modal->setQuery(query);
    ui->tableView->setModel(modal);
}
