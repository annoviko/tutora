#include "OrmTranslationEntry.h"

#include <QSqlQuery>
#include <QVariant>

#include "DatabaseInstance.h"


TranslationEntry OrmTranslationEntry::Find(const QUuid & p_key_id) const {
    DatabaseConnection & connection = DatabaseInstance::Get();
    QSqlQuery query(connection.Get());

    query.prepare("SELECT id, key_id, translation, audio_path "
                  "FROM dictionary_values "
                  "WHERE key_id = :key_id");

    query.bindValue(":key_id", p_key_id);

    if (query.exec()) {
        throw std::runtime_error("Impossible to execute request to get tranlation.");
    }

    if (query.next()) {
        QUuid id = query.value(0).toUuid();
        QUuid key_id = query.value(1).toUuid();
        QString trans = query.value(2).toString();
        QString audio = query.value(3).toString();

        return TranslationEntry(id, key_id, trans, audio);
    }

    throw std::runtime_error("Impossible to get translation from response.");
}


bool OrmTranslationEntry::Insert(const TranslationEntry & p_entry) const {
    DatabaseConnection & connection = DatabaseInstance::Get();
    QSqlQuery query(connection.Get());

    query.prepare("INSERT INTO dictionary_values (id,  key_id, translation, audio_path) "
                  "VALUES (:id, :key, :trans, :audio)");

    query.bindValue(":id", p_entry.GetId());
    query.bindValue(":key", p_entry.GetKeyId());
    query.bindValue(":trans", p_entry.GetTranslation());
    query.bindValue(":audio", p_entry.GetAudioPath());

    return query.exec();
}
