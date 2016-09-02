#ifndef BALLOON_H
#define BALLOON_H

#include <QGraphicsTextItem>
#include <QColor>
#include <QBrush>
#include <QPen>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>
#include <QObject>
#include <QTimer>
#include <QGraphicsEllipseItem>

#include <QDebug>

class Balloon: public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT
public:
    Balloon(int _speed = 1, QColor _color = QColor(0,0,0), QGraphicsItem *parent = NULL);
    ~Balloon();

    void mousePressEvent(QGraphicsSceneMouseEvent* event);

    void setColor(QColor _color);
    void setSpeed(int _speed);

public slots:
    void move();
    void removeItself();

signals:
    void increaseScore(int _speed);
    void playPopSound();

private:
    QTimer* timer;

    int speed;
    QGraphicsTextItem* speedText;

    QColor color;
};

#endif // BALLOON_H
