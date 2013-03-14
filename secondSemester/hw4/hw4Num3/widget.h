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
    QSignalMapper *signalMapper;
    Ui::Widget *ui;
private slots:
    void clicked(const QString & numberStr);
    //void calculate(const QString & numberStr);
};
