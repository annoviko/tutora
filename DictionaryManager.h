#pragma once

#include <QString>

#include "DictionaryEntry.h"
#include "DictionaryContainer.h"


class DictionaryManager {
private:
    DictionaryContainer m_table;

public:
    bool InsertWord(const QString & p_word, const QString & p_translation);

    DictionaryEntry FindTranslation(const QString & p_word);

    const DictionaryContainer & GetDictionary();
};
