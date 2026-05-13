#include QMK_KEYBOARD_H
#if __has_include("keymap.h")
#    include "keymap.h"
#endif

enum custom_keycodes {
    MICMUTE = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MICMUTE: {
            if (record->event.pressed) {
                // when keycode MICMUTE is pressed
                SEND_STRING(SS_LGUI(SS_LALT("k")));
            } else {
                // when keycode MICMUTE is released
            }
            break;
        }
        case CW_TOGG: {
            static uint16_t registered_key = KC_NO;
            if (record->event.pressed) {  // On key press.
                const uint8_t mods = get_mods();
                uint8_t shift_mods = mods & MOD_MASK_SHIFT;
                if (shift_mods) {  // At least one shift is held
                    registered_key = KC_CAPS;
                    // If one shift is held, clear it from the mods. But if both
                    // shifts are held, leave as is to send Shift + Caps.
                    if (shift_mods != MOD_MASK_SHIFT) {
                        unregister_mods(MOD_MASK_SHIFT);
                    }
                } else {
                    registered_key = CW_TOGG;
                }

                register_code(registered_key);
                set_mods(mods);
            } else {  // On key release.
                unregister_code(registered_key);
            }
            break;
        }
    }
    return true;
};

enum custom_layers {
     _BASE,
     _NUMBERS,
     _EXTRA,
     _FUNCTION,
     _SYMBOLS,
     _NAVIGATION,
     _MEDIA,
     _QWERTY
};


