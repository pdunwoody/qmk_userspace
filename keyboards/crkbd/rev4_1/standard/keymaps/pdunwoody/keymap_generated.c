#include QMK_KEYBOARD_H
#if __has_include("keymap.h")
#    include "keymap.h"
#endif


/* THIS FILE WAS GENERATED!
 *
 * This file was generated by qmk json2c. You may or may not want to
 * edit it directly.
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3_ex2(KC_LCTL, KC_Q, KC_W, KC_F, KC_P, KC_B, KC_MUTE, KC_VOLU, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, TG(7), KC_LSFT, LGUI_T(KC_A), LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T), KC_G, KC_MPLY, KC_VOLD, KC_M, RSFT_T(KC_N), RCTL_T(KC_E), RALT_T(KC_I), RGUI_T(KC_O), KC_QUOT, KC_LALT, KC_Z, KC_X, KC_C, KC_D, KC_V, KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, KC_NO, LT(3,KC_ESC), LT(1,KC_SPC), LT(2,KC_TAB), LT(5,KC_ENT), LT(4,KC_BSPC), LT(6,KC_DEL)),
    [1] = LAYOUT_split_3x6_3_ex2(KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_GRV, KC_7, KC_8, KC_9, KC_LPRN, KC_RPRN, KC_TRNS, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, QK_LLCK, KC_TRNS, KC_TRNS, KC_PAST, KC_4, KC_5, KC_6, KC_PPLS, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_PSLS, KC_1, KC_2, KC_3, KC_PEQL, KC_NO, KC_NO, KC_NO, KC_NO, KC_MINS, KC_0, KC_DOT),
    [2] = LAYOUT_split_3x6_3_ex2(KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TILD, KC_AMPR, KC_ASTR, KC_LPRN, KC_LCBR, KC_RCBR, KC_TRNS, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, QK_LLCK, KC_TRNS, KC_TRNS, KC_NO, KC_DLR, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_EXLM, KC_AT, KC_HASH, KC_BSLS, KC_PIPE, KC_NO, KC_NO, KC_NO, KC_UNDS, KC_LPRN, KC_RPRN),
    [3] = LAYOUT_split_3x6_3_ex2(KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_PSCR, KC_F7, KC_F8, KC_F9, KC_F12, KC_TRNS, KC_TRNS, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, QK_LLCK, KC_TRNS, KC_TRNS, KC_SCRL, KC_F4, KC_F5, KC_F6, KC_F11, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_PAUS, KC_F1, KC_F2, KC_F3, KC_F10, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_ENT, KC_BSPC, KC_DEL),
    [4] = LAYOUT_split_3x6_3_ex2(KC_TRNS, KC_UNDO, KC_PSTE, KC_COPY, KC_CUT, KC_AGIN, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, CW_TOGG, KC_TRNS, KC_TRNS, QK_LLCK, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, KC_TRNS, KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_INS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
    [5] = LAYOUT_split_3x6_3_ex2(KC_TRNS, KC_UNDO, KC_PSTE, KC_COPY, KC_CUT, KC_AGIN, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, MS_LEFT, MS_DOWN, MS_UP, MS_RGHT, KC_NO, KC_TRNS, KC_TRNS, QK_LLCK, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, KC_TRNS, KC_TRNS, MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
    [6] = LAYOUT_split_3x6_3_ex2(KC_TRNS, RGB_VAI, RGB_SAI, RGB_HUI, RGB_MOD, RGB_TOG, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_NO, KC_TRNS, KC_TRNS, QK_LLCK, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, KC_TRNS, KC_TRNS, RGB_VAD, RGB_SAD, RGB_HUD, RGB_RMOD, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_MUTE, KC_MPLY, KC_MSTP, KC_NO, KC_NO, KC_NO),
    [7] = LAYOUT_split_3x6_3_ex2(KC_TRNS, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_TRNS, KC_TRNS, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_TRNS, KC_TRNS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_TRNS, KC_TRNS, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_TRNS, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)
};



#ifdef OTHER_KEYMAP_C
#    include OTHER_KEYMAP_C
#endif // OTHER_KEYMAP_C


