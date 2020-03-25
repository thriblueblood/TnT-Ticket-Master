#include "register.h"
#include "ui_register.h"
#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSql>
#include <QDebug>
#include <QString>
#include <QMessageBox>
#include <qdebug.h>
Register::Register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
}

Register::~Register()
{
    delete ui;
}

void Register::on_pushButton_cancel_clicked()
{
this->hide();
}

bool Register :: openDB(){
    QSqlDatabase data = QSqlDatabase::addDatabase("QSQLITE");
    data.setDatabaseName("/Users/thriblueblood/Desktop/C++ project/database.db");
    qDebug() << ("Status: ") << data.open() << endl;

    if(data.open() == true) {
        qDebug() << ("Connected....");
        return true;
    }
    else{
        qDebug() << ("Failend to open the database.");
        return false;
    }
}


void Register::closeDB(){
    data.close();
    data.removeDatabase(QSqlDatabase::defaultConnection);
}

void Register::on_pushButton_submit_clicked()
{
    QString username = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();
    QString confirm_password = ui->lineEdit_3->text();
    QString first_name = ui->lineEdit_4->text();
    QString surname = ui->lineEdit_5->text();
    QString birth = ui->lineEdit_6->text();
    QString address = ui->textedit_address->toPlainText();
    QString phone = ui->lineEdit_7->text();
    QString gender;
    if (ui->radioButton->isChecked()){
        gender = ui->radioButton->text();
    }

    if(ui->radioButton_2->isChecked()){
        gender = ui->radioButton_2->text();
    }

    if (username !="" && password!=""&& first_name!=""&&surname!=""&&birth!=""&& address!=""&&phone!="" && gender !="" && password == confirm_password){
        openDB();
        QSqlQuery qry;
        qry.prepare("select * from login_data where username='"+username +"'");
        if (qry.exec()) {
            int count = 0;
            QString name;
            while(qry.next()){
                count++;
                name = qry.value(2).toString();
            }
            if(count == 1)
                QMessageBox::warning(this,"Register","This username is already in use.");
            else {
                QMessageBox:: information(this,"Register","You have been successfully registered.", QMessageBox::Ok);
                qry.prepare("INSERT INTO login_data(username,password,first_name,surname,birth,address,mobile_phone,gender)""VALUES(?,?,?,?,?,?,?,?)");
                qry.addBindValue(username);
                qry.addBindValue(password);
                qry.addBindValue(first_name);
                qry.addBindValue(surname);
                qry.addBindValue(birth);
                qry.addBindValue(address);
                qry.addBindValue(phone);
                qry.addBindValue(gender);
                qry.exec();
                closeDB();
                this->hide();

            }
    }
    }
    else{
       QMessageBox :: warning(this,"Register","Please enter the details correctly!");
        }
        }


