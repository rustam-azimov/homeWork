#include "widget.h"
#include "ui_widget.h"
#include <QString>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //this->setFixedSize(this->geometry().width(),this->geometry().height());
    signalMapper = new QSignalMapper(this);
    for (int i = 1; i <= 9; ++i) {
        QPushButton *button = new QPushButton(QString::number(i));
        connect(button, SIGNAL(clicked()), signalMapper, SLOT(map()));
        signalMapper->setMapping(button, QString::number(i));
        ui->gridLayout->addWidget(button, (i - 1) / 3, (i -1) % 3);
    }
    QPushButton* button = new QPushButton(QString::number(0));
    connect(button, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(button, QString::number(0));
    ui->gridLayout->addWidget(button, 3, 0);
    const int operatorsCount = 4;
        const char operators[operatorsCount] = {'+', '-', '*', '/'};
        for (int i = 0; i < operatorsCount; ++i)
            {
                QString bName = QChar(operators[i]);
                button = new QPushButton(bName);
                connect(button, SIGNAL(clicked()), signalMapper, SLOT(map()));
                signalMapper->setMapping(button, bName);
                ui->gridLayout->addWidget(button, i , 3);
            }
        connect(signalMapper, SIGNAL(mapped(const QString &)),
                this, SLOT(clicked(const QString &)));
        button = new QPushButton("=");
        connect(button, SIGNAL(clicked()), signalMapper, SLOT(map()));
        signalMapper->setMapping(button, "=");
        ui->gridLayout->addWidget(button, 3, 2);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::clicked(const QString &numberStr) {
    QString str = ui->lineEdit->text();
    str = str + numberStr;
    ui->lineEdit->setText(str);
}
