#include "TranslationEntry.h"


TranslationEntry::TranslationEntry(const QUuid p_key_id, const QString & p_translation, const QString & p_audio) :
    m_id(QUuid::createUuid()),
    m_key_id(p_key_id),
    m_translation(p_translation),
    m_audio_path(p_audio)
{ }


TranslationEntry::TranslationEntry(const QUuid p_id, const QUuid p_key_id, const QString & p_translation, const QString & p_audio) :
    m_id(p_id),
    m_key_id(p_key_id),
    m_translation(p_translation),
    m_audio_path(p_audio)
{ }


const QUuid TranslationEntry::GetId() const {
    return m_id;
}


const QUuid TranslationEntry::GetKeyId() const {
    return m_key_id;
}


const QString & TranslationEntry::GetTranslation() const {
    return m_translation;
}


const QString & TranslationEntry::GetAudioPath() const {
    return m_audio_path;
}
