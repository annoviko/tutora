#pragma once

#include <QString>
#include <QUuid>


class TranslationEntry {
private:
    QUuid   m_id;
    QUuid   m_key_id;
    QString m_translation;
    QString m_audio_path;

public:
    TranslationEntry() = default;
    TranslationEntry(const QUuid p_key_id, const QString & p_translation, const QString & p_audio);
    TranslationEntry(const QUuid p_id, const QUuid p_key_id, const QString & p_translation, const QString & p_audio);

public:
    const QUuid GetId() const;
    const QUuid GetKeyId() const;
    const QString & GetTranslation() const;
    const QString & GetAudioPath() const;
};
