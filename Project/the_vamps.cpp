#include "the_vamps.h"
#include "ui_the_vamps.h"
#include <QSqlQuery>
#include "mainwindow.h"
#include <vamps_seat.h>

the_vamps::the_vamps(QWidget *parent,QString username,QString con_name) :
    QDialog(parent),
    ui(new Ui::the_vamps)
{
    ui->setupUi(this);
    this->username = username;
    this->con_name = con_name;
    QSqlQuery query("SELECT name FROM concert_list WHERE concert_id = 3");
    QSqlQuery query1("SELECT venue FROM concert_list WHERE concert_id = 3");
    QSqlQuery query2("SELECT public_sale FROM concert_list WHERE concert_id = 3");
    QSqlQuery query3("SELECT date FROM concert_list WHERE concert_id = 3");
    while (query.next() && query1.next() && query2.next() && query3.next()){
    ui->label_name->setText(query.value(0).toString());
    ui->label_locate->setText(query1.value(0).toString());
    ui->label_time->setText(query2.value(0).toString());
    ui->label_calendar->setText(query3.value(0).toString());
}
}

the_vamps::~the_vamps()
{
    delete ui;
}

void the_vamps::on_pushButton_2_clicked()
{
    vamps_seat *seat = new vamps_seat(nullptr,this->username,this->con_name);
    this->hide();
    seat->show();
}

void the_vamps::on_pushButton_3_clicked()
{
    MainWindow *back = new MainWindow(nullptr,this->username);
    this->hide();
    back->show();
}


