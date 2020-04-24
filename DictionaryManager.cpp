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

    bool result = OrmDictionaryEntry().Insert(entry);
    if (result) {
        m_table.insert(entry.GetWord(), entry);
    }

    return result;
}


DictionaryEntry DictionaryManager::FindTranslation(const QString & p_word) {
    if (p_word.isEmpty()) {
        return DictionaryEntry();
    }

    /* Check database cache */
    auto it = m_table.find(p_word);
    if (it != m_table.end()) {
        return it.value();
    }

    /* Find in database */
    DictionaryEntry entry = OrmDictionaryEntry().Find(p_word);
    if (!entry.IsEmpty()) {
        m_table.insert(entry.GetWord(), entry);
    }

    return entry;
}


const DictionaryContainer & DictionaryManager::GetDictionary() {
    if (m_table.empty()) {
        m_table = OrmDictionaryContainer().Select();
    }

    return m_table;
}
