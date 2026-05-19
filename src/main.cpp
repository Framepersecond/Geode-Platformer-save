#include <Geode/Geode.hpp>
#include <Geode/modify/CheckpointObject.hpp>
#include <Geode/modify/LevelInfoLayer.hpp>
#include <Geode/modify/PauseLayer.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <Geode/ui/Popup.hpp>
#include <Geode/binding/ButtonSprite.hpp>
#include <Geode/binding/CCMenuItemSpriteExtra.hpp>
#include <Geode/binding/CheckpointGameObject.hpp>
#include <Geode/binding/CheckpointObject.hpp>
#include <Geode/binding/GameObject.hpp>
#include <Geode/binding/GJGameLevel.hpp>
#include <Geode/binding/GradientTriggerObject.hpp>
#include <Geode/binding/LevelInfoLayer.hpp>
#include <Geode/binding/PauseLayer.hpp>
#include <Geode/binding/PlayerCheckpoint.hpp>
#include <Geode/binding/PlayerObject.hpp>
#include <Geode/binding/PlayLayer.hpp>
#include <Geode/binding/SavedActiveObjectState.hpp>
#include <Geode/binding/SavedObjectStateRef.hpp>
#include <Geode/binding/SavedSpecialObjectState.hpp>
#include <Geode/binding/SequenceTriggerState.hpp>
#include <Geode/cocos/cocoa/CCArray.h>
#include <Geode/cocos/platform/CCPlatformMacros.h>
#include <Geode/utils/string.hpp>

#include <PersistenceAPI.hpp>

#include <algorithm>
#include <chrono>
#include <cstdint>
#include <cstring>
#include <filesystem>
#include <optional>
#include <string>
#include <string_view>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace geode::prelude;
using namespace persistenceAPI;
using geode::utils::string::pathToString;

class $modify(PlatformerSaveCheckpointObject, CheckpointObject) {
protected:
    friend void operator>>(persistenceAPI::Stream& stream, PlatformerSaveCheckpointObject& value);
    friend void operator<<(persistenceAPI::Stream& stream, PlatformerSaveCheckpointObject& value);

public:
    struct Fields {
        bool m_wasLoaded = false;
        cocos2d::CCPoint m_position = { 0.f, 0.f };
        double m_timePlayed = 0.0;
        long long m_timestamp = 0;
    };

    void load(persistenceAPI::Stream& stream) {
        reinterpret_cast<PACCNode*>(this)->load(stream);
        stream >> *this;
    }

    void save(persistenceAPI::Stream& stream) {
        reinterpret_cast<PACCNode*>(this)->save(stream);
        stream << *this;
    }

    void clean() {
        if (!m_fields->m_wasLoaded) return;

        reinterpret_cast<PAGJGameState*>(&m_gameState)->clean();
        reinterpret_cast<PAEffectManagerState*>(&m_effectManagerState)->clean();

        m_vectorSavedObjectStateRef.clear();
        gd::vector<SavedObjectStateRef>().swap(m_vectorSavedObjectStateRef);

        m_vectorActiveSaveObjectState.clear();
        gd::vector<SavedActiveObjectState>().swap(m_vectorActiveSaveObjectState);

        m_vectorSpecialSaveObjectState.clear();
        gd::vector<SavedSpecialObjectState>().swap(m_vectorSpecialSaveObjectState);
    }
};

