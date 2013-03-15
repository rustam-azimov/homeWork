#include "widget.h"
#include "ui_widget.h"
#include <QString>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    currentNumb = "???";
    currentOpr = "???";
    lastNumb = "???";
    needToChangeNumb = false;
    signalMapperNumb = new QSignalMapper(this);
    for (int i = 1; i <= 9; ++i) {
        QPushButton *button = new QPushButton(QString::number(i));
        connect(button, SIGNAL(clicked()), signalMapperNumb, SLOT(map()));
        signalMapperNumb->setMapping(button, QString::number(i));
        ui->gridLayout->addWidget(button, (i - 1) / 3, (i -1) % 3);
    }
    QPushButton* button = new QPushButton(QString::number(0));
    connect(button, SIGNAL(clicked()), signalMapperNumb, SLOT(map()));
    signalMapperNumb->setMapping(button, QString::number(0));
    ui->gridLayout->addWidget(button, 3, 0);
    connect(signalMapperNumb, SIGNAL(mapped(const QString &)),
            this, SLOT(clickedNumb(const QString &)));
    const int operatorsCount = 4;
    const char operators[operatorsCount] = {'+', '-', '*', '/'};
    signalMapperOpr = new QSignalMapper(this);
    for (int i = 0; i < operatorsCount; ++i) {
        QString bName = QChar(operators[i]);
        button = new QPushButton(bName);
        connect(button, SIGNAL(clicked()), signalMapperOpr, SLOT(map()));
        signalMapperOpr->setMapping(button, bName);
        ui->gridLayout->addWidget(button, i , 3);
    }
    connect(signalMapperOpr, SIGNAL(mapped(const QString &)),
            this, SLOT(clickedOpr(const QString &)));
    button = new QPushButton("=");
    connect(button, SIGNAL(clicked()), this, SLOT(calculate()));
    ui->gridLayout->addWidget(button, 3, 2);
}

Widget::~Widget() {
    delete ui;
}

void Widget::clickedNumb(const QString &numberStr) {
    if(needToChangeNumb){
        lastNumb = ui->lineEdit->text();
        needToChangeNumb = false;
        ui->lineEdit->setText(numberStr);
    } else {
        QString str = ui->lineEdit->text();
        currentNumb = str + numberStr;
        ui->lineEdit->setText(currentNumb);
    }
}

void Widget::clickedOpr(const QString &oprStr) {
    calculate();
    needToChangeNumb = true;
    currentOpr = oprStr;
}

void Widget::calculate() {
    if ((lastNumb != "???")&&(currentNumb != "???")&&(currentOpr != "???"));
}
