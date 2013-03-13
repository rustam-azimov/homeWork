#include "widget.h"
#include <QString>
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget) {
    ui->setupUi(this);
    connect(ui->leftValueSpinBox, SIGNAL(valueChanged(int)), this, SLOT(calculator()));
    connect(ui->rightValueSpinBox, SIGNAL(valueChanged(int)), this, SLOT(calculator()));
    connect(ui->operatorComboBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(calculator()));
}

Widget::~Widget() {
    delete ui;
}

void Widget::calculator() {
    int leftValue = ui->leftValueSpinBox->value();
    int rightValue = ui->rightValueSpinBox->value();
    QString opr = ui->operatorComboBox->currentText();
    double result;
    if (opr == "+")
        result = leftValue + rightValue;
    if(opr == "-")
        result = leftValue - rightValue;
    if (opr == "*")
        result = leftValue * rightValue;
    if (opr == "/") {
        if(rightValue == 0) {
            ui->resultLineEdit->setText("???");
            return;
        }
        result = (double)leftValue / rightValue;
    }
    QString resultString;
    resultString.setNum(result, 'f', 6);
    ui->resultLineEdit->setText(resultString);
    return;
}
