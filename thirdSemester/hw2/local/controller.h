#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>

class Scene;
class LANController;

class Controller : public QObject
{
	Q_OBJECT
public:
	explicit Controller();
	~Controller();

	Scene *scene() const;


public slots:
	void pressed(int number);
	void doStep();

private:
	Scene *mScene;
	LANController *mController;
};

#endif // CONTROLLER_H
