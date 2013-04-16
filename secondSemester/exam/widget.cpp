#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    signalMapper(new QSignalMapper(this))
{
    ui->setupUi(this);

    endButton = new QPushButton(" ", this);
    endButton->move(162, 144);
    endButton->setVisible(false);

    for (int i = 0; i < numOfButtons; i++)
    {
        buttons[i] = new QPushButton(" ", this);
        buttons[i]->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        ui->gridLayout->addWidget(buttons[i], i / 3, (i % 3) + 2);
    }
    for (int i = 0; i < numOfButtons; i++)
    {
        signalMapper->setMapping(buttons[i], QString::number(i));
        connect(buttons[i], SIGNAL(clicked()), signalMapper, SLOT(map()));
    }

    connect(signalMapper, SIGNAL(mapped(QString)), this, SLOT(pushBtn(QString)));
}

Widget::~Widget()
{
    delete[] buttons;
    delete endButton;
    delete signalMapper;
    delete ui;
}


void Widget::pushBtn(QString newChar)
{
    buttonClicked(newChar.toInt());

    if (game.isWin() == 0)
        return;
    if (game.isWin() == 1)
    {
        endButton->setText("Player 1 WIN!");
    }
    if (game.isWin() == -1)
    {
        endButton->setText("Player 2 WIN!");
    }
    if (game.isWin() == 2)
    {
        endButton->setText("DRAW!");
    }

    for (int i = 0; i < numOfButtons; i++)
        buttons[i]->setEnabled(false);

    endButton->setVisible(true);
}

void Widget::buttonClicked(int numOfBtn)
{
    QString sign = game.setSign(numOfBtn);
    buttons[numOfBtn]->setText(sign);
    buttons[numOfBtn]->setEnabled(false);
}
