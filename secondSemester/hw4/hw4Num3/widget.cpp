#include "widget.h"
#include "ui_widget.h"
#include <QString>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    rightNumb = "???";
    currentOpr = "???";
    leftNumb = "???";
    needToChangeNumb = false;
    isHaveDot = false;
    QPushButton* button = new QPushButton("C");
    connect(button, SIGNAL(clicked()),
             this, SLOT(clear()));
    ui->gridLayout->addWidget(button, 0, 3);
    signalMapperNumb = new QSignalMapper(this);
    for (int i = 1; i <= 9; ++i) {
        QPushButton *button = new QPushButton(QString::number(i));
        connect(button, SIGNAL(clicked()), signalMapperNumb, SLOT(map()));
        signalMapperNumb->setMapping(button, QString::number(i));
        ui->gridLayout->addWidget(button, (i - 1) / 3 + 1, (i -1) % 3);
    }
    button = new QPushButton(QString::number(0));
    connect(button, SIGNAL(clicked()), signalMapperNumb, SLOT(map()));
    signalMapperNumb->setMapping(button, QString::number(0));
    ui->gridLayout->addWidget(button, 4, 0);
    connect(signalMapperNumb, SIGNAL(mapped(const QString &)),
            this, SLOT(clickedNumb(const QString &)));
    button = new QPushButton(".");
    ui->gridLayout->addWidget(button, 4, 1);
    connect(button, SIGNAL(clicked()),
            this, SLOT(clickedDot()));
    const int operatorsCount = 4;
    const char operators[operatorsCount] = {'+', '-', '*', '/'};
    signalMapperOpr = new QSignalMapper(this);
    for (int i = 0; i < operatorsCount; ++i) {
        QString bName = QChar(operators[i]);
        button = new QPushButton(bName);
        connect(button, SIGNAL(clicked()), signalMapperOpr, SLOT(map()));
        signalMapperOpr->setMapping(button, bName);
        ui->gridLayout->addWidget(button, i + 1 , 3);
    }
    connect(signalMapperOpr, SIGNAL(mapped(const QString &)),
            this, SLOT(clickedOpr(const QString &)));
    button = new QPushButton("=");
    connect(button, SIGNAL(clicked()), this, SLOT(calculate()));
    ui->gridLayout->addWidget(button, 4, 2);
}

Widget::~Widget() {
    delete signalMapperNumb;
    delete signalMapperOpr;
    delete ui;
}

void Widget::clear() {
    rightNumb = "???";
    currentOpr = "???";
    leftNumb = "???";
    needToChangeNumb = false;
    isHaveDot = false;
    ui->lineEdit->setText("");
}

void Widget::clickedNumb(const QString &numberStr) {
    if(needToChangeNumb){
        isHaveDot = false;
        leftNumb = ui->lineEdit->text();
        needToChangeNumb = false;
        rightNumb = numberStr;
        ui->lineEdit->setText(rightNumb);
    } else {
        QString str = ui->lineEdit->text();
        rightNumb = str + numberStr;
        ui->lineEdit->setText(rightNumb);
    }
}

void Widget::clickedOpr(const QString &oprStr) {
    calculate();
    needToChangeNumb = true;
    currentOpr = oprStr;
}

void Widget::clickedDot() {
    if(!isHaveDot) {
        isHaveDot = true;
        QString str = ui->lineEdit->text();
        str = str + ".";
        ui->lineEdit->setText(str);
    }
}

void Widget::calculate() {
    if ((leftNumb != "???")&&(rightNumb != "???")&&(currentOpr != "???")) {
        float leftValue = leftNumb.toFloat();
        float rightValue = rightNumb.toFloat();
        float result = 0;
        switch ((char)*currentOpr.toLatin1()) {
        case '+': {
            result = leftValue + rightValue;
            break;
        }
        case '-': {
            result = leftValue - rightValue;
            break;
        }
        case '*': {
            result = leftValue * rightValue;
            break;
        }
        case '/': {
            result = leftValue / rightValue;
            break;
        }
        }
        if (result == (int)result) {
            isHaveDot = false;
        }
        else {
            isHaveDot = true;
        }
        leftNumb = QString::number(result);
        rightNumb = "???";
        ui->lineEdit->setText(leftNumb);
    }
}
