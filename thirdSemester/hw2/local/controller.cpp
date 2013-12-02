#include "controller.h"

#include <QTimer>

#include "scene.h"
#include "lanController.h"

Controller::Controller() :
	mScene(new Scene),
	mController(new LANController)
{
	connect(mScene, SIGNAL(pressed(int)), this, SLOT(pressed(int)));

	for (int i = 0; i < 15; i++) {
		mController->addComputer();
	}

	mScene->setNames(mController->computerNames());

	QList<int> list;
	for (int i = 0; i < 20; i++) {
		list.append(0);
	}

	for (int i = 0; i < 40; i++) {
		int r1 = qrand() % 20;
		int r2 = qrand() % 20;
		mController->connectComputer(r1, r2);
	}

	for (int i = 0; i < 20; i++) {
		mScene->setConnection(i, mController->connections(i));
	}

	mScene->setColor(list);

	QTimer *timer = new QTimer;
	connect(timer, SIGNAL(timeout()), this, SLOT(doStep()));

	timer->start(50);
}

Controller::~Controller()
{
	delete mScene;
	mScene = NULL;

	delete mController;
	mController = NULL;
}

Scene *Controller::scene() const
{
	return mScene;
}

void Controller::pressed(int number)
{
	mController->infectComputer(number);
}

void Controller::doStep()
{
	QList<int> stat = mController->nextStep();

	mScene->setColor(mController->numberOfViruses());
	mScene->setStatistic(stat);
}
