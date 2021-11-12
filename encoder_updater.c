#ifndef ENCODER_UPDATER
#define ENCODER_UPDATER

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

#endif
