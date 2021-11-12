

#pragma once

#ifdef AUDIO_ENABLE
#   define AUDIO_CLICKY
#   define AUDIO_CLICKY_FREQ_RANDOMNESS 1.0f
#   define MIDI_BASIC
#   define MUSIC_MASK keycode != KC_NO
#endif

/*
 * MIDI options
 */

// #define MIDI_BASIC

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
// #define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
// #define MIDI_TONE_KEYCODE_OCTAVES 4


#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX 45

#undef MOUSEKEY_WHEEL_MAX_SPEED
#define MOUSEKEY_WHEEL_MAX_SPEED 6

#undef MOUSEKEY_WHEEL_TIME_TO_MAX
#define MOUSEKEY_WHEEL_TIME_TO_MAX 50

#define RGBLIGHT_LAYERS

#define AUTO_SHIFT_TIMEOUT 220
#define TAPPING_TERM 180
#define TAP_CODE_DELAY 10

#define ENCODERS_PAD_A { B12 }
#define ENCODERS_PAD_B { B13 }
#define ENCODER_RESOLUTION 4
