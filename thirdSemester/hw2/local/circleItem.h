#ifndef CIRCLEITEM_H
#define CIRCLEITEM_H

/**
 * @file circleItem.h
 *
 * Implementation of CircleItem class. Contains all to visualizite the computer.
 */

#include <QGraphicsEllipseItem>
#include <QString>

class CircleItem : public QObject, public QGraphicsEllipseItem
{
	Q_OBJECT
public:
	CircleItem(const int &number);

	void setColor(int power);
	void setText(const QString& text);

signals:
	void pressed(int number);

protected:
	void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
	int mNumber;
};

#endif // CIRCLEITEM_H
