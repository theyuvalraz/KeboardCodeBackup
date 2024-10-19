/* Copyright 2022 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "keychron_common.h"
#include "tap_dance_config.c"

// clang-format off

enum layers{
    MAC_BASE,
    MAC_FN,
    WIN_BASE,
    WIN_FN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_ansi_89(
        KC_MUTE,    KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,  KC_MINS,  KC_EQL,  KC_DEL,             KC_VOLU,
        LGUI(KC_S),       KC_GRV,   LGUI(LSFT(KC_4)),  KC_MUTE, RAG(KC_L) ,  LCTL(KC_R),  LCMD(KC_F12),KC_ESC  ,   KC_BSPC,  KC_HOME,  KC_END,  KC_CALC,    KC_LEFT, KC_RGHT,   KC_BSPC,            KC_VOLD,
        KC_MAC_UNDO,       KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P, TD(TD_L_BRA),     TD(TD_R_BRA),      KC_BSLS,            KC_PGUP,
        LGUI(KC_F),       OSL(MAC_FN),  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,        KC_H,     KC_J,     KC_K,     KC_L,   KC_QUOT,    KC_SCLN,          KC_ENT,             KC_PGDN,
        KC_MAC_PASTE,       KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,  KC_B,      KC_N,     KC_M,     KC_KP_DOT,   TD(TD_COMMA),     KC_SLSH,  OSL(MAC_FN),  KC_UP,
        KC_MAC_COPY,       KC_LCTL,  KC_LOPTN,           KC_LCMMD, KC_SPC,  LT(MAC_FN, KC_SPACE) ,                     KC_SPC,      LGUI_T(KC_SPACE),                     KC_MINS,  KC_DOWN,  KC_ENT),

    [MAC_FN] = LAYOUT_ansi_89(
        RGB_TOG,    _______,  _______,    _______,    _______,    _______,    _______,     _______,    _______,    _______,    _______,    _______,   RGB_VAD,   RGB_VAI,   _______,            RGB_SPI,
        LSFT(KC_F6),    _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  RGB_HUD,  RGB_HUI,  _______,            RGB_SPD,
        SCMD(KC_Z),    _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            RGB_SAI,
        SCMD(KC_F),    _______,  _______, _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,            _______,            RGB_SAD,
        SCMD(KC_V),    _______,            _______,  _______,  _______,  _______,   _______,  _______,  NK_TOGG,  _______,  _______,  _______,  LGUI(KC_SLASH),  _______,  RGB_MOD,
        KC_MAC_CUT,    _______,  _______,            _______,  _______,  _______,                       _______,            _______,                      _______,  RGB_RMOD,  _______),

    [WIN_BASE] = LAYOUT_ansi_89(
        KC_MUTE,    KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,                KC_5,     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_MINS,   KC_EQL,   KC_DEL,                            KC_VOLU,
        LCTL(KC_S),       KC_GRV,   KC_PSCR,  KC_MUTE,  _______,  KC_MPLY,  KC_MSTP,  _______,   KC_BSPC,  KC_HOME,  KC_END,  KC_CALC,     KC_LEFT, KC_RGHT,   KC_BSPC,                        KC_VOLD,
        LCTL(KC_Z),       KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,                KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,       TD(TD_L_BRA),     TD(TD_R_BRA),       KC_BSLS,     KC_PGUP,
        LCTL(KC_F),       OSL(WIN_FN),  KC_A,     KC_S,     KC_D,     KC_F,                KC_G,        KC_H,     KC_J,     KC_K,     KC_L,   KC_QUOT,      KC_SCLN,        KC_ENT,             KC_PGDN,
        KC_PC_PASTE,KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,              KC_B,  KC_B,        KC_N,     KC_M,     KC_KP_DOT,    TD(TD_COMMA),    KC_SLSH,  OSL(WIN_FN),  KC_UP,
        KC_PC_COPY, KC_LCTL, KC_LALT,  KC_LWIN,  KC_SPC,   LT(WIN_FN, KC_SPACE),KC_SPC,                                                KC_MENU,  KC_MINS,  KC_DOWN,                          KC_ENT),

    [WIN_FN] = LAYOUT_ansi_89(
        RGB_TOG,    _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  RGB_VAD,   RGB_VAI,  _______,            RGB_SPI,
        _______,    _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  RGB_HUD,  RGB_HUI,  _______,            RGB_SPD,
        _______,    _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,            RGB_SAI,
        _______,    _______,  _______, _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,             _______,            RGB_SAD,
        _______,    _______,            _______,  _______,  _______,  _______,   _______,  _______,  NK_TOGG,  _______,  _______,  _______,   _______,  _______,  RGB_MOD,
        _______,    _______,  _______,            _______,  _______,  _______,                       _______,            _______,                       _______,  RGB_RMOD,  _______),
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [MAC_BASE] = { ENCODER_CCW_CW(KC_LEFT, KC_RGHT) },
    [MAC_FN]   = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [WIN_BASE] = { ENCODER_CCW_CW(KC_LEFT, KC_RGHT) },
    [WIN_FN]   = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) }
};
#endif // ENCODER_MAP_ENABLE

// clang-format on

void housekeeping_task_user(void) {
    housekeeping_task_keychron();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_keychron(keycode, record)) {
        return false;
    }
    return true;
}
