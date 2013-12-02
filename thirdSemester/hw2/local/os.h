#ifndef OS_H
#define OS_H

/**
 * @file os.h
 *
 * Contains diferent types of OS's.
 */

#include <QString>
#include <QStringList>

class OS
{
public:
	OS()
	{
	}

	QString name() const { return mName; }
	int safety() const { return mSafety; }

protected:
	QString mName;
	int mSafety;
};

class Linux : public OS
{
public:
	Linux()
	{
		mName = "Linux";
		mSafety = 100;
	}
};

class MacOS : public OS
{
public:
	MacOS()
	{
		mName = "MacOS";
		mSafety = 80;
	}
};

class Windows : public OS
{
public:
	Windows()
	{
		mName = "Windows";
		mSafety = 50;
	}
};

#endif // OS_H
