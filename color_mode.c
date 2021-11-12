#ifndef COLOR_MODE
#define COLOR_MODE
#include <muse.h>
#include "music_mode.c"


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

/*Here I set the first rgb mode*/
void keyboard_post_init_user(void) {
    rgblight_enable();  // Enables RGB, without saving settings
    rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL + 3);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _QWERTY:
        rgblight_increase_speed();
        rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL + 5);
        autoshift_enable();
        break;
    case _MOUSE:
        PLAY_SONG(zeldaTreasureSong);
        rgblight_mode(RGBLIGHT_MODE_CHRISTMAS);
        rgblight_increase_speed();
        autoshift_enable();
        break;
    case _MAC_ACTIONS:
        rgblight_mode(RGBLIGHT_MODE_SNAKE);
        rgblight_sethsv_red();
        autoshift_enable();
        break;
    case _WIN_ACTIONS:
        rgblight_mode(RGBLIGHT_MODE_SNAKE);
        rgblight_sethsv_blue();
        autoshift_enable();
        break;
    case _NORMIE:
        rgblight_mode(1);
        rgblight_setrgb (0xFF, 0xFF , 0xFF);
        autoshift_disable();
        break;
    case _LOWER:
        rgblight_mode(RGBLIGHT_MODE_SNAKE);
        rgblight_sethsv_magenta();
        autoshift_enable();
        break;
    case _RAISE:
        rgblight_mode(RGBLIGHT_MODE_SNAKE);
        rgblight_sethsv_yellow();
        autoshift_enable();
        break;
    case _ADJUST:
        rgblight_mode(RGBLIGHT_MODE_SNAKE);
        rgblight_sethsv_blue();
        autoshift_enable();
        break;
    default:
        rgblight_mode(1);
        rgblight_setrgb (0,  255, 0);
        autoshift_enable();
        break;
    }
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

#endif
