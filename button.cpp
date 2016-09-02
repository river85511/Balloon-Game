#include "button.h"

Button::Button(QString _name,QGraphicsItem *parent): QGraphicsRectItem(parent),
    name(_name),alpha(50),alphaWhenHover(150)
{
    this->setRect(0,0,200,50);

    textDisplay = new QGraphicsTextItem(this);
    textDisplay->setPlainText(name);
    textDisplay->setScale(3);

    textDisplay->setPos(this->rect().width()/2 - textDisplay->boundingRect().width()*3/2, this->rect().height()/2 - textDisplay->boundingRect().height()*3/2);

    color = QColor(200,10,10,alpha);
    this->setBrush(color);

    this->setAcceptHoverEvents(true);
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit clicked();
}

void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    color.setAlpha(alphaWhenHover);
    this->setBrush(color);
}

void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    color.setAlpha(alpha);
    this->setBrush(color);
}
