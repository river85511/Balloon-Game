#include "score.h"

Score::Score(QGraphicsItem *parent): score(0)
{
    this->setPlainText(QString("SCORE: %1").arg(score));
    this->setScale(3);
}

int Score::getScore()
{
    return score;
}

void Score::increaseScore(int _score)
{
    score += _score;
    this->setPlainText(QString("SCORE: %1").arg(score));
}
