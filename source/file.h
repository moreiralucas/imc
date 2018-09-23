#ifndef FILE_H
#define FILE_H
#include<fstream>
#include <QFile>
#include <QFileInfo>
#include <QDebug>

class file
{
private:
    QString path_file;
    bool exist();
public:
    file();
    ~file();
    void create_file();
    void write(QString);
};

#endif // FILE_H
