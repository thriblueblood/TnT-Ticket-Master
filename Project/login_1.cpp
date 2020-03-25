#include "login_1.h"
#include "ui_login_1.h"
#include <QPixmap>
#include <QMessageBox>
#include "register.h"
#include "mainwindow.h"

login_1::login_1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login_1)
{
    ui->setupUi(this);
    QPixmap pix(":/img/img/logo5.png");
    int width = ui->label_picture->width();
    int height = ui->label_picture->height();
    ui->label_picture->setPixmap(pix.scaled(width,height,Qt::KeepAspectRatio));
    ui->lineEdit_username->setPlaceholderText("Enter your Email");
    ui->lineEdit_password->setPlaceholderText("Enter your password");

}

login_1::~login_1()
{
    delete ui;
}

void login_1::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();
    Register db;

    db.openDB();
    QSqlQuery qry;
    qry.prepare("select * from login_data where username = '"+ username +"'and password='"+password+"'");
    if(qry.exec()){
        int count = 0;
        while(qry.next()){
            count++;
        }
        if (count==1){
            this->username = username;
            MainWindow *home = new MainWindow(nullptr,this->username);
            this->hide();
            home->show();
        }
        else{
             QMessageBox::warning(this,"Nope","Username or password are not correct!");
        }

    }
}


void login_1::on_pushButton_register_clicked()
{
    Register reg;
    reg.setModal(true);
    reg.exec();

}
