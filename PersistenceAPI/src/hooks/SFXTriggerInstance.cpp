#include "hooks/SFXTriggerInstance.hpp"
#include "Geode/binding/SFXTriggerGameObject.hpp"
#include "Geode/binding/PlayLayer.hpp"
#include "hooks/cocos2d/CCNode.hpp"
#include "hooks/PlayLayer.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistenceAPI;

void PASFXTriggerInstance::load(Stream& i_stream) {
    i_stream >> *this;
}

void PASFXTriggerInstance::save(Stream& o_stream) {
    o_stream << *this;
}

inline void persistenceAPI::operator>>(Stream& i_stream, PASFXTriggerInstance& o_value) {
    if (i_stream.getPAVersion() > 1) {
        i_stream >> o_value.m_groupID1;
        SEPARATOR_I
        i_stream >> o_value.m_groupID2;
        SEPARATOR_I
        i_stream >> o_value.m_controlID;
    } else {
        i_stream.read(reinterpret_cast<char*>(&o_value), 16);
    }
    SEPARATOR_I
    i_stream >> o_value.m_sfxTriggerGameObject;
    SEPARATOR_I
}

inline void persistenceAPI::operator<<(Stream& o_stream, PASFXTriggerInstance& i_value) {
    o_stream << i_value.m_groupID1;
    SEPARATOR_O
    o_stream << i_value.m_groupID2;
    SEPARATOR_O
    o_stream << i_value.m_controlID;
    SEPARATOR_O
    o_stream << i_value.m_sfxTriggerGameObject;
    SEPARATOR_O
}

#if defined(PA_DEBUG) && defined(PA_DESCRIBE)
void PASFXTriggerInstance::describe() {
    float m_groupID1;
    float m_groupID2;
    float m_controlID;
    log::info("[PASFXTriggerInstance - describe] m_groupID1: {}", m_groupID1);
    log::info("[PASFXTriggerInstance - describe] m_groupID2: {}", m_groupID2);
    log::info("[PASFXTriggerInstance - describe] m_controlID: {}", m_controlID);
    int l_objectIndex = -1;
    PAPlayLayer* l_playLayer = static_cast<PAPlayLayer*>(PlayLayer::get());
    if (l_playLayer) l_objectIndex = l_playLayer->getGameObjectIndex(m_sfxTriggerGameObject);
    log::info("[PASFXTriggerInstance - describe] m_sfxTriggerGameObject l_objectIndex: {}", l_objectIndex);
}
#endif