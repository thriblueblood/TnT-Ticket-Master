#ifndef SAVAGE_H
#define SAVAGE_H

#include <QDialog>

namespace Ui {
class savage;
}

class savage : public QDialog
{
    Q_OBJECT

public:
    explicit savage(QWidget *parent = nullptr,QString username="",QString con_name="");
    ~savage();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::savage *ui;
    QString username,con_name;
};

#endif // SAVAGE_H
