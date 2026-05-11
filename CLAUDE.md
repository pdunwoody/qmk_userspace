# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Build Commands

First-time setup (must be run from the repo root):
```sh
qmk config user.overlay_dir="$(realpath .)"
```

Compile a single keyboard:
```sh
qmk compile -kb crkbd/rev4_1/standard -km pdunwoody
qmk compile -kb crkbd/rev1 -km pdunwoody
qmk compile -kb keebio/iris_ce/rev1 -km pdunwoody
```

Or using make:
```sh
make crkbd/rev4_1/standard:pdunwoody
make keebio/iris_ce/rev1:pdunwoody
```

Compile all targets defined in `qmk.json` at once:
```sh
qmk userspace-compile
```

Manage build targets:
```sh
qmk userspace-list
qmk userspace-add -kb <keyboard> -km <keymap>
qmk userspace-remove -kb <keyboard> -km <keymap>
```

CI builds run automatically on push via GitHub Actions (`.github/workflows/build_binaries.yaml`) and publish `.uf2` firmware files as release artifacts.

## Repository Structure

Three keyboards are maintained, all sharing an identical 8-layer layout philosophy:

| Keyboard | Path | Notes |
|---|---|---|
| Corne rev4.1 (standard) | `keyboards/crkbd/rev4_1/standard/keymaps/pdunwoody/` | RP2040, RGB Matrix, `LAYOUT_split_3x6_3_ex2` |
| Corne rev1 | `keyboards/crkbd/rev1/keymaps/pdunwoody/` | RP2040, RGB Matrix + OLED, `LAYOUT_split_3x6_3` |
| Keebio Iris CE rev1 | `keyboards/keebio/iris_ce/rev1/keymaps/pdunwoody/` | ATmega32U4, RGB Matrix, VIA enabled, `LAYOUT` (4-row split) |

The `modules/getreuer/` directory is a git submodule containing community QMK modules (currently unused/commented out in `rgb_matrix_user.inc`).

## Keymap Architecture

All three keyboards share the same 8-layer structure and custom keycode logic. When updating layers or keycodes, changes typically need to be mirrored across all three `keymap.c` files.

### Layers

| # | Name | Activated by |
|---|---|---|
| 0 | `_BASE` | Default (Colemak-style home row mods) |
| 1 | `_NUMBERS` | Hold `LT(1, TAB)` |
| 2 | `_EXTRA` | (Reserved / empty) |
| 3 | `_FUNCTION` | Hold `LT(3, ESC)` |
| 4 | `_SYMBOLS` | Hold `LT(4, ENT)` |
| 5 | `_NAVIGATION` | Hold `LT(5, BSPC)` |
| 6 | `_MEDIA` | Hold `LT(6, DEL)` |
| 7 | `_QWERTY` | `TG(7)` toggle |

### Home Row Mods

`_BASE` uses GACS (GUI/Alt/Ctrl/Shift) home row mods on both hands:
- Left: `LGUI_T(A)`, `LALT_T(S)`, `LCTL_T(D)`, `LSFT_T(F)`
- Right: `RSFT_T(J)`, `RCTL_T(K)`, `RALT_T(L)`, `RGUI_T(;)`

`CHORDAL_HOLD` and `PERMISSIVE_HOLD` are enabled in `config.h` to make home row mods reliable. `chordal_hold_layout` defines left-hand (`'L'`) vs right-hand (`'R'`) key zones so opposite-hand chords resolve immediately without waiting for `TAPPING_TERM` (250ms).

### Custom Keycodes

- **`MICMUTE`**: Sends `Win+Alt+K` (Microsoft Teams mute shortcut).
- **`CW_TOGG` override**: `process_record_user` intercepts Caps Word toggle — if Shift is held when `CW_TOGG` is pressed, it sends `KC_CAPS` (traditional Caps Lock) instead of toggling Caps Word. Both-shifts-held preserves the shift, enabling `Shift+Caps` to turn Caps Lock off.

### RGB Layer Indicators

`rgb_matrix_indicators_advanced_user` in each `keymap.c` lights active keys per layer with Solarized palette colors:

| Layer | Color (RGB) |
|---|---|
| 1 `_NUMBERS` | Red (220, 50, 47) |
| 2 `_EXTRA` | Magenta (211, 54, 130) |
| 3 `_FUNCTION` | Orange (203, 75, 22) |
| 4 `_SYMBOLS` | Blue (38, 139, 210) |
| 5 `_NAVIGATION` | Violet (108, 113, 196) |
| 6 `_MEDIA` | Teal (42, 161, 152) |

Caps Lock / Caps Word active on `_BASE`: Gold (181, 137, 0) on all non-transparent keys.

## Per-Keyboard Differences

- **Iris CE rev1** has an extra number row on `_BASE` (row 0) and an additional encoder column; uses `LAYOUT` (not split_3x6_3). Also enables `VIA_ENABLE = yes` and `RGB_MATRIX_CUSTOM_USER = yes`.
- **Corne rev1** includes an OLED (`oled.c`), WPM display, and uses RP2040-specific serial/pin config (`SPLIT_HAND_PIN`, `SERIAL_PIO_USE_PIO0`). `LAYER_LOCK_ENABLE` is not set in its `rules.mk` (uses the older `EE_CLR` placeholder comment).
- **Corne rev4.1** uses `LAYOUT_split_3x6_3_ex2` (adds 2 extra columns for encoders/thumb keys in the layout macro).

## Key QMK Features Enabled

- `CAPS_WORD_ENABLE` — all keyboards
- `LAYER_LOCK_ENABLE` (`QK_LLCK`) — Corne rev4.1 and Iris; used on modifier layers to lock a layer active
- `RGB_MATRIX_ENABLE` — all keyboards (replaces `RGBLIGHT`)
- `LTO_ENABLE` — link-time optimization to reduce firmware size
- `MOUSEKEY_ENABLE` / `EXTRAKEY_ENABLE` — all keyboards
