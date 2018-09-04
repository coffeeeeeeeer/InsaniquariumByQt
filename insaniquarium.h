#ifndef INSANIQUARIUM_H
#define INSANIQUARIUM_H

#include "pixmapsmaker.h"
#include "menubtn.h"
#include "fishfactory.h"
#include "foodfactory.h"
#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QColor>
#include <QPixmap>
#include <QTime>
#include <QTimer>

class Insaniquarium : public QGraphicsView
{
    Q_OBJECT

public:
    Insaniquarium(QWidget *parent = nullptr);
    // show start menu
    void showMenu();
    void mousePressEvent(QMouseEvent *event);
    void addFood(const QPointF &pos);

public slots:
    // game start
    void slt_start();
    // next level
    void slt_nextLevel(int);
    // game over
    void slt_gameOver();
    // update scene
    void slt_update();
    // food eaten by fish or out of screen
    void slt_foodReduce();

signals:

private:
    QGraphicsScene *m_scene;
    // bg images
    QPixmap m_bgGamePix;
    QPixmap m_bgMenuPix;

    QPixmap m_startGameBtnPix;

    int m_maxFoodCount;
    int m_currentFoodCount;

    int m_foodLevel;
    int m_maxFoodLevel;

    QTimer * m_timer;

    bool m_alienAttack;
    bool m_gaming;

    int m_step;

};

#endif // INSANIQUARIUM_H
