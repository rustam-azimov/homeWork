#ifndef COMPUTER_H
#define COMPUTER_H

/**
 * @file computer.h
 *
 * Implementation of computer class.
 */

#include <QSet>
#include <QString>

class AntivirusBase;
class OS;

class Computer
{
public:
	/// Creates new computer with mOS = os.
	Computer(OS *os);
	~Computer();

	/// Load the set of viruses on the computer.
	void loadViruses(QSet<int> &viruses);
	/// Load one virus on the computer.
	void loadViruses(const int& virus);

	/// Remove one virus from computer.
	void removeVirus(const int& virus);

	/// Returns the safety of computer os.
	int safety() const;

	/// Returns the os of the computer.
	QString os() const;

	///
	void nextStep();

	/// Returns the set of the computer viruses.
	QSet<int> viruses() const;
	/// Returns true, if the computer is infected.
	bool isInfected() const;
	/// Returns the number of the computer viruses.
	int numberOfViruses() const { return mOldViruses.size(); }

private:
	OS *mOS;

	QSet<int> mViruses;
	QSet<int> mOldViruses;
};

#endif // COMPUTER_H
