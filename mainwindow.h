#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void Simple_DU();
    void Multiple_DU();
    void Line_DU();
    void Bernulli_DU();
    void Full_DU();
    void Start();
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
