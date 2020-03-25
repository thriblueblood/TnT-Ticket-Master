#include "payment.h"
#include "ui_payment.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <register.h>
#include <QSqlQuery>
#include "ed_seat.h"
#include <QString>
#include<QSqlError>
#include<login_1.h>
#include "theend.h"
#include <QDebug>

payment::payment(QWidget *parent, QString zone, QString seat, int current_seat,int order,QString username,QString con_name) :
    QDialog(parent),
    ui(new Ui::payment)
{
    ui->setupUi(this);
    this->current_seat = current_seat;
    this->order = order;
    this->zone = zone;
    this->seat = seat;
    this->username = username;
    this->con_name = con_name;

    ui->label_price->setText(zone);
    int price =0,seat_number;
    if (zone == "A"){
        price = 4500;
    }
    if (zone == "B"){
        price = 2500;
    }
    if (zone == "C"){
       price = 1500;
    }
    seat_number =seat.toInt();
    int total_number = price*seat_number;
    QString total = QString::number(total_number);

    QString detail = "Zone "+zone+" for "+seat+" ticket(s) : "+total+" Bahts" ;
    ui->label_price->setText(detail);
    qDebug() << "Show order: " << order;


}

payment::~payment()
{
    delete ui;
}

void payment::on_pushButton_2_clicked()
{
 QMessageBox::StandardButtons answer;
 answer = QMessageBox::question(this,"Make payment","Return to main menu?",QMessageBox::Yes | QMessageBox::No);

 if(answer == QMessageBox::Yes){
     MainWindow *main = new MainWindow(nullptr,this->username);
     this->hide();
     main->show();
 }

}

void payment::on_pushButton_clicked()
{

//    Register db;
//    db.openDB();
//    int s = seat.toInt();
//    int left_seat = current_seat - s;
//    QSqlQuery query("UPDATE ticket SET seat = " +QString::number(left_seat)+ " WHERE type = '" + zone + "'");
//    QSqlQuery query1("INSERT INTO order_history VALUES ( '" +this->username +"','"+this->con_name +"','"+zone+"','"+seat+"')");
//    query.exec();
//    qDebug() << query.lastError();
//    db.closeDB();
//    theEnd *end = new theEnd(nullptr,this->username);
//    this->hide();
//    end->show();

    QString number = ui->lineEdit->text();
    QString name = ui->lineEdit_2->text();
    QString exp = ui->lineEdit_4->text();
    QString cvv = ui->lineEdit_5->text();

    if(number !=" "&&name!=""&&exp!=""&&cvv!=""){
        Register db;
        db.openDB();
        int s = seat.toInt();
        int left_seat = current_seat - s;
        if (order == 1){
        QSqlQuery query("UPDATE ticket SET seat = " +QString::number(left_seat)+ " WHERE type = '" + zone + "'");
        QSqlQuery query1("INSERT INTO order_history VALUES ( '" +this->username +"','"+this->con_name +"','"+zone+"','"+seat+"')");
          query.exec();
          db.closeDB();
          theEnd *end = new theEnd(nullptr,this->username);
          this->hide();
          end->show();
    }
        if(order == 2){
            QSqlQuery query("UPDATE ticket_ariana SET seat = " +QString::number(left_seat)+ " WHERE type = '" + zone + "'");
            QSqlQuery query1("INSERT INTO order_history VALUES ( '" +this->username +"','"+this->con_name +"','"+zone+"','"+seat+"')");
              query.exec();
              db.closeDB();
              theEnd *end = new theEnd(nullptr,this->username);
              this->hide();
              end->show();
    }
        if(order == 3){
            QSqlQuery query("UPDATE ticket_vamps SET seat = " +QString::number(left_seat)+ " WHERE type = '" + zone + "'");
            QSqlQuery query1("INSERT INTO order_history VALUES ( '" +this->username +"','"+this->con_name +"','"+zone+"','"+seat+"')");
              query.exec();
              db.closeDB();
              theEnd *end = new theEnd(nullptr,this->username);
              this->hide();
              end->show();}
        if(order == 4){
            QSqlQuery query("UPDATE ticket_savage SET seat = " +QString::number(left_seat)+ " WHERE type = '" + zone + "'");
            QSqlQuery query1("INSERT INTO order_history VALUES ( '" +this->username +"','"+this->con_name +"','"+zone+"','"+seat+"')");
              query.exec();
              db.closeDB();
              theEnd *end = new theEnd(nullptr,this->username);
              this->hide();
              end->show();}
//        QSqlQuery query("UPDATE ticket SET seat = " +QString::number(left_seat)+ " WHERE type = '" + zone + "'");
//        QSqlQuery query_ariana("UPDATE ticket_ariana SET seat = " +QString::number(left_seat)+ " WHERE type = '" + zone + "'");
//        QSqlQuery query_vamps("UPDATE ticket_vamps SET seat = " +QString::number(left_seat)+ " WHERE type = '" + zone + "'");
//        QSqlQuery query_savage("UPDATE ticket_savage SET seat = " +QString::number(left_seat)+ " WHERE type = '" + zone + "'");
//        QSqlQuery query1("INSERT INTO order_history VALUES ( '" +this->username +"','"+this->con_name +"','"+zone+"','"+seat+"')");
//        query.exec();
//        query_ariana.exec();
//        query_vamps.exec();
//        query_savage.exec();
//        qDebug() << query.lastError();
//        db.closeDB();
//        theEnd *end = new theEnd(nullptr,this->username);
//        this->hide();
//        end->show();
    }
    else{
        QMessageBox::critical(this,"Warning","Error");
    }


}
