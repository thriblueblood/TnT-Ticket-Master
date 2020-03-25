#include "pictur_display.h"
#include "stage_show.h"


pictur_display::pictur_display(QWidget* parent) : QLabel(parent)
{
//       this->setMouseTracking(true);
}

//void pictur_display::mouseMoveEvent(QMouseEvent *mouse_event)
//{
//    QPoint mouse_pos = mouse_event->pos();

//    if(mouse_pos.x() <= this->size().width() && mouse_pos.y() <= this->size().height()){
//        if(mouse_pos.x() >= 0 && mouse_pos.y() >= 0)
//        {
//            emit sendMousePosition(mouse_pos);
//        }
//    }
//}

void pictur_display::mousePressEvent(QMouseEvent *mouse_event)
{
    if(mouse_event->button() == Qt::LeftButton){
        stage_show pic;
        pic.setModal(true);
        pic.exec();
    }
}
