#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "formulario.h"

Formulario *tmp;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tmp = new Formulario();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_salvar_clicked() {
    tmp->setNome_do_paciente(ui->input_nome->text().toStdString());
    tmp->setData_de_nascimento(ui->input_nasc->text().toStdString());
}

void MainWindow::on_input_nasc_editingFinished() {
    int current_date = QDate::currentDate().day();
    int current_month = QDate::currentDate().month();
    int current_year = QDate::currentDate().year();

    int birth_date = ui->input_nasc->date().day();
    int birth_month = ui->input_nasc->date().month();
    int birth_year = ui->input_nasc->date().year();
    if(birth_year > current_year) birth_year -= 100;

    // days of every month
    int month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (birth_date > current_date) {
        current_date = current_date + month[birth_month - 1];
        current_month = current_month - 1;
    }
    if (birth_month > current_month) {
       current_year = current_year - 1;
       current_month = current_month + 12;
    }
    int calculated_year = current_year - birth_year;
    tmp->setIdade(calculated_year); // Atribui valor a variável idade

    QString num;
    num.setNum(calculated_year);
    num.append(" anos");
    ui->lb_result_idade->setText(num);

    // TODO: Remover esse if
    if(ui->input_nasc->date().month() == QDate::currentDate().month()
            && ui->input_nasc->date().day() == QDate::currentDate().day()) {
        qDebug() << "Parabéns pelo se aniversário";
    }
}


void MainWindow::on_rdBtn_1_clicked() {
    tmp->setSexo(true);
}

void MainWindow::on_rdBtn_2_clicked() {
    tmp->setSexo(false);
}

void MainWindow::on_input_altura_editingFinished() {
    tmp->setAltura(ui->input_altura->text());
    if (tmp->getPeso() != 0) {
        ui->lb_result_imc->setText(tmp->calculaIMC());
    }
}

void MainWindow::on_input_peso_editingFinished() {
    tmp->setPeso(ui->input_peso->text());
    if (tmp->getAltura() != 0) {
        ui->lb_result_imc->setText(tmp->calculaIMC());
    }
}

bool MainWindow::eventFilter(QObject *target, QEvent *event) {
    if (event->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
        if (keyEvent->key() == Qt::Key_Escape) {
            this->close();
            qDebug() << "Esc was pressioned!";
            return QMainWindow::eventFilter(target,event);
        }
    }
    return QMainWindow::eventFilter(target,event);
}
