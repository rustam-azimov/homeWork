#include <QApplication>

#include <QGraphicsView>
#include <QTime>

#include "controller.h"
#include "scene.h"

int main(int argc, char *argv[])
{
	qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));

	QApplication a(argc, argv);

	Controller viewController;

	QGraphicsView view;
	view.setScene(viewController.scene());
	view.show();

	return a.exec();
}
