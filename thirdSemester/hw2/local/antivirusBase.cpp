#include "antivirusBase.h"

AntivirusBase::AntivirusBase() :
	mAntivirusCounter(0)
{
	mAntivirusList.append(0);
	mAntivirusPowerList.append(AntivirusPower::max);

	mAntivirusCounter++;
}

void AntivirusBase::addVirus(const int &number)
{
	if (isVirusKnown(number)) {
		return;
	}

	mAntivirusList.append(number);
	mAntivirusPowerList.append(15);

	mAntivirusCounter++;
}

bool AntivirusBase::isVirusKnown(const int &number) const
{
	return (mAntivirusList.contains(number));
}

int AntivirusBase::antivirusPower(const int &number) const
{
	if (!isVirusKnown(number)) {
		return -1;
	}

	return (mAntivirusPowerList.at(mAntivirusList.indexOf(number)));
}

void AntivirusBase::powerUp(const int &number)
{
	if (!isVirusKnown(number)) {
		return;
	}

	mAntivirusPowerList[mAntivirusList.indexOf(number)] += AntivirusPower::learnSpeed;
}
