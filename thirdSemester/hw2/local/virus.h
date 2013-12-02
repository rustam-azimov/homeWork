#ifndef VIRUS_H
#define VIRUS_H

/**
 * @file virus.h
 *
 * Implementation of Virus class. Each virus has the strength and the type, and can mutate.
 */

namespace VirusPower {
const int min = 1;
const int max = 100;

const int maxMutate = 60;

const int hybridizeBorder = 30;
const int hybridizeCoefficient = 5;
}

class Virus
{
public:
	Virus(const int &type);
	/// Creates the new virus, hybrid of v1 and v2, if both can hybridize.
	Virus(Virus * const &v1, Virus * const &v2, const int &type);

	int power() const { return mPower; }
	int type() const { return mType; }
	bool canHybridize() const { return mCanHybridize; }

	/// Increases the virus power.
	void mutate();

protected:
	/**
	* Returns the new power of the hybridize power1 and power2.
	* In most cases it is more then power1 and power2,
	* but sometimes it can be between.
	*/
	int hybridePower(const int &power1, const int &power2);

	void setPower(const int &power);
	void setType(const int &type);

private:
	int mType;
	int mPower;

	bool mCanHybridize;
};

#endif // VIRUS_H
