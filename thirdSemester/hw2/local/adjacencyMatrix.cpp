#include "adjacencyMatrix.h"

AdjacencyMatrix::AdjacencyMatrix(const int &size)
{
	for (int i = 0; i < size; i++) {
		mMatrix.append(QList<bool>());
		for (int j = 0; j < size; j++) {
			mMatrix[i].append(false);
		}
	}
}

int AdjacencyMatrix::size() const
{
	return mMatrix.size();
}

void AdjacencyMatrix::addComputer()
{
	int size = this->size();

	for (int i = 0; i < size; i++) {
		mMatrix[i].append(false);
	}

	mMatrix.append(QList<bool>());
	size = this->size();

	for (int i = 0; i < size; i++) {
		mMatrix[size - 1].append(false);
	}
}

void AdjacencyMatrix::removeComputer(const int &number)
{
	int size = this->size();

	if (number >= size) {
		return;
	}

	for (int i = 0; i < size; i++) {
		mMatrix[i].removeAt(number);
	}

	mMatrix.removeAt(number);
}

void AdjacencyMatrix::addLink(const int &number1, const int &number2)
{
	int size = this->size();

	if ((number1 >= size) || (number2 >= size)) {
		return;
	}

	mMatrix[number1][number2] = true;
	mMatrix[number2][number1] = true;
}

void AdjacencyMatrix::breakLink(const int &number1, const int &number2)
{
	int size = this->size();

	if ((number1 >= size) || (number2 >= size)) {
		return;
	}

	mMatrix[number1][number2] = false;
	mMatrix[number2][number1] = false;
}

QList<bool> AdjacencyMatrix::connectionList(const int &number) const
{
	if (number >= this->size()) {
		return QList<bool>();
	}

	return mMatrix.at(number);
}

bool AdjacencyMatrix::isConnected(const int &number1, const int &number2) const
{
	if ((number1 >= this->size()) || (number2 >= this->size())) {
		return false;
	}

	return mMatrix[number1][number2];
}
