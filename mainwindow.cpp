#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->current = 0;
    this->currentList = 0;
    this->cutting = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::copy(SerpentList<ExplorerObject*>* currentList, ExplorerObject* current)
{
    this->current = current;
    this->currentList = currentList;
    cutting = false;
}

void MainWindow::cut(SerpentList<ExplorerObject*>* currentList, ExplorerObject* current)
{
    this->current = current;
    this->currentList = currentList;
    cutting = true;
}

void MainWindow::paste(SerpentList<ExplorerObject*>* forwardList)
{
    forwardList->add(current);
    if(cutting){
        currentList->remove(currentList->indexOf(current));
    }
    current = 0;
    currentList = 0;
    cutting = false;

}



void MainWindow::on_pushButton_clicked()
{
}
