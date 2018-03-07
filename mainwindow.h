#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QDateTimeEdit>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btn_salvar_clicked();

    void on_input_nasc_editingFinished();


    void on_rdBtn_1_clicked();

    void on_rdBtn_2_clicked();

    void on_input_altura_editingFinished();

    void on_input_peso_editingFinished();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
