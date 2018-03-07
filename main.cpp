#include "mainwindow.h"
#include <QApplication>
#include<file.h>
#include <QDialog>

int main(int argc, char *argv[])
{
    file *my_fyle = new file(); //Classe file criada por mim
    my_fyle->create_file();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
