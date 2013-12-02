#ifndef ROBOGRAPH_H
#define ROBOGRAPH_H

/**
 * @file RoboGraph.h
 *
 * Implementation of RoboGraph class.
 * Determine, whether there is a sequence of teleportations,
 * in which all robots self-destruct.
 */

#include <QVector>

class RoboGraph
{
public:
	RoboGraph(const int& size);

	/// Adds one robot. If vertex > number of verteces in graph, does nothing.
	void addRobot(const int& vertex);
	/// Adds link between vertex1 and vertex2. If vertex1 or vertex2 > number of verteces in graph, does nothing.
	void addLink(const int& vertex1, const int& vertex2);

	enum RobotContain {
		noRobot = false,
		hasRobot = true
	};
	/// Returns true, if all robots can self-destruct, otherwise returns false.
	bool isAllRobotDestroyed();

private:
	QVector<QVector<bool> > mAdjacencyMatrix;

	QVector<bool> mIsRobotSet;

	int mSize;
};

#endif // ROBOGRAPH_H
