#include "animator.h"
#include <cmath>

Animator::Animator(Qt3DCore::QTransform *transform, QObject *parent, float speed)
    : QObject(parent), transform_(transform), time_(0.0), fps_(60), xCoord(0.0), speedX(speed)
{
    setObjectName("Animator");
    timer_ = new QTimer(this);
    connect(timer_, &QTimer::timeout, this, &Animator::update);
    timer_->start(1000.0 / fps_);
}

void Animator::update()
{
    xCoord -= speedX;
    time_ += 1.0 / fps_;
    const qreal r = 1.0, a = 2.0, b = 0.4, w = 0.8;
    qreal z = a * fabs(sin(w * 2 * M_PI * time_)) - b;
    qreal s = (r + 0.5 * fmin(0, z)) / r;
    transform_->setTranslation(QVector3D(xCoord, 0, r + z));
}
