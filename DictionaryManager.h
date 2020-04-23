#pragma once

#include <QString>

#include "DictionaryEntry.h"


class DictionaryManager {
public:
    static bool InsertWord(const QString & p_word, const QString & p_translation);

    static DictionaryEntry FindTranslation(const QString & p_word);

    static QList<DictionaryEntry> GetDictionary();
};