inline void operator>>(persistenceAPI::Stream& stream, PlatformerSaveCheckpointObject& value) {
    SEPARATOR_I_C(GAME)
    reinterpret_cast<PAGJGameState*>(&value.m_gameState)->load(stream);
    SEPARATOR_I_C(GAME)
    SEPARATOR_I_C(SHAD)
    reinterpret_cast<PAGJShaderState*>(&value.m_shaderState)->load(stream);
    SEPARATOR_I_C(SHAD)
    SEPARATOR_I_C(AUDI)
    reinterpret_cast<PAFMODAudioState*>(&value.m_audioState)->load(stream);
    SEPARATOR_I_C(AUDI)
    stream >> value.m_fields->m_position;
    SEPARATOR_I

    value.m_player1Checkpoint = PlayerCheckpoint::create();
    CC_SAFE_RETAIN(value.m_player1Checkpoint);
    reinterpret_cast<PAPlayerCheckpoint*>(value.m_player1Checkpoint)->load(stream);

    bool hasPlayer2 = false;
    stream >> hasPlayer2;
    SEPARATOR_I
    if (hasPlayer2) {
        value.m_player2Checkpoint = PlayerCheckpoint::create();
        CC_SAFE_RETAIN(value.m_player2Checkpoint);
        reinterpret_cast<PAPlayerCheckpoint*>(value.m_player2Checkpoint)->load(stream);
    }

    stream >> value.m_unke78;
    SEPARATOR_I
    stream >> value.m_unke7c;
    SEPARATOR_I
    stream >> value.m_unke80;
    SEPARATOR_I
    if (stream.getPAVersion() > 1) {
        stream >> value.m_ground2Invisible;
        SEPARATOR_I
        stream >> value.m_streakBlend;
    }
    else {
        stream.read(reinterpret_cast<char*>(&value.m_ground2Invisible), 2);
    }
    SEPARATOR_I
    stream >> value.m_uniqueID;
    SEPARATOR_I
    stream >> value.m_respawnID;
    VEC_SEPARATOR_I
    stream >> value.m_vectorSavedObjectStateRef;
    VEC_SEPARATOR_I
    stream >> value.m_vectorActiveSaveObjectState;
    VEC_SEPARATOR_I
    stream >> value.m_vectorSpecialSaveObjectState;
    VEC_SEPARATOR_I
    SEPARATOR_I_C(EFFE)
    reinterpret_cast<PAEffectManagerState*>(&value.m_effectManagerState)->load(stream);
    SEPARATOR_I_C(EFFE)

    bool hasGradientTriggerObjectArray = false;
    stream >> hasGradientTriggerObjectArray;
    SEPARATOR_I
    if (hasGradientTriggerObjectArray) {
        value.m_gradientTriggerObjectArray = CCArray::create();
        CC_SAFE_RETAIN(value.m_gradientTriggerObjectArray);
        static_cast<PACCArray*>(value.m_gradientTriggerObjectArray)->load<GradientTriggerObject>(stream);
        ARR_SEPARATOR_I
    }

    stream >> value.m_unk11e8;
    UMAP_SEPARATOR_I
    stream >> value.m_sequenceTriggerStateUnorderedMap;
    UMAP_SEPARATOR_I
    if (stream.getPAVersion() > 1) {
        stream >> value.m_commandIndex;
    }
    else {
        stream.read(reinterpret_cast<char*>(&value.m_commandIndex), 8);
    }
    SEPARATOR_I

    stream >> value.m_fields->m_timePlayed;
    stream >> value.m_fields->m_timestamp;
    value.m_fields->m_wasLoaded = true;
}

inline void operator<<(persistenceAPI::Stream& stream, PlatformerSaveCheckpointObject& value) {
    SEPARATOR_O_C(GAME)
    reinterpret_cast<PAGJGameState*>(&value.m_gameState)->save(stream);
    SEPARATOR_O_C(GAME)
    SEPARATOR_O_C(SHAD)
    reinterpret_cast<PAGJShaderState*>(&value.m_shaderState)->save(stream);
    SEPARATOR_O_C(SHAD)
    SEPARATOR_O_C(AUDI)
    reinterpret_cast<PAFMODAudioState*>(&value.m_audioState)->save(stream);
    SEPARATOR_O_C(AUDI)
    stream << value.m_physicalCheckpointObject->m_startPosition;
    SEPARATOR_O

    reinterpret_cast<PAPlayerCheckpoint*>(value.m_player1Checkpoint)->save(stream);
    bool hasPlayer2 = value.m_player2Checkpoint != nullptr;
    stream << hasPlayer2;
    SEPARATOR_O
    if (hasPlayer2) {
        reinterpret_cast<PAPlayerCheckpoint*>(value.m_player2Checkpoint)->save(stream);
    }

    stream << value.m_unke78;
    SEPARATOR_O
    stream << value.m_unke7c;
    SEPARATOR_O
    stream << value.m_unke80;
    SEPARATOR_O
    stream << value.m_ground2Invisible;
    SEPARATOR_O
    stream << value.m_streakBlend;
    SEPARATOR_O
    stream << value.m_uniqueID;
    SEPARATOR_O
    stream << value.m_respawnID;
    VEC_SEPARATOR_O
    stream << value.m_vectorSavedObjectStateRef;
    VEC_SEPARATOR_O
    stream << value.m_vectorActiveSaveObjectState;
    VEC_SEPARATOR_O
    stream << value.m_vectorSpecialSaveObjectState;
    VEC_SEPARATOR_O
    SEPARATOR_O_C(EFFE)
    reinterpret_cast<PAEffectManagerState*>(&value.m_effectManagerState)->save(stream);
    SEPARATOR_O_C(EFFE)

    bool hasGradientTriggerObjectArray = value.m_gradientTriggerObjectArray != nullptr;
    stream << hasGradientTriggerObjectArray;
    SEPARATOR_O
    if (hasGradientTriggerObjectArray) {
        static_cast<PACCArray*>(value.m_gradientTriggerObjectArray)->save<GradientTriggerObject>(stream);
        ARR_SEPARATOR_O
    }

    stream << value.m_unk11e8;
    UMAP_SEPARATOR_O
    stream << value.m_sequenceTriggerStateUnorderedMap;
    UMAP_SEPARATOR_O
    stream << value.m_commandIndex;
    SEPARATOR_O

    stream << value.m_fields->m_timePlayed;
    stream << value.m_fields->m_timestamp;
}

