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
    nameNumbers.clear();

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

        // convert first names to numbers
        vector<string> letters;
        QString firstNameNum;

        for(int j = 0; j < fields[0].size(); j++)
        {
            string letter;
            if(j == 0)
                letter = fields[0].left(1).toLower().toStdString();
            else
                letter = fields[0].mid(j,1).toLower().toStdString();

            if(letter=="a"||letter=="b"||letter=="c")
                firstNameNum += "2";
            else if(letter=="d"||letter=="e"||letter=="f")
                firstNameNum += "3";
            else if(letter=="g"||letter=="h"||letter=="i")
                firstNameNum += "4";
            else if(letter=="j"||letter=="k"||letter=="l")
                firstNameNum += "5";
            else if(letter=="m"||letter=="n"||letter=="o")
                firstNameNum += "6";
            else if(letter=="p"||letter=="q"||letter=="r"||letter=="s")
                firstNameNum += "7";
            else if(letter=="t"||letter=="u"||letter=="v")
                firstNameNum += "8";
            else if(letter=="w"||letter=="x"||letter=="y"||letter=="z")
                firstNameNum += "9";
        }
        nameNumbers.push_back(firstNameNum);

        // convert last names to numbers
        vector<string> lettma;
        QString lastNameNum;

        for(int j = 0; j < fields[1].size(); j++)
        {
            string lettma;
            if(j == 0)
                lettma = fields[1].left(1).toLower().toStdString();
            else
                lettma = fields[1].mid(j,1).toLower().toStdString();

            if(lettma=="a"||lettma=="b"||lettma=="c")
                lastNameNum += "2";
            else if(lettma=="d"||lettma=="e"||lettma=="f")
                lastNameNum += "3";
            else if(lettma=="g"||lettma=="h"||lettma=="i")
                lastNameNum += "4";
            else if(lettma=="j"||lettma=="k"||lettma=="l")
                lastNameNum += "5";
            else if(lettma=="m"||lettma=="n"||lettma=="o")
                lastNameNum += "6";
            else if(lettma=="p"||lettma=="q"||lettma=="r"||lettma=="s")
                lastNameNum += "7";
            else if(lettma=="t"||lettma=="u"||lettma=="v")
                lastNameNum += "8";
            else if(lettma=="w"||lettma=="x"||lettma=="y"||lettma=="z")
                lastNameNum += "9";
        }
        lastNameNumbers.push_back(lastNameNum);

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
            filterIndex.push_back(i);
    }
    for (int j = 0; j < nameNumbers.size(); j++)
    {
        if (nameNumbers[j].startsWith(fStr))
        {
            filterIndex.push_back(j);
        }
    }
    for (int j = 0; j < lastNameNumbers.size(); j++)
    {
        if (lastNameNumbers[j].startsWith(fStr))
            filterIndex.push_back(j);
    }

    emit layoutChanged();
}
