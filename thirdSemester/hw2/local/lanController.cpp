#include "lanController.h"

#include "adjacencyMatrix.h"
#include "antivirusBase.h"
#include "computer.h"
#include "osFactory.h"
#include "virusController.h"

const int standartLANSize = 5;

LANController::LANController() :
	mMatrix(new AdjacencyMatrix(standartLANSize)),
	mAntivirusBase(new AntivirusBase),
	mViruses(new VirusController),
	mOSFactory(new OSFactory)
{
	standardLANCreator();
}

LANController::~LANController()
{
	delete mMatrix;

	while (!mComputers.isEmpty()) {
		delete mComputers.takeFirst();
	}

	delete mAntivirusBase;
	delete mViruses;
	delete mOSFactory;
}

void LANController::addComputer(const QString &operationSystem)
{
	Computer *newComputer = new Computer( mOSFactory->createOS(operationSystem) );

	mComputers.append(newComputer);
	mMatrix->addComputer();

	mComputerNames.append(newComputer->os());
}


void LANController::connectComputer(const int &number, const QList<int> &connectionList)
{
	if (number > mMatrix->size()) {
		return;
	}

	for (int i = 0; i < connectionList.size(); i++) {
		mMatrix->addLink(number, connectionList.at(i));
	}
}

void LANController::connectComputer(const int &number1, const int &number2)
{
	if (number1 > mMatrix->size() || number2 > mMatrix->size()) {
		return;
	}

	mMatrix->addLink(number1, number2);
}

int LANController::numberOfComputers() const
{
	return mMatrix->size();
}

QString LANController::computerOS(const int &number) const
{
	if (number > this->numberOfComputers()) {
		return QString("no computer");
	}

	return mComputers.at(number)->os();
}

QString LANController::computerName(const int &number) const
{
	if (number > this->numberOfComputers()) {
		return QString("no computer");
	}

	return mComputerNames.at(number);
}

QList<int> LANController::infectedComputers() const
{
	QList<int> infected;

	for (int i = 0; i < this->numberOfComputers(); i++) {
		if (mComputers.at(i)->isInfected()) {
			infected.append(i);
		}
	}

	return infected;
}

QList<int> LANController::numberOfViruses()
{
	QList<int> list;

	for (int i = 0; i < mMatrix->size(); i++) {
		list.append(mComputers.at(i)->numberOfViruses());
	}

	return list;
}

QList<int> LANController::doStep()
{
	int infected = 0;
	if ( qrand() % 3 ) {
		infected = virusStep();
	}
	int cured = antivirusStep();
	if ( qrand() % 2 ) {
		cured += antivirusStep();
	}

	for (int i = 0; i < mMatrix->size(); i++) {
		mComputers.at(i)->nextStep();
	}

	QList<int> list;
	list.append(infected);
	list.append(cured);

	return list;
}

void LANController::infectComputer(const int &number)
{
	if (number > this->numberOfComputers()) {
		return;
	}

	mComputers.at(number)->loadViruses( mViruses->createNewVirus() );
}

QList<int> LANController::nextStep()
{
	QList<int> result;
	result.append(0);
	result.append(0);

	for (int i = 0; i < 10; i++) {
		QList<int> temp = doStep();

		result[0] += temp[0];
		result[1] += temp[1];
	}

	return result;
}

QList<bool> LANController::connections(const int &number)
{
	return mMatrix->connectionList(number);
}

int LANController::virusStep()
{
	int sender = qrand() % mMatrix->size();
	int counter = 0;

	QList<bool> possibleVictims = mMatrix->connectionList(sender);
	QList<int> viruses = mComputers.at(sender)->viruses().toList();
	if (viruses.size() == 0) {
		return 0;
	}

	bool noNewViruses = qrand() % 10;

	if (!noNewViruses) {
		int newVirus = mViruses->createNewVirus();
		mComputers[sender]->loadViruses(newVirus);

		mAntivirusBase->addVirus(newVirus);
	}

	int loadingVirus = viruses.at( qrand() % viruses.size() );

	for (int i = 0; i < possibleVictims.size(); i++) {
		if (possibleVictims.at(i)) {
			int power = (mComputers[i]->safety()
					* mAntivirusBase->antivirusPower(loadingVirus)
					/ 50)
					- mViruses->virusPower(loadingVirus);

			int infectChance = qrand() % 10;

			if (power < 0) {
				infectChance += 25;
			}

			bool isInfected = (qrand() % 100) < infectChance;

			if (isInfected) {
				mComputers[i]->loadViruses(loadingVirus);
				counter++;
			} else {
				mAntivirusBase->powerUp(loadingVirus);
			}
		}
	}

	if (counter) {
		mViruses->virusMutate(loadingVirus);
	}

	return counter;
}

int LANController::antivirusStep()
{
	int counter = 0;

	for (int i = 0; i < mMatrix->size(); i++) {
		QList<int> viruses = mComputers.at(i)->viruses().toList();

		for (int j = 0; j < viruses.size(); j++) {
			int currentVirus = viruses.at(j);

			if (mAntivirusBase->antivirusPower(currentVirus)
					> mViruses->virusPower(currentVirus)) {
				mComputers.at(i)->removeVirus(currentVirus);
				counter++;
			} else {
				mAntivirusBase->powerUp(currentVirus);
			}
		}
	}

	return counter;
}

void LANController::standardLANCreator()
{
	for (int i = 0; i < standartLANSize; i++) {
		mComputers.append(new Computer(mOSFactory->createOS()));
		mComputerNames.append(mComputers.at(i)->os());
	}

	for (int i = 0; i < standartLANSize; i++) {
		mMatrix->addLink(i, qrand() % standartLANSize);
	}
}
