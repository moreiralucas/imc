#ifndef FORMULARIO_H
#define FORMULARIO_H

#include <QMainWindow>
#include <QDebug>

class Formulario
{
private:
    std::string nome_do_paciente;
    std::string data_de_nascimento;
    bool sexo;
    int idade;
    float altura;
    float peso;
    float imc;
    float cc;
    float cq;
    float rcq;
    QString categoriaIMC;
    QString categoriaRCQ;
public:
    Formulario();
    ~Formulario();
    std::string getNome_do_paciente() const;
    void setNome_do_paciente(const std::string &value);
    std::string getData_de_nascimento() const;
    void setData_de_nascimento(const std::string &value);
    bool getSexo() const;
    void setSexo(bool);
    int getIdade() const;
    void setIdade(int);
    float getAltura() const;
    void setAltura(QString);
    float getPeso() const;
    void setPeso(QString);
    float getImc() const;
    void setImc(float);
    QString calculaIMC();
    void limpa_dados();
    QString get_datas_QString();
    void set_categoriaIMC();
    QString getCategoriaIMC() const;
    void setCategoriaIMC();
    float getCc() const;
    void setCc(QString value);
    float getCq() const;
    void setCq(QString value);
    QString getCategoriaRCQ() const;
    void setCategoriaRCQ();
    QString calculaRCQ();
    float getRcq() const;
    void setRcq(float value);
};

#endif // FORMULARIO_H