namespace {
    constexpr char kMagic[] = { 'F', 'P', 'S', 'A', 'V', 'E', '2', '\0' };
    constexpr int kSaveFormatVersion = 3;
    constexpr int kPAVersion = 2;

#if defined(GEODE_IS_WINDOWS)
    constexpr int kUniqueIDOffset = 0x6ba158;
#endif

    enum class RunChoice {
        None,
        NewSave,
        LoadSave,
        NoSave
    };

    std::unordered_set<PlayLayer*> g_activeSaveRuns;
    std::unordered_set<PlayLayer*> g_restoringLayers;
    std::unordered_set<LevelInfoLayer*> g_bypassPlayPrompt;
    std::unordered_map<int, RunChoice> g_pendingChoices;
    std::unordered_map<PlayLayer*, std::vector<int>> g_activatedCheckpointUIDs;
    std::unordered_map<PlayLayer*, GameObject*> g_hiddenCheckpointObjects;

    struct LoadedRuntimeData {
        cocos2d::CCPoint position = { 0.f, 0.f };
        CheckpointObject* checkpoint = nullptr;
        bool objectStateApplied = false;
        double timePlayed = 0.0;
        double levelTime = 0.0;
        double totalTime = 0.0;
        int attempts = 0;
        gd::unordered_map<int, int> persistentItemCountMap;
        gd::unordered_set<int> persistentTimerItemSet;
    };

    std::unordered_map<PlayLayer*, LoadedRuntimeData> g_loadedRuntimeData;

    bool enabled() {
        return Mod::get()->getSettingValue<bool>("enabled");
    }

    int levelKey(GJGameLevel* level) {
        return level ? static_cast<int>(level->m_levelID.value()) : 0;
    }

    std::filesystem::path saveDirectory(bool persistent) {
        auto base = persistent ? Mod::get()->getPersistentDir(true) : Mod::get()->getSaveDir();
        return base / "saves";
    }

    bool ensureDirectory(std::filesystem::path const& directory) {
        std::error_code ec;
        std::filesystem::create_directories(directory, ec);
        if (ec) {
            log::warn("Platformer Save could not create save directory {}: {}", pathToString(directory), ec.message());
            return false;
        }
        return true;
    }

    std::filesystem::path savePath(int id, bool persistent) {
        return saveDirectory(persistent) / (std::to_string(id) + ".psf");
    }

    std::filesystem::path legacyJsonSavePath(int id, bool persistent) {
        return saveDirectory(persistent) / (std::to_string(id) + ".json");
    }

    bool existingFileWithMinSize(std::filesystem::path const& path, std::uintmax_t minSize) {
        std::error_code ec;
        if (!std::filesystem::exists(path, ec) || ec) return false;

        auto size = std::filesystem::file_size(path, ec);
        return !ec && size >= minSize;
    }

    uint32_t stableHash(std::string_view value) {
        uint32_t hash = 2166136261u;
        for (unsigned char ch : value) {
            hash ^= ch;
            hash *= 16777619u;
        }
        return hash;
    }

    uint32_t levelHash(GJGameLevel* level) {
        if (!level) return 0;
        return stableHash(level->m_levelString.c_str());
    }

