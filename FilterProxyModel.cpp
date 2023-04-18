#include "FilterProxyModel.h"

FilterProxyModel::FilterProxyModel(QObject *parent)
    : QSortFilterProxyModel{parent}
{
    setSortOrder(false);
    qInfo()<<Q_FUNC_INFO;
}

FilterProxyModel::~FilterProxyModel()
{
    qInfo()<<Q_FUNC_INFO;
}

void FilterProxyModel::setFilterString(QString string)
{
    this->setFilterCaseSensitivity(Qt::CaseInsensitive);
    this->setFilterFixedString(string);
}

void FilterProxyModel::setSortOrder(bool checked)
{
    if(checked)
    {
        this->sort(0, Qt::DescendingOrder);
    }
    else
    {
        this->sort(0, Qt::AscendingOrder);
    }
}
