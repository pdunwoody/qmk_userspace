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
    [0] = LAYOUT(KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, TG(7), KC_LCTL, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_NO, KC_LSFT, LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G, KC_H, RSFT_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L), RGUI_T(KC_SCLN), KC_QUOT, KC_LALT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_MPLY, KC_NO, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_BSLS, LT(3,KC_ESC), KC_SPC, LT(1,KC_TAB), LT(4,KC_ENT), LT(5,KC_BSPC), LT(6,KC_DEL)),
    [1] = LAYOUT(KC_GRV, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_EXLM, KC_AT, KC_LBRC, KC_RBRC, KC_TILD, KC_UNDS, KC_7, KC_8, KC_9, KC_AMPR, KC_NO, KC_TRNS, LGUI_T(KC_HASH), LALT_T(KC_DLR), LCTL_T(KC_LPRN), LSFT_T(KC_RPRN), EE_CLR, KC_MINS, KC_4, KC_5, KC_6, KC_PLUS, KC_DQUO, KC_TRNS, KC_PERC, KC_CIRC, KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS, KC_TRNS, KC_ASTR, KC_1, KC_2, KC_3, KC_SLSH, KC_NO, KC_NO, KC_NO, KC_NO, KC_EQL, KC_0, KC_DOT),
    [2] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
    [3] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_PSCR, KC_F7, KC_F8, KC_F9, KC_F12, KC_NO, KC_NO, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, EE_CLR, KC_SCRL, KC_F4, KC_F5, KC_F6, KC_F11, KC_NO, KC_NO, LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), KC_NO, KC_TRNS, KC_TRNS, KC_PAUS, KC_F1, KC_F2, KC_F3, KC_F10, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS),
    [4] = LAYOUT(KC_GRV, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_EXLM, KC_AT, KC_LBRC, KC_RBRC, KC_TILD, KC_UNDS, KC_7, KC_8, KC_9, KC_AMPR, KC_NO, KC_TRNS, KC_HASH, KC_DLR, KC_LPRN, KC_RPRN, EE_CLR, KC_MINS, LSFT_T(KC_4), LCTL_T(KC_5), LALT_T(KC_6), LGUI_T(KC_PLUS), KC_DQUO, KC_TRNS, KC_PERC, KC_CIRC, KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS, KC_TRNS, KC_ASTR, KC_1, KC_2, KC_3, KC_SLSH, KC_NO, KC_NO, KC_NO, KC_EQL, KC_NO, KC_0, KC_DOT),
    [5] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_INS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, CW_TOGG, EE_CLR, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RCTL(KC_V), RCTL(KC_C), RCTL(KC_X), RCTL(KC_Z), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
    [6] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RGB_VAI, RGB_SAI, RGB_HUI, RGB_MOD, RGB_TOG, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, EE_CLR, EE_CLR, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, KC_NO, KC_NO, RGB_VAD, RGB_SAD, RGB_HUD, RGB_RMOD, KC_NO, KC_MPLY, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MUTE, KC_NO, KC_MSTP, KC_NO, KC_NO, KC_NO),
    [7] = LAYOUT(KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_TRNS, KC_LCTL, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_NO, KC_LSFT, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_LALT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_TRNS, KC_TRNS, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)
};



#ifdef OTHER_KEYMAP_C
#    include OTHER_KEYMAP_C
#endif // OTHER_KEYMAP_C


