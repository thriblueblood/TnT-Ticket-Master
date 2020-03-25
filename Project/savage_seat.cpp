#include "savage_seat.h"
#include "ui_savage_seat.h"
#include <register.h>
#include "payment.h"
#include <QMessageBox>
#include "mainwindow.h"

savage_seat::savage_seat(QWidget *parent,QString username,QString con_name) :
    QDialog(parent),
    ui(new Ui::savage_seat)
{
    ui->setupUi(this);
    ui->comboBox_zone->addItem("A");
    ui->comboBox_zone->addItem("B");
    ui->comboBox_zone->addItem("C");
    ui->comboBox_seat->addItem("1");
    ui->comboBox_seat->addItem("2");
    ui->comboBox_seat->addItem("3");
    ui->comboBox_seat->addItem("4");
    ui->comboBox_seat->addItem("5");
    this->username = username;
    this->con_name = con_name;
}

void savage_seat::checked_seat(){
   QString seat_type = ui->comboBox_zone->currentText();
   QString seat_seat = ui->comboBox_seat->currentText();
   Register db;
   db.openDB();
   QSqlQuery query("SELECT seat FROM ticket_savage WHERE type = '"+seat_type+"'");
   while (query.next()){
       this->current_seat = query.value(0).toInt();

   ui->number_seat->setText("Available ="+query.value(0).toString());}
   db.closeDB();
}

savage_seat::~savage_seat()
{
    delete ui;
}

void savage_seat::on_comboBox_zone_currentTextChanged(const QString &arg1)
{
    checked_seat();
}

void savage_seat::on_pushButton_clicked()
{
   QString seat_type = ui->comboBox_zone->currentText();
   QString seat_seat = ui->comboBox_seat->currentText();
   payment *pay = new payment(this, seat_type, seat_seat,this->current_seat,4,this->username,this->con_name);
   this->hide();
   pay->show();

}

void savage_seat::on_pushButton_2_clicked()
{
    QMessageBox::StandardButtons answer;
    answer = QMessageBox::question(this,"Select seat","Return to main menu?",QMessageBox::Yes | QMessageBox::No);

    if(answer == QMessageBox::Yes){
        MainWindow *main = new MainWindow(nullptr,this->username);
        this->hide();
        main->show();
    }
}

