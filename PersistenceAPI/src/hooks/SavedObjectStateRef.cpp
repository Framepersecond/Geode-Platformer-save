#include "hooks/SavedObjectStateRef.hpp"
#include "hooks/PlayLayer.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistenceAPI;

void PASavedObjectStateRef::load(Stream& i_stream) {
    i_stream >> *this;
}

void PASavedObjectStateRef::save(Stream& o_stream) {
    o_stream << *this;
}

inline void persistenceAPI::operator>>(Stream& i_stream, PASavedObjectStateRef& o_value) {
    i_stream >> o_value.m_gameObject;
    SEPARATOR_I
    i_stream >> o_value.m_positionX;
    SEPARATOR_I
    i_stream >> o_value.m_positionY;
    SEPARATOR_I
    i_stream >> o_value.m_rotationXOffset;
    SEPARATOR_I
    i_stream >> o_value.m_rotationYOffset;
    SEPARATOR_I
    i_stream >> o_value.m_addToCustomScaleX;
    SEPARATOR_I
    i_stream >> o_value.m_addToCustomScaleY;
    SEPARATOR_I
    i_stream >> o_value.m_unkFloat3;
    SEPARATOR_I
    i_stream >> o_value.m_unkFloat4;
    SEPARATOR_I_END
}

inline void persistenceAPI::operator<<(Stream& o_stream, PASavedObjectStateRef& i_value) {
    o_stream << i_value.m_gameObject;
    SEPARATOR_O
    o_stream << i_value.m_positionX;
    SEPARATOR_O
    o_stream << i_value.m_positionY;
    SEPARATOR_O
    o_stream << i_value.m_rotationXOffset;
    SEPARATOR_O
    o_stream << i_value.m_rotationYOffset;
    SEPARATOR_O
    o_stream << i_value.m_addToCustomScaleX;
    SEPARATOR_O
    o_stream << i_value.m_addToCustomScaleY;
    SEPARATOR_O
    o_stream << i_value.m_unkFloat3;
    SEPARATOR_O
    o_stream << i_value.m_unkFloat4;
    SEPARATOR_O_END
}

#if defined(PA_DEBUG) && defined(PA_DESCRIBE)
void PASavedObjectStateRef::describe() {
    int l_objectIndex = -1;
    PAPlayLayer* l_playLayer = static_cast<PAPlayLayer*>(PlayLayer::get());
    if (l_playLayer) l_objectIndex = l_playLayer->getGameObjectIndex(m_gameObject);

    log::info("[PASavedObjectStateRef - describe] l_objectIndex: {}", l_objectIndex);
    log::info("[PASavedObjectStateRef - describe] m_positionX: {}", m_positionX);
    log::info("[PASavedObjectStateRef - describe] m_positionY: {}", m_positionY);
    log::info("[PASavedObjectStateRef - describe] m_rotationXOffset: {}", m_rotationXOffset);
    log::info("[PASavedObjectStateRef - describe] m_rotationYOffset: {}", m_rotationYOffset);
    log::info("[PASavedObjectStateRef - describe] m_addToCustomScaleX: {}", m_addToCustomScaleX);
    log::info("[PASavedObjectStateRef - describe] m_addToCustomScaleY: {}", m_addToCustomScaleY);
    log::info("[PASavedObjectStateRef - describe] m_unkFloat3: {}", m_unkFloat3);
    log::info("[PASavedObjectStateRef - describe] m_unkFloat4: {}", m_unkFloat4);
}
#endif