    long long nowMillis() {
        return std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()
        ).count();
    }

    int readHeaderVersion(Stream& stream) {
        char magic[sizeof(kMagic)] = {};
        stream.read(magic, sizeof(kMagic));
        if (std::memcmp(magic, kMagic, sizeof(kMagic)) != 0) return 0;

        bool finishedSaving = false;
        stream.read(reinterpret_cast<char*>(&finishedSaving), sizeof(finishedSaving));
        if (!finishedSaving) return 0;

        int formatVersion = 0;
        stream >> formatVersion;
        if (formatVersion == 2 || formatVersion == kSaveFormatVersion) {
            return formatVersion;
        }
        return 0;
    }

    bool readHeader(Stream& stream) {
        return readHeaderVersion(stream) != 0;
    }

    void writeHeader(Stream& stream) {
        stream.write(const_cast<char*>(kMagic), sizeof(kMagic));

        bool finishedSaving = false;
        stream.write(reinterpret_cast<char*>(&finishedSaving), sizeof(finishedSaving));

        int formatVersion = kSaveFormatVersion;
        stream << formatVersion;
    }

    void markHeaderFinished(Stream& stream) {
        stream.seek(sizeof(kMagic));
        bool finishedSaving = true;
        stream.write(reinterpret_cast<char*>(&finishedSaving), sizeof(finishedSaving));
    }

    bool hasSave(int id) {
        for (bool persistent : { true, false }) {
            auto path = savePath(id, persistent);
            if (!existingFileWithMinSize(path, sizeof(kMagic) + sizeof(bool) + sizeof(int))) {
                continue;
            }

            Stream stream;
            if (stream.setFile(pathToString(path), kPAVersion) && readHeader(stream)) {
                stream.end();
                return true;
            }
            stream.end();
        }
        return false;
    }

    std::optional<std::filesystem::path> firstReadableSavePath(int id) {
        for (bool persistent : { true, false }) {
            auto path = savePath(id, persistent);
            if (existingFileWithMinSize(path, 1)) {
                return path;
            }
        }
        return std::nullopt;
    }

    void deleteSave(int id) {
        std::error_code ec;
        for (bool persistent : { true, false }) {
            std::filesystem::remove(savePath(id, persistent), ec);
            std::filesystem::remove(legacyJsonSavePath(id, persistent), ec);
        }
    }

    bool isActiveSaveRun(PlayLayer* layer) {
        return layer && g_activeSaveRuns.contains(layer);
    }

    bool isRestoring(PlayLayer* layer) {
        return layer && g_restoringLayers.contains(layer);
    }

    bool runtimeSaveStateStable(PlayLayer* layer) {
        return layer &&
            !layer->m_hasCompletedLevel &&
            !layer->m_inResetDelay &&
            (!layer->m_player1 || !layer->m_player1->m_isDead);
    }

    bool shouldPreserveCheckpointAudio(PlayLayer* layer) {
        return enabled() &&
            isActiveSaveRun(layer) &&
            layer &&
            layer->m_level &&
            layer->m_level->isPlatformer() &&
            layer->m_checkpointArray &&
            layer->m_checkpointArray->count() > 0;
    }

    void recordActivatedCheckpoint(PlayLayer* layer, CheckpointGameObject* object) {
        if (!layer || !object) return;

        auto uid = object->m_uniqueID;
        auto& uids = g_activatedCheckpointUIDs[layer];
        if (std::find(uids.begin(), uids.end(), uid) == uids.end()) {
            uids.push_back(uid);
        }
    }

    RunChoice takePendingChoice(int id) {
        auto it = g_pendingChoices.find(id);
        if (it == g_pendingChoices.end()) return RunChoice::None;
        auto choice = it->second;
        g_pendingChoices.erase(it);
        return choice;
    }

    bool hasPendingChoice(LevelInfoLayer* layer) {
        auto id = levelKey(layer ? layer->m_level : nullptr);
        return id != 0 && g_pendingChoices.contains(id);
    }

    CheckpointGameObject* findCheckpointObject(PlayLayer* layer, int uid) {
        if (!layer || !layer->m_objects || uid == 0) return nullptr;

        for (unsigned int i = 0; i < layer->m_objects->count(); ++i) {
            auto object = typeinfo_cast<CheckpointGameObject*>(layer->m_objects->objectAtIndex(i));
            if (object && object->m_uniqueID == uid) return object;
        }

        return nullptr;
    }

    int activeCheckpointUID(PlayLayer* layer, CheckpointObject* checkpoint) {
        if (!layer || !checkpoint) return 0;
        if (layer->m_activatedCheckpoint) return layer->m_activatedCheckpoint->m_uniqueID;
        if (checkpoint->m_physicalCheckpointObject) return checkpoint->m_physicalCheckpointObject->m_uniqueID;
        return 0;
    }

    GameObject* createHiddenCheckpointObject(cocos2d::CCPoint position) {
        auto object = GameObject::createWithFrame("square_01_001.png");
        if (!object) return nullptr;

        CC_SAFE_RETAIN(object);
        object->m_objectID = 0x2c;
        object->m_objectType = GameObjectType::Decoration;
        object->m_glowSprite = nullptr;
        object->m_isDisabled2 = true;
        object->m_isInvisible = true;
        object->setOpacity(0);
        object->setStartPos(position);
        return object;
    }

    bool writeSaveFile(std::filesystem::path const& path, PlayLayer* layer, CheckpointObject* checkpoint) {
        if (!layer || !layer->m_level || !checkpoint || !checkpoint->m_player1Checkpoint || !checkpoint->m_physicalCheckpointObject) {
            return false;
        }
        if (!ensureDirectory(path.parent_path())) {
            return false;
        }

        auto psCheckpoint = static_cast<PlatformerSaveCheckpointObject*>(checkpoint);
        auto oldLevelTime = checkpoint->m_gameState.m_levelTime;
        auto oldTotalTime = checkpoint->m_gameState.m_totalTime;
        auto oldTimePlayed = psCheckpoint->m_fields->m_timePlayed;
        auto oldTimestamp = psCheckpoint->m_fields->m_timestamp;

        checkpoint->m_gameState.m_levelTime = layer->m_gameState.m_levelTime;
        checkpoint->m_gameState.m_totalTime = layer->m_gameState.m_totalTime;
        psCheckpoint->m_fields->m_timePlayed = layer->m_timePlayed;
        psCheckpoint->m_fields->m_timestamp = nowMillis();

        Stream stream;
        if (!stream.setFile(pathToString(path), kPAVersion, true)) {
            checkpoint->m_gameState.m_levelTime = oldLevelTime;
            checkpoint->m_gameState.m_totalTime = oldTotalTime;
            psCheckpoint->m_fields->m_timePlayed = oldTimePlayed;
            psCheckpoint->m_fields->m_timestamp = oldTimestamp;
            return false;
        }

        writeHeader(stream);

        int id = levelKey(layer->m_level);
        uint32_t hash = levelHash(layer->m_level);
        int checkpointUID = activeCheckpointUID(layer, checkpoint);
        stream << id;
        stream << hash;
        stream << checkpointUID;

        auto& activatedUIDs = g_activatedCheckpointUIDs[layer];
        auto activatedCount = static_cast<unsigned int>(activatedUIDs.size());
        stream << activatedCount;
        for (auto uid : activatedUIDs) {
            stream << uid;
        }

        psCheckpoint->save(stream);

        if (layer->m_effectManager) {
            stream << layer->m_effectManager->m_persistentItemCountMap;
            stream << layer->m_effectManager->m_persistentTimerItemSet;
        }
        else {
            gd::unordered_map<int, int> emptyCounts;
            gd::unordered_set<int> emptyTimers;
            stream << emptyCounts;
            stream << emptyTimers;
        }
        stream << layer->m_attempts;

        markHeaderFinished(stream);
        stream.end();

        checkpoint->m_gameState.m_levelTime = oldLevelTime;
        checkpoint->m_gameState.m_totalTime = oldTotalTime;
        psCheckpoint->m_fields->m_timePlayed = oldTimePlayed;
        psCheckpoint->m_fields->m_timestamp = oldTimestamp;
        return true;
    }

    void saveCheckpoint(PlayLayer* layer, CheckpointObject* checkpoint) {
        if (!enabled() || !isActiveSaveRun(layer) || isRestoring(layer) || !runtimeSaveStateStable(layer) || !layer->m_level || !layer->m_level->isPlatformer() || !checkpoint) {
            return;
        }

        auto id = levelKey(layer->m_level);
        if (id == 0) return;

        bool wroteAny = false;
        for (bool persistent : { true, false }) {
            wroteAny = writeSaveFile(savePath(id, persistent), layer, checkpoint) || wroteAny;
        }

        if (!wroteAny) {
            log::warn("Platformer Save could not write checkpoint for level {}", id);
        }
    }

    void saveCurrentCheckpoint(PlayLayer* layer) {
        if (!enabled() || !isActiveSaveRun(layer) || isRestoring(layer) || !runtimeSaveStateStable(layer) || !layer->m_level || !layer->m_level->isPlatformer()) {
            return;
        }

        if (auto checkpoint = layer->getLastCheckpoint()) {
            saveCheckpoint(layer, checkpoint);
        }
    }

    void applyLoadedRuntimeData(PlayLayer* layer, bool erase) {
        if (!layer) return;

        auto it = g_loadedRuntimeData.find(layer);
        if (it == g_loadedRuntimeData.end()) return;

        auto& data = it->second;
        if (data.checkpoint && !data.objectStateApplied) {
            g_restoringLayers.insert(layer);
            layer->loadFromCheckpoint(data.checkpoint);
            g_restoringLayers.erase(layer);
            data.objectStateApplied = true;
        }
        if (layer->m_effectManager) {
            layer->m_effectManager->m_persistentItemCountMap = data.persistentItemCountMap;
            layer->m_effectManager->m_persistentTimerItemSet = data.persistentTimerItemSet;
        }
        layer->m_attempts = data.attempts;
        layer->m_timePlayed = data.timePlayed;
        layer->m_gameState.m_levelTime = data.levelTime;
        layer->m_gameState.m_totalTime = data.totalTime;
        if (layer->m_player1) {
            layer->m_player1->setStartPos(data.position);
        }

        if (erase) {
            g_loadedRuntimeData.erase(it);
        }
    }

    bool restoreSaveBeforeSetup(PlayLayer* layer) {
        if (!enabled() || !layer || !layer->m_level || !layer->m_level->isPlatformer()) return false;

        auto path = firstReadableSavePath(levelKey(layer->m_level));
        if (!path) return false;

        Stream stream;
        if (!stream.setFile(pathToString(*path), kPAVersion)) {
            stream.end();
            return false;
        }

        auto saveVersion = readHeaderVersion(stream);
        if (saveVersion == 0) {
            stream.end();
            return false;
        }

        int savedLevelID = 0;
        uint32_t savedLevelHash = 0;
        int checkpointUID = 0;
        stream >> savedLevelID;
        stream >> savedLevelHash;
        stream >> checkpointUID;

        std::vector<int> activatedUIDs;
        if (saveVersion >= 3) {
            unsigned int activatedCount = 0;
            stream >> activatedCount;
            activatedUIDs.reserve(activatedCount);
            for (unsigned int i = 0; i < activatedCount; ++i) {
                int uid = 0;
                stream >> uid;
                if (uid != 0) {
                    activatedUIDs.push_back(uid);
                }
            }
        }
        else if (checkpointUID != 0) {
            activatedUIDs.push_back(checkpointUID);
        }

        if (savedLevelID != levelKey(layer->m_level)) {
            stream.end();
            return false;
        }

        if (savedLevelHash != 0 && savedLevelHash != levelHash(layer->m_level)) {
            log::warn("Loading Platformer Save for level {} even though the level string changed", savedLevelID);
        }

        auto checkpoint = static_cast<PlatformerSaveCheckpointObject*>(CheckpointObject::create());
        if (!checkpoint) {
            stream.end();
            return false;
        }
        checkpoint->load(stream);

        gd::unordered_map<int, int> persistentItemCountMap;
        gd::unordered_set<int> persistentTimerItemSet;
        int attempts = layer->m_attempts;
        stream >> persistentItemCountMap;
        stream >> persistentTimerItemSet;
        stream >> attempts;
        stream.end();

        auto hiddenCheckpoint = createHiddenCheckpointObject(checkpoint->m_fields->m_position);
        if (!hiddenCheckpoint) return false;

        CC_SAFE_RELEASE(checkpoint->m_physicalCheckpointObject);
        checkpoint->m_physicalCheckpointObject = hiddenCheckpoint;

        g_restoringLayers.insert(layer);
        if (layer->m_checkpointArray) {
            layer->m_checkpointArray->addObject(checkpoint);
        }
        layer->m_currentCheckpoint = checkpoint;
        g_hiddenCheckpointObjects[layer] = hiddenCheckpoint;
        layer->addToSection(hiddenCheckpoint);
        hiddenCheckpoint->activateObject();
        for (auto uid : activatedUIDs) {
            if (auto realCheckpoint = findCheckpointObject(layer, uid)) {
                realCheckpoint->triggerActivated(0.0f);
            }
        }
        g_activatedCheckpointUIDs[layer] = activatedUIDs;
        if (layer->m_player1) {
            layer->m_player1->setStartPos(checkpoint->m_fields->m_position);
        }
        g_restoringLayers.erase(layer);

        LoadedRuntimeData data;
        data.position = checkpoint->m_fields->m_position;
        data.checkpoint = checkpoint;
        data.timePlayed = checkpoint->m_fields->m_timePlayed;
        data.levelTime = checkpoint->m_gameState.m_levelTime;
        data.totalTime = checkpoint->m_gameState.m_totalTime;
        data.attempts = attempts;
        data.persistentItemCountMap = persistentItemCountMap;
        data.persistentTimerItemSet = persistentTimerItemSet;
        g_loadedRuntimeData[layer] = data;

        return true;
    }

    class SaveChoicePopup : public Popup {
    protected:
        LevelInfoLayer* m_infoLayer = nullptr;
        int m_levelID = 0;

        bool setup(LevelInfoLayer* layer, bool saveExists) {
            constexpr float width = 340.f;
            constexpr float height = 190.f;
            constexpr float center = width / 2.f;

            m_infoLayer = layer;
            m_levelID = levelKey(layer ? layer->m_level : nullptr);

            this->setID("save-choice-popup"_spr);
            m_buttonMenu->setID("save-choice-menu"_spr);
            this->setTitle("Platformer Save", "goldFont.fnt", .62f, 20.f);

            auto text = CCLabelBMFont::create(
                saveExists ? "Saved Run Found" : "No Saved Run",
                "bigFont.fnt"
            );
            text->setID("save-status-label"_spr);
            text->limitLabelWidth(width - 44.f, .5f, .1f);
            text->setPosition({ center, height - 64.f });
            m_mainLayer->addChild(text);

            auto info = CCLabelBMFont::create(
                saveExists ? "Load it, overwrite it, delete it, or play once without saving." : "Start saving this run or play once without saving.",
                "chatFont.fnt"
            );
            info->setID("save-help-label"_spr);
            info->limitLabelWidth(width - 36.f, .58f, .25f);
            info->setPosition({ center, height - 94.f });
            m_mainLayer->addChild(info);

            if (saveExists) {
                addButton("New Save", center - 68.f, 62.f, 1, "new-save-button"_spr);
                addButton("Load Save", center + 68.f, 62.f, 3, "load-save-button"_spr);
                addButton("No Save", center - 68.f, 28.f, 2, "no-save-button"_spr);
                addButton("Delete", center + 68.f, 28.f, 4, "delete-save-button"_spr, "GJ_button_06.png");
            }
            else {
                addButton("Start Save", center - 68.f, 42.f, 1, "start-save-button"_spr);
                addButton("No Save", center + 68.f, 42.f, 2, "no-save-button"_spr);
            }
            return true;
        }

        void addButton(char const* label, float x, float y, int tag, std::string const& id, char const* bg = "GJ_button_01.png") {
            auto sprite = ButtonSprite::create(label, 104, 0, .5f, true, "bigFont.fnt", bg, 30.f);
            sprite->setID(id + "-sprite");
            auto button = CCMenuItemSpriteExtra::create(sprite, this, menu_selector(SaveChoicePopup::onChoice));
            button->setID(id);
            button->setTag(tag);
            button->setPosition({ x, y });
            m_buttonMenu->addChild(button);
        }

        void onChoice(cocos2d::CCObject* sender) {
            auto tag = sender ? sender->getTag() : 2;
            if (tag == 4) {
                if (m_levelID != 0) {
                    deleteSave(m_levelID);
                }
                this->onClose(nullptr);
                if (m_infoLayer) {
                    if (auto popup = SaveChoicePopup::create(m_infoLayer, false)) {
                        popup->show();
                    }
                }
                return;
            }
            if (m_infoLayer && m_levelID != 0) {
                if (tag == 1) g_pendingChoices[m_levelID] = RunChoice::NewSave;
                else if (tag == 3) g_pendingChoices[m_levelID] = RunChoice::LoadSave;
                else g_pendingChoices[m_levelID] = RunChoice::NoSave;
                g_bypassPlayPrompt.insert(m_infoLayer);
            }
            if (m_infoLayer) {
                m_infoLayer->runAction(cocos2d::CCSequence::create(
                    cocos2d::CCDelayTime::create(.05f),
                    cocos2d::CCCallFunc::create(m_infoLayer, callfunc_selector(LevelInfoLayer::playStep3)),
                    nullptr
                ));
            }
            this->onClose(nullptr);
        }

    public:
        static SaveChoicePopup* create(LevelInfoLayer* layer, bool saveExists) {
            auto ret = new SaveChoicePopup();
            if (ret && ret->init(340.f, 190.f) && ret->setup(layer, saveExists)) {
                ret->autorelease();
                return ret;
            }
            delete ret;
            return nullptr;
        }
    };

    bool showSaveChoice(LevelInfoLayer* layer) {
        if (!enabled() || !layer || !layer->m_level || !layer->m_level->isPlatformer()) return false;
        if (auto popup = SaveChoicePopup::create(layer, hasSave(levelKey(layer->m_level)))) {
            popup->show();
            return true;
        }
        return false;
    }
}

