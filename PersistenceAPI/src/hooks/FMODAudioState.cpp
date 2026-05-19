#include "hooks/FMODAudioState.hpp"
#include "Geode/binding/FMODQueuedMusic.hpp"
#include "Geode/binding/FMODSoundState.hpp"
#include "Geode/binding/FMODSoundTween.hpp"
#include "hooks/cocos2d/CCNode.hpp"
#include "hooks/FMODQueuedMusic.hpp"
#include "hooks/FMODSoundState.hpp"
#include "hooks/FMODSoundTween.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistenceAPI;

void PAFMODAudioState::load(Stream& i_stream) {
    i_stream >> *this;
}

void PAFMODAudioState::save(Stream& o_stream) {
    o_stream << *this;
}

inline void persistenceAPI::operator>>(Stream& i_stream, PAFMODAudioState& o_value) {
    i_stream >> o_value.m_interval;
    SEPARATOR_I
    i_stream >> o_value.m_elapsed;
    MAP_SEPARATOR_I
    i_stream >> o_value.m_tweensForEffectChannels;
    MAP_SEPARATOR_I
    i_stream >> o_value.m_tweensForEffectGroups;
    MAP_SEPARATOR_I
    i_stream >> o_value.m_tweensForMusicChannels;
    UMAP_SEPARATOR_I
    i_stream >> o_value.m_volumeForEffectChannels;
    UMAP_SEPARATOR_I
    i_stream >> o_value.m_volumeModForEffectChannels;
    UMAP_SEPARATOR_I
    i_stream >> o_value.m_pitchForEffectChannels;
    UMAP_SEPARATOR_I
    i_stream >> o_value.m_volumeForEffectGroups;
    UMAP_SEPARATOR_I
    i_stream >> o_value.m_volumeModForEffectGroups;
    UMAP_SEPARATOR_I
    i_stream >> o_value.m_pitchForEffectGroups;
    UMAP_SEPARATOR_I
    i_stream >> o_value.m_volumeForMusicChannels;
    UMAP_SEPARATOR_I
    i_stream >> o_value.m_volumeModForMusicChannels;
    UMAP_SEPARATOR_I
    i_stream >> o_value.m_pitchForMusicChannels;
    UMAP_SEPARATOR_I
    i_stream >> o_value.m_intervalForEffects;
    UMAP_SEPARATOR_I
    i_stream >> o_value.m_queuedMusicForChannels1;
    UMAP_SEPARATOR_I
    i_stream >> o_value.m_queuedMusicForChannels2;
    UMAP_SEPARATOR_I
    i_stream >> o_value.m_soundStateForChannels;
    UMAP_SEPARATOR_I
    i_stream >> o_value.m_unkUint64_1;
    SEPARATOR_I
}

inline void persistenceAPI::operator<<(Stream& o_stream, PAFMODAudioState& i_value) {
    o_stream << i_value.m_interval;
    SEPARATOR_O
    o_stream << i_value.m_elapsed;
    MAP_SEPARATOR_O
    o_stream << i_value.m_tweensForEffectChannels;
    MAP_SEPARATOR_O
    o_stream << i_value.m_tweensForEffectGroups;
    MAP_SEPARATOR_O
    o_stream << i_value.m_tweensForMusicChannels;
    UMAP_SEPARATOR_O
    o_stream << i_value.m_volumeForEffectChannels;
    UMAP_SEPARATOR_O
    o_stream << i_value.m_volumeModForEffectChannels;
    UMAP_SEPARATOR_O
    o_stream << i_value.m_pitchForEffectChannels;
    UMAP_SEPARATOR_O
    o_stream << i_value.m_volumeForEffectGroups;
    UMAP_SEPARATOR_O
    o_stream << i_value.m_volumeModForEffectGroups;
    UMAP_SEPARATOR_O
    o_stream << i_value.m_pitchForEffectGroups;
    UMAP_SEPARATOR_O
    o_stream << i_value.m_volumeForMusicChannels;
    UMAP_SEPARATOR_O
    o_stream << i_value.m_volumeModForMusicChannels;
    UMAP_SEPARATOR_O
    o_stream << i_value.m_pitchForMusicChannels;
    UMAP_SEPARATOR_O
    o_stream << i_value.m_intervalForEffects;
    UMAP_SEPARATOR_O
    o_stream << i_value.m_queuedMusicForChannels1;
    UMAP_SEPARATOR_O
    o_stream << i_value.m_queuedMusicForChannels2;
    UMAP_SEPARATOR_O
    o_stream << i_value.m_soundStateForChannels;
    UMAP_SEPARATOR_O
    o_stream << i_value.m_unkUint64_1;
    SEPARATOR_O
}

