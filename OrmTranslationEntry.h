#pragma once

#include "TranslationEntry.h"


class OrmTranslationEntry {
public:
    TranslationEntry Find(const QUuid & p_id) const;

    bool Insert(const TranslationEntry & p_entry) const;
};
