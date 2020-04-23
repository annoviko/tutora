#pragma once

#include <QList>

#include "DictionaryEntry.h"


class OrmDictionaryContainer {
public:
    QList<DictionaryEntry> Select() const;
};
