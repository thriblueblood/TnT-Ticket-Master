#ifndef LOGIN_1_H
#define LOGIN_1_H

#include <QDialog>

namespace Ui {
class login_1;
}

class login_1 : public QDialog
{
    Q_OBJECT

public:
    explicit login_1(QWidget *parent = nullptr);
    ~login_1();


private slots:
    void on_pushButton_login_clicked();
    void on_pushButton_register_clicked();

private:
    Ui::login_1 *ui;
    QString username;
};

#endif // LOGIN_1_H
