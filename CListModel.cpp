#include "CListModel.h"

CListModel::CListModel(QObject *parent)
    : QAbstractListModel{parent}
{
    qInfo()<<Q_FUNC_INFO;
}
CListModel::~CListModel()
{
    qInfo()<<Q_FUNC_INFO;
}

void CListModel::addData(const QString &unit)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_names.append(unit);
    endInsertRows();
}

int CListModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_names.count();
}

QVariant CListModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= m_names.count())
        return QVariant();

    const QString &name = m_names[index.row()];
    if (role == NameRole)
        return name;
    return QVariant();
}

QHash<int, QByteArray> CListModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";
    return roles;
}
