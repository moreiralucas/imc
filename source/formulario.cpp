#include "formulario.h"

Formulario::Formulario() {
    this->limpa_dados();
}

std::string Formulario::getNome_do_paciente() const {
    return nome_do_paciente;
}

void Formulario::setNome_do_paciente(const std::string &value) {
    nome_do_paciente = value;
}

std::string Formulario::getData_de_nascimento() const {
    return data_de_nascimento;
}

void Formulario::setData_de_nascimento(const std::string &value) {
    data_de_nascimento = value;
}

int Formulario::getIdade() const {
    return idade;
}

void Formulario::setIdade(int value) {
    idade = value;
}

bool Formulario::getSexo() const {
    return sexo;
}

void Formulario::setSexo(bool value) {
    sexo = value;
}

float Formulario::getAltura() const {
    return altura;
}

void Formulario::setAltura(QString value) {
    const int num = value.indexOf(',');
    // Se não utilizou vírgula, ele não precisa ser corrigido
    if (num >= 0)
        value.replace(num, 1, QString("."));
    altura = value.toFloat();
}

float Formulario::getPeso() const {
    return peso;
}

void Formulario::setPeso(QString value) {
    const int num = value.indexOf(',');
    // Se não utilizou vírgula, ele não precisa ser corrigido
    if (num >= 0) value.replace(num, 1, QString("."));
    peso = value.toFloat();
}

float Formulario::getImc() const {
    return imc;
}

void Formulario::setImc(float value) {
    imc = value;
}

QString Formulario::calculaIMC() {
    float imc = (float)this->getPeso() / (this->getAltura() * this->getAltura());
    this->setImc(imc);
    QString num;
    num.setNum(imc);
    this->setCategoriaIMC();
    return num;
}

QString Formulario::calculaRCQ() {
    float rcq_tmp = (float)this->getCc()/this->getCq();
    this->setRcq(rcq_tmp);
    QString num;
    num.setNum(rcq_tmp);
    this->setCategoriaRCQ();
    return num;
}


void Formulario::limpa_dados() {
    this->nome_do_paciente = "";
    this->data_de_nascimento = "";
    this->idade = 0;
    this->altura = 0;
    this->peso = 0;
    this->imc = 0;
    this->cc = 0;
    this->cq = 0;
    this->rcq = 0;
}

QString Formulario::get_datas_QString() {
    QString nome = QString::fromStdString(this->getNome_do_paciente());
    QString data = QString::fromStdString(this->getData_de_nascimento());
    QString sexo; sexo = (this->getSexo()?"F":"M");
    QString idade; idade.setNum(this->getIdade());
    QString altura; altura.setNum(this->getAltura());
    QString peso; peso.setNum(this->getPeso());
    QString imc; imc.setNum(this->getImc());
    QString cc1; cc1.setNum(this->getCc());
    QString cq1; cq1.setNum(this->getCq());
    QString rcq1; rcq1.setNum(this->getRcq());

    return nome + "," + data + "," + sexo + "," + idade + "," + altura +
            "," + peso + "," + imc + "," + cc1 + "," + cq1 + "," + rcq1;
}

QString Formulario::getCategoriaIMC() const {
    return categoriaIMC;
}

void Formulario::setCategoriaIMC() {
    if (this->getIdade() >= 60) {
        if (this->getImc() < 22)
            categoriaIMC = "Baixo peso";
        else if (this->getImc() < 27)
            categoriaIMC = "Eutrofia";
        else if (this->getImc() < 30)
            categoriaIMC = "Sobrepeso";
        else
            categoriaIMC = "Obesidade";
    }
    else{
        if (this->getImc() <= 18.4)
            categoriaIMC = "Baixo peso";
        else if (this->getImc() < 25)
            categoriaIMC = "Eutrofia";
        else if(this->getImc() < 30)
            categoriaIMC = "Sobrepeso";
        else if(this->getImc() < 35)
            categoriaIMC = "Obesidade grau 1";
        else if(this->getImc() < 40)
            categoriaIMC = "Obesidade grau 2";
        else
            categoriaIMC = "Obesidade grau 3";
    }
}

float Formulario::getCc() const {
    return cc;
}

void Formulario::setCc(QString value) {
    const int num = value.indexOf(',');
    // Se não utilizou vírgula, ele não precisa ser corrigido
    if (num >= 0) value.replace(num, 1, QString("."));
    cc = value.toFloat();
}

float Formulario::getCq() const {
    return cq;
}

void Formulario::setCq(QString value) {
    const int num = value.indexOf(',');
    // Se não utilizou vírgula, ele não precisa ser corrigido
    if (num >= 0) value.replace(num, 1, QString("."));
    cq = value.toFloat();
}

QString Formulario::getCategoriaRCQ() const {
    return categoriaRCQ;
}

void Formulario::setCategoriaRCQ() {
    const float value = this->getRcq();
    const bool MULHER = true;
    if (this->getSexo() == MULHER) {
        if (value >= 0.85)
            this->categoriaRCQ = "Risco de complicação metabólica aumentado";
        else
            this->categoriaRCQ = "Normal";
    }
    else {
        if (value >= 0.9)
            this->categoriaRCQ = "Risco de complicação metabólica aumentado";
        else
            this->categoriaRCQ = "Normal";
    }
}

float Formulario::getRcq() const {
    return rcq;
}

void Formulario::setRcq(float value) {
    rcq = value;
}
