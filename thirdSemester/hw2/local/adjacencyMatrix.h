#ifndef ADJACENCYMATRIX_H
#define ADJACENCYMATRIX_H

/**
 * @file adjacencyMatrix.h
 *
 * Implementation of AdjacencyMatrix class. Contains all information about computer connections.
 */

#include <QList>

class AdjacencyMatrix
{
public:
	AdjacencyMatrix(const int& size);

	/// Returns the size of the network.
	int size() const;

	/// Adds the new computer to the network.
	void addComputer();
	/// Removes the computer from the network.
	void removeComputer(const int& number);

	/// Adds the new link between computer number1 and computer number2.
	void addLink(const int& number1, const int& number2);
	/// Removes the link between computer number1 and computer number2.
	void breakLink(const int& number1, const int& number2);

	/// Returns the bool list of computer connections.
	QList<bool> connectionList(const int& number) const;

	/// Returns true, if computer number1 and computer number2 is connected.
	bool isConnected(const int& number1, const int& number2) const;

private:
	QList<QList<bool> > mMatrix;
};

#endif // ADJACENCYMATRIX_H
