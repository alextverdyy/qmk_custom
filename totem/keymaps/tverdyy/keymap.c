// clang-format off
#include <inttypes.h>
#include QMK_KEYBOARD_H
#include "oneshot.h"
#include "totem.h"

#include "g/keymap_combo.h"

enum totem_layers {
  _BASE,
  _NAV,
  _NUM,
  _SYM,
  _FUN,
  _UTIL,
};

enum keycodes {
  OS_GUI = SAFE_RANGE,
  OS_ALT,
  OS_SHFT,
  OS_CTRL,
  QK_UNDO,
  QK_CUT,
  QK_COPY,
  QK_PASTE,
  QK_BSPC,
  SW_APP,
    SW_INSTANCE
};

// LAYER TAP KEYS          ├───────────────────────────────────┐

#define NAV LT(_NAV, KC_SPACE)
#define NUM LT(_NUM, KC_BSPC)
#define FUN LT(_FUN, KC_DEL)
#define UTIL LT(_UTIL, KC_TAB)
#define SYM LT(_SYM, OS_SHFT)

// OTHER KEY DEFINITIONS   ├───────────────────────────────────┐

#define QK_UNDO LCTL(KC_Z)
#define QK_CUT LCTL(KC_X)
#define QK_COPY LCTL(KC_C)
#define QK_PASTE LCTL(KC_V)
#define QK_BSPC LCTL(KC_BSPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//             ┌───┬───┬──────┬─────┬─────┐   ┌─────┬─────┬─────┬───┬───┐
//             │ q │ w │  e   │  r  │  t  │   │  y  │  u  │  i  │ o │ p │
//             ├───┼───┼──────┼─────┼─────┤   ├─────┼─────┼─────┼───┼───┤
//             │ a │ s │  d   │  f  │  g  │   │  h  │  j  │  k  │ l │ ; │
//    ┌────────┼───┼───┼──────┼─────┼─────┤   ├─────┼─────┼─────┼───┼───┼─────────────┐
//    │ SW_APP │ z │ x │  c   │  v  │  b  │   │  n  │  m  │  ,  │ . │ ' │ SW_INSTANCE │
//    └────────┴───┴───┼──────┼─────┼─────┤   ├─────┼─────┼─────┼───┴───┴─────────────┘
//                     │ UTIL │ NAV │ SYM │   │ ent │ NUM │ FUN │
//                     └──────┴─────┴─────┘   └─────┴─────┴─────┘
[_BASE] = LAYOUT(
           KC_Q , KC_W , KC_E , KC_R , KC_T ,     KC_Y   , KC_U , KC_I    , KC_O   , KC_P                 ,
           KC_A , KC_S , KC_D , KC_F , KC_G ,     KC_H   , KC_J , KC_K    , KC_L   , KC_SCLN              ,
  SW_APP , KC_Z , KC_X , KC_C , KC_V , KC_B ,     KC_N   , KC_M , KC_COMM , KC_DOT , KC_QUOT , SW_INSTANCE,
                         UTIL , NAV  , SYM  ,     KC_ENT , NUM  , FUN
),

//          ┌─────────┬─────────┬──────────┬───────────┬────────┐   ┌──────┬──────┬──────┬──────┬──────┐
//          │ QK_UNDO │ QK_COPY │ QK_PASTE │  QK_CUT   │ QK_REP │   │      │ home │  up  │ end  │ pgup │
//          ├─────────┼─────────┼──────────┼───────────┼────────┤   ├──────┼──────┼──────┼──────┼──────┤
//          │ OS_CTRL │ OS_ALT  │  OS_GUI  │  OS_SHFT  │        │   │ caps │ left │ down │ rght │ pgdn │
//    ┌─────┼─────────┼─────────┼──────────┼───────────┼────────┤   ├──────┼──────┼──────┼──────┼──────┼─────┐
//    │     │         │         │ csa-none │ csag-none │        │   │      │  ~   │      │  /   │      │     │
//    └─────┴─────────┴─────────┼──────────┼───────────┼────────┤   ├──────┼──────┼──────┼──────┴──────┴─────┘
//                              │          │           │        │   │ ent  │ bspc │ del  │
//                              └──────────┴───────────┴────────┘   └──────┴──────┴──────┘
[_NAV] = LAYOUT(
            QK_UNDO , QK_COPY , QK_PASTE , QK_CUT  , QK_REP  ,     _______ , KC_HOME , KC_UP   , KC_END   , KC_PGUP          ,
            OS_CTRL , OS_ALT  , OS_GUI   , OS_SHFT , _______ ,     KC_CAPS , KC_LEFT , KC_DOWN , KC_RIGHT , KC_PGDN          ,
  _______ , _______ , _______ , KC_MEH   , KC_HYPR , _______ ,     _______ , KC_TILD , _______ , KC_SLSH  , _______ , _______,
                                _______  , _______ , _______ ,     KC_ENT  , KC_BSPC , KC_DEL
),

