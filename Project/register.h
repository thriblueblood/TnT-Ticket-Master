#ifndef REGISTER_H
#define REGISTER_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSql>
#include <QDebug>
#include <QString>
namespace Ui {
class Register;
}

class Register : public QDialog
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();
    bool openDB();
    void closeDB();
    QSqlDatabase data;

private slots:
    void on_pushButton_cancel_clicked();

    void on_pushButton_submit_clicked();



private:
    Ui::Register *ui;

};

#endif // REGISTER_H
