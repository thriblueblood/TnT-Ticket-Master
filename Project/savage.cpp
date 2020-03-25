#include "savage.h"
#include "ui_savage.h"
#include <QSqlQuery>
#include "mainwindow.h"
#include "savage_seat.h"

savage::savage(QWidget *parent,QString username,QString con_name) :
    QDialog(parent),
    ui(new Ui::savage)
{
    ui->setupUi(this);
    this->username = username;
    this->con_name = con_name;
    QSqlQuery query("SELECT name FROM concert_list WHERE concert_id = 4");
    QSqlQuery query1("SELECT venue FROM concert_list WHERE concert_id = 4");
    QSqlQuery query2("SELECT public_sale FROM concert_list WHERE concert_id = 4");
    QSqlQuery query3("SELECT date FROM concert_list WHERE concert_id = 4");
    while (query.next() && query1.next() && query2.next() && query3.next()){
    ui->label_name->setText(query.value(0).toString());
    ui->label_locate->setText(query1.value(0).toString());
    ui->label_time->setText(query2.value(0).toString());
    ui->label_calendar->setText(query3.value(0).toString());}
}

savage::~savage()
{
    delete ui;
}

void savage::on_pushButton_2_clicked()
{
    savage_seat *seat = new savage_seat(nullptr,this->username,this->con_name);
    this->hide();
    seat->show();
}

void savage::on_pushButton_3_clicked()
{
    MainWindow *back = new MainWindow(nullptr,this->username);
    this->hide();
    back->show();
}
