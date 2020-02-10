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

    // parse the csv file and set table view
    QStandardItemModel *model = addressParser.Parse();
    ui->tableSafe->setModel(model);
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
