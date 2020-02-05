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

private:
    Ui::DialerWindow *ui;
};
#endif // DIALERWINDOW_H
