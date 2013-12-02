#include "scene.h"

#include <qmath.h>

#include "circleItem.h"

const double myPi = 3.1415;
const double twoPi = 2 * myPi;

const int centerX = 250;
const int centerY = 250;

const int R = 200;

const int circleR = 25;

Scene::Scene(QObject *parent) :
	QGraphicsScene(parent)
{
	mInfected = 0;
	mCured = 0;

	QString string;
	string = "Click to the computer,\nto infect it.";

	QGraphicsTextItem *text = new QGraphicsTextItem(string);
	this->addItem(text);
	text->setPos(20, 50);

	double currArg = 0;

	for (int i = 0; i < 20; i++) {
		mList.append(new CircleItem(i));

		this->addItem(mList.at(i));

		mList.at(i)->setPos(centerX - R * cos(currArg), centerY - R * sin(currArg));

		connect(mList.at(i), SIGNAL(pressed(int)), this, SLOT(compPressed(int)));

		currArg += twoPi / 20;
	}
}

void Scene::setNames(const QStringList &list)
{
	for (int i = 0; i < list.size(); i++) {
		mList.at(i)->setText(list.at(i));
	}
}

void Scene::setConnection(const int &number, const QList<bool> &list)
{
	for (int i = 0; i < list.size(); i++) {
		if (list.at(i)) {
			this->addLine(mList.at(number)->x() + circleR
				, mList.at(number)->y() + circleR
				, mList.at(i)->x() + circleR
				, mList.at(i)->y() + circleR);
		}
	}
}

void Scene::setColor(const QList<int> &power)
{
	for (int i = 0; i < power.size(); i++) {
		mList.at(i)->setColor(power.at(i));
	}
}

void Scene::setStatistic(const QList<int> &stat)
{
	mInfected += stat.at(0);
	mCured += stat.at(1);
}


void Scene::compPressed(int number)
{
	mInfected++;

	emit pressed(number);
}
