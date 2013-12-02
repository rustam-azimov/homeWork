#ifndef VIRUSCONTROLLER_H
#define VIRUSCONTROLLER_H

/**
 * @file virusController.h
 *
 * Implementation of VirusController class. It contains information about all known viruses.
 */

#include <QList>

class Virus;

class VirusController
{
public:
	VirusController();
	~VirusController();

	int baseSize() const { return (mVirusCounter - 1); }

	/// Creates the new virus.
	int createNewVirus();

	/// Creates the new virus, which is a hybrid of the other two.
	int createHybridizeVirus(const int &number1, const int &number2);

	/// Returns the power of the virus. If the virus is unknown, returns -1.
	int virusPower(const int &number);

	void virusMutate(const int &number);

	int numberOfViruses() const { return mVirusBase.size(); }

private:
	QList<Virus *> mVirusBase;
	int mVirusCounter;
};

#endif // VIRUSCONTROLLER_H
