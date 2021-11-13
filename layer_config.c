
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
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
        case _LOWER:
            rgblight_mode(RGBLIGHT_MODE_BREATHING);
            rgblight_sethsv_magenta();
            autoshift_enable();
            break;
        case _RAISE:
            rgblight_mode(RGBLIGHT_MODE_BREATHING);
            rgblight_sethsv_yellow();
            autoshift_enable();
            break;
        case _ADJUST:
            rgblight_mode(RGBLIGHT_MODE_BREATHING);
            rgblight_sethsv_blue();
            autoshift_enable();
            break;
        default:
            rgblight_increase_speed();
            rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL + 5);
            autoshift_enable();
            break;
    }
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
