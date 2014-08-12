#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "efile.h"
#include "edirectory.h"
#include "serpentlist.h"
#include <QLabel>
#include <QVBoxLayout>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    bool cutting;
    ExplorerObject* current;
    SerpentList<ExplorerObject*>* currentList;
    ~MainWindow();

signals:
public slots:

    void copy(SerpentList<ExplorerObject*>* currentList, ExplorerObject* current);
    void cut(SerpentList<ExplorerObject*>* currentList, ExplorerObject* current);
    void paste(SerpentList<ExplorerObject*>* forwardList);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
