#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login_1.h"
#include <QDebug>
#include "register.h"
#include "QSqlQuery"
#include <QSqlQueryModel>
#include "ed_sheeran.h"
#include "ariana_grande.h"
#include "history.h"
#include "the_vamps.h"
#include "savage.h"

MainWindow::MainWindow(QWidget *parent,QString username) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->username = username;
    Register reg;
    reg.openDB();
    QSqlQuery query("SELECT username FROM login_data where username ='"+username+"'");
    while(query.next()){
        ui->label_6->setText("Welcome, "+query.value(0).toString()+"!");
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    ed_sheeran *ed = new ed_sheeran(nullptr,this->username,QString("Ed Sheeran"));
    this->hide();
    ed->show();



}

void MainWindow::on_pushButton_2_clicked()
{
    ariana_grande *ariana = new ariana_grande(nullptr,this->username,QString("Ariana Grande"));
    this->hide();
    ariana->show();
}

void MainWindow::on_pushButton_6_clicked()
{
    history *order = new history(nullptr,this->username);
    order->setModal(true);
    order->exec();
}

void MainWindow::on_pushButton_7_clicked()
{
    login_1 *login = new login_1();
    this->hide();
    login->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    the_vamps *vamps= new the_vamps(nullptr,this->username,QString("The Vamps"));
    this->hide();
    vamps->show();
}

void MainWindow::on_pushButton_4_clicked()
{
    savage *sav= new savage(nullptr,this->username,QString("21 Savage"));
    this->hide();
    sav->show();
}
