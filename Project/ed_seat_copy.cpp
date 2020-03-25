#include "ed_seat.h"
#include "ui_ed_seat.h"
#include "register.h"
#include <QString>
#include "payment.h"

ed_seat::ed_seat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ed_seat)
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
}

void ed_seat::checked_seat(){
   QString seat_type = ui->comboBox_zone->currentText();
   QString seat_seat = ui->comboBox_seat->currentText();
   Register db;
   db.openDB();
   QSqlQuery query("SELECT seat FROM ticket WHERE type = '"+seat_type+"'");
   while (query.next()){
       this->current_seat = query.value(0).toInt();

   ui->number_seat->setText("Available ="+query.value(0).toString());}
   db.closeDB();
}


ed_seat::~ed_seat()
{
    delete ui;
}

void ed_seat::on_comboBox_zone_currentTextChanged(const QString &arg1)
{
    checked_seat();
}

void ed_seat::on_pushButton_clicked()
{
   QString seat_type = ui->comboBox_zone->currentText();
   QString seat_seat = ui->comboBox_seat->currentText();
   qDebug() << this->current_seat;
   payment *pay = new payment(this, seat_type, seat_seat,this->current_seat);
   this->hide();
   pay->show();

}
