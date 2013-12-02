#include "osFactory.h"

#include "os.h"

OSFactory::OSFactory()
{
	mAvailableOS.append("Linux");
	mAvailableOS.append("MacOS");
	mAvailableOS.append("Windows");
}

OS *OSFactory::createOS(const QString &type)
{
	if (type == "Linux") {
		OS *lin = new Linux;

		return lin;
	}

	if (type == "MacOS") {
		OS *macOS = new MacOS;

		return macOS;
	}

	if (type == "Windows") {
		OS *windows = new Windows;

		return windows;
	}

	if (type == "random") {
		OS *random = this->createOS(mAvailableOS.at( qrand() % 3 ));

		return random;
	}

	OS *byDefault = new Windows;
	return byDefault;
}
