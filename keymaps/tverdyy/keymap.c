/*
                                             ▀▀▀▀▀     ▀▀▀▀▀          ▀▀█▀▀
                                             ▄▀▀▀▄  ▄  ▄▀▀▀▄  ▄  ▄▀▀▀▄  █  ▄▀▀▀▄
                                             █   █  █  █   █  █  █   █  █  █   █
                                              ▀▀▀   █   ▀▀▀   █   ▀▀▀   ▀   ▀▀▀
                                                    █      ▄▄▄█▄▄▄    █   █
                                                    ▀      █  █  █     █▄█
                                                  ▀▀▀▀▀    █  █  █      ▀
                                                           ▀  ▀  ▀  D E F A U L T

▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
*/

#include QMK_KEYBOARD_H
#include <stdio.h>
#include "swapper.h"
#include "sm_td.h"

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ D E F I N I T I O N S                                                                                                  │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

// ┌─────────────────────────────────────────────────┐
// │ d e f i n e   l a y e r s                       │
// └─────────────────────────────────────────────────┘

enum totem_layers {
    _QWERTY,
    _NAV,
    _SYM,
    _NUM,
    _UTIL
};

// ┌─────────────────────────────────────────────────┐
// │ d e f i n e   k e y c o d e s                   │
// └─────────────────────────────────────────────────┘

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    NAV,
    SYM,
    ADJUST,
    SW_WIN,
    SW_IN,
};

// ┌─────────────────────────────────────────────────┐
// │ d e f i n e   m a c r o n a m e s               │
// └─────────────────────────────────────────────────┘

#define NAV LT(_NAV, KC_TAB)
#define SYM LT(_SYM, KC_ENT)
#define NUM LT(_NUM, KC_BSPC)
#define UTIL LT(_UTIL, KC_DEL)
#define ADJUST MO(_NUM)


#define UNDO G(KC_Z)
#define REDO S(G(KC_Z))
#define S_CUT G(KC_X)
#define S_COPY G(KC_C)
#define S_PASTE G(KC_V)


// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ C O M B O S                                                                                                            │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘



// Left hand vertical combos
// Between top and home row
const uint16_t PROGMEM at_combo[] = {KC_W, KC_S, COMBO_END};
const uint16_t PROGMEM hash_combo[] = {KC_E, KC_D, COMBO_END};
const uint16_t PROGMEM dollar_combo[] = {KC_R, KC_F, COMBO_END};
const uint16_t PROGMEM perc_combo[] = {KC_T, KC_G, COMBO_END};

// Between home and bottom row
const uint16_t PROGMEM grave_combo[] = {KC_S, KC_X, COMBO_END};
const uint16_t PROGMEM bsls_combo[] = {KC_D, KC_C, COMBO_END};
const uint16_t PROGMEM eql_combo[] = {KC_F, KC_V, COMBO_END};
const uint16_t PROGMEM tilde_combo[] = {KC_G, KC_B, COMBO_END};

// horizontal combos
const uint16_t PROGMEM esc_combo[] = {KC_S, KC_F, COMBO_END};
const uint16_t PROGMEM copy_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM paste_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM cut_combo[] = {KC_X, KC_V, COMBO_END};

// Right hand vertical combos
// Between top and home row
const uint16_t PROGMEM caret_combo[] = {KC_Y, KC_H, COMBO_END};
const uint16_t PROGMEM plus_combo[] = {KC_U, KC_J, COMBO_END};
const uint16_t PROGMEM star_combo[] = {KC_I, KC_K, COMBO_END};
const uint16_t PROGMEM amp_combo[] = {KC_O, KC_L, COMBO_END};

// Between home and bottow row
const uint16_t PROGMEM unds_combo[] = {KC_H, KC_N, COMBO_END};
const uint16_t PROGMEM mins_combo[] = {KC_J, KC_M, COMBO_END};
const uint16_t PROGMEM slsh_combo[] = {KC_K, KC_COMM, COMBO_END};
const uint16_t PROGMEM pipe_combo[] = {KC_L, KC_DOT, COMBO_END};

