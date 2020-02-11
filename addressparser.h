#ifndef ADDRESSPARSER_H
#define ADDRESSPARSER_H
#include <QStandardItem>

class AddressParser
{
public:
    AddressParser();
    QStandardItemModel* Parse();
};

#endif // ADDRESSPARSER_H
