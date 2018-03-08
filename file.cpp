#include "file.h"

file::file() {
    this->path_file = "dados.csv";
}

file::~file(){}

void file::create_file() {
    if (!this->exist()) {
        qDebug() << "Tentando criar o arquivo!";
        QFile file(this->path_file);
        if ( file.open(QIODevice::ReadWrite | QIODevice::Append | QIODevice::Text) ) {
            QTextStream stream( &file );
            stream << "nome_do_paciente,data_de_nascimento,sexo,idade,altura,peso,imc,cc,cq,rcq" << endl;
            qDebug() << "Arquivo criado com sucesso! \0/";
        }
        else {
            qDebug() << "Algo deu errado ao tentar criar o arquivo!";
        }
    }
}

bool file::exist() {
    QFile file(this->path_file);
    if (QFileInfo::exists(this->path_file)) {
        qDebug() << "O arquivo já existe\0/!";
        return true;
    }
    else {
        qDebug() << "O arquivo não existe!";
        return false;
    }
}

void file::write(QString str){
    qDebug() << "Tentando escrever no arquivo!";
    QFile file(this->path_file);
    if ( file.open(QIODevice::ReadWrite | QIODevice::Append | QIODevice::Text) ) {
        QTextStream stream( &file );
        stream << str << endl;
        qDebug() << "Consegui escrever no arquivo\0/!";
    }

}
