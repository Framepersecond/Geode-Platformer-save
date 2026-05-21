# Platformer Progression Save

Save and restore progress in Geometry Dash platformer levels.

Platformer Progression Save stores the last checkpoint state for a platformer level and lets you load it before the level starts. Unlike older checkpoint save mods, the run time is refreshed when you quit so loading a save resumes with the latest saved timer instead of only the checkpoint timer.

Saves are stored in Geode's persistent mod data directory and mirrored to the mod save directory under `saves/` as `.psf` files, so they can be copied or backed up outside the game.

Checkpoint serialization is provided by the required `sabe.persistenceapi` Geode dependency. This mod does not bundle `PersistenceAPI` or `PlatformerSaves` source code.
