#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include "efile.h"
#include "edirectory.h"
#include "serpentlist.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    EDirectory *current_directory = new EDirectory("C:");
    current_directory->fileList->add(new EFile("test.txt"));
    current_directory->fileList->add(new EDirectory("testDirectory"));
    for(int i = 0; i < current_directory->fileList->size(); i++){
        qDebug() << current_directory->fileList->get(i)->isDirectory();
    }
    return a.exec();
}
