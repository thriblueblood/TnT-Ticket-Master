#ifndef PICTUR_DISPLAY_H
#define PICTUR_DISPLAY_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QMouseEvent>

class pictur_display : public QLabel
{
    Q_OBJECT
public:
    pictur_display(QWidget *parent = 0);



protected:

//    void mouseMoveEvent(QMouseEvent *mouse_event);
    void mousePressEvent(QMouseEvent *mouse_event);

signals:
    void sendMousePosition(QPoint&);


};

#endif // PICTUR_DISPLAY_H
