#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QStandardItemModel>

class TableModel : public QStandardItemModel
{
public:
    TableModel(int, int);
    void switchItems(QStandardItem* item1, QStandardItem* item2);
};

#endif // TABLEMODEL_H