//        ┌───┬───┬─────┬───┬───┐   ┌─────┬───────────┬──────────┬────────┬─────────┐
//        │ + │ 1 │  2  │ 3 │ * │   │     │           │          │        │         │
//        ├───┼───┼─────┼───┼───┤   ├─────┼───────────┼──────────┼────────┼─────────┤
//        │ . │ 4 │  5  │ 6 │ = │   │     │  OS_CTRL  │  OS_ALT  │ OS_GUI │ OS_SHFT │
//    ┌───┼───┼───┼─────┼───┼───┤   ├─────┼───────────┼──────────┼────────┼─────────┼───┐
//    │ ( │ - │ 7 │  8  │ 9 │ / │   │     │ csag-none │ csa-none │        │         │ ) │
//    └───┴───┴───┼─────┼───┼───┤   ├─────┼───────────┼──────────┼────────┴─────────┴───┘
//                │     │ 0 │ ; │   │     │           │          │
//                └─────┴───┴───┘   └─────┴───────────┴──────────┘
[_NUM] = LAYOUT(
            KC_PLUS , KC_1 , KC_2    , KC_3 , KC_ASTR ,     _______ , _______ , _______ , _______ , _______          ,
            KC_DOT  , KC_4 , KC_5    , KC_6 , KC_EQL  ,     _______ , OS_CTRL , OS_ALT  , OS_GUI  , OS_SHFT          ,
  KC_LPRN , KC_MINS , KC_7 , KC_8    , KC_9 , KC_SLSH ,     _______ , KC_HYPR , KC_MEH  , _______ , _______ , KC_RPRN,
                             _______ , KC_0 , KC_SCLN ,     _______ , _______ , _______
),

//          ┌───┬───┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬─────┬─────┐
//          │ \ │ | │  _  │  &  │  %  │   │  +  │  -  │  =  │  *  │  /  │
//          ├───┼───┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┤
//          │ < │ : │  {  │  (  │  [  │   │  $  │     │     │     │     │
//    ┌─────┼───┼───┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┐
//    │     │ > │ ; │  }  │  )  │  ]  │   │     │  @  │  #  │  ^  │  ~  │     │
//    └─────┴───┴───┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┴─────┴─────┘
//                  │     │     │     │   │     │     │     │
//                  └─────┴─────┴─────┘   └─────┴─────┴─────┘
[_SYM] = LAYOUT(
            KC_BSLS , KC_PIPE , KC_UNDS , KC_AMPR , KC_PERC ,     KC_PLUS , KC_MINS , KC_EQL  , KC_ASTR , KC_SLSH          ,
            KC_LABK , KC_COLN , KC_LCBR , KC_LPRN , KC_LBRC ,     KC_DLR  , _______ , _______ , _______ , _______          ,
  _______ , KC_RABK , KC_SCLN , KC_RCBR , KC_RPRN , KC_RBRC ,     _______ , KC_AT   , KC_HASH , KC_CIRC , KC_TILD , _______,
                                _______ , _______ , _______ ,     _______ , _______ , _______
),

