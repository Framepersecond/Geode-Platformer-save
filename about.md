# Platformer Save

Save and restore progress in Geometry Dash platformer levels.

Platformer Save stores the last checkpoint state for a platformer level and lets you load it before the level starts. Unlike older checkpoint save mods, the run time is refreshed when you quit so loading a save resumes with the latest saved timer instead of only the checkpoint timer.

Saves are stored in Geode's persistent mod data directory and mirrored to the mod save directory under `saves/` as `.psf` files, so they can be copied or backed up outside the game.

Credits: inspired by the deprecated PlatformerSaves mod by Sabe and bundled with the GPL-licensed PersistenceAPI serialization code needed for checkpoint state.
