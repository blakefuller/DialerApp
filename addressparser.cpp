#include "addressparser.h"
#include <QApplication>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QStandardItem>

AddressParser::AddressParser()
{

}

QStandardItemModel* AddressParser::Parse()
{
    QStandardItemModel *model = new QStandardItemModel;

    QFile file("us-500.csv");
    if(file.open(QIODevice::ReadOnly))
    {
        int lineindex = 0;
        QTextStream in(&file);

        while(!in.atEnd())
        {
            QString line = in.readLine();
            QStringList lineToken = line.split(",", QString::SkipEmptyParts);

            for(int i = 0; i < lineToken.size(); i++)
            {
                QString value = lineToken.at(i);
                QStandardItem *item = new QStandardItem(value);
                model->setItem(lineindex, i, item);
            }
            lineindex++;
        }
        file.close();
    }
    return model;
}
