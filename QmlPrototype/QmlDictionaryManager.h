#pragma once

#include <QObject>

#include "DictionaryManager.h"


class QmlDictionaryManager : public QObject {
    Q_OBJECT

private:
    DictionaryManager m_manager;

public slots:
    bool SlotInsert(const QString & p_word, const QString & p_translation);
};