//           ┌─────┬────┬─────┬─────┬─────┐   ┌─────┬───────────┬──────────┬─────────┬─────────┐
//           │ f12 │ f7 │ f8  │ f9  │     │   │     │           │          │         │         │
//           ├─────┼────┼─────┼─────┼─────┤   ├─────┼───────────┼──────────┼─────────┼─────────┤
//           │ f11 │ f4 │ f5  │ f6  │     │   │     │           │          │         │         │
//    ┌──────┼─────┼────┼─────┼─────┼─────┤   ├─────┼───────────┼──────────┼─────────┼─────────┼─────────┐
//    │ pscr │ f10 │ f1 │ f2  │ f3  │     │   │     │ csag-none │ csa-none │ DM_REC1 │ DM_RSTP │ DM_PLY1 │
//    └──────┴─────┴────┼─────┼─────┼─────┤   ├─────┼───────────┼──────────┼─────────┴─────────┴─────────┘
//                      │     │     │     │   │     │           │          │
//                      └─────┴─────┴─────┘   └─────┴───────────┴──────────┘
[_FUN] = LAYOUT(
            KC_F12 , KC_F7 , KC_F8   , KC_F9   , _______ ,     _______ , _______ , _______ , _______ , _______          ,
            KC_F11 , KC_F4 , KC_F5   , KC_F6   , _______ ,     _______ , _______ , _______ , _______ , _______          ,
  KC_PSCR , KC_F10 , KC_F1 , KC_F2   , KC_F3   , _______ ,     _______ , KC_HYPR , KC_MEH  , DM_REC1 , DM_RSTP , DM_PLY1,
                             _______ , _______ , _______ ,     _______ , _______ , _______
),

//          ┌─────────┬─────────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬─────┬─────┐
//          │ QK_BOOT │ DB_TOGG │     │     │     │   │     │     │     │     │     │
//          ├─────────┼─────────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┤
//          │         │         │     │     │     │   │     │     │     │     │     │
//    ┌─────┼─────────┼─────────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼──────┐
//    │     │         │         │     │     │     │   │     │     │     │     │     │ mCTL │
//    └─────┴─────────┴─────────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┴─────┴──────┘
//                              │     │     │     │   │     │     │     │
//                              └─────┴─────┴─────┘   └─────┴─────┴─────┘
[_UTIL] = LAYOUT(
            QK_BOOT , DB_TOGG , _______ , _______ , _______ ,     _______ , _______ , _______ , _______ , _______          ,
            _______ , _______ , _______ , _______ , _______ ,     _______ , _______ , _______ , _______ , _______          ,
  _______ , _______ , _______ , _______ , _______ , _______ ,     _______ , _______ , _______ , _______ , _______ , KC_MCTL,
                                _______ , _______ , _______ ,     _______ , _______ , _______
)
};
// clang-format on

bool is_oneshot_cancel_key(uint16_t keycode) {
  switch (keycode) {
  case NAV:
  case NUM:
    return true;
  default:
    return false;
  }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
  switch (keycode) {
  case NAV:
  case NUM:
  case KC_LSFT:
  case OS_SHFT:
  case OS_CTRL:
  case OS_ALT:
  case OS_GUI:
    return true;
  default:
    return false;
  }
}

oneshot_state os_gui_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;

bool is_mac = false;

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  update_oneshot(&os_gui_state, KC_LGUI, OS_GUI, keycode, record);

  update_oneshot(&os_shft_state, KC_LSFT, OS_SHFT, keycode, record);

  update_oneshot(&os_alt_state, KC_LALT, OS_ALT, keycode, record);

  update_oneshot(&os_ctrl_state, KC_LCTL, OS_CTRL, keycode, record);
  switch (keycode) {
  case SW_APP:

    if (record->event.pressed) {
      if (!is_alt_tab_active) {
        is_alt_tab_active = true;
        register_code(is_mac ? KC_LGUI : KC_LALT);
      }
      alt_tab_timer = timer_read();
      register_code(KC_TAB);
    } else {
      unregister_code(KC_TAB);
    }
    break;
  case SW_INSTANCE:

    if (record->event.pressed) {
      if (!is_alt_tab_active) {
        is_alt_tab_active = true;
        register_code(is_mac ? KC_LGUI : KC_LALT);
      }
      alt_tab_timer = timer_read();
      register_code(KC_GRV);
    } else {
      unregister_code(KC_GRV);
    }
    break;
  }

  return true;
}

bool process_detected_host_os_kb(os_variant_t detected_os) {
  if (!process_detected_host_os_user(detected_os)) {
    return false;
  }
  switch (detected_os) {
  case OS_MACOS:
  case OS_IOS:
    is_mac = true;
    keymap_config.swap_lctl_lgui = true;
    break;
  case OS_WINDOWS:
  case OS_LINUX:
  case OS_UNSURE:
    is_mac = false;
    keymap_config.swap_lctl_lgui = true;
    break;
  }

  return true;
}
