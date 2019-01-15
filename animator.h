#ifndef ANIMATOR_H
#define ANIMATOR_H

#include <QObject>
#include <QTransform>
#include <QTimer>

class Animator : public QObject
{
    Q_OBJECT
public:
    explicit Animator(Qt3DCore::QTransform *transform, QObject *parent = 0, float speed=0.1);
    float xCoord;
    float speedX;

public slots:
    void update();


private:
    Qt3DCore::QTransform *transform_;
    qreal time_;
    int fps_;
    QTimer *timer_;
};

#endif // ANIMATOR_H
