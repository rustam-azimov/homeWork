#include "roboGraph.h"

#include <QQueue>

#include <QDebug>

RoboGraph::RoboGraph(const int& size) :
	mSize(size)
{
	mAdjacencyMatrix.fill(QVector<bool>(), mSize);
	for (int i = 0; i < mSize; i++) {
		mAdjacencyMatrix[i].fill(false, mSize);
	}

	mIsRobotSet.fill(noRobot, mSize);
}

void RoboGraph::addRobot(const int &vertex)
{
	if (vertex >= mSize) {
		return;
	}

	mIsRobotSet[vertex] = hasRobot;
}

void RoboGraph::addLink(const int &vertex1, const int &vertex2)
{
	if (vertex1 >= mSize || vertex2 >= mSize) {
		return;
	}

	mAdjacencyMatrix[vertex1][vertex2] = true;
	mAdjacencyMatrix[vertex2][vertex1] = true;
}

bool RoboGraph::isAllRobotDestroyed()
{
	int robotsAmount = 0;

	for (int i = 0; i < mSize; i++) {
		if (mIsRobotSet[i] == hasRobot) {
			robotsAmount++;
		}
	}

	if (robotsAmount == 1) {
		return false;
	}

	QVector<bool> visitedVertices;
	visitedVertices.fill(false, mSize);

	visitedVertices[0] = true;

	QQueue<int> listOfVisitedVertices;
	listOfVisitedVertices.enqueue(0);

	int firstAmount = 0;

	if (mIsRobotSet[0] == hasRobot) {
		firstAmount++;
	}

	while (!listOfVisitedVertices.isEmpty()) {
		int current = listOfVisitedVertices.head();
		listOfVisitedVertices.dequeue();

		for (int i = 0; i < mSize; i++) {
			if (!mAdjacencyMatrix[i][current]) {
				continue;
			}

			for (int j = 0; j < mSize; j++) {
				if (!mAdjacencyMatrix[i][j]) {
					continue;
				}

				if (!visitedVertices[j]) {
					visitedVertices[j] = true;
					listOfVisitedVertices.enqueue(j);

					if (mIsRobotSet[j] == hasRobot) {
						firstAmount++;
					}
				}
			}

		}
	}

	if ((firstAmount == 1) || ((robotsAmount - firstAmount) == 1)) {
		return false;
	}

	return true;
}
