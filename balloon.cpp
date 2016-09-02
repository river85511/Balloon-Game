#include "balloon.h"

Balloon::Balloon(int _speed, QColor _color, QGraphicsItem *parent):
    speed(_speed),color(_color)
{
    this->setRect(0,0,80,80);

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(1);

}

Balloon::~Balloon()
{

    qDebug() << "DEL BALLOON!";
}

void Balloon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){

        emit increaseScore(speed);
        emit playPopSound();

        this->scene()->removeItem(this);
        delete this;
        return;
    }
}

void Balloon::setColor(QColor _color)
{
    color = _color;
    this->setBrush(color);
}

void Balloon::setSpeed(int _speed)
{
    speed = _speed;
    speedText = new QGraphicsTextItem(QString("%1").arg(speed),this);
    speedText->setScale(4);
    speedText->setPos(this->rect().width()/2 - speedText->boundingRect().width()*4/2, this->rect().height()/2 - speedText->boundingRect().height()*4/2);
}

void Balloon::move()
{
    this->setPos(this->pos().x(), this->pos().y() - speed*0.08 );

    if(this->pos().y() < (-100 )){
        this->scene()->removeItem(this);
        delete this;
        return;
    }

    return;
}

void Balloon::removeItself()
{
    this->scene()->removeItem(this);
    delete this;
    return;
}
