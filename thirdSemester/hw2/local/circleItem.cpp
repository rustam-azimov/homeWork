#include "circleItem.h"

#include <QBrush>

CircleItem::CircleItem(const int& number) :
	mNumber(number)
{
	this->setZValue(1000);
	this->setRect(0, 0, 50, 50);
}

void CircleItem::setColor(int power)
{
	if (power > 50) {
		power = 50;
	}

	if (power < 0) {
		power = 0;
	}

	QColor color(5 * power, 250 - 5 * power, 0);

	QBrush brush;
	brush.setStyle(Qt::SolidPattern);
	brush.setColor(color);

	this->setBrush(brush);
}

void CircleItem::setText(const QString& text)
{
	QGraphicsTextItem *textItem = new QGraphicsTextItem(text, this);

	textItem->setPos(6, 15);
}

void CircleItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	emit pressed(mNumber);
}

