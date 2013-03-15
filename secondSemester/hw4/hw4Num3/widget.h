#pragma once

#include <QtGui/QWidget>
#include <QtGui/QPushButton>
#include <QtCore/QSignalMapper>


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
    QSignalMapper* signalMapperNumb;
    QSignalMapper* signalMapperOpr;
    QString currentNumb;
    QString lastNumb;
    QString currentOpr;
    bool needToChangeNumb;
    Ui::Widget *ui;
private slots:
    void clickedNumb(const QString& numberStr);
    void clickedOpr(const QString& oprStr);
    void calculate();
};
