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

    QString CurrentNumber();



private slots:
    void on_pushOne_clicked();

private:
    Ui::DialerWindow *ui;
    QString number;
    AddressParser addressParser;
};
#endif // DIALERWINDOW_H
