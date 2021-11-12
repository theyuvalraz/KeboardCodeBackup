#ifndef TAP_DANCE_CONFIG
#define TAP_DANCE_CONFIG



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
    TD_COMMA,
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
    [TD_ESC_CAPS]  = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
    [TD_COMMA]     = ACTION_TAP_DANCE_DOUBLE( KC_COMMA, KC_DOT),
    [TD_COL_PIPE]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, col_finished, col_reset),
    [TD_L_BRA]     = ACTION_TAP_DANCE_FN_ADVANCED(NULL, l_bra_finished, l_bra_reset),
    [TD_R_BRA]     = ACTION_TAP_DANCE_FN_ADVANCED(NULL, r_bra_finished, r_bra_reset),
    [TD_BACKSPACE] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, back_finished, back_reset, 150),
};


#endif