class $modify(PlatformerSaveLevelInfoLayer, LevelInfoLayer) {
    void playStep3() {
        if (g_bypassPlayPrompt.erase(this) > 0 || hasPendingChoice(this)) {
            LevelInfoLayer::playStep3();
            return;
        }
        if (showSaveChoice(this)) return;
        LevelInfoLayer::playStep3();
    }

    void onExit() {
        g_bypassPlayPrompt.erase(this);
        LevelInfoLayer::onExit();
    }
};

class $modify(PlatformerSavePlayLayer, PlayLayer) {
    struct Fields {
        bool m_shouldLoad = false;
        bool m_inPostUpdate = false;
        bool m_triedPlacingCheckpoint = false;
        bool m_startedLoadingObjects = false;
        bool m_inSetupHasCompleted = false;
        bool m_inResetLevel = false;
        bool m_blockSaveUntilReset = false;
    };

    bool init(GJGameLevel* level, bool useReplay, bool dontCreateObjects) {
        GameObject::resetMID();
        reinterpret_cast<PAPlayLayer*>(this)->m_fields->m_uniqueIDBase = 12;

        if (!PlayLayer::init(level, useReplay, dontCreateObjects)) return false;

        if (enabled() && level && level->isPlatformer()) {
            auto id = levelKey(level);
            auto choice = takePendingChoice(id);

            if (choice == RunChoice::NewSave) {
                deleteSave(id);
                g_activeSaveRuns.insert(this);
                g_activatedCheckpointUIDs.erase(this);
                g_hiddenCheckpointObjects.erase(this);
            }
            else if (choice == RunChoice::LoadSave) {
                g_activeSaveRuns.insert(this);
                m_fields->m_shouldLoad = true;
            }
            else if (choice == RunChoice::NoSave) {
                g_activeSaveRuns.erase(this);
                g_activatedCheckpointUIDs.erase(this);
                g_hiddenCheckpointObjects.erase(this);
            }
            else if (!hasSave(id)) {
                g_activeSaveRuns.insert(this);
                g_activatedCheckpointUIDs.erase(this);
                g_hiddenCheckpointObjects.erase(this);
            }
        }

        return true;
    }

