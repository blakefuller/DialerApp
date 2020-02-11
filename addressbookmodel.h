#ifndef ADDRESSBOOKMODEL_H
#define ADDRESSBOOKMODEL_H

#include <QAbstractTableModel>

class AddressBookModel : public QAbstractTableModel
{
public:
    AddressBookModel(QObject *parent);

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
};

#endif // ADDRESSBOOKMODEL_H
