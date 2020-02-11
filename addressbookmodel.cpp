#include "addressbookmodel.h"

AddressBookModel::AddressBookModel(QObject *parent)
    :QAbstractTableModel(parent)
{

}

int AddressBookModel::rowCount(const QModelIndex &parent) const
{
    return 2;
}

int AddressBookModel::columnCount(const QModelIndex &parent) const
{
    return 3;
}

QVariant AddressBookModel::data(const QModelIndex &index, int role) const
{
    if(role == Qt::DisplayRole)
    {
        return QString("Row%1, Column%2")
                .arg(index.row())
                .arg(index.column());
    }

    return QVariant();
}
