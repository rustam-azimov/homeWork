#include "computer.h"

#include "antivirusBase.h"
#include "os.h"

Computer::Computer(OS *os) :
	mOS(os)
{
}

Computer::~Computer()
{
	delete mOS;
	mOS = NULL;
}

void Computer::loadViruses(QSet<int> &viruses)
{
	mViruses.unite(viruses);
}

void Computer::loadViruses(const int &virus)
{
	mViruses.insert(virus);
}

void Computer::removeVirus(const int &virus)
{
	mViruses.remove(virus);
}

int Computer::safety() const
{
	return mOS->safety();
}

QString Computer::os() const
{
	return mOS->name();
}

QSet<int> Computer::viruses() const
{
	return mOldViruses;
}

bool Computer::isInfected() const
{
	return (this->numberOfViruses() == 0);
}


void Computer::nextStep()
{
	mOldViruses = mViruses;
}
