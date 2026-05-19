#include "hooks/FMODQueuedMusic.hpp"
#include "Geode/binding/FMODAudioEngine.hpp"
#include "hooks/cocos2d/CCNode.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistenceAPI;

void PAFMODQueuedMusic::load(Stream& i_stream) {
    i_stream >> *this;
}

void PAFMODQueuedMusic::save(Stream& o_stream) {
    o_stream << *this;
}

inline void persistenceAPI::operator>>(Stream& i_stream, PAFMODQueuedMusic& o_value) {
    STR_SEPARATOR_I
    i_stream >> o_value.m_filePath;
    STR_SEPARATOR_I
    if (i_stream.getPAVersion() > 1) {
        i_stream >> o_value.m_pitch;
        SEPARATOR_I
        i_stream >> o_value.m_unkFloat2;
        SEPARATOR_I
        i_stream >> o_value.m_volume;
        SEPARATOR_I
        i_stream >> o_value.m_start;
        SEPARATOR_I
        i_stream >> o_value.m_end;
        SEPARATOR_I
        i_stream >> o_value.m_fadeIn;
        SEPARATOR_I
        i_stream >> o_value.m_fadeOut;
        SEPARATOR_I
        i_stream >> o_value.m_loop;
        SEPARATOR_I
        i_stream >> o_value.m_musicID;
        SEPARATOR_I
        i_stream >> o_value.m_stopMusic;
        SEPARATOR_I
        i_stream >> o_value.m_channelID;
        SEPARATOR_I
        i_stream >> o_value.m_noPrepare;
        SEPARATOR_I
        i_stream >> o_value.m_queuedStatus;
        SEPARATOR_I
        int l_dummy;
        i_stream >> l_dummy;
        if (l_dummy == -1) {
            //TODO: This may be wrong
            o_value.m_sound = FMODAudioEngine::get()->preloadMusic(o_value.m_filePath, true, o_value.m_musicID);
        } else {
            //geode::log::info("!!!!!!!!!!!!!!!!!!! NOT Trying to load FMODQueuedMusic with preloadMusic CAUSE it was nullptr");
            o_value.m_sound = nullptr;
        }
        SEPARATOR_I
        i_stream >> o_value.m_dontReset;
    } else {
        i_stream.read(reinterpret_cast<char*>(&o_value) + offsetof(PAFMODQueuedMusic,m_filePath) + sizeof(gd::string), 56);
    }
    SEPARATOR_I
}

inline void persistenceAPI::operator<<(Stream& o_stream, PAFMODQueuedMusic& i_value) {
    STR_SEPARATOR_O
    o_stream << i_value.m_filePath;
    STR_SEPARATOR_O
    o_stream << i_value.m_pitch;
    SEPARATOR_O
    o_stream << i_value.m_unkFloat2;
    SEPARATOR_O
    o_stream << i_value.m_volume;
    SEPARATOR_O
    o_stream << i_value.m_start;
    SEPARATOR_O
    o_stream << i_value.m_end;
    SEPARATOR_O
    o_stream << i_value.m_fadeIn;
    SEPARATOR_O
    o_stream << i_value.m_fadeOut;
    SEPARATOR_O
    o_stream << i_value.m_loop;
    SEPARATOR_O
    o_stream << i_value.m_musicID;
    SEPARATOR_O
    o_stream << i_value.m_stopMusic;
    SEPARATOR_O
    o_stream << i_value.m_channelID;
    SEPARATOR_O
    o_stream << i_value.m_noPrepare;
    SEPARATOR_O
    o_stream << i_value.m_queuedStatus;
    SEPARATOR_O
    int l_dummy;
    if (i_value.m_sound == nullptr) {
        l_dummy = -2;
    } else {
        l_dummy = -1;
    }
    o_stream << l_dummy;
    SEPARATOR_O
    o_stream << i_value.m_dontReset;
    SEPARATOR_O
}

#if defined(PA_DEBUG) && defined(PA_DESCRIBE)
void PAFMODQueuedMusic::describe() {
    log::info("[PAFMODQueuedMusic - describe] m_filePath: {}", m_filePath);
    log::info("[PAFMODQueuedMusic - describe] m_pitch: {}", m_pitch);
    log::info("[PAFMODQueuedMusic - describe] m_unkFloat2: {}", m_unkFloat2);
    log::info("[PAFMODQueuedMusic - describe] m_volume: {}", m_volume);
    log::info("[PAFMODQueuedMusic - describe] m_start: {}", m_start);
    log::info("[PAFMODQueuedMusic - describe] m_end: {}", m_end);
    log::info("[PAFMODQueuedMusic - describe] m_fadeIn: {}", m_fadeIn);
    log::info("[PAFMODQueuedMusic - describe] m_fadeOut: {}", m_fadeOut);
    log::info("[PAFMODQueuedMusic - describe] m_loop: {}", m_loop);
    log::info("[PAFMODQueuedMusic - describe] m_musicID: {}", m_musicID);
    log::info("[PAFMODQueuedMusic - describe] m_stopMusic: {}", m_stopMusic);
    log::info("[PAFMODQueuedMusic - describe] m_channelID: {}", m_channelID);
    log::info("[PAFMODQueuedMusic - describe] m_noPrepare: {}", m_noPrepare);
    log::info("[PAFMODQueuedMusic - describe] m_queuedStatus: {}", m_queuedStatus);
    log::info("[PAFMODQueuedMusic - describe] m_sound: {}", *reinterpret_cast<size_t*>(&m_sound));
    log::info("[PAFMODQueuedMusic - describe] m_dontReset: {}", m_dontReset);
}
#endif