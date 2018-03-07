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

void Formulario::setAltura(float value) {
    altura = value;
}

float Formulario::getPeso() const {
    return peso;
}

void Formulario::setPeso(float value) {
    peso = value;
}

float Formulario::getImc() const {
    return imc;
}

void Formulario::setImc(float value) {
    imc = value;
}

QString Formulario::calculaIMC() {
    //TODO: Implementar a função
    float imc = (float)this->getPeso() / (this->getAltura() * this->getAltura());
    QString num;
    num.setNum(imc);
    //num.append(" ");
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
