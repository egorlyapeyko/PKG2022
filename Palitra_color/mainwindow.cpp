#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QColorDialog>
#include <colormath.h>
QStringList variable_colors;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(Window);
    this->chosenColor = Qt::white;

    variable_colors  << "RGB-HSV-HSL";

    this->Current_Clr->setAutoFillBackground(true);
    this->Current_Clr->setFixedSize(200,200); // РАЗМЕР ОКОШКА ЦВЕТ

    this->hexx->setFixedSize(200,50); // РАЗМЕРЫ КНОПОК
    this->Button_Color->setFixedSize(200,40);



    Input();



    this->Models->setFixedSize(200,50);

    this->Models->addItems(variable_colors);
    connect(this->Models,SIGNAL(activated(int)),SLOT(ChooseModels(int)));
    connect(this->Button_Color,SIGNAL(clicked()),SLOT(ChooseColor()));

}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent*)
{
    QPalette palit;
    palit.setColor(Current_Clr->backgroundRole(),this->chosenColor);
    Current_Clr->setPalette(palit);
}

void MainWindow::Input()
{
    QVBoxLayout *ly_up = new QVBoxLayout;
    QVBoxLayout *ly = new QVBoxLayout;
    _Up->addWidget(Current_Clr);


    ly_up->addWidget(this->hexx);
    ly_up->addWidget(this->Button_Color);

    _Up->addLayout(ly_up);
    _Up->addWidget(Models);
    _Up->setAlignment(Qt::AlignmentFlag::AlignLeft);


    ly->addLayout(_Up);
    ly->addLayout(_Down);
    Window->setLayout(ly);
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress && obj == this->Current_Clr)
    {
        ChooseColor();
        return true;
    }
    return false;
}

void MainWindow::ChooseColor()
{
    QColorDialog *RGB = new QColorDialog;
    this->chosenColor = RGB->getColor();
    this->hexx->setText(this->chosenColor.name());
}

