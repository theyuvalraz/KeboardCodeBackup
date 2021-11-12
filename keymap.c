#include QMK_KEYBOARD_H
#include "tap_dance_config.c"
#include "encoder_updater.c"
#include "color_mode.c"
#include "music_mode.c"


#include <muse.h>


// make preonic/rev3:dragon_yraz


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_preonic_grid( \
    KC_1,    KC_2,    KC_3,      KC_4,    KC_5,            KC_GESC,   KC_BSPC , KC_6,   KC_7,    KC_8,         KC_9,    KC_0,   \
    KC_Q,    KC_W,    KC_E,      KC_R,    KC_T,            TD(TD_L_BRA),     TD(TD_R_BRA),     KC_Y,             KC_U,    KC_I,         KC_O,    KC_P, \
    KC_A,    KC_S,    KC_D,      KC_F,    KC_G,            KC_TAB,           KC_QUOTE,         KC_H,             KC_J,    KC_K,         KC_L,    TD(TD_COL_PIPE), \
    KC_Z,    KC_X,    KC_C,      KC_V,    KC_B,            LSFT_T(KC_ENTER), TO(1),            KC_N,             KC_M,    TD(TD_COMMA), KC_UP  , KC_SLASH , \
    OSL(2),  OSL(3),  KC_LCTRL,  KC_LALT, LT(6, KC_SPACE), KC_SPACE,         LT(7, KC_SPACE),  LGUI_T(KC_SPACE), KC_MINS, KC_EQUAL,     KC_DOWN, KC_ENTER \
),

[_MOUSE] = LAYOUT_preonic_grid( \
    _______,    _______, _______,  _______,             _______,              _______,    _______,          _______, _______,    _______, _______,        _______, \
    LGUI(KC_M), KC_UP,   _______,  LALT(LGUI(KC_LEFT)), LALT(LGUI(KC_RIGHT)), _______,    LGUI(LSFT(KC_T)), _______, KC_WH_D,    KC_MS_U, KC_WH_U,        KC_MS_BTN3, \
    KC_LEFT,    KC_DOWN, KC_RIGHT, _______,             _______,              LGUI(KC_R), LGUI(KC_W),       _______, KC_MS_L,    KC_MS_D, KC_MS_R,        KC_MS_BTN2, \
    _______,    _______, _______,  LGUI(KC_LEFT),       LGUI(KC_RIGHT),       _______,    TO(0),            _______, _______,    _______, _______,        _______, \
    _______,    _______, _______,  _______,             _______ ,             _______,    _______,          _______, KC_MS_BTN1, _______, LGUI(KC_MINUS), LGUI(KC_EQUAL) \
),


[_MAC_ACTIONS] = LAYOUT_preonic_grid( \
    _______,    _______,    _______,     _______,          _______,          _______, _______, _______, _______,       _______,        _______,        _______, \
    _______,    _______,    LGUI(KC_E),  LGUI(LSFT(KC_4)), LGUI(LSFT(KC_3)), _______, _______, _______, _______,       _______,        _______,        _______, \
    LGUI(KC_A), LGUI(KC_S), LGUI(KC_D),  LGUI(KC_F),       _______,          _______, _______, _______, _______,       _______,        LGUI(KC_Q),     _______, \
    LGUI(KC_Z), KC_MAC_CUT, KC_MAC_COPY, KC_MAC_PASTE,     _______,          _______, _______, _______, _______,       _______,        _______,        LGUI(KC_SLASH), \
    TO(0),      _______,    _______,     _______,          _______,          _______, _______, _______, LGUI(KC_LEFT), LGUI(KC_RIGHT), LGUI(KC_MINUS), LGUI(KC_EQUAL) \
),

[_WIN_ACTIONS] = LAYOUT_preonic_grid( \
    _______,    _______,          _______,          _______,          _______,          _______,              _______, _______,          _______,       _______,        _______,        _______, \
    _______,    _______,          _______,          LCTL(LSFT(KC_R)), LALT(LCTL(KC_T)), _______,              _______, LCTL(LSFT(KC_Z)), _______,       _______,        _______,        _______, \
    LCTL(KC_A), LCTL(KC_S),       _______,          LCTL(KC_F),       _______,          LALT(LSFT(KC_ENTER)), _______, _______,          _______,       _______,        LGUI(KC_L),     _______, \
    LCTL(KC_Z), KC_PC_CUT,        KC_PC_COPY,       KC_PC_PASTE,      _______,          LALT(KC_ENTER),       _______, _______,          _______,       _______,        _______,        LCTL(KC_SLASH), \
    TO(0),      TO(0),            LCTL(LSFT(KC_C)), LCTL(LSFT(KC_V)), _______,          _______,              _______,   _______,          LALT(KC_LEFT), LALT(KC_RIGHT), LCTL(KC_MINUS), LCTL(KC_EQUAL) \
),
[_NORMIE] = LAYOUT_preonic_grid( \
    KC_1,    KC_2,    KC_3,      KC_4,    KC_5,             KC_GESC,   KC_BSPC,         KC_6,         KC_7,    KC_8,    KC_9,     KC_0,   \
    KC_Q,    KC_W,    KC_E,      KC_R,    KC_T,             KC_LBRC,   KC_LBRC,         KC_Y,         KC_U,    KC_I,    KC_O,     KC_P, \
    KC_A,    KC_S,    KC_D,      KC_F,    KC_G,             KC_TAB,    KC_QUOTE,        KC_H,         KC_J,    KC_K,    KC_L,     KC_SCLN, \
    KC_Z,    KC_X,    KC_C,      KC_V,    KC_B,             KC_LSHIFT, KC_SLASH,        KC_N,         KC_M,    KC_UP,   KC_MINS,  KC_EQUAL, \
    _______, _______, KC_LCTRL,  KC_LALT, LT(6, KC_SPACE),  KC_SPACE,  LT(7, KC_SPACE), TD(TD_COMMA), KC_LEFT, KC_DOWN, KC_RIGHT, KC_ENTER \
),

