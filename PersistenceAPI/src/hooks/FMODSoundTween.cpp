#include "hooks/FMODSoundTween.hpp"
#include "hooks/cocos2d/CCNode.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistenceAPI;

void PAFMODSoundTween::load(Stream& i_stream) {
    i_stream >> *this;
}

void PAFMODSoundTween::save(Stream& o_stream) {
    o_stream << *this;
}

inline void persistenceAPI::operator>>(Stream& i_stream, PAFMODSoundTween& o_value) {
    if (i_stream.getPAVersion() > 1) {
        i_stream >> o_value.m_interval;
        SEPARATOR_I;
        i_stream >> o_value.m_duration;
        SEPARATOR_I;
        i_stream >> o_value.m_start;
        SEPARATOR_I;
        i_stream >> o_value.m_end;
        SEPARATOR_I;
        i_stream >> o_value.m_value;
        SEPARATOR_I;
        i_stream >> o_value.m_finished;
        i_stream.read(reinterpret_cast<char*>(&o_value) + offsetof(PAFMODSoundTween,m_finished) + sizeof(bool), 7);
        SEPARATOR_I;
    } else {
        i_stream.read(reinterpret_cast<char*>(&o_value), 40);
    }
}

inline void persistenceAPI::operator<<(Stream& o_stream, PAFMODSoundTween& i_value) {
    o_stream << i_value.m_interval;
    SEPARATOR_O;
    o_stream << i_value.m_duration;
    SEPARATOR_O;
    o_stream << i_value.m_start;
    SEPARATOR_O;
    o_stream << i_value.m_end;
    SEPARATOR_O;
    o_stream << i_value.m_value;
    SEPARATOR_O;
    o_stream << i_value.m_finished;
    o_stream.write(reinterpret_cast<char*>(&i_value) + offsetof(PAFMODSoundTween,m_finished) + sizeof(bool), 7);
    SEPARATOR_O
}

#if defined(PA_DEBUG) && defined(PA_DESCRIBE)
void PAFMODSoundTween::describe() {
    log::info("[PAFMODSoundTween - describe] m_interval: {}", m_interval);
    log::info("[PAFMODSoundTween - describe] m_duration: {}", m_duration);
    log::info("[PAFMODSoundTween - describe] m_start: {}", m_start);
    log::info("[PAFMODSoundTween - describe] m_end: {}", m_end);
    log::info("[PAFMODSoundTween - describe] m_value: {}", m_value);
    log::info("[PAFMODSoundTween - describe] m_finished: {}", m_finished);
}
#endif