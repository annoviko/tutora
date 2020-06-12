#include "OrmDictionaryEntry.h"

#include <QSqlQuery>
#include <QVariant>

#include "DatabaseInstance.h"
#include "OrmTranslationEntry.h"


DictionaryEntry OrmDictionaryEntry::Find(const QString & p_word) const {
    DatabaseConnection & connection = DatabaseInstance::Get();
    QSqlQuery query(connection.Get());

    query.prepare("SELECT id, key, picture_path "
                  "FROM dictionary_keys "
                  "WHERE key = :key");

    query.bindValue(0, p_word);

    if (!query.exec()) {
        throw std::exception("Impossible to execute request to find translation.");
    }

    if (!query.next()) {
        throw std::exception("Impossible to get dictionary entry from response.");
    }

    QUuid id = query.value(0).toUuid();
    QString key = query.value(1).toString();
    QString picture = query.value(2).toString();
    TranslationEntry translation = OrmTranslationEntry().Find(id);

    return DictionaryEntry(id, key, picture, translation);
}


bool OrmDictionaryEntry::Insert(const DictionaryEntry & p_entry) const {
    DatabaseConnection & connection = DatabaseInstance::Get();
    QSqlQuery query(connection.Get());

    query.prepare("INSERT INTO dictionary_keys (id, key, picture_path) "
                  "VALUES (:id, :key, :picture)");

    query.bindValue(":id", p_entry.GetId());
    query.bindValue(":key", p_entry.GetWord());
    query.bindValue(":picture", p_entry.GetPicturePath());

    if (!query.exec()) {
        return false;
    }

    return OrmTranslationEntry().Insert(p_entry.GetTranslation());
}