[_MTGAP] = LAYOUT_preonic_grid( \
    KC_1,   KC_2,   KC_3,     KC_4,    KC_5,            LGUI_T(KC_ESC),   KC_BSPC , KC_6,             KC_7,    KC_8,     KC_9,    KC_0,   \
    KC_Y,   KC_P,   KC_O,     KC_U,    KC_J,            TD(TD_L_BRA),     TD(TD_R_BRA),     KC_K,             KC_D,    KC_L,     KC_C,    KC_W, \
    KC_I,   KC_N,   KC_E,     KC_A,    TD(TD_COMMA),    KC_TAB,           KC_QUOTE,         KC_M,             KC_H,    KC_T,     KC_S,    KC_R, \
    KC_Q,   KC_Z,   KC_SLASH, _______, TD(TD_COL_PIPE), LSFT_T(KC_ENTER), TO(1),            KC_B,             KC_F,    KC_G,     KC_V,    KC_X, \
    OSL(2), OSL(3), KC_LCTRL, KC_LALT, LT(6, KC_SPACE), KC_SPACE,         LT(7, KC_SPACE),  LGUI_T(KC_SPACE), KC_MINS, KC_EQUAL, KC_DOWN, KC_ENTER \
),

[_LOWER] = LAYOUT_preonic_grid( \
    _______,       _______, _______,        _______,               _______, _______, _______,   _______, _______,             _______,       _______,              _______, \
    LALT(KC_LEFT), KC_UP,   LALT(KC_RIGHT), _______,               _______, _______, KC_BSPACE, _______, LALT(LSFT(KC_LEFT)), LSFT(KC_UP),   LALT(LSFT(KC_RIGHT)), _______, \
    KC_LEFT,       KC_DOWN, KC_RIGHT,       _______,               _______, _______, _______,   _______, LSFT(KC_LEFT),       LSFT(KC_DOWN), LSFT(KC_RIGHT),       _______, \
    _______,       _______, _______,        LCTL(LSFT(KC_BSPACE)), _______, _______, _______,   _______, _______,             _______,       _______,              _______, \
    _______,     KC_LGUI, KC_LCTRL,       KC_LALT,               _______, _______, _______,     _______, LSFT(KC_HOME),       LSFT(KC_END),  KC_HOME,              KC_END   \
),


[_RAISE] = LAYOUT_preonic_grid( \
    KC_F1,   KC_F2,     KC_F3,   KC_F4,   KC_F5,   _______, _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, \
    _______, _______,   _______, _______, _______, KC_F11,  KC_F12,  _______, _______, _______, _______, _______,\
    _______, _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,\
    _______, _______,   _______, _______, _______, _______, KC_EXLM, KC_AMPR, KC_ASTR, KC_PERC, KC_DLR,  KC_EXLM,\
    KC_AT,   KC_BSLASH, KC_PIPE, _______, _______, _______, _______, KC_DOT,  KC_LPRN, KC_RPRN, KC_CIRC, KC_HASH \
),


[_ADJUST] = LAYOUT_preonic_grid( \
  TO(0),   AU_TOG, CK_TOGG, _______, _______, TO(1),   _______, _______, _______,  _______, TO(5), TO(4),   \
  _______, RESET,   DEBUG,   _______, _______, _______, _______, TERM_ON, TERM_OFF, _______, _______, KC_DEL,  \
  _______, _______, _______,  _______,   _______,  _______, _______, _______, _______,  _______, _______, _______, \
  _______, MUV_DE,  MUV_IN,  _______, _______,  MI_ON,   MI_OFF,  _______, _______,  BL_INC, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, MU_TOG , _______,  BL_DEC, _______, _______  \
),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
        case MAC_ACTIONS:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_MAC_ACTIONS);
          }
          return false;
          break;
        case WIN_ACTIONS:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_WIN_ACTIONS);
          }
          return false;
          break;
        case NORMIE:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_NORMIE);
          }
          return false;
          break;
        case MTGAP:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_MTGAP);
          }
          return false;
          break;
        case MOUSE:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_MOUSE);
          }
          return false;
          break;

        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
      }
    return true;
};
