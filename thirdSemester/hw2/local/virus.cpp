#include "virus.h"

#include <QObject>

int const maxInitVirusPower = 30;
int const virusLuck = 10;

Virus::Virus(const int &type) :
	mType(type)
{
	setPower(qrand() % (maxInitVirusPower + 1) + virusLuck);
}

Virus::Virus(Virus * const& v1, Virus * const& v2, const int &type)
{
	if (!v1->canHybridize() || !v2->canHybridize()) {
		if (v1->power() > v2->power()) {
			setType(v1->type());
			setPower(v1->power());
		} else {
			setType(v2->type());
			setPower(v2->power());
		}
	} else {
		setType(type);
		setPower(hybridePower(v1->power(), v2->power()));
	}
}

void Virus::mutate()
{
	if (this->power() >= 60) {
		return;
	}

	setPower(this->power() + 1);
}

int Virus::hybridePower(const int &power1, const int &power2)
{
	bool goodLuck = qrand() % virusLuck;

	if (!goodLuck) {
		return ((power1 + power2) / 2);
	}

	int increase = qrand() % (VirusPower::hybridizeCoefficient + 1);
	return ((power1 > power2) ? (power1 + increase) : (power2 + increase));
}

void Virus::setPower(const int &power)
{
	if (power > VirusPower::max) {
		mPower = VirusPower::max;
	} else if (power < VirusPower::min) {
		mPower = VirusPower::min;
	} else {
		mPower = power;
	}

	mCanHybridize = (mPower > VirusPower::hybridizeBorder) ? true : false;
}

void Virus::setType(const int &type)
{
	mType = type;
}
