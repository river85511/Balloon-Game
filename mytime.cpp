#include "mytime.h"

MyTime::MyTime(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    this->setScale(3);
}

void MyTime::setTime(int _time)
{
    time = _time;
    this->setPlainText(QString("TIME: %1").arg(time));
}
