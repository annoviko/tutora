#pragma once

#include <QSet>
#include <QString>
#include <QUuid>

#include "TranslationEntry.h"

class DictionaryEntry {
private:
    QUuid   m_id;
    QString m_word;
    QString m_picture_path;

    TranslationEntry m_translation;

public:
    DictionaryEntry() = default;
    DictionaryEntry(const QString & p_word, const QString & p_picture, const TranslationEntry & p_translation);
    DictionaryEntry(const QUuid p_id, const QString & p_word, const QString & p_picture, const TranslationEntry & p_translation);

public:
    const QUuid GetId() const;
    const QString & GetWord() const;
    const QString & GetPicturePath() const;
    const TranslationEntry & GetTranslation() const;

    bool IsEmpty() const;
};