#if defined(PA_DEBUG) && defined(PA_DESCRIBE)
void PAFMODAudioState::describe() {
    log::info("[PAFMODAudioState - describe] m_interval: {}", m_interval);
    log::info("[PAFMODAudioState - describe] m_elapsed: {}", m_elapsed);
    int l_size = m_tweensForEffectChannels.size();
    log::info("[PAFMODAudioState - describe] m_tweensForEffectChannels.size(): {}", l_size);
    int i = 0;
    for (gd::pair<std::pair<int,int>, FMODSoundTween> l_pair : m_tweensForEffectChannels) {
        log::info("[PAFMODAudioState - describe] m_tweensForEffectChannels element {} key: {}", i, l_pair.first);
        reinterpret_cast<PAFMODSoundTween*>(&l_pair.second)->describe();
        i++;
    }
    l_size = m_tweensForEffectGroups.size();
    log::info("[PAFMODAudioState - describe] m_tweensForEffectGroups.size(): {}", l_size);
    i = 0;
    for (gd::pair<std::pair<int,int>, FMODSoundTween> l_pair : m_tweensForEffectGroups) {
        log::info("[PAFMODAudioState - describe] m_tweensForEffectGroups element {} key: {}", i, l_pair.first);
        reinterpret_cast<PAFMODSoundTween*>(&l_pair.second)->describe();
        i++;
    }
    l_size = m_tweensForMusicChannels.size();
    log::info("[PAFMODAudioState - describe] m_tweensForMusicChannels.size(): {}", l_size);
    i = 0;
    for (gd::pair<std::pair<int,int>, FMODSoundTween> l_pair : m_tweensForMusicChannels) {
        log::info("[PAFMODAudioState - describe] m_tweensForMusicChannels element {} key: {}", i, l_pair.first);
        reinterpret_cast<PAFMODSoundTween*>(&l_pair.second)->describe();
        i++;
    }
    l_size = m_volumeForEffectChannels.size();
    log::info("[PAFMODAudioState - describe] m_volumeForEffectChannels.size(): {}", l_size);
    i = 0;
    for (gd::pair<int, float> l_pair : m_volumeForEffectChannels) {
        log::info("[PAFMODAudioState - describe] m_volumeForEffectChannels element {} key: {}", i, l_pair.first);
        log::info("[PAFMODAudioState - describe] m_volumeForEffectChannels element {} value {}", i, l_pair.second);
        i++;
    }
    l_size = m_volumeModForEffectChannels.size();
    log::info("[PAFMODAudioState - describe] m_volumeForEffectChannels.size(): {}", l_size);
    i = 0;
    for (gd::pair<int, float> l_pair : m_volumeModForEffectChannels) {
        log::info("[PAFMODAudioState - describe] m_volumeModForEffectChannels element {} key: {}", i, l_pair.first);
        log::info("[PAFMODAudioState - describe] m_volumeModForEffectChannels element {} value {}", i, l_pair.second);
        i++;
    }
    l_size = m_pitchForEffectChannels.size();
    log::info("[PAFMODAudioState - describe] m_pitchForEffectChannels.size(): {}", l_size);
    i = 0;
    for (gd::pair<int, float> l_pair : m_pitchForEffectChannels) {
        log::info("[PAFMODAudioState - describe] m_pitchForEffectChannels element {} key: {}", i, l_pair.first);
        log::info("[PAFMODAudioState - describe] m_pitchForEffectChannels element {} value {}", i, l_pair.second);
        i++;
    }
    l_size = m_volumeForEffectGroups.size();
    log::info("[PAFMODAudioState - describe] m_volumeForEffectGroups.size(): {}", l_size);
    i = 0;
    for (gd::pair<int, float> l_pair : m_volumeForEffectGroups) {
        log::info("[PAFMODAudioState - describe] m_volumeForEffectGroups element {} key: {}", i, l_pair.first);
        log::info("[PAFMODAudioState - describe] m_volumeForEffectGroups element {} value {}", i, l_pair.second);
        i++;
    }
    l_size = m_volumeModForEffectGroups.size();
    log::info("[PAFMODAudioState - describe] m_volumeModForEffectGroups.size(): {}", l_size);
    i = 0;
    for (gd::pair<int, float> l_pair : m_volumeModForEffectGroups) {
        log::info("[PAFMODAudioState - describe] m_volumeModForEffectGroups element {} key: {}", i, l_pair.first);
        log::info("[PAFMODAudioState - describe] m_volumeModForEffectGroups element {} value {}", i, l_pair.second);
        i++;
    }
    l_size = m_pitchForEffectGroups.size();
    log::info("[PAFMODAudioState - describe] m_pitchForEffectGroups.size(): {}", l_size);
    i = 0;
    for (gd::pair<int, float> l_pair : m_pitchForEffectGroups) {
        log::info("[PAFMODAudioState - describe] m_pitchForEffectGroups element {} key: {}", i, l_pair.first);
        log::info("[PAFMODAudioState - describe] m_pitchForEffectGroups element {} value {}", i, l_pair.second);
        i++;
    }
    l_size = m_volumeForMusicChannels.size();
    log::info("[PAFMODAudioState - describe] m_volumeForMusicChannels.size(): {}", l_size);
    i = 0;
    for (gd::pair<int, float> l_pair : m_volumeForMusicChannels) {
        log::info("[PAFMODAudioState - describe] m_volumeForMusicChannels element {} key: {}", i, l_pair.first);
        log::info("[PAFMODAudioState - describe] m_volumeForMusicChannels element {} value {}", i, l_pair.second);
        i++;
    }
        l_size = m_volumeModForMusicChannels.size();
    log::info("[PAFMODAudioState - describe] m_volumeModForMusicChannels.size(): {}", l_size);
    i = 0;
    for (gd::pair<int, float> l_pair : m_volumeModForMusicChannels) {
        log::info("[PAFMODAudioState - describe] m_volumeModForMusicChannels element {} key: {}", i, l_pair.first);
        log::info("[PAFMODAudioState - describe] m_volumeModForMusicChannels element {} value {}", i, l_pair.second);
        i++;
    }
    l_size = m_pitchForMusicChannels.size();
    log::info("[PAFMODAudioState - describe] m_pitchForMusicChannels.size(): {}", l_size);
    i = 0;
    for (gd::pair<int, float> l_pair : m_pitchForMusicChannels) {
        log::info("[PAFMODAudioState - describe] m_pitchForMusicChannels element {} key: {}", i, l_pair.first);
        log::info("[PAFMODAudioState - describe] m_pitchForMusicChannels element {} value {}", i, l_pair.second);
        i++;
    }
    l_size = m_intervalForEffects.size();
    log::info("[PAFMODAudioState - describe] m_intervalForEffects.size(): {}", l_size);
    i = 0;
    for (gd::pair<int, float> l_pair : m_intervalForEffects) {
        log::info("[PAFMODAudioState - describe] m_intervalForEffects element {} key: {}", i, l_pair.first);
        log::info("[PAFMODAudioState - describe] m_intervalForEffects element {} value {}", i, l_pair.second);
        i++;
    }
    l_size = m_queuedMusicForChannels1.size();
    log::info("[PAFMODAudioState - describe] m_queuedMusicForChannels1.size(): {}", l_size);
    i = 0;
    for (gd::pair<int, FMODQueuedMusic> l_pair : m_queuedMusicForChannels1) {
        log::info("[PAFMODAudioState - describe] m_queuedMusicForChannels1 element {} key: {}", i, l_pair.first);
        log::info("[PAFMODAudioState - describe] m_queuedMusicForChannels1 element {} value:", i);
        reinterpret_cast<PAFMODQueuedMusic*>(&l_pair.second)->describe();
    }
    l_size = m_queuedMusicForChannels2.size();
    log::info("[PAFMODAudioState - describe] m_queuedMusicForChannels2.size(): {}", l_size);
    i = 0;
    for (gd::pair<int, FMODQueuedMusic> l_pair : m_queuedMusicForChannels2) {
        log::info("[PAFMODAudioState - describe] m_queuedMusicForChannels2 element {} key: {}", i, l_pair.first);
        log::info("[PAFMODAudioState - describe] m_queuedMusicForChannels2 element {} value:", i);
        reinterpret_cast<PAFMODQueuedMusic*>(&l_pair.second)->describe();
    }
    l_size = m_soundStateForChannels.size();
    log::info("[PAFMODAudioState - describe] m_soundStateForChannels.size(): {}", l_size);
    i = 0;
    for (gd::pair<int, FMODSoundState> l_pair : m_soundStateForChannels) {
        log::info("[PAFMODAudioState - describe] m_soundStateForChannels element {} key: {}", i, l_pair.first);
        log::info("[PAFMODAudioState - describe] m_soundStateForChannels element {} value:", i);
        reinterpret_cast<PAFMODSoundState*>(&l_pair.second)->describe();
    }
    log::info("[PAFMODAudioState - describe] m_unkUint64_1: {}", m_unkUint64_1);
}
#endif