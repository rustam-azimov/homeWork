#ifndef OSFACTORY_H
#define OSFACTORY_H

/**
 * @file osFactory.h
 *
 * Implementation of OSFactory class. Creates and returns OS objects.
 */

#include <QString>
#include <QStringList>

class OS;

class OSFactory
{
public:
	OSFactory();

	/// Returns new OS object.
	OS *createOS(const QString& type = "random");

private:
	QStringList mAvailableOS;
};

#endif // OSFACTORY_H
