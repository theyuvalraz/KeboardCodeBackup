#include QMK_KEYBOARD_H
#include "muse.h"

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

// make preonic/rev3:dragon_yraz

typedef struct {
    bool is_press_action;
    int state;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    TRIPLE_TAP,
    TRIPLE_HOLD
};

enum {
    TD_ESC_CAPS,
    TD_COL_PIPE,
    TD_L_BRA,
    TD_R_BRA,
    TD_BACKSPACE,
    TD_COMMA
};

int cur_dance(qk_tap_dance_state_t *state);
void x_finished(qk_tap_dance_state_t *state, void *user_data);
void x_reset(qk_tap_dance_state_t *state, void *user_data);

int cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }

    if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TRIPLE_TAP;
        else return TRIPLE_HOLD;
    } else return 8;
}

// Create an instance of 'tap' for the 'x' tap dance.
static tap xtap_state = {
    .is_press_action = true,
    .state = 0
};

void col_finished(qk_tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        case SINGLE_TAP: register_code16(KC_SCOLON); break;
        case SINGLE_HOLD: register_code16(KC_COLON); break;
        case DOUBLE_TAP: register_code16(KC_PIPE); break;
        case DOUBLE_HOLD: register_code16(KC_NO); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_SCOLON); register_code16(KC_SCOLON);
    }
}

void col_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (xtap_state.state) {
        case SINGLE_TAP: unregister_code16(KC_SCOLON); break;
        case SINGLE_HOLD: unregister_code16(KC_COLON); break;
        case DOUBLE_TAP: unregister_code16(KC_PIPE); break;
        case DOUBLE_HOLD: unregister_code16(KC_NO);
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_SCOLON);
    }
    xtap_state.state = 0;
}

void l_bra_finished(qk_tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        case SINGLE_TAP: register_code16(KC_LEFT_CURLY_BRACE); break;
        case SINGLE_HOLD: register_code16(KC_LBRC); break;
        case DOUBLE_TAP: register_code16(KC_LEFT_PAREN); break;
        case DOUBLE_HOLD: register_code16(KC_LEFT_ANGLE_BRACKET); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_LEFT_CURLY_BRACE); register_code16(KC_LEFT_CURLY_BRACE);
    }
}

void l_bra_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (xtap_state.state) {
        case SINGLE_TAP: unregister_code16(KC_LEFT_CURLY_BRACE); break;
        case SINGLE_HOLD: unregister_code16(KC_LBRC); break;
        case DOUBLE_TAP: unregister_code16(KC_LEFT_PAREN); break;
        case DOUBLE_HOLD: unregister_code16(KC_LEFT_ANGLE_BRACKET);
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_LEFT_CURLY_BRACE);
    }
    xtap_state.state = 0;
}

void r_bra_finished(qk_tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        case SINGLE_TAP: register_code16(KC_RIGHT_CURLY_BRACE); break;
        case SINGLE_HOLD: register_code16(KC_RBRC); break;
        case DOUBLE_TAP: register_code16(KC_RIGHT_PAREN); break;
        case DOUBLE_HOLD: register_code16(KC_RIGHT_ANGLE_BRACKET); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_RIGHT_CURLY_BRACE); register_code16(KC_RIGHT_CURLY_BRACE);
    }
}

void r_bra_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (xtap_state.state) {
        case SINGLE_TAP: unregister_code16(KC_RIGHT_CURLY_BRACE); break;
        case SINGLE_HOLD: unregister_code16(KC_RBRC); break;
        case DOUBLE_TAP: unregister_code16(KC_RIGHT_PAREN); break;
        case DOUBLE_HOLD: unregister_code16(KC_RIGHT_ANGLE_BRACKET);
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_RIGHT_CURLY_BRACE);
    }
    xtap_state.state = 0;
}


