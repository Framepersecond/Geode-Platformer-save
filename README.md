# Platformer Progression Save

Platformer Progression Save is a Geode mod for Geometry Dash platformer levels. It saves your latest checkpoint progress and lets you resume that saved run before the level loads.

The mod is built for Geometry Dash `2.2081` on Windows and Geode `5.7.1`.

## Features

- Choose how to enter a platformer level before it loads: start a new save, load an existing save, play without saving, or delete the saved run.
- Saves checkpoint state, player state, trigger state, camera state, persistent item counters, timers, and attempts.
- Updates the saved timer when leaving the level, so loaded runs use the latest quit time instead of only the checkpoint timestamp.
- Keeps saves after completing a level unless `Remove Save on Complete` is enabled.
- Mirrors saves to an export-friendly save directory so they can be backed up manually.

## Requirements

- Geometry Dash: `2.2081`
- Geode: `5.7.1`
- Platform: Windows
- Required dependency: `sabe.persistenceapi >= v1.2.0`

The mod ID is `frxme.platformer-save`. The ID is intentionally unchanged so existing save paths and future updates remain compatible.

## Installation

1. Install Geode for Geometry Dash `2.2081`.
2. Install the required `sabe.persistenceapi` dependency through Geode.
3. Place `Platformer-Progression-Save.geode` in your Geode mods directory.
4. Start Geometry Dash and enable the mod if it is not already enabled.

## Save Files

Save files are named by level ID:

```text
saves/<level-id>.psf
```

They are written to Geode persistent mod data and mirrored to the mod save directory. The persistent copy is used first, and the mirror is kept for manual backup/export.

The save format is versioned so future updates can add fields without intentionally invalidating existing saves.

## Index Notes

This repository does not vendor or bundle source code from `PlatformerSaves` or `PersistenceAPI`. Serialization is provided by the declared `sabe.persistenceapi` Geode dependency.

The mod uses Geode `$modify` hooks and Geode-managed dependency resolution. It does not download runtime code, install other mods outside Geode's dependency system, collect user data, or patch unrelated mods.

## Credits

- Developer: Frxme
- Checkpoint serialization dependency: `sabe.persistenceapi` by Sabe

## License

See [LICENSE](LICENSE).
