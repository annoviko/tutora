#include "OrmDictionaryContainer.h"

#include <QSqlQuery>
#include <QVariant>

#include "DatabaseInstance.h"


DictionaryContainer OrmDictionaryContainer::Select() const {
    DatabaseConnection & connection = DatabaseInstance::Get();
    QSqlQuery query(connection.Get());

    query.prepare("SELECT dictionary_keys.id, dictionary_keys.key, dictionary_keys.picture_path, "
                  "dictionary_values.id, dictionary_values.translation, dictionary_values.audio_path "
                  "FROM dictionary_keys FULL OUTER JOIN dictionary_values "
                  "ON dictionary_keys.id = dictionary_values.key_id");

    DictionaryContainer collection;
    if (query.exec()) {
        while(query.next()) {
            QUuid key_id = query.value(0).toUuid();
            QString word = query.value(1).toString();
            QString picture_path = query.value(2).toString();
            QUuid value_id = query.value(3).toUuid();
            QString translation = query.value(4).toString();
            QString audio_path = query.value(5).toString();

            DictionaryEntry entry = DictionaryEntry(key_id, word, picture_path, TranslationEntry(value_id, translation, audio_path));
            collection.insert(entry.GetWord(), entry);
        }
    }

    return collection;
}
