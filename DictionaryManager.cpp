#include "DictionaryManager.h"

#include "OrmDictionaryEntry.h"
#include "OrmDictionaryContainer.h"
#include "TranslationEntry.h"


bool DictionaryManager::InsertWord(const QString & p_word, const QString & p_translation) {
    if (p_word.isEmpty() || p_translation.isEmpty()) {
        return false;
    }

    QUuid key_id = QUuid::createUuid();
    DictionaryEntry entry = DictionaryEntry(key_id, p_word, "", TranslationEntry(key_id, p_translation, ""));
    return OrmDictionaryEntry().Insert(entry);
}


DictionaryEntry DictionaryManager::FindTranslation(const QString & p_word) {
    if (p_word.isEmpty()) {
        return DictionaryEntry();
    }

    return OrmDictionaryEntry().Find(p_word);
}


QList<DictionaryEntry> DictionaryManager::GetDictionary() {
    return OrmDictionaryContainer().Select();
}
