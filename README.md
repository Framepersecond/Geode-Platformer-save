# Platformer Save

Platformer Save is a Geode mod for Geometry Dash `2.2081` that saves and restores platformer checkpoint runs.

## Features

- Prompts before loading a platformer level: start a new save, load an existing save, play without saving, or delete the save.
- Saves the last platformer checkpoint state, including checkpoint object state, trigger state, persistent item counters, timers, and attempts.
- Refreshes the saved run time when quitting so loaded saves resume with a more accurate timer than checkpoint-only saves.
- Keeps saves after level completion by default. Saves are only removed with the in-game Delete button or when `Remove Save on Complete` is enabled.
- Stores saves in Geode persistent data and mirrors them to the mod save directory under `saves/` as `.psf` files for manual backup.

## Compatibility

- Geode: `5.7.1`
- Geometry Dash: Windows `2.2081`
- Mod ID: `frxme.platformer-save`

The mod uses Geode `$modify` hooks and does not install runtime code, download code, collect data, or patch other mods. UI nodes created by the mod use the `frxme.platformer-save` node ID prefix through Geode's `_spr` suffix.

## Save Files

Save files are named after the level ID:

```text
saves/<level-id>.psf
```

They are written to:

- Geode persistent mod data, used as the primary save location.
- Geode mod save data, used as a backup/export mirror.

The binary save format is versioned so future updates can add fields without invalidating older saves.

## Release Notes

This release targets the current Geode/GD versions and changes the old PlatformerSaves behavior by saving the latest quit time instead of only restoring the time from the last checkpoint.

Credits: inspired by the deprecated PlatformerSaves mod by Sabe and bundled with the GPL-licensed PersistenceAPI serialization code required for Geometry Dash checkpoint state.
