#include "dialog2.h"
#include "ui_dialog2.h"
#include "mainwindow.h"

Dialog2::Dialog2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog2)
{
    ui->setupUi(this);
}

Dialog2::~Dialog2()
{
    delete ui;
}


void Dialog2::ustawWiadomosc(QString wiadomosc)
{
    ui->label->setText(wiadomosc);

}

void Dialog2::on_pushButton_2_clicked()
{
    this->hide();
    emit zmienPoziom();

}
