#include "dialerwindow.h"
#include "ui_dialerwindow.h"
#include "QLineEdit"
#include <sstream>

using namespace std;

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

// Sets all the
QString DialerWindow :: CurrentNumber()
{
    stringstream ss;


}


void DialerWindow::on_pushOne_clicked()
{
    ui->lineDisplay->setText("1");
}
