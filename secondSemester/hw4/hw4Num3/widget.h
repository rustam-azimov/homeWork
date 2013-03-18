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
    QSignalMapper* signalMapperNumb;
    QSignalMapper* signalMapperOpr;
    /// @param rightNumb - right operand number.
    QString rightNumb;
    /// @param leftNumb - left operand number.
    QString leftNumb;
    /// @param currentOpr - current operator.
    QString currentOpr;
    bool needToChangeNumb;
    bool isHaveDot;
    Ui::Widget *ui;
private slots:
    /// Return all parameters in they start states.
    void clear();
    void clickedNumb(const QString& numberStr);
    void clickedOpr(const QString& oprStr);
    void clickedDot();
    void calculate();
};
