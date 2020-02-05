#include "dialerwindow.h"
#include "ui_dialerwindow.h"

DialerWindow::DialerWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DialerWindow)
{
    ui->setupUi(this);
}

DialerWindow::~DialerWindow()
{
    delete ui;
}

