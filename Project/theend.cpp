#include "theend.h"
#include "ui_theend.h"
#include "mainwindow.h"

theEnd::theEnd(QWidget *parent,QString username) :
    QDialog(parent),
    ui(new Ui::theEnd)
{
    ui->setupUi(this);
    this->username = username;
}

theEnd::~theEnd()
{
    delete ui;
}

void theEnd::on_pushButton_clicked()
{
    MainWindow *main = new MainWindow(nullptr,this->username);
    this->hide();
    main->show();
}
