#ifndef GAME_H
#define GAME_H

#include <QColor>
#include <QTimer>
#include <QPointF>
#include <QKeyEvent>
#include <QWidget>
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>
#include <ctime>
#include <QMediaPlayer>
#include <QList>
#include <QGraphicsItem>
#include <QGraphicsTextItem>

#include "button.h"
#include "balloon.h"
#include "mytime.h"
#include "score.h"
#include "gameresult.h"

class Game: public QGraphicsView
{
    Q_OBJECT
public:
    Game(QWidget *parent = NULL);

    void keyPressEvent(QKeyEvent* event);

    void cleanScene();

public slots:

    void runGameMenu();
    void runGame();
    void runGameResult();

    void genBalloon();
    void countDown();

    void playPopSound();

signals:
    void removeAllBalloon();

private:
    QGraphicsScene *scene;

    QGraphicsTextItem* gameDisplay;
    Button * startButton;
    Button * exitButton;

    QTimer *countDownTimer;
    int countTime;
    MyTime *timeDisplay;

    QTimer *spawnTimer;
    Score* scoreDisplay;
    QMediaPlayer* popSound;


};

#endif // GAME_H