void back_finished(qk_tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        case SINGLE_TAP: register_code16(KC_BSPACE); break;
        case SINGLE_HOLD: register_code16(KC_BSPACE); break;
        case DOUBLE_TAP: tap_code16(KC_BSPACE); register_code16(KC_BSPACE); break;
        case DOUBLE_HOLD: register_code16(LALT(KC_BSPACE)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_BSPACE); register_code16(KC_BSPACE);
    }
}

void back_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (xtap_state.state) {
        case SINGLE_TAP: unregister_code16(KC_BSPACE); break;
        case SINGLE_HOLD: unregister_code16(KC_BSPACE); break;
        case DOUBLE_TAP: unregister_code16(KC_BSPACE); break;
        case DOUBLE_HOLD: unregister_code16(LALT(KC_BSPACE)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_BSPACE);
    }
    xtap_state.state = 0;
}

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_ESC_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
    [TD_COL_PIPE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, col_finished, col_reset),
    [TD_L_BRA] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, l_bra_finished, l_bra_reset),
    [TD_R_BRA] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, r_bra_finished, r_bra_reset),
    [TD_BACKSPACE] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, back_finished, back_reset, 150),
    [TD_COMMA] = ACTION_TAP_DANCE_DOUBLE( KC_COMMA, KC_DOT),

};


enum preonic_layers {
  _QWERTY,
  _MOUSE,
  _MAC_ACTIONS,
  _WIN_ACTIONS,
  _NORMIE,
  _MTGAP,
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  MOUSE,
  MAC_ACTIONS,
  WIN_ACTIONS,
  NORMIE,
  MTGAP,
  LOWER,
  RAISE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_preonic_grid( \
    KC_1,    KC_2,    KC_3,      KC_4,    KC_5,            LGUI_T(KC_ESC),   KC_BSPC , KC_6,   KC_7,    KC_8,         KC_9,    KC_0,   \
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
    TO(0),      LCTL(LSFT(KC_X)), LCTL(LSFT(KC_C)), LCTL(LSFT(KC_V)), _______,          _______,              _______,   _______,          LALT(KC_LEFT), LALT(KC_RIGHT), LCTL(KC_MINUS), LCTL(KC_EQUAL) \
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
  TO(0),   _______, _______, _______, _______, TO(1),   _______, _______, _______,  _______, TO(5), TO(4),   \
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

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;


void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _QWERTY:
        rgblight_setrgb (0,  255, 0);
        autoshift_enable();
        break;
    case _MOUSE:
        rgblight_setrgb (0xFF,  0x14, 0x93);
        autoshift_enable();
        break;
    case _MAC_ACTIONS:
        rgblight_setrgb (0xFF, 0x00 , 0x00);
        autoshift_enable();
        break;
    case _WIN_ACTIONS:
        rgblight_setrgb (0x00, 0x00 , 0xFF);
        autoshift_enable();
        break;
    case _NORMIE:
        rgblight_setrgb (0xFF, 0xFF , 0xFF);
        autoshift_disable();
        break;
    case _MTGAP:
        rgblight_setrgb (81, 233, 255);
        autoshift_enable();
        break;
    case _LOWER:
        rgblight_setrgb (0xFF, 0xFF , 0x00);
        autoshift_enable();
        break;
    case _RAISE:
        rgblight_setrgb (0x00, 0x00 , 0xFF);
        autoshift_enable();
        break;
    case _ADJUST:
        rgblight_setrgb (0x7F, 0xFF , 0xD4);
        autoshift_enable();
        break;
    default: //  for any other layers, or the default layer
        rgblight_setrgb (255,  255, 0);
        autoshift_enable();
        break;
    }
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

void encoder_update_user(uint8_t index, bool clockwise) {
    switch(biton32(layer_state)){
        case 6:
            if (clockwise){tap_code(KC_VOLU);}
            else{tap_code(KC_VOLD);}
            break;
        case 1:
            if (clockwise) {tap_code(KC_WH_R);}
            else {tap_code(KC_WH_L);}
            break;
        default:
            if (clockwise){tap_code(KC_RIGHT);}
            else{tap_code(KC_LEFT);}
            break;
    }
}
