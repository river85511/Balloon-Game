#ifndef GAMERESULT_H
#define GAMERESULT_H

#include <QBrush>
#include <QColor>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QObject>
#include <QString>

#include "button.h"

class GameResult: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    GameResult(int _score = 0, QGraphicsItem* parent = NULL);

    int score;

    Button *resetButton;
    Button *exitButton;
};

#endif // GAMERESULT_H
