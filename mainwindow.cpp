#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QProgressBar>
#include <QPushButton>
#include <thread>
#include <chrono>

using namespace std::chrono;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->Counter->setValue(0);

    ui->pushButton->setCheckable(false);

    connect(ui->pushButton,&QPushButton::toggled,this,&MainWindow::on_pushButton_toggled);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_toggled(bool checked)
{
    if (checked)
    {
        if (cnt == 100) {}
        else
        {
            while(cnt <= 100)
            {
                cnt += 10;
                ui->Counter->setValue(cnt);
                std::this_thread::sleep_for(std::chrono::seconds(1));
            }
        }
    }
    else
    {
        if (cnt == 100)
        {
            cnt = 0;
            ui->Counter->setValue(cnt);
        }
    }
}

