#ifndef CLISTMODEL_H
#define CLISTMODEL_H
#include <qdebug.h>
#include <QAbstractListModel>

enum Roles {
    NameRole = Qt::UserRole + 1,
};

class CListModel : public QAbstractListModel
{
public:
    explicit CListModel(QObject *parent = nullptr);
    ~CListModel();

    void addData(const QString &unit);

    int rowCount(const QModelIndex & parent = QModelIndex()) const;

    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

protected:
    QHash<int, QByteArray> roleNames() const;

private:
    QStringList m_names;

};

#endif // CLISTMODEL_H
