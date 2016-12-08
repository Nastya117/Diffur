#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <ginac/ginac.h>
#include <ginac/iintegral.h>
#include <sstream>
#include <vector>

using namespace GiNaC;

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
    int i = 3;
    QString ur = ui->lineEdit->text();
    QString ururu, ggh = "";
    while (i < ur.size())
    {
        if (ur[i] != '+' && ur[i] != '-')
        {
            ururu.append(ur[i]);
            ++i;
        }
        else
        {
            std::vector<QString> po;
            std::vector<QString> st;
            QString num;
            for (int j = 0; j < ururu.size(); ++j)
            {
                if ((ururu[j] <= '9' && ururu[j] >= '0') || ururu[j] == 'x')
                {
                    if (ururu[j] == 'x') po.push_back("x");
                    else
                    {
                        while(ururu[j] <= '9' && ururu[j] >= '0')
                        {
                            num.append(ururu[j]);
                            ++j;
                        }
                        po.push_back(num);
                        num = "";
                        --j;
                    }
                }
                else
                {
                    if (ururu[j] == '^')
                        st.push_back("^");
                    else
                    if (ururu[j] == '*' || ururu[j] == '/')
                    {
                        if (st.size() > 0 && st[st.size() - 1] == "^")
                        {
                            po.push_back("^");
                            st.pop_back();
                            st.push_back(QString(ururu[j]));
                        }
                        else
                            st.push_back(QString(ururu[j]));
                    }
                    else
                    if (ururu[j] == '+' || ururu[j] == '-')
                    {
                        if (st.size() > 0)
                        {
                        int k = st.size() - 1;
                        while(st[k] == "^" || st[k] == "*" || st[k] == "/")
                        {
                            po.push_back(st[k]);
                            st.pop_back();
                            --k;
                        }
                        }
                        st.push_back(QString(ururu[j]));
                    }
                }
            }
                if (st.size() > 0)
                {
                    int k = st.size();
                    for (int l = k - 1; l >= 0; --l)
                        po.push_back(st[l]);
                }

                int fot = 0;
                ex Pt = 0;


                for (int k = 0; k < po.size(); ++k)
                    ggh += po[k];
                ggh += "\n";
                ui->label->setText(ggh);
                ++i;
                ururu = "";
        }
    }
    /*symbol x("x");
        ex P = pow(3, x);
        iintegral ii(x, P);
        integral a(x, 0, 1, P);
        ex U = ii.eval_integ();
    std::ostringstream gg;
         gg << U;
         std::string hh = gg.str();
         QString sss;
         sss = QString::fromStdString(hh);
         if (sss[0] == 'i' && sss[1] == 'i' && sss[2] == 'n') sss = "Я так не умею :(";
         ui->label->setText(sss + " + c");*/
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