// Horizontal combos: brackets
const uint16_t PROGMEM lsqr_combo[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM rsqr_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM lpar_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM rpar_combo[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM lcbr_combo[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM rcbr_combo[] = {KC_COMM, KC_DOT, COMBO_END};

const uint16_t PROGMEM lt_combo[] = {KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM gt_combo[] = {KC_L, KC_S, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  COMBO(at_combo, KC_AT),
  COMBO(hash_combo, KC_HASH),
  COMBO(dollar_combo, KC_DLR),
  COMBO(perc_combo, KC_PERC),
  COMBO(grave_combo, KC_GRV),
  COMBO(bsls_combo, KC_BSLS),
  COMBO(eql_combo, KC_EQL),
  COMBO(tilde_combo, KC_TILD),
  COMBO(esc_combo, KC_ESC),
  COMBO(copy_combo, S_COPY),
  COMBO(paste_combo, S_PASTE),
  COMBO(cut_combo, S_CUT),
  COMBO(caret_combo, KC_CIRC),
  COMBO(plus_combo, KC_PLUS),
  COMBO(star_combo, KC_ASTR),
  COMBO(amp_combo, KC_AMPR),
  COMBO(unds_combo, KC_UNDS),
  COMBO(mins_combo, KC_MINS),
  COMBO(slsh_combo, KC_SLSH),
  COMBO(pipe_combo, KC_PIPE),
  COMBO(lsqr_combo, KC_LBRC),
  COMBO(rsqr_combo, KC_RBRC),
  COMBO(lpar_combo, KC_LPRN),
  COMBO(rpar_combo, KC_RPRN),
  COMBO(lcbr_combo, KC_LCBR),
  COMBO(rcbr_combo, KC_RCBR),
  COMBO(lt_combo, KC_LT),
  COMBO(gt_combo, KC_GT)
};


// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ K E Y M A P S                                                                                                          │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//              ┌───┬───┬─────┬─────┬─────┐   ┌─────┬─────┬──────┬───┬───┐
//              │ q │ w │  e  │  r  │  t  │   │  y  │  u  │  i   │ o │ p │
//              ├───┼───┼─────┼─────┼─────┤   ├─────┼─────┼──────┼───┼───┤
//              │ a │ s │  d  │  f  │  g  │   │  h  │  j  │  k   │ l │ ; │
//    ┌─────────┼───┼───┼─────┼─────┼─────┤   ├─────┼─────┼──────┼───┼───┼─────┐
//    │ LCTL(s) │ z │ x │  c  │  v  │  b  │   │  n  │  m  │  ,   │ . │ / │ tab │
//    └─────────┴───┴───┼─────┼─────┼─────┤   ├─────┼─────┼──────┼───┴───┴─────┘
//                      │ esc │ NAV │ tab │   │ SYM │ NUM │ UTIL │
//                      └─────┴─────┴─────┘   └─────┴─────┴──────┘
[_QWERTY] = LAYOUT(
               KC_Q , KC_W , KC_E   , KC_R , KC_T   ,     KC_Y , KC_U , KC_I    , KC_O   , KC_P            ,
               KC_A , KC_S , KC_D   , KC_F , KC_G   ,     KC_H , KC_J , KC_K    , KC_L   , KC_SCLN         ,
  LCTL(KC_S) , KC_Z , KC_X , KC_C   , KC_V , KC_B   ,     KC_N , KC_M , KC_COMM , KC_DOT , KC_SLSH , KC_TAB,
                             KC_ESC , NAV  , KC_TAB ,     SYM  , NUM  , UTIL
),

//          ┌───┬───┬───┬───┬───┐   ┌─────┬──────┬──────┬──────┬──────┐
//          │ { │ & │ * │ ( │ } │   │     │      │      │      │      │
//          ├───┼───┼───┼───┼───┤   ├─────┼──────┼──────┼──────┼──────┤
//          │ ' │ $ │ % │ ^ │ + │   │     │ rsft │ rctl │ ralt │ rgui │
//    ┌─────┼───┼───┼───┼───┼───┤   ├─────┼──────┼──────┼──────┼──────┼─────┐
//    │     │ ~ │ ! │ @ │ # │ | │   │     │      │      │      │      │     │
//    └─────┴───┴───┼───┼───┼───┤   ├─────┼──────┼──────┼──────┴──────┴─────┘
//                  │ ( │ } │ _ │   │     │      │      │
//                  └───┴───┴───┘   └─────┴──────┴──────┘
[_SYM] = LAYOUT(
            KC_LCBR , KC_AMPR , KC_ASTR , KC_LPRN , KC_RCBR ,     KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS          ,
            KC_QUOT , KC_DLR  , KC_PERC , KC_CIRC , KC_PLUS ,     KC_TRNS , KC_RSFT , KC_RCTL , KC_RALT , KC_RGUI          ,
  KC_TRNS , KC_TILD , KC_EXLM , KC_AT   , KC_HASH , KC_PIPE ,     KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS,
                                KC_LPRN , KC_RCBR , KC_UNDS ,     KC_TRNS , KC_TRNS , KC_TRNS
),

//         ┌────┬────┬───────┬────────┬────┐   ┌──────┬──────┬──────┬──────┬────┐
//         │ no │ no │ SW_IN │ SW_WIN │ no │   │ pscr │ home │  up  │ end  │ no │
//         ├────┼────┼───────┼────────┼────┤   ├──────┼──────┼──────┼──────┼────┤
//         │ no │ no │  no   │   no   │ no │   │ caps │ left │ down │ rght │ no │
//    ┌────┼────┼────┼───────┼────────┼────┤   ├──────┼──────┼──────┼──────┼────┼────┐
//    │ no │ no │ no │ UNDO  │  REDO  │ no │   │  no  │  no  │  no  │  no  │ no │ no │
//    └────┴────┴────┼───────┼────────┼────┤   ├──────┼──────┼──────┼──────┴────┴────┘
//                   │  no   │   no   │ no │   │  no  │  no  │  no  │
//                   └───────┴────────┴────┘   └──────┴──────┴──────┘
[_NAV] = LAYOUT(
            XXXXXXX , XXXXXXX , SW_IN   , SW_WIN  , XXXXXXX ,     KC_PSCR , KC_HOME , KC_UP   , KC_END  , XXXXXXX          ,
            XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,     KC_CAPS , KC_LEFT , KC_DOWN , KC_RGHT , XXXXXXX          ,
  XXXXXXX , XXXXXXX , XXXXXXX , UNDO    , REDO    , XXXXXXX ,     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX,
                                XXXXXXX , XXXXXXX , XXXXXXX ,     XXXXXXX , XXXXXXX , XXXXXXX
),

//         ┌───┬───┬───┬───┬──────┐   ┌────┬──────┬──────┬──────┬──────┐
//         │ [ │ 7 │ 8 │ 9 │  ]   │   │ no │  no  │  no  │  no  │  no  │
//         ├───┼───┼───┼───┼──────┤   ├────┼──────┼──────┼──────┼──────┤
//         │ ` │ 4 │ 5 │ 6 │ kp_= │   │ no │ rsft │ rctl │ ralt │ rgui │
//    ┌────┼───┼───┼───┼───┼──────┤   ├────┼──────┼──────┼──────┼──────┼────┐
//    │ no │ ? │ 1 │ 2 │ 3 │  \   │   │ no │  no  │  no  │  no  │  no  │ no │
//    └────┴───┴───┼───┼───┼──────┤   ├────┼──────┼──────┼──────┴──────┴────┘
//                 │ . │ 0 │ kp_- │   │ no │  no  │  no  │
//                 └───┴───┴──────┘   └────┴──────┴──────┘
[_NUM] = LAYOUT(
            KC_LBRC , KC_7 , KC_8   , KC_9 , KC_RBRC ,     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX          ,
            KC_GRV  , KC_4 , KC_5   , KC_6 , KC_PEQL ,     XXXXXXX , KC_RSFT , KC_RCTL , KC_RALT , KC_RGUI          ,
  XXXXXXX , KC_QUES , KC_1 , KC_2   , KC_3 , KC_BSLS ,     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX,
                             KC_DOT , KC_0 , KC_PMNS ,     XXXXXXX , XXXXXXX , XXXXXXX
),

//         ┌─────────┬─────────┬────┬────┬────┐   ┌────┬────┬──────┬────┬────┐
//         │ QK_BOOT │ DB_TOGG │ no │ no │ no │   │ no │ no │ volu │ no │ no │
//         ├─────────┼─────────┼────┼────┼────┤   ├────┼────┼──────┼────┼────┤
//         │   no    │   no    │ no │ no │ no │   │ no │ no │ vold │ no │ no │
//    ┌────┼─────────┼─────────┼────┼────┼────┤   ├────┼────┼──────┼────┼────┼────┐
//    │ no │   no    │   no    │ no │ no │ no │   │ no │ no │  no  │ no │ no │ no │
//    └────┴─────────┴─────────┼────┼────┼────┤   ├────┼────┼──────┼────┴────┴────┘
//                             │ no │ no │ no │   │ no │ no │ mute │
//                             └────┴────┴────┘   └────┴────┴──────┘
[_UTIL] = LAYOUT(
            QK_BOOT , DB_TOGG , XXXXXXX , XXXXXXX , XXXXXXX ,     XXXXXXX , XXXXXXX , KC_VOLU , XXXXXXX , XXXXXXX          ,
            XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,     XXXXXXX , XXXXXXX , KC_VOLD , XXXXXXX , XXXXXXX          ,
  XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX,
                                XXXXXXX , XXXXXXX , XXXXXXX ,     XXXXXXX , XXXXXXX , KC_MUTE
)
};



// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ M A C R O S                                                                                                            │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

bool sw_win_active = false;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
     update_swapper(
        &sw_win_active, KC_LGUI, KC_TAB, SW_WIN,
        keycode, record
    );

    update_swapper(
        &sw_win_active, KC_LGUI, KC_TILD, SW_IN,
        keycode, record
    );
    return true;
}


smtd_resolution on_smtd_action(uint16_t keycode, smtd_action action, uint8_t tap_count) {
    switch (keycode) {
        // Left hand
        SMTD_MT(KC_A, KC_LCTL)
        SMTD_MT(KC_S, KC_LALT)
        SMTD_MT(KC_D, KC_LGUI)
        SMTD_MT(KC_F, KC_LSFT)
        SMTD_MT(KC_ESC, KC_LEFT)
        SMTD_MT(KC_TAB, OS_LSFT)

        // Right hand
        SMTD_MT(KC_J, KC_RSFT)
        SMTD_MT(KC_K, KC_RGUI)
        SMTD_MT(KC_L, KC_RALT)
        SMTD_MT(KC_SCLN, KC_RCTL)

    }

    return SMTD_RESOLUTION_UNHANDLED;
}