    void setupHasCompleted() {
        if (m_fields->m_shouldLoad) {
            m_fields->m_shouldLoad = false;
            restoreSaveBeforeSetup(this);
        }

        m_fields->m_inSetupHasCompleted = true;
        PlayLayer::setupHasCompleted();
        m_fields->m_inSetupHasCompleted = false;
        applyLoadedRuntimeData(this, false);
    }

    void processCreateObjectsFromSetup() {
#if defined(GEODE_IS_WINDOWS)
        if (!m_fields->m_startedLoadingObjects) {
            m_fields->m_startedLoadingObjects = true;
            *reinterpret_cast<int*>(geode::base::get() + kUniqueIDOffset) = 12;
            reinterpret_cast<PAPlayLayer*>(this)->m_fields->m_uniqueIDBase = 12;
        }
#endif
        PlayLayer::processCreateObjectsFromSetup();
    }

    void postUpdate(float dt) {
        m_fields->m_inPostUpdate = true;
        m_fields->m_triedPlacingCheckpoint = m_tryPlaceCheckpoint;
        PlayLayer::postUpdate(dt);
        applyLoadedRuntimeData(this, true);
        m_fields->m_inPostUpdate = false;
        m_fields->m_triedPlacingCheckpoint = false;
    }

    void loadFromCheckpoint(CheckpointObject* object) {
        auto it = g_loadedRuntimeData.find(this);
        bool restoringLoadedSave = it != g_loadedRuntimeData.end() && it->second.checkpoint == object;

        if (restoringLoadedSave) {
            g_restoringLayers.insert(this);
        }
        PlayLayer::loadFromCheckpoint(object);
        if (restoringLoadedSave) {
            auto updated = g_loadedRuntimeData.find(this);
            if (updated != g_loadedRuntimeData.end()) {
                updated->second.objectStateApplied = true;
            }
            g_restoringLayers.erase(this);
        }
    }

