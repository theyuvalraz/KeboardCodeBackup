#include "music_mode.c"
#include "layer_config.c"

enum preonic_keycodes {
    QWERTY = SAFE_RANGE,
    MOUSE,
    MAC_ACTIONS,
    WIN_ACTIONS,
    LOWER,
    RAISE,
};

/*Here I set the first rgb mode*/
void keyboard_post_init_user(void) {
    rgblight_enable();  // Enables RGB, without saving settings
}

void suspend_wakeup_init_user(void) {
    rgblight_enable();  // Enables RGB, without saving settings
    rgblight_mode(RGBLIGHT_MODE_BREATHING);
    rgblight_sethsv_chartreuse();
    startup_user();
}

void startup_user()
{
    wait_ms(20);
    PLAY_SONG(zeldaPazzleSong);
}

