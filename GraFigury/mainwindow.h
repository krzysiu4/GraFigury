#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>
#include <QTime>
#include <QList>
#include "dialog.h"
#include "dialog2.h"
#include "figura.h"
#include "odcinek.h"




namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    enum {FIGURY,INFO,KONIEC,WYGRANA,PRZEGRANA,REMIS,ZMIANA};
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void connectToServer(QString,int);
    void newMessage();
    void on_pushButtonPolacz_clicked();
    void keyPressEvent(QKeyEvent *);
    void zmienPoziomMessage();

private:
    QList <Figura*> listaFigur; // pośredniczy w przesyłaniu
    QList <Odcinek*> listaOdcinkow;
    Ui::MainWindow *ui;
    QTcpSocket *socket;
    Dialog *dialog;
    Dialog2 *dialog2;
    int wynik;


};

#endif // MAINWINDOW_H
