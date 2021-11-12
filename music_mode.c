#ifndef MUSIC_MODE
#define MUSIC_MODE
#include <muse.h>


#ifdef AUDIO_ENABLE
float goodBySong[][2] = SONG(GOODBYE_SOUND);
float zeldaPazzleSong[][2] = SONG(ZELDA_PUZZLE);
float zeldaTreasureSong[][2] = SONG(ZELDA_TREASURE);


void suspend_wakeup_init_user(void) {
        rgblight_mode(RGBLIGHT_MODE_BREATHING);
        rgblight_sethsv_chartreuse();
        PLAY_SONG(zeldaPazzleSong);
}
#endif


#define ZELDA_PUZZLE \
    Q__NOTE(_G5),     \
    Q__NOTE(_FS5),    \
    Q__NOTE(_DS5),     \
    Q__NOTE(_A4),    \
    Q__NOTE(_GS4),     \
    Q__NOTE(_E5),     \
    Q__NOTE(_GS5),     \
    HD_NOTE(_C6),

#define ZELDA_TREASURE \
    Q__NOTE(_A4 ), \
    Q__NOTE(_AS4), \
    Q__NOTE(_B4 ), \
    HD_NOTE(_C5 ), \

#define COIN_SOUND \
    E__NOTE(_A5  ),      \
    HD_NOTE(_E6  ),

#define ONE_UP_SOUND \
    Q__NOTE(_E6  ),  \
    Q__NOTE(_G6  ),  \
    Q__NOTE(_E7  ),  \
    Q__NOTE(_C7  ),  \
    Q__NOTE(_D7  ),  \
    Q__NOTE(_G7  ),

#define SONIC_RING \
    E__NOTE(_E6),  \
    E__NOTE(_G6),  \
    HD_NOTE(_C7),

#define MARIO_THEME \
    Q__NOTE(_E5), \
    H__NOTE(_E5), \
    H__NOTE(_E5), \
    Q__NOTE(_C5), \
    H__NOTE(_E5), \
    W__NOTE(_G5), \
    Q__NOTE(_G4),

#define MARIO_GAMEOVER \
    HD_NOTE(_C5 ), \
    HD_NOTE(_G4 ), \
    H__NOTE(_E4 ), \
    H__NOTE(_A4 ), \
    H__NOTE(_B4 ), \
    H__NOTE(_A4 ), \
    H__NOTE(_AF4), \
    H__NOTE(_BF4), \
    H__NOTE(_AF4), \
    WD_NOTE(_G4 ),

#define MARIO_MUSHROOM \
    S__NOTE(_C5 ), \
    S__NOTE(_G4 ), \
    S__NOTE(_C5 ), \
    S__NOTE(_E5 ), \
    S__NOTE(_G5 ), \
    S__NOTE(_C6 ), \
    S__NOTE(_G5 ), \
    S__NOTE(_GS4), \
    S__NOTE(_C5 ), \
    S__NOTE(_DS5), \
    S__NOTE(_GS5), \
    S__NOTE(_DS5), \
    S__NOTE(_GS5), \
    S__NOTE(_C6 ), \
    S__NOTE(_DS6), \
    S__NOTE(_GS6), \
    S__NOTE(_DS6), \
    S__NOTE(_AS4), \
    S__NOTE(_D5 ), \
    S__NOTE(_F5 ), \
    S__NOTE(_AS5), \
    S__NOTE(_D6 ), \
    S__NOTE(_F6 ), \
    S__NOTE(_AS6), \
    S__NOTE(_F6 )

