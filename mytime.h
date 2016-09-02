#ifndef TIME_H
#define TIME_H

#include <QGraphicsTextItem>
#include <QString>

class MyTime: public QGraphicsTextItem
{
    Q_OBJECT
public:
    MyTime(QGraphicsItem* parent = NULL);

public slots:
    void setTime(int _time);

private:
    int time;
};

#endif // TIME_H
