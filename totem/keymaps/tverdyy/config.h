#pragma once

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/

#define MASTER_LEFT
// #define MASTER_RIGHT

/* QMK */
#define TAPPING_TERM 200

#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#define CAPS_WORD_INVERT_ON_SHIFT

#define COMBO_COUNT 28
#define COMBO_MUST_TAP_PER_COMBO
