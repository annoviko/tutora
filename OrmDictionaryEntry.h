#pragma once


#include "DictionaryEntry.h"


class OrmDictionaryEntry {
public:
    DictionaryEntry Find(const QString & p_word) const;
    bool Insert(const DictionaryEntry & p_entry) const;
};
