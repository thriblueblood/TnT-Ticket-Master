#include "ed_sheeran.h"
#include "ui_ed_sheeran.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "mainwindow.h"
#include <QString>
#include "ed_seat.h"

ed_sheeran::ed_sheeran(QWidget *parent,QString username,QString con_name) :
    QDialog(parent),
    ui(new Ui::ed_sheeran)
{
    ui->setupUi(this);
    this->username = username;
    this->con_name = con_name;
    QSqlQuery query("SELECT name FROM concert_list WHERE concert_id = 1");
    QSqlQuery query1("SELECT venue FROM concert_list WHERE concert_id = 1");
    QSqlQuery query2("SELECT public_sale FROM concert_list WHERE concert_id = 1");
    QSqlQuery query3("SELECT date FROM concert_list WHERE concert_id = 1");
    while (query.next() && query1.next() && query2.next() && query3.next()){
    ui->label_name->setText(query.value(0).toString());
    ui->label_locate->setText(query1.value(0).toString());
    ui->label_time->setText(query2.value(0).toString());
    ui->label_calendar->setText(query3.value(0).toString());

//    connect(ui->label_stage,SIGNAL(sendMousePostion(QPoint&)),this,SLOT(showMousePosition(QPoint&)));

    }
}

ed_sheeran::~ed_sheeran()
{
    delete ui;
}



void ed_sheeran::on_pushButton_3_clicked()
{
    MainWindow *back = new MainWindow(nullptr,this->username);
    this->hide();
    back->show();
}

void ed_sheeran::on_pushButton_2_clicked()
{
    ed_seat *seat = new ed_seat(nullptr,this->username,this->con_name);
    this->hide();
    seat->show();

}