    void prepareMusic(bool dontWait) {
        if (m_fields->m_inSetupHasCompleted && !m_fields->m_inResetLevel && shouldPreserveCheckpointAudio(this)) {
            return;
        }
        PlayLayer::prepareMusic(dontWait);
    }

    void startMusic() {
        if (shouldPreserveCheckpointAudio(this)) {
            return;
        }
        PlayLayer::startMusic();
    }

    void resetLevel() {
        m_fields->m_inResetLevel = true;
        PlayLayer::resetLevel();
        m_fields->m_inResetLevel = false;
        m_fields->m_blockSaveUntilReset = false;
    }

    void destroyPlayer(PlayerObject* player, GameObject* object) {
        m_fields->m_blockSaveUntilReset = true;
        PlayLayer::destroyPlayer(player, object);
    }

    void updateVisibility(float dt) {
        PlayLayer::updateVisibility(dt);
        if (auto it = g_hiddenCheckpointObjects.find(this); it != g_hiddenCheckpointObjects.end() && it->second) {
            it->second->m_isInvisible = true;
            it->second->setOpacity(0);
        }
    }

    CheckpointObject* markCheckpoint() {
        auto checkpoint = PlayLayer::markCheckpoint();

        if (
            checkpoint &&
            enabled() &&
            isActiveSaveRun(this) &&
            !isRestoring(this) &&
            this->m_level &&
            this->m_level->isPlatformer() &&
            !this->m_isPracticeMode &&
            m_fields->m_inPostUpdate &&
            !m_fields->m_triedPlacingCheckpoint &&
            !m_fields->m_blockSaveUntilReset &&
            runtimeSaveStateStable(this) &&
            this->m_activatedCheckpoint
        ) {
            recordActivatedCheckpoint(this, this->m_activatedCheckpoint);
            saveCheckpoint(this, checkpoint);
        }

        return checkpoint;
    }

