#include <QGuiApplication>
#include <QQuickView>
#include <QQuickItem>
#include <Qt3DExtras/Qt3DWindow>
#include "animator.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQuickView view;

    view.resize(800, 800);
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.setSource(QUrl("qrc:/main.qml"));
    view.show();

    // entities are accessed by objectName, not by id!
    Qt3DCore::QTransform *transform = view.rootObject()->findChild<Qt3DCore::QTransform*>("sphereTransform");

    Q_ASSERT(transform);
    Animator a(transform, &view, 0.01);

    return app.exec();
}
