#include "QmlDictionaryManager.h"


bool QmlDictionaryManager::SlotInsert(const QString & p_word, const QString & p_translation) {
    return m_manager.InsertWord(p_word, p_translation);
}
