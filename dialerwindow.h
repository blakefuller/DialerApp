#ifndef DIALERWINDOW_H
#define DIALERWINDOW_H

#include <QMainWindow>
#include <QStandardItem>
#include "addressparser.h"

QT_BEGIN_NAMESPACE
namespace Ui { class DialerWindow; }
QT_END_NAMESPACE

class DialerWindow : public QMainWindow
{
    Q_OBJECT

public:
    DialerWindow(QWidget *parent = nullptr);
    ~DialerWindow();

   // QString CurrentNumber();



private slots:
    void on_pushOne_clicked();

    void on_pushTwo_clicked();

    void on_pushThree_clicked();

    void on_pushFour_clicked();

    void on_pushFive_clicked();

    void on_pushSix_clicked();

    void on_pushSeven_clicked();

    void on_pushEight_clicked();

    void on_pushNine_clicked();

    void on_pushZero_clicked();

    void on_pushStar_clicked();

    void on_pushHash_clicked();

    void on_pushDel_clicked();

    void on_pushEnd_clicked();

    void on_actionOpen_Address_Book_triggered();

private:
    Ui::DialerWindow *ui;

    QString numMain;
    AddressParser addressParser;
};
#endif // DIALERWINDOW_H
