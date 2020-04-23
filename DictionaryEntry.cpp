#include "DictionaryEntry.h"


DictionaryEntry::DictionaryEntry(const QString & p_word, const QString & p_picture, const TranslationEntry & p_translation) :
    m_id(QUuid::createUuid()),
    m_word(p_word),
    m_picture_path(p_picture),
    m_translation(p_translation)
{ }


DictionaryEntry::DictionaryEntry(const QUuid p_id, const QString & p_word, const QString & p_picture, const TranslationEntry & p_translation) :
    m_id(p_id),
    m_word(p_word),
    m_picture_path(p_picture),
    m_translation(p_translation)
{ }


const QUuid DictionaryEntry::GetId() const {
    return m_id;
}


const QString & DictionaryEntry::GetWord() const {
    return m_word;
}


const QString & DictionaryEntry::GetPicturePath() const {
    return m_picture_path;
}


const TranslationEntry & DictionaryEntry::GetTranslation() const {
    return m_translation;
}


bool DictionaryEntry::IsEmpty() const {
    return m_id.isNull() || m_word.isEmpty();
}
