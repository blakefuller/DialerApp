#include "dialerwindow.h"
#include "ui_dialerwindow.h"
#include "QLineEdit"


DialerWindow::DialerWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DialerWindow)
{
    ui->setupUi(this);
    ui->lineDisplay->setInputMask("(999) 999-9999");
}

DialerWindow::~DialerWindow()
{
    delete ui;
}


void DialerWindow::on_pushOne_clicked()
{
    ui->lineDisplay->setText("1");
}
