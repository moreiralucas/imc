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
    return num;
}

void Formulario::limpa_dados() {
    this->nome_do_paciente = "";
    this->data_de_nascimento = "";
    this->idade = 0;
    this->altura = 0;
    this->peso = 0;
    this->imc = 0;
}
