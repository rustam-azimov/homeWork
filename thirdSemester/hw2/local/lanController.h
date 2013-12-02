#ifndef LANCONTROLLER_H
#define LANCONTROLLER_H

/**
 * @file lanController.h
 *
 * Implementation of LANController class. Contains all to simulate the lan network.
 */

#include <QList>
#include <QString>
#include <QStringList>

class AdjacencyMatrix;
class AntivirusBase;
class VirusController;
class Computer;

class OSFactory;

class LANController
{
public:
	LANController();
	~LANController();

	/// Adds the new computer to the network, with the os = operationSystem.
	void addComputer(const QString& operationSystem = "random");
	/// Connects the computer number = number with all computers from connectionList.
	void connectComputer(const int& number, const QList<int>& connectionList);
	/// Connects the computer number1 with the computer number2.
	void connectComputer(const int& number1, const int& number2);

	/// Returns the number of computers in the network.
	int numberOfComputers() const;
	/// Returns the os of the computer number = number.
	QString computerOS(const int& number) const;
	/// Returns the name of the computer number = number.
	QString computerName(const int& number) const;
	/// Returns the int list of the infected computers.
	QList<int> infectedComputers() const;
	/// Returns the int list of the number of viruses.
	QList<int> numberOfViruses();
	/// Returns QStringList of the computer names.
	QStringList computerNames() const { return mComputerNames; }

	/// Infect computer number = number.
	void infectComputer(const int& number);

	/**
	* Do one step, and returns the int list of two elements.
	* Element1 = number of infected computers.
	* Element2 = numer of cured computers.
	*/
	QList<int> nextStep();

	/// Returns the bool list of computers. Element = true, if Element.number = connected with number.
	QList<bool> connections(const int& number);

protected:
	int virusStep();
	int antivirusStep();
	QList<int> doStep();

	void standardLANCreator();

private:
	AdjacencyMatrix *mMatrix;
	QList<Computer* > mComputers;
	QStringList mComputerNames;

	AntivirusBase *mAntivirusBase;

	VirusController *mViruses;

	OSFactory *mOSFactory;
};

#endif // LANCONTROLLER_H
