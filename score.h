#ifndef SCORE_H
#define SCORE_H

#include <QString>
#include <QGraphicsTextItem>

class Score: public QGraphicsTextItem
{
    Q_OBJECT
public:
    Score(QGraphicsItem* parent = NULL);

    int getScore();
public slots:
    void increaseScore(int _score);

private:
    int score;
};

#endif // SCORE_H
