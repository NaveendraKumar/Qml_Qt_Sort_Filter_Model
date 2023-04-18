#ifndef FILTERPROXYMODEL_H
#define FILTERPROXYMODEL_H
#include <qdebug.h>
#include <QSortFilterProxyModel>
#include <QObject>

class FilterProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    explicit FilterProxyModel(QObject *parent = nullptr);
    ~FilterProxyModel();

    Q_INVOKABLE void setFilterString(QString string);

    Q_INVOKABLE void setSortOrder(bool checked);
};

#endif // FILTERPROXYMODEL_H
