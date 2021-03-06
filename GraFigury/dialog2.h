#ifndef DIALOG2_H
#define DIALOG2_H

#include <QDialog>

namespace Ui {
class Dialog2;
}
/*!
 * \brief Okno Dialogowe, umożliwiające przejście do następnego poziomu.
 *
 * Wyświetlane po ukończeniu poziomu
 */

class Dialog2 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog2(QWidget *parent = 0);
    ~Dialog2();
    void ustawWiadomosc(QString);

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::Dialog2 *ui;

signals:
    void zmienPoziom();
};

#endif // DIALOG2_H
