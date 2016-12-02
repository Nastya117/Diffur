#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::Start);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Simple_DU()
{
    ui->label->setText("Здесь могла быть ваша математика по СимплДу");
}

void MainWindow::Multiple_DU()
{
    ui->label->setText("Здесь могла быть ваша математика по МультиплДу");
}

void MainWindow::Line_DU()
{
    ui->label->setText("Здесь могла быть ваша математика по ЛайнДу");
}

void MainWindow::Bernulli_DU()
{
    ui->label->setText("Здесь могла быть ваша математика по БернуллиДу (Верблюжий регистр)");
}

void MainWindow::Full_DU()
{
    ui->label->setText("Здесь могла быть ваша математика по ФулДу");
}

void MainWindow::Start()
{
    if (ui->comboBox->currentText() == "Простейшее ДУ I порядка")
        Simple_DU();

    if (ui->comboBox->currentText() == "ДУ с разделяющимися переменными I порядка")
        Multiple_DU();

    if (ui->comboBox->currentText() == "Линейное неоднородное ДУ I порядка")
        Line_DU();

    if (ui->comboBox->currentText() == "ДУ Бернулли I порядка")
        Bernulli_DU();

    if (ui->comboBox->currentText() == "Уравнение в полных дифференциалах I порядка")
        Full_DU();
}
