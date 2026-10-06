#include QMK_KEYBOARD_H
#include "lib/lib8tion/lib8tion.h"
#include "transactions.h"
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
                SEND_STRING(SS_LGUI(SS_LALT("k")));
            } else {
            }
            break;
        }
        case CW_TOGG: {
            static uint16_t registered_key = KC_NO;
            if (record->event.pressed) {
                const uint8_t mods = get_mods();
                uint8_t shift_mods = mods & MOD_MASK_SHIFT;
                if (shift_mods) {
                    registered_key = KC_CAPS;
                    if (shift_mods != MOD_MASK_SHIFT) {
                        unregister_mods(MOD_MASK_SHIFT);
                    }
                } else {
                    registered_key = CW_TOGG;
                }
                register_code(registered_key);
                set_mods(mods);
            } else {
                unregister_code(registered_key);
            }
            break;
        }
    }
    return true;
};

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_F):
        case RSFT_T(KC_J):
            return true;
        default:
            return false;
    }
}

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
    LAYOUT_split_3x6_3_ex2(
        'L', 'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',           'R', 'R', 'R', 'R', 'R', 'R',
                            '*', '*', '*', '*', '*', '*'
    );

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3_ex2(
        KC_LALT, KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,    KC_VOLD, KC_VOLU, KC_Y,    KC_U,         KC_I,         KC_O,         KC_P,            TG(7),
        KC_LSFT, LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G,    KC_MPLY, MICMUTE, KC_H,    RSFT_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L), RGUI_T(KC_SCLN), KC_QUOT,
        KC_LCTL, KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,             KC_N,    KC_M,    KC_COMM,      KC_DOT,       KC_SLSH,       KC_NO,
        LT(3,KC_ESC), KC_SPC, LT(1,KC_TAB), LT(4,KC_ENT), LT(5,KC_BSPC), LT(6,KC_DEL)
    ),
    [_NUMBERS] = LAYOUT_split_3x6_3_ex2(
        KC_TRNS, KC_EXLM, KC_AT,   KC_LBRC, KC_RBRC, KC_TILD, KC_TRNS, KC_TRNS, KC_UNDS, KC_7, KC_8, KC_9, KC_AMPR, KC_NO,
        KC_TRNS, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, QK_LLCK, KC_TRNS, KC_TRNS, KC_MINS, KC_4, KC_5, KC_6, KC_PLUS, KC_DQUO,
        KC_TRNS, KC_PERC, KC_CIRC, KC_LCBR, KC_RCBR, KC_PIPE,          KC_ASTR, KC_1,    KC_2, KC_3, KC_SLSH, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_EQL, KC_0, KC_DOT
    ),
    [_EXTRA] = LAYOUT_split_3x6_3_ex2(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),
    [_FUNCTION] = LAYOUT_split_3x6_3_ex2(
        KC_NO, KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,    KC_TRNS, KC_TRNS, KC_PSCR, KC_F7, KC_F8, KC_F9, KC_F12, KC_NO,
        KC_NO, KC_LGUI,     KC_LALT,     KC_LCTL,     KC_LSFT,     QK_LLCK,  KC_TRNS, KC_TRNS, KC_SCRL, KC_F4, KC_F5, KC_F6, KC_F11, KC_NO,
        KC_NO, LCTL(KC_Z),  LCTL(KC_X),  LCTL(KC_C),  LCTL(KC_V),  KC_NO,            KC_PAUS, KC_F1,   KC_F2, KC_F3, KC_F10, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [_SYMBOLS] = LAYOUT_split_3x6_3_ex2(
        KC_TRNS, KC_EXLM, KC_AT,   KC_LBRC, KC_RBRC, KC_TILD, KC_TRNS, KC_TRNS, KC_UNDS, KC_7, KC_8, KC_9, KC_AMPR, KC_NO,
        KC_TRNS, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, QK_LLCK, KC_TRNS, KC_TRNS, KC_MINS, KC_4, KC_5, KC_6, KC_PLUS, KC_DQUO,
        KC_TRNS, KC_PERC, KC_CIRC, KC_LCBR, KC_RCBR, KC_PIPE,          KC_ASTR, KC_1,    KC_2, KC_3, KC_SLSH, KC_NO,
        KC_NO, KC_NO, KC_EQL, KC_NO, KC_0, KC_DOT
    ),
    [_NAVIGATION] = LAYOUT_split_3x6_3_ex2(
        KC_NO, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_INS,  KC_TRNS, KC_TRNS, KC_NO,   KC_NO,       KC_NO,       KC_NO,       KC_NO,   KC_NO,
        KC_NO, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, CW_TOGG, KC_TRNS, KC_TRNS, QK_LLCK, KC_RSFT,     KC_RCTL,     KC_RALT,     KC_RGUI, KC_NO,
        KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,            KC_NO,   RCTL(KC_V), RCTL(KC_C), RCTL(KC_X), RCTL(KC_Z), KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),
    [_MEDIA] = LAYOUT_split_3x6_3_ex2(
        KC_NO, RM_VALU, RM_SATU, RM_HUEU, RM_NEXT, RM_SPDU, KC_TRNS, KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, RM_TOGG, KC_MPLY, KC_TRNS, QK_LLCK, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, KC_NO,
        KC_NO, RM_VALD, RM_SATD, RM_HUED, RM_PREV, RM_SPDD,          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_MUTE, KC_NO, KC_MSTP, KC_NO, KC_NO, KC_NO
    ),
    [_QWERTY] = LAYOUT_split_3x6_3_ex2(
        KC_TRNS, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_TRNS, KC_TRNS, KC_Y, KC_U, KC_I, KC_O, KC_P,    KC_TRNS,
        KC_TRNS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_TRNS, KC_TRNS, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
        KC_TRNS, KC_Z, KC_X, KC_C, KC_V, KC_B,          KC_N,    KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_NO,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
};

// QMK doesn't share Caps Word state between halves, so the primary half sends
// it across for the secondary half's indicators.
static bool remote_caps_word = false;

static void caps_word_sync_handler(uint8_t in_len, const void *in_data, uint8_t out_len, void *out_data) {
    remote_caps_word = *(const bool *)in_data;
}

void keyboard_post_init_user(void) {
    transaction_register_rpc(CAPS_WORD_SYNC, caps_word_sync_handler);
}

void housekeeping_task_user(void) {
    if (!is_keyboard_master()) return;
    static bool     last_sent = false;
    static uint32_t last_sync = 0;
    bool on = is_caps_word_on();
    if (on != last_sent || timer_elapsed32(last_sync) > 500) {
        if (transaction_rpc_send(CAPS_WORD_SYNC, sizeof(on), &on)) {
            last_sent = on;
            last_sync = timer_read32();
        }
    }
}

// 0..255..0 over one step: a smooth "boop" used by the letter-spelling indicators.
static uint8_t pulse_amount(uint32_t t, uint16_t step) {
    uint8_t phase = (uint32_t)t * 255 / step;
    return sin8((uint8_t)(phase - 64));
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    // On power-up the keys stay dark and spell "HELLO PAUL" before the normal
    // backlight starts: the word fades up, each letter pulses white in turn,
    // then the word fades out and the effect takes over.
    static const uint16_t hello_letters[] = {KC_H, KC_E, KC_L, KC_L, KC_O, KC_NO, KC_P, KC_A, KC_U, KC_L};
    const uint16_t HELLO_DELAY_MS = 500; // dark lead-in while the halves connect
    const uint16_t HELLO_IN_MS    = 300; // word fades up
    const uint16_t HELLO_STEP_MS  = 250; // time per letter (KC_NO is the gap between words)
    const uint16_t HELLO_OUT_MS   = 400; // word fades out before the backlight starts
    const uint8_t  HELLO_BASE     = 50;  // word brightness between letter pulses

    static bool hello_done = false;
    if (!hello_done) {
        // Time since power-up, synced from the primary half so both halves spell together.
        uint32_t t          = sync_timer_read32();
        uint8_t  amt        = 0;   // brightness of the word
        uint8_t  active     = 255; // letter currently pulsing, if any
        uint8_t  active_amt = 0;
        if (t < HELLO_DELAY_MS) {
            // dark
        } else if ((t -= HELLO_DELAY_MS) < HELLO_IN_MS) {
            amt = scale8(pulse_amount(t, 2 * HELLO_IN_MS), HELLO_BASE); // rising half of a boop
        } else if ((t -= HELLO_IN_MS) < (uint32_t)ARRAY_SIZE(hello_letters) * HELLO_STEP_MS) {
            amt        = HELLO_BASE;
            active     = t / HELLO_STEP_MS;
            active_amt = qadd8(HELLO_BASE, scale8(pulse_amount(t % HELLO_STEP_MS, HELLO_STEP_MS), 255 - HELLO_BASE));
        } else if ((t -= (uint32_t)ARRAY_SIZE(hello_letters) * HELLO_STEP_MS) < HELLO_OUT_MS) {
            amt = scale8(pulse_amount(t + HELLO_OUT_MS, 2 * HELLO_OUT_MS), HELLO_BASE); // falling half
        } else {
            hello_done = true;
        }
        if (!hello_done) {
            for (uint8_t i = led_min; i < led_max; ++i) {
                rgb_matrix_set_color(i, 0, 0, 0);
            }
            for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
                for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                    uint8_t index = g_led_config.matrix_co[row][col];
                    if (index < led_min || index >= led_max || index == NO_LED) continue;
                    uint16_t kc = keymap_key_to_keycode(0, (keypos_t){col, row});
                    if (IS_QK_MOD_TAP(kc))   kc = QK_MOD_TAP_GET_TAP_KEYCODE(kc);
                    if (IS_QK_LAYER_TAP(kc)) kc = QK_LAYER_TAP_GET_TAP_KEYCODE(kc);
                    if (kc == KC_NO) continue;
                    // L appears more than once, so check every position before settling on a level.
                    bool    light = false;
                    uint8_t a     = amt;
                    for (uint8_t i = 0; i < ARRAY_SIZE(hello_letters); ++i) {
                        if (hello_letters[i] != kc) continue;
                        light = true;
                        if (i == active) a = active_amt;
                    }
                    if (light) rgb_matrix_set_color(index, a, a, a);
                }
            }
            return false;
        }
    }

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

    bool caps_word = is_keyboard_master() ? is_caps_word_on() : remote_caps_word;
    if (host_keyboard_led_state().caps_lock || caps_word) {
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

    // Caps Word spells "CAPS WORD" on a loop over the gold: each letter pulses
    // white in turn, a beat's gap between the words, then a pause.
    static const uint16_t caps_word_letters[] = {KC_C, KC_A, KC_P, KC_S, KC_NO, KC_W, KC_O, KC_R, KC_D};
    const uint16_t CAPS_WORD_STEP_MS  = 250; // time per letter (KC_NO is the gap between words)
    const uint16_t CAPS_WORD_PAUSE_MS = 600; // gap before the sequence restarts
    const uint8_t  CAPS_WORD_IDLE     = 60;  // letters' blend toward white between pulses

    static bool     prev_caps_word  = false;
    static uint32_t caps_word_timer = 0;
    if (caps_word && !prev_caps_word) caps_word_timer = timer_read32(); // start on the first letter
    prev_caps_word = caps_word;
    if (caps_word) {
        uint16_t pos = timer_elapsed32(caps_word_timer) % (ARRAY_SIZE(caps_word_letters) * CAPS_WORD_STEP_MS + CAPS_WORD_PAUSE_MS);
        for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
            for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                uint8_t index = g_led_config.matrix_co[row][col];
                if (index < led_min || index >= led_max || index == NO_LED) continue;
                uint16_t kc = keymap_key_to_keycode(0, (keypos_t){col, row});
                if (IS_QK_MOD_TAP(kc))   kc = QK_MOD_TAP_GET_TAP_KEYCODE(kc);
                if (IS_QK_LAYER_TAP(kc)) kc = QK_LAYER_TAP_GET_TAP_KEYCODE(kc);
                if (kc == KC_NO) continue;
                for (uint8_t i = 0; i < ARRAY_SIZE(caps_word_letters); ++i) {
                    if (caps_word_letters[i] != kc) continue;
                    uint8_t a = CAPS_WORD_IDLE;
                    if (pos / CAPS_WORD_STEP_MS == i) {
                        a = qadd8(CAPS_WORD_IDLE, scale8(pulse_amount(pos % CAPS_WORD_STEP_MS, CAPS_WORD_STEP_MS), 255 - CAPS_WORD_IDLE));
                    }
                    rgb_matrix_set_color(index, 255, blend8(180, 255, a), blend8(0, 255, a));
                    break;
                }
            }
        }
    }

    // Holding a layer key shows the layer's name: the whole word fades up from
    // the layer color, each letter pulses to white in turn, then the word fades
    // back down.
    static const uint16_t layer_letters[][5] = {
        [_NUMBERS]    = {KC_N, KC_U, KC_M},
        [_FUNCTION]   = {KC_F, KC_U, KC_N, KC_C},
        [_SYMBOLS]    = {KC_S, KC_Y, KC_M},
        [_NAVIGATION] = {KC_N, KC_A, KC_V},
        [_MEDIA]      = {KC_M, KC_E, KC_D, KC_I, KC_A},
    };
    const uint16_t LAYER_WORD_IN_MS   = 250; // word fades up
    const uint16_t LAYER_WORD_STEP_MS = 250; // time per letter pulse
    const uint16_t LAYER_WORD_OUT_MS  = 400; // word fades back to the layer color
    const uint8_t  LAYER_WORD_BASE    = 120; // word brightness between letter pulses (255 = white)

    static uint8_t  prev_layer  = 0;
    static uint32_t layer_timer = 0;
    if (layer != prev_layer) layer_timer = timer_read32();
    prev_layer = layer;
    if (layer < ARRAY_SIZE(layer_letters) && layer < ARRAY_SIZE(layer_colors)) {
        uint8_t len = 0;
        while (len < ARRAY_SIZE(layer_letters[layer]) && layer_letters[layer][len]) ++len;
        uint32_t t      = timer_elapsed32(layer_timer);
        bool     show   = true;
        uint8_t  amt    = 0;   // blend toward white for the word
        uint8_t  active = 255; // letter currently pulsing, if any
        uint8_t  active_amt = 0;
        if (t < LAYER_WORD_IN_MS) {
            amt = scale8(pulse_amount(t, 2 * LAYER_WORD_IN_MS), LAYER_WORD_BASE); // rising half of a boop
        } else if ((t -= LAYER_WORD_IN_MS) < (uint32_t)len * LAYER_WORD_STEP_MS) {
            amt        = LAYER_WORD_BASE;
            active     = t / LAYER_WORD_STEP_MS;
            active_amt = qadd8(LAYER_WORD_BASE, scale8(pulse_amount(t % LAYER_WORD_STEP_MS, LAYER_WORD_STEP_MS), 255 - LAYER_WORD_BASE));
        } else if ((t -= (uint32_t)len * LAYER_WORD_STEP_MS) < LAYER_WORD_OUT_MS) {
            amt = scale8(pulse_amount(t + LAYER_WORD_OUT_MS, 2 * LAYER_WORD_OUT_MS), LAYER_WORD_BASE); // falling half
        } else {
            show = false;
        }
        if (show) {
            const uint8_t *c = layer_colors[layer];
            for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
                for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                    uint8_t index = g_led_config.matrix_co[row][col];
                    if (index < led_min || index >= led_max || index == NO_LED) continue;
                    uint16_t kc = keymap_key_to_keycode(0, (keypos_t){col, row});
                    if (IS_QK_MOD_TAP(kc))   kc = QK_MOD_TAP_GET_TAP_KEYCODE(kc);
                    if (IS_QK_LAYER_TAP(kc)) kc = QK_LAYER_TAP_GET_TAP_KEYCODE(kc);
                    for (uint8_t i = 0; i < len; ++i) {
                        if (layer_letters[layer][i] == kc) {
                            uint8_t a = (i == active) ? active_amt : amt;
                            rgb_matrix_set_color(index, blend8(c[0], 255, a), blend8(c[1], 255, a), blend8(c[2], 255, a));
                            break;
                        }
                    }
                }
            }
        }
    }

    // Held mods spell their name on the keys: each letter pulses white in
    // turn, then a pause before the sequence repeats (boop boop boop, pause).
    static const uint16_t mod_letters[][4] = {
        {KC_S, KC_H, KC_F, KC_T},
        {KC_C, KC_T, KC_R, KC_L},
        {KC_A, KC_L, KC_T},
        {KC_W, KC_I, KC_N},
    };
    static const uint8_t mod_masks[] = {MOD_MASK_SHIFT, MOD_MASK_CTRL, MOD_MASK_ALT, MOD_MASK_GUI};
    const uint16_t MOD_PULSE_STEP_MS  = 250; // time per letter
    const uint16_t MOD_PULSE_PAUSE_MS = 600; // gap before the sequence restarts
    const uint8_t  MOD_PULSE_IDLE     = 40;  // letter brightness between pulses

    static uint8_t  prev_mods  = 0;
    static uint32_t mods_timer = 0;
    uint8_t mods = get_mods();
    if (mods && !prev_mods) mods_timer = timer_read32(); // start each hold on the first letter
    prev_mods = mods;
    if (mods) {
        uint32_t elapsed = timer_elapsed32(mods_timer);
        for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
            for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                uint8_t index = g_led_config.matrix_co[row][col];
                if (index < led_min || index >= led_max || index == NO_LED) continue;
                uint16_t kc = keymap_key_to_keycode(0, (keypos_t){col, row});
                if (IS_QK_MOD_TAP(kc))   kc = QK_MOD_TAP_GET_TAP_KEYCODE(kc);
                if (IS_QK_LAYER_TAP(kc)) kc = QK_LAYER_TAP_GET_TAP_KEYCODE(kc);
                bool    light = false;
                uint8_t level = 0;
                for (uint8_t m = 0; m < ARRAY_SIZE(mod_masks); ++m) {
                    if (!(mods & mod_masks[m])) continue;
                    uint8_t len = 0;
                    while (len < ARRAY_SIZE(mod_letters[m]) && mod_letters[m][len]) ++len;
                    uint16_t pos = elapsed % (len * MOD_PULSE_STEP_MS + MOD_PULSE_PAUSE_MS);
                    for (uint8_t i = 0; i < len; ++i) {
                        if (mod_letters[m][i] != kc) continue;
                        uint8_t b = MOD_PULSE_IDLE;
                        if (pos / MOD_PULSE_STEP_MS == i) {
                            b = qadd8(MOD_PULSE_IDLE, scale8(pulse_amount(pos % MOD_PULSE_STEP_MS, MOD_PULSE_STEP_MS), 255 - MOD_PULSE_IDLE));
                        }
                        light = true;
                        if (b > level) level = b;
                    }
                }
                if (light) rgb_matrix_set_color(index, level, level, level);
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
