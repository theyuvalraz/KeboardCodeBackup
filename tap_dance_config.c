
typedef struct {
    bool is_press_action;
    int  state;
} tap;

enum { SINGLE_TAP = 1, SINGLE_HOLD, DOUBLE_TAP, DOUBLE_HOLD, DOUBLE_SINGLE_TAP, TRIPLE_TAP, TRIPLE_HOLD };

enum {
    TD_COMMA,
    TD_L_BRA,
    TD_R_BRA,
};

int  cur_dance(tap_dance_state_t *state);
void x_finished(tap_dance_state_t *state, void *user_data);
void x_reset(tap_dance_state_t *state, void *user_data);

int cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else
            return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted)
            return DOUBLE_SINGLE_TAP;
        else if (state->pressed)
            return DOUBLE_HOLD;
        else
            return DOUBLE_TAP;
    }

    if (state->count == 3) {
        if (state->interrupted || !state->pressed)
            return TRIPLE_TAP;
        else
            return TRIPLE_HOLD;
    } else
        return 8;
}

// Create an instance of 'tap' for the 'x' tap dance.
static tap xtap_state = {.is_press_action = true, .state = 0};

void l_bra_finished(tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        case SINGLE_TAP:
            register_code16(KC_LEFT_CURLY_BRACE);
            break;
        case SINGLE_HOLD:
            register_code16(KC_LBRC);
            break;
        case DOUBLE_TAP:
            register_code16(KC_LEFT_PAREN);
            break;
        case DOUBLE_HOLD:
            register_code16(KC_LEFT_ANGLE_BRACKET);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_LEFT_CURLY_BRACE);
            register_code16(KC_LEFT_CURLY_BRACE);
    }
}

void l_bra_reset(tap_dance_state_t *state, void *user_data) {
    switch (xtap_state.state) {
        case SINGLE_TAP:
            unregister_code16(KC_LEFT_CURLY_BRACE);
            break;
        case SINGLE_HOLD:
            unregister_code16(KC_LBRC);
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_LEFT_PAREN);
            break;
        case DOUBLE_HOLD:
            unregister_code16(KC_LEFT_ANGLE_BRACKET);
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_LEFT_CURLY_BRACE);
    }
    xtap_state.state = 0;
}

void r_bra_finished(tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        case SINGLE_TAP:
            register_code16(KC_RIGHT_CURLY_BRACE);
            break;
        case SINGLE_HOLD:
            register_code16(KC_RBRC);
            break;
        case DOUBLE_TAP:
            register_code16(KC_RIGHT_PAREN);
            break;
        case DOUBLE_HOLD:
            register_code16(KC_RIGHT_ANGLE_BRACKET);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_RIGHT_CURLY_BRACE);
            register_code16(KC_RIGHT_CURLY_BRACE);
    }
}

void r_bra_reset(tap_dance_state_t *state, void *user_data) {
    switch (xtap_state.state) {
        case SINGLE_TAP:
            unregister_code16(KC_RIGHT_CURLY_BRACE);
            break;
        case SINGLE_HOLD:
            unregister_code16(KC_RBRC);
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_RIGHT_PAREN);
            break;
        case DOUBLE_HOLD:
            unregister_code16(KC_RIGHT_ANGLE_BRACKET);
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_RIGHT_CURLY_BRACE);
    }
    xtap_state.state = 0;
}

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    [TD_COMMA] = ACTION_TAP_DANCE_DOUBLE(KC_COMMA, KC_DOT),
    [TD_L_BRA] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, l_bra_finished, l_bra_reset),
    [TD_R_BRA] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, r_bra_finished, r_bra_reset),
};
