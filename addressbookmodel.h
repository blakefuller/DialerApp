#ifndef ADDRESSBOOKMODEL_H
#define ADDRESSBOOKMODEL_H

#include <QAbstractTableModel>
#include <vector>

using namespace std;

class AddressBookModel : public QAbstractTableModel
{
public:
    AddressBookModel(QObject *parent);
    vector<QString> firstNames;
    vector<QString> lastNames;
    vector<QString> phoneNumbers;

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;

    void openFile(QString filePath);
};

#endif // ADDRESSBOOKMODEL_H
