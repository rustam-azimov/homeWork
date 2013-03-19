#pragma once
#include "calculator.h"

 /**
 * @file widget.h
 *
 * @section DESCRIPTION
 *
 * Widget class realization.
 */

#include <QtGui/QWidget>
#include <QtGui/QPushButton>
#include <QtCore/QSignalMapper>


namespace Ui {
class Widget;
}
/// Widget class.
class Widget : public QWidget {
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    
private:
    Calculator calculator;
    QSignalMapper* signalMapper;
    Ui::Widget *ui;
private slots:
    /// Return all parameters in they start states.
    void clear();
    void clicked(const QString& str);
    void calculate();
};
