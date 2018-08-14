
#ifndef CONFIG_USER_H
  #define CONFIG_USER_H
#endif

#include "../../config.h"

#define PERMISSIVE_HOLD
#undef TAPPING_TOGGLE
#define TAPPING_TOGGLE 2

#ifndef NO_DEBUG
  #define NO_DEBUG
#endif
#ifndef NO_PRINT
  #define NO_PRINT
#endif

#define EMPTY_BOTTOM_ROW                                       \
_______, _______, _______, _______, _______

#define EMPTY_TOP_ROW                                          \
_______, _______, _______, _______, _______, _______, _______

#define THUMBS                                                 \
_______, _______, _______, _______, _______, _______

#define EMPTY_HALF                                             \
_______, _______, _______, _______, _______, _______, _______, \
_______, _______, _______, _______, _______, _______, _______, \
_______, _______, _______, _______, _______, _______,          \
_______, _______, _______, _______, _______, _______, _______, \
_______, _______, _______, _______, _______,                   \
_______, _______, _______,                                     \
_______, _______, _______

#define LAYOUT_ergodox_pretty_wrapper(...) LAYOUT_ergodox_pretty(__VA_ARGS__)
#define LAYOUT_ergodox_wrapper(...) LAYOUT_ergodox(__VA_ARGS__)

#define LED_INTERVAL 1500
#define LG__GERMAN__ 0
#define LG__ENGLISH__ 1
#define is_shifted (keyboard_report->mods & MOD_BIT(KC_LSFT) || \
                   ((get_oneshot_mods() & MOD_BIT(KC_LSFT)) &&  \
                   !has_oneshot_mods_timed_out()))

