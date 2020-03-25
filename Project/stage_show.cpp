#include "stage_show.h"
#include "ui_stage_show.h"

stage_show::stage_show(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stage_show)
{
    ui->setupUi(this);
}

stage_show::~stage_show()
{
    delete ui;
}

void stage_show::on_pushButton_clicked()
{
    this->hide();
}
