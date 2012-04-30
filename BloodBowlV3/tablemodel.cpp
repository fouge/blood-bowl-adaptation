#include "tablemodel.h"

TableModel::TableModel(int rows, int columns): QStandardItemModel(rows, columns)
{

}


void TableModel::switchItems(QStandardItem *item1, QStandardItem *item2)
{

    QStandardItem *temp1 = item1->clone();
    QStandardItem *temp2 = item2->clone();
//    QStandardItem* un = new QStandardItem(*item1);
    setItem(item1->row(), item1->column(), temp2);
    setItem(item2->row(), item2->column(), temp1);
}

