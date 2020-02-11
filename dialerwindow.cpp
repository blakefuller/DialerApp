#include "dialerwindow.h"
#include "ui_dialerwindow.h"
#include "QLineEdit"
#include "QMessageBox"
#include <sstream>

using namespace std;
const QString MASK = "(999) 999-9999";

DialerWindow::DialerWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DialerWindow)
{
    ui->setupUi(this);
    ui->lineDisplay->setInputMask(MASK);

}

DialerWindow::~DialerWindow()
{
    delete ui;
}


void DialerWindow::on_pushOne_clicked()
{
    if (numMain.length() < 10)
    {
        numMain += "1";
        ui->lineDisplay->setText(numMain);
    }
}

void DialerWindow::on_pushTwo_clicked()
{
    if (numMain.length() < 10)
    {
        numMain += "2";
        ui->lineDisplay->setText(numMain);
    }
}

void DialerWindow::on_pushThree_clicked()
{
    if (numMain.length() < 10)
    {
        numMain += "3";
        ui->lineDisplay->setText(numMain);
    }
}


void DialerWindow::on_pushFour_clicked()
{
    if (numMain.length() < 10)
    {
        numMain += "4";
        ui->lineDisplay->setText(numMain);
    }
}

void DialerWindow::on_pushFive_clicked()
{
    if (numMain.length() < 10)
    {
        numMain += "5";
        ui->lineDisplay->setText(numMain);
    }
}

void DialerWindow::on_pushSix_clicked()
{
    if (numMain.length() < 10)
    {
        numMain += "6";
        ui->lineDisplay->setText(numMain);
    }
}

void DialerWindow::on_pushSeven_clicked()
{
    if (numMain.length() < 10)
    {
        numMain += "7";
        ui->lineDisplay->setText(numMain);
    }
}

void DialerWindow::on_pushEight_clicked()
{
    if (numMain.length() < 10)
    {
        numMain += "8";
        ui->lineDisplay->setText(numMain);
    }
}

void DialerWindow::on_pushNine_clicked()
{
    if (numMain.length() < 10)
    {
        numMain += "9";
        ui->lineDisplay->setText(numMain);
    }
}

void DialerWindow::on_pushZero_clicked()
{
    if (numMain.length() < 10)
    {
        numMain += "0";
        ui->lineDisplay->setText(numMain);
    }
}

void DialerWindow::on_pushStar_clicked()
{
    ui->lineDisplay->setText(numMain);
}

void DialerWindow::on_pushHash_clicked()
{
    ui->lineDisplay->setText(numMain);
}

void DialerWindow::on_pushDel_clicked()
{
    // remove last element on numMain
    numMain.remove(numMain.length()-1,1);
    ui->lineDisplay->setText(numMain);
}

void DialerWindow::on_pushEnd_clicked()
{
    // build message box
    QMessageBox msgBox;
    msgBox.setText("Calling\n (" + numMain.left(3) + ") " + numMain.mid(3,3) + "-" + numMain.mid(6));
    msgBox.exec();

    // reset numMain
    numMain.clear();
    ui->lineDisplay->clear();

}

void DialerWindow::on_actionOpen_Address_Book_triggered()
{

}
