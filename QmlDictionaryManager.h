#pragma once

#include <QObject>

#include "DictionaryManager.h"


class QmlDictionaryManager : public QObject {
Q_OBJECT
public slots:
    bool SlotInsert(const QString & p_word, const QString & p_translation) {
        return DictionaryManager::InsertWord(p_word, p_translation);
    }
};
