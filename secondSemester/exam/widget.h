
#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui/QWidget>
#include <QtGui/QPushButton>
#include <QtGui/QLineEdit>
#include <QtCore/QSignalMapper>
#include <QtGui/QFont>

#include "ticTacToeRules.h"

/**
 * @file widget.h
 *
 * Widget class to play tic-tac-toe game with graphics.
 */

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    
private:
    QSignalMapper *signalMapper;
    QPushButton *buttons[numOfButtons];
    QPushButton *endButton;
    Ui::Widget *ui;
    TicTacToeRules game;
    void buttonClicked(int numOfBtn);

private slots:
    void pushBtn(QString newChar);
};

#endif // WIDGET_H
