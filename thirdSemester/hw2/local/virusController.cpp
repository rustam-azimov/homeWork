#include "virusController.h"

#include "virus.h"

VirusController::VirusController() :
	mVirusCounter(0)
{
	Virus *nullVirus = new Virus(0);
	mVirusBase.append(nullVirus);
	mVirusCounter++;
}

VirusController::~VirusController()
{
	while (!mVirusBase.isEmpty()) {
		delete mVirusBase.takeFirst();
	}
}

int VirusController::createNewVirus()
{
	Virus *newVirus = new Virus(mVirusCounter);
	mVirusBase.append(newVirus);
	mVirusCounter++;

    return newVirus->type();
}

int VirusController::createHybridizeVirus(const int &number1, const int &number2)
{
	Virus *newVirus = new Virus(
			mVirusBase.at(number1)
			, mVirusBase.at(number2)
			, mVirusCounter
			);

	if (newVirus->type() == mVirusCounter) {
		mVirusBase.append(newVirus);
		mVirusCounter++;
	}

	return newVirus->type();
}

int VirusController::virusPower(const int &number)
{
	if ((number <= 0) || (number > mVirusCounter)) {
		return -1;
	}

	return (mVirusBase.at(number)->power());
}

void VirusController::virusMutate(const int &number)
{
	if (number == 0) {
		return;
	}

	mVirusBase.at(number)->mutate();
}
