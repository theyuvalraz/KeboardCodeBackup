/* Copyright 2019
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

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)

enum layers {
    _BASE = 0,
    _FN1,
    _FN2,
    _FN3,
    _FN4
};


// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    QMKURL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     [_BASE] = LAYOUT_ortho_4x4(
        LGUI(LSFT(KC_4)), KC_UP, LGUI(KC_Z), LGUI(LSFT(KC_Z)),
        KC_LEFT, KC_DOWN, KC_RIGHT, MO(_FN2),
        LGUI(KC_A), LGUI(KC_F), LGUI(LSFT(KC_F)), LGUI(KC_SLASH),
        KC_MAC_CUT, KC_MAC_COPY, KC_MAC_PASTE, RAG(KC_L)),

        [_FN1] = LAYOUT_ortho_4x4(
            KC_F7, KC_F8, KC_F9, KC_TRNS,
            KC_F4, KC_F5, KC_F6, KC_TRNS,
            KC_F1, KC_F2, KC_F3, KC_NO,
            KC_F10, KC_F11, KC_F12, KC_TRNS),

        [_FN2] = LAYOUT_ortho_4x4(
            RGB_VAD, RGB_SAI, RGB_VAI, TG(4),
            RGB_HUD, RGB_SAD, RGB_HUI, KC_TRNS,
            KC_NO, KC_NO, KC_NO, KC_NO,
             RGB_MOD, RGB_RMOD, TG(_FN3), KC_TRNS),

        [_FN3] = LAYOUT_ortho_4x4(
            KC_NO, KC_NO, KC_NO, KC_NO,
            KC_NO, KC_NO, KC_NO, KC_NO,
            KC_NO, KC_NO, KC_NO, KC_NO,
             KC_NO, KC_NO,KC_TRNS, KC_TRNS),

        [_FN4] = LAYOUT_ortho_4x4(
            KC_WH_D, KC_MS_U, KC_WH_U, KC_BTN3,
            KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN2,
            KC_NO, KC_NO, KC_NO, KC_NO,
            KC_BTN1, KC_NO, KC_NO, TO(_BASE))
};


layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _BASE:
        rgblight_setrgb (0x00,  0xFF, 0x00);
        break;
    case _FN1:
        rgblight_setrgb (0xFF,  0x00, 0x00);
        break;
    case _FN2:
        rgblight_setrgb (0xFF, 0xFF , 0xFF);
        break;
    case _FN3:
        rgblight_setrgb (0x00, 0x00 , 0x00);
        break;
    case _FN4:
        rgblight_setrgb (0x00, 0x00 , 0xFF);
        break;
    default: //  for any other layers, or the default layer
        rgblight_setrgb (0xFF,  0xFF, 0x00);
        break;
    }
  return state;
}

