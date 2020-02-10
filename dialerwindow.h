#ifndef DIALERWINDOW_H
#define DIALERWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class DialerWindow; }
QT_END_NAMESPACE

class DialerWindow : public QMainWindow
{
    Q_OBJECT

public:
    DialerWindow(QWidget *parent = nullptr);
    ~DialerWindow();

private slots:
    void on_pushOne_clicked();

private:
    Ui::DialerWindow *ui;
    QString number;
};
#endif // DIALERWINDOW_H
