#ifndef ED_SHEERAN_H
#define ED_SHEERAN_H

#include <QDialog>

namespace Ui {
class ed_sheeran;
}

class ed_sheeran : public QDialog
{
    Q_OBJECT

public:
    explicit ed_sheeran(QWidget *parent = nullptr,QString username="",QString con_name="");
    ~ed_sheeran();

private slots:

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ed_sheeran *ui;
    QString username,con_name;

};

#endif // ED_SHEERAN_H
