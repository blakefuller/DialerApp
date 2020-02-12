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
    return filterIndex.size();
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
            return firstNames.at(filterIndex[index.row()]);
        // last name
        case 1:
            return lastNames.at(filterIndex[index.row()]);
        // phone numbers
        case 2:
            return phoneNumbers.at(filterIndex[index.row()]);
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

        firstNames.push_back(fields[0]);
        lastNames.push_back(fields[1]);
        phoneNumbers.push_back(fields[7]);

        filterIndex.push_back(i);
    }

    file.close();

    emit layoutChanged();
}

QString AddressBookModel::getPhoneNumber(int index)
{
    QString numDashes = phoneNumbers.at(filterIndex[index]);
    QString number = numDashes.left(3) + numDashes.mid(4,3) + numDashes.mid(8);
    return number;
}

void AddressBookModel::setFilterString(QString fStr)
{
    // clear finter index
    filterIndex.clear();

    // matches phone numbers that start with fStr
    for (int i = 0; i < phoneNumbers.size(); i++)
    {
        if (phoneNumbers[i].startsWith(fStr))
        {
            filterIndex.push_back(i);
        }
    }

    emit layoutChanged();
}
