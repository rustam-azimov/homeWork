#ifndef ANTIVIRUSBASE_H
#define ANTIVIRUSBASE_H

/**
 * @file antivirusBase.h
 *
 * Implementation of AntivirusBase class. Contains the known types of viruses, and the antivirus power.
 */

#include <QList>

namespace AntivirusPower {
int const max = 101;

int const learnSpeed = 3;
}

class AntivirusBase
{
public:
	AntivirusBase();

	/// Adds new virus to the antivirus base.
	void addVirus(const int& number);

	/// Returns true, if the virus is known.
	bool isVirusKnown(const int& number) const;
	/// Returns the power of antivirus against virus with number = number.
	int antivirusPower(const int& number) const;

	/// Increase antivirus power against virus number = number.
	void powerUp(const int& number);

private:
	QList<int> mAntivirusList;
	QList<int> mAntivirusPowerList;

	int mAntivirusCounter;
};

#endif // ANTIVIRUSBASE_H