    void checkpointActivated(CheckpointGameObject* object) {
        PlayLayer::checkpointActivated(object);
        if (enabled() && isActiveSaveRun(this) && !isRestoring(this) && this->m_level && this->m_level->isPlatformer()) {
            recordActivatedCheckpoint(this, object);
        }
    }

    void onQuit() {
        saveCurrentCheckpoint(this);
        PlayLayer::onQuit();
    }

    void onExit() {
        saveCurrentCheckpoint(this);
        g_activeSaveRuns.erase(this);
        g_restoringLayers.erase(this);
        g_loadedRuntimeData.erase(this);
        g_activatedCheckpointUIDs.erase(this);
        g_hiddenCheckpointObjects.erase(this);
        PlayLayer::onExit();
    }

    void levelComplete() {
        if (this->m_level && this->m_level->isPlatformer()) {
            if (Mod::get()->getSettingValue<bool>("remove-save-on-complete")) {
                deleteSave(levelKey(this->m_level));
            }
            g_activeSaveRuns.erase(this);
            g_activatedCheckpointUIDs.erase(this);
            g_hiddenCheckpointObjects.erase(this);
        }
        PlayLayer::levelComplete();
    }
};

class $modify(PlatformerSavePauseLayer, PauseLayer) {
    void tryQuit(cocos2d::CCObject* sender) {
        if (auto playLayer = PlayLayer::get()) {
            saveCurrentCheckpoint(playLayer);
        }
        PauseLayer::tryQuit(sender);
    }

    void onQuit(cocos2d::CCObject* sender) {
        if (auto playLayer = PlayLayer::get()) {
            saveCurrentCheckpoint(playLayer);
        }
        PauseLayer::onQuit(sender);
    }
};
