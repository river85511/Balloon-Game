#include "game.h"

Game::Game(QWidget *parent): QGraphicsView(parent)
{
    scene = new QGraphicsScene(this);
    this->setScene(scene);
    this->setSceneRect(0,0,800,600);

    this->setFixedSize(800,600);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    this->setBackgroundBrush(QColor(255,171,0,25));

    srand(time(NULL));

    runGameMenu();


}

void Game::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Escape){
        this->close();
    }
}

void Game::cleanScene()
{
    QList<QGraphicsItem* > itemList = scene->items();
    foreach(QGraphicsItem* item, itemList){
        scene->removeItem(item);
        delete item;
    }
}

void Game::runGameMenu()
{
    gameDisplay = new QGraphicsTextItem(QString("BALLOON\n    GAME"));
    gameDisplay->setScale(4);
    gameDisplay->setPos(this->sceneRect().width()/2 - gameDisplay->boundingRect().width()*4/2,75);
    scene->addItem(gameDisplay);

    startButton = new Button(QString("START"));
    startButton->setPos(this->sceneRect().width()/2 - startButton->rect().width()/2, 380);
    connect(startButton,SIGNAL(clicked()),this,SLOT(runGame()));
    scene->addItem(startButton);

    exitButton = new Button(QString("EXIT"));
    exitButton->setPos(this->sceneRect().width()/2 - exitButton->rect().width()/2, 480);
    connect(exitButton,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(exitButton);
}

void Game::runGame()
{
    qDebug() << "GAME START";
    cleanScene();

        this->setBackgroundBrush(QColor(255,171,0,25));
        countDownTimer = new QTimer();
        connect(countDownTimer,SIGNAL(timeout()),this,SLOT(countDown()));

        spawnTimer = new QTimer();
        connect(spawnTimer,SIGNAL(timeout()),this,SLOT(genBalloon()));

        timeDisplay = new MyTime();
        countTime = 30;
        timeDisplay->setTime(countTime);
        scene->addItem(timeDisplay);

        scoreDisplay = new Score();
        scoreDisplay->setPos(0,60);
        scene->addItem(scoreDisplay);

        popSound = new QMediaPlayer();
        popSound->setMedia(QUrl("qrc:/sounds/pop.wav"));

        countDownTimer->start(1000);
        spawnTimer->start(500);
}

void Game::runGameResult()
{
    GameResult* gameResult = new GameResult(scoreDisplay->getScore());
    gameResult->setPos(this->sceneRect().width()/2 - gameResult->rect().width()/2, this->sceneRect().height()/2 - gameResult->rect().height()/2);
    connect(gameResult->resetButton,SIGNAL(clicked()),this,SLOT(runGame()));
    connect(gameResult->exitButton,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(gameResult);
}

void Game::genBalloon()
{
    qDebug() << "GEN BALLOON!";
    Balloon* balloon = new Balloon();
    connect(balloon,SIGNAL(increaseScore(int)),scoreDisplay,SLOT(increaseScore(int)));
    connect(balloon,SIGNAL(playPopSound()),this,SLOT(playPopSound()));
    connect(this,SIGNAL(removeAllBalloon()),balloon,SLOT(removeItself()));
        int randSpeed = (rand()%9) + 1;
        balloon->setSpeed(randSpeed);

        int randXMax = this->sceneRect().width() - balloon->rect().width();
        QPointF randPos = QPointF(rand()%randXMax, this->sceneRect().height());
        balloon->setPos(randPos);

        QColor randColor = QColor(rand()%255,rand()%255,rand()%255,200);
        balloon->setColor(randColor);
    scene->addItem(balloon);
}

void Game::countDown()
{
    if(countTime != 0)
    {
        countTime--;
        timeDisplay->setTime(countTime);
        return;
    }
    else
    {
        timeDisplay->setTime(countTime);
        countDownTimer->stop();
        spawnTimer->stop();

        emit removeAllBalloon();
        runGameResult();
    }
}

void Game::playPopSound()
{
    if(popSound->state() == QMediaPlayer::PlayingState){
        popSound->setPosition(0);
    }else if(popSound->state() == QMediaPlayer::StoppedState){
        popSound->play();
    }
}
