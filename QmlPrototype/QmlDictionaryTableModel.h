#pragma once

#include <QAbstractTableModel>

#include "OrmDictionaryContainer.h"


class QmlDictionaryTableModel : public QAbstractTableModel {
    Q_OBJECT

public:
    DictionaryContainer m_content;

public:
    int rowCount(const QModelIndex & = QModelIndex()) const override;

    int columnCount(const QModelIndex & = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role) const override;

    QHash<int, QByteArray> roleNames() const override;
};