#define DISNEY_SONG \
    H__NOTE(_G3 ),  \
    H__NOTE(_G4 ),  \
    H__NOTE(_F4 ),  \
    H__NOTE(_E4 ),  \
    H__NOTE(_CS4),  \
    H__NOTE(_D4 ),  \
    W__NOTE(_A4 ),  \
    H__NOTE(_B3 ),  \
    H__NOTE(_B4 ),  \
    H__NOTE(_A4 ),  \
    H__NOTE(_G4 ),  \
    H__NOTE(_FS4),  \
    H__NOTE(_G4 ),  \
    W__NOTE(_C5 ),  \
    H__NOTE(_D5 ),  \
    H__NOTE(_C5 ),  \
    H__NOTE(_B4 ),  \
    H__NOTE(_A4 ),  \
    H__NOTE(_G4 ),  \
    H__NOTE(_F4 ),  \
    H__NOTE(_E4 ),  \
    H__NOTE(_D4 ),  \
    W__NOTE(_A4 ),  \
    W__NOTE(_B3 ),  \
    W__NOTE(_C4 ),

#define NUMBER_ONE \
    HD_NOTE(_F4 ), \
    Q__NOTE(_C5 ), \
    E__NOTE(_B4 ), \
    E__NOTE(_C5 ), \
    E__NOTE(_B4 ), \
    E__NOTE(_C5 ), \
    Q__NOTE(_B4 ), \
    Q__NOTE(_C5 ), \
    H__NOTE(_AF4), \
    HD_NOTE(_F4 ), \
    Q__NOTE(_F4 ), \
    Q__NOTE(_AF4), \
    Q__NOTE(_C5 ), \
    H__NOTE(_DF5), \
    H__NOTE(_AF4), \
    H__NOTE(_DF5), \
    H__NOTE(_EF5), \
    Q__NOTE(_C5 ), \
    Q__NOTE(_DF5), \
    Q__NOTE(_C5 ), \
    Q__NOTE(_DF5), \
    H__NOTE(_C5 ),

#define CABBAGE_SONG \
    H__NOTE(_C4),    \
    H__NOTE(_A4),    \
    H__NOTE(_B4),    \
    H__NOTE(_B4),    \
    H__NOTE(_A4),    \
    H__NOTE(_G4),    \
    H__NOTE(_E4),

#define OLD_SPICE  \
    Q__NOTE(_A4 ), \
    Q__NOTE(_A4 ), \
    H__NOTE(_B4 ), \
    H__NOTE(_D5 ), \
    H__NOTE(_CS5), \
    Q__NOTE(_E5 ), \
    H__NOTE(_FS5), \
    H__NOTE(_D5 ), \

#define VICTORY_FANFARE_SHORT \
    ED_NOTE(_C6), \
    ED_NOTE(_C6), \
    ED_NOTE(_C6), \
    ED_NOTE(_C6), \
    W__NOTE(_REST), \
    QD_NOTE(_GS5), \
    QD_NOTE(_AS5), \
    Q__NOTE(_C6), \
    Q__NOTE(_AS5), \
    Q__NOTE(_C6), \

#define ALL_STAR \
    H__NOTE(_AS4), W__NOTE(_FS4), Q__NOTE(_FS4), Q__NOTE(_DS4), H__NOTE(_FS4), W__NOTE(_FS4), Q__NOTE(_FS4), Q__NOTE(_DS4), \
    H__NOTE(_FS4), W__NOTE(_FS4), W__NOTE(_FS4), QD_NOTE(_AS4), \
    H__NOTE(_AS4), W__NOTE(_FS4), Q__NOTE(_FS4), Q__NOTE(_DS4), H__NOTE(_FS4), W__NOTE(_FS4), Q__NOTE(_FS4), Q__NOTE(_DS4), \
    H__NOTE(_FS4), W__NOTE(_FS4), W__NOTE(_FS4), W__NOTE(_AS4), H__NOTE(_REST),\
    W__NOTE(_AS4), W__NOTE(_CS5), H__NOTE(_B4),  H__NOTE(_CS5), H__NOTE(_DS5), W__NOTE(_FS5), \
    H__NOTE(_GS5), W__NOTE(_GS5), H__NOTE(_FS4), H__NOTE(_FS4), H__NOTE(_GS4), H__NOTE(_FS4), \
    H__NOTE(_AS4), W__NOTE(_GS4), W__NOTE(_GS4), W__NOTE(_FS4), W__NOTE(_GS4), \
    H__NOTE(_AS4), WD_NOTE(_DS4)

#endif

