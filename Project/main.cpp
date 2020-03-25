#include "mainwindow.h"
#include "login_1.h"
#include <QApplication>
#include <QSplashScreen>
#include <QTimer>
#include "ed_sheeran.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSplashScreen *intro = new QSplashScreen;
    intro->setPixmap(QPixmap(":/img/img/intro.png"));
    intro->show();

    login_1 login;
    QTimer::singleShot(3000,intro,SLOT(close()));
    QTimer::singleShot(3000,&login,SLOT(show()));

    return a.exec();
}