const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT_split_3x6_3(
        'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R',
                       '*', '*', '*', '*', '*', '*'
    );

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3(
        KC_GRV, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, TG(7),
        KC_LSFT, LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G, KC_H, RSFT_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L), RGUI_T(KC_SCLN), KC_QUOT,
        KC_LALT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, MICMUTE,
        LT(3,KC_ESC), KC_SPC, LT(1,KC_TAB), LT(4,KC_ENT), LT(5,KC_BSPC), LT(6,KC_DEL)),
    [_NUMBERS] = LAYOUT_split_3x6_3(
        KC_TRNS, KC_EXLM, KC_AT, KC_LBRC, KC_RBRC, KC_TILD, KC_UNDS, KC_7, KC_8, KC_9, KC_AMPR, KC_NO,
        KC_TRNS, KC_HASH, KC_DLR, KC_LPRN, KC_RPRN, QK_LLCK, KC_MINS, KC_4, KC_5, KC_6, KC_PLUS, KC_DQUO,
        KC_TRNS, KC_PERC, KC_CIRC, KC_LCBR, KC_RCBR, KC_PIPE, KC_ASTR, KC_1, KC_2, KC_3, KC_SLSH, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_EQL, KC_0, KC_DOT
    ),
    [_EXTRA] = LAYOUT_split_3x6_3(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
    [_FUNCTION] = LAYOUT_split_3x6_3(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_PSCR, KC_F7, KC_F8, KC_F9, KC_F12, KC_NO,
        KC_NO, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, QK_LLCK, KC_SCRL, KC_F4, KC_F5, KC_F6, KC_F11, KC_NO,
        KC_NO, LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), KC_NO, KC_PAUS, KC_F1, KC_F2, KC_F3, KC_F10, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS),
    [_SYMBOLS] = LAYOUT_split_3x6_3(
        KC_TRNS, KC_EXLM, KC_AT, KC_LBRC, KC_RBRC, KC_TILD, KC_UNDS, KC_7, KC_8, KC_9, KC_AMPR, KC_NO,
        KC_TRNS, KC_HASH, KC_DLR, KC_LPRN, KC_RPRN, QK_LLCK, KC_MINS, KC_4, KC_5, KC_6, KC_PLUS, KC_DQUO,
        KC_TRNS, KC_PERC, KC_CIRC, KC_LCBR, KC_RCBR, KC_PIPE, KC_ASTR, KC_1, KC_2, KC_3, KC_SLSH, KC_NO,
        KC_NO, KC_NO, KC_EQL, KC_NO, KC_0, KC_DOT
    ),
    [_NAVIGATION] = LAYOUT_split_3x6_3(
        KC_NO, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_INS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, CW_TOGG, QK_LLCK, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RCTL(KC_V), RCTL(KC_C), RCTL(KC_X), RCTL(KC_Z), KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
    [_MEDIA] = LAYOUT_split_3x6_3(
        KC_NO, RM_VALU, RM_SATU, RM_HUEU, RM_NEXT, RM_SPDU, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, RM_TOGG, QK_LLCK, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, KC_NO,
        KC_NO, RM_VALD, RM_SATD, RM_HUED, RM_PREV, RM_SPDD, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_MUTE, KC_NO, KC_MSTP, KC_NO, KC_NO, KC_NO),
    [_QWERTY] = LAYOUT_split_3x6_3(
        KC_GRV, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_TRNS,
        KC_LSFT, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
        KC_LALT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_NO,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)
};

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    static const uint8_t layer_colors[][3] = {
        [_NUMBERS]    = {255, 200,   0},
        [_EXTRA]      = {255,   0, 200},
        [_FUNCTION]   = {  0,   0, 255},
        [_SYMBOLS]    = {255, 200,   0},
        [_NAVIGATION] = {  0, 200, 255},
        [_MEDIA]      = {  0, 255,  80},
    };

    uint8_t layer = get_highest_layer(layer_state);
    if (layer > 0 && layer < ARRAY_SIZE(layer_colors)) {
        const uint8_t *c = layer_colors[layer];
        for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
            for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                uint8_t index = g_led_config.matrix_co[row][col];
                if (index >= led_min && index < led_max && index != NO_LED &&
                    keymap_key_to_keycode(layer, (keypos_t){col, row}) > KC_TRNS) {
                    rgb_matrix_set_color(index, c[0], c[1], c[2]);
                }
            }
        }
    }

    if (host_keyboard_led_state().caps_lock || is_caps_word_on()) {
        for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
            for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                uint8_t index = g_led_config.matrix_co[row][col];
                if (index >= led_min && index < led_max && index != NO_LED &&
                    keymap_key_to_keycode(0, (keypos_t){col, row}) > KC_TRNS) {
                    rgb_matrix_set_color(index, 255, 180, 0);
                }
            }
        }
    }

    uint8_t mods = get_mods();
    if (mods) {
        for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
            for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                uint8_t index = g_led_config.matrix_co[row][col];
                if (index < led_min || index >= led_max || index == NO_LED) continue;
                uint16_t kc = keymap_key_to_keycode(0, (keypos_t){col, row});
                if (IS_QK_MOD_TAP(kc))   kc = QK_MOD_TAP_GET_TAP_KEYCODE(kc);
                if (IS_QK_LAYER_TAP(kc)) kc = QK_LAYER_TAP_GET_TAP_KEYCODE(kc);
                bool light = false;
                if ((mods & MOD_MASK_SHIFT) && (kc == KC_S || kc == KC_H || kc == KC_F || kc == KC_T)) light = true;
                if ((mods & MOD_MASK_ALT)   && (kc == KC_A || kc == KC_L || kc == KC_T))               light = true;
                if ((mods & MOD_MASK_CTRL)  && (kc == KC_C || kc == KC_T || kc == KC_R || kc == KC_L)) light = true;
                if ((mods & MOD_MASK_GUI)   && (kc == KC_W || kc == KC_I || kc == KC_N))               light = true;
                if (light) rgb_matrix_set_color(index, 255, 255, 255);
            }
        }
    }

    if (layer == _QWERTY) {
        for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
            for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                uint8_t index = g_led_config.matrix_co[row][col];
                if (index < led_min || index >= led_max || index == NO_LED) continue;
                uint16_t kc = keymap_key_to_keycode(0, (keypos_t){col, row});
                if (IS_QK_MOD_TAP(kc))   kc = QK_MOD_TAP_GET_TAP_KEYCODE(kc);
                if (IS_QK_LAYER_TAP(kc)) kc = QK_LAYER_TAP_GET_TAP_KEYCODE(kc);
                bool is_toggle = IS_QK_TOGGLE_LAYER(kc) && QK_TOGGLE_LAYER_GET_LAYER(kc) == _QWERTY;
                if (kc == KC_W || kc == KC_A || kc == KC_S || kc == KC_D || is_toggle) {
                    rgb_matrix_set_color(index, 0, 255, 80);
                }
            }
        }
    }
    return false;
}


#ifdef OTHER_KEYMAP_C
#    include OTHER_KEYMAP_C
#endif // OTHER_KEYMAP_C


#ifdef OLED_ENABLE
#    include "oled.c"
#endif // OLED_ENABLE
