#ifndef SCENE_H
#define SCENE_H

/**
 * @file scene.h
 *
 * Implementation of Scene class. Contains the list of CircleItem objects.
 */

#include <QGraphicsScene>
#include <QStringList>
#include <QList>

class CircleItem;

class Scene : public QGraphicsScene
{
	Q_OBJECT
public:
	explicit Scene(QObject *parent = 0);

	void setNames(const QStringList& list);
	/// Add link between computer number = number and all true elements from the list.
	void setConnection(const int& number, const QList<bool>& list);
	void setColor(const QList<int>& power);
	void setStatistic(const QList<int>& stat);

signals:
	void pressed(int number);

protected slots:
	void compPressed(int number);

private:
	QList<CircleItem *> mList;
	QGraphicsTextItem *mStat;

	int mInfected;
	int mCured;
};

#endif // SCENE_H
