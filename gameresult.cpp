#include "gameresult.h"

GameResult::GameResult(int _score, QGraphicsItem *parent): QGraphicsRectItem(parent),
    score(_score)
{
    this->setRect(0,0,400,300);
    this->setBrush(QColor(0,0,0,50));

    QGraphicsTextItem* scoreText = new QGraphicsTextItem(this);
    scoreText->setPlainText(QString("SCORE: %1").arg(score));
    scoreText->setScale(4);
    scoreText->setPos(this->rect().width()/2 - scoreText->boundingRect().width()*4/2, 25);

    resetButton = new Button(QString("RESTART"),this);
    resetButton->setPos(this->rect().width()/2 - resetButton->rect().width()/2, 150);
    exitButton = new Button(QString("EXIT"),this);
    exitButton->setPos(this->rect().width()/2 - exitButton->rect().width()/2, 230);
}
