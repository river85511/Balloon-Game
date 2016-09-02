#ifndef BUTTON_H
#define BUTTON_H

#include <QColor>
#include <QBrush>
#include <QString>
#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSceneHoverEvent>

class Button:public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Button(QString _name = QString("DEFAULT"), QGraphicsItem* parent = NULL);

    void mousePressEvent(QGraphicsSceneMouseEvent* event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent* event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent* event);

signals:
    void clicked();

private:
    QString name;
    QGraphicsTextItem* textDisplay;

    QColor color;
    int alpha;
    int alphaWhenHover;
};

#endif // BUTTON_H
