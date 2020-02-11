#include "addressbookmodel.h"
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <iostream>

AddressBookModel::AddressBookModel(QObject *parent)
    :QAbstractTableModel(parent)
{

}

int AddressBookModel::rowCount(const QModelIndex &parent) const
{
    return firstNames.size();
}

int AddressBookModel::columnCount(const QModelIndex &parent) const
{
    return 3;
}

QVariant AddressBookModel::data(const QModelIndex &index, int role) const
{
    if(role == Qt::DisplayRole)
    {
        switch(index.column())
        {
        // first name
        case 0:
            return firstNames.at(index.row());
        // last name
        case 1:
            return lastNames.at(index.row());
        // phone numbers
        case 2:
            return phoneNumbers.at(index.row());
        }

        return QString("Row%1, Column%2")
                .arg(index.row())
                .arg(index.column());
    }

    return QVariant();
}

void AddressBookModel::openFile(QString filePath)
{
    QFile file(filePath);
    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(0, "error", file.errorString());
        return;
    }

    //clear old stuff
    firstNames.clear();
    lastNames.clear();
    phoneNumbers.clear();

    QTextStream in(&file);
    for(int i = 0; !in.atEnd(); i++)
    {
        QString line = in.readLine();
        QStringList fields = line.split(",");

        if(i == 0)
            continue;

        for(int j = 0; j < fields.length(); j++)
        {
            std::cout << fields[j].toStdString() << std::endl;
        }

        firstNames.push_back(fields[0]);
        lastNames.push_back(fields[1]);
        phoneNumbers.push_back(fields[7]);
    }
    file.close();

    emit layoutChanged();
}

QString AddressBookModel::getPhoneNumber(int index)
{
    QString numDashes = phoneNumbers.at(index);
    QString number = numDashes.left(3) + numDashes.mid(4,3) + numDashes.mid(8);
    cout << number.toStdString() << endl;
    return number;
}