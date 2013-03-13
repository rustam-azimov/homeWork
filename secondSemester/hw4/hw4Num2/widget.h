#pragma once

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
public slots:
    void calculator();
private:
    Ui::Widget *ui;
};
