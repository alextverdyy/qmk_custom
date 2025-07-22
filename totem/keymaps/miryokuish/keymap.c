/*
                                             ▀▀▀▀▀     ▀▀▀▀▀          ▀▀█▀▀
                                             ▄▀▀▀▄  ▄  ▄▀▀▀▄  ▄  ▄▀▀▀▄  █  ▄▀▀▀▄
                                             █   █  █  █   █  █  █   █  █  █   █
                                              ▀▀▀   █   ▀▀▀   █   ▀▀▀   ▀   ▀▀▀
                                                    █      ▄▄▄█▄▄▄    █   █
                                                    ▀      █  █  █     █▄█
                                                  ▀▀▀▀▀    █  █  █      ▀   ┌─┐┌─╴╷┌──┬─
                                                           ▀  ▀  ▀          │ ┐├─╴│└─┐│
                                                                            └─┘└─╴╵╶─┘╵
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
*/

#include QMK_KEYBOARD_H

#include "totem.h"

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ D E F I N I T I O N S                                                                                                  │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

bool select_word_host_is_mac(void) {
    switch (detected_host_os()) {
        case OS_LINUX:
        case OS_WINDOWS:
            return false;
        case OS_MACOS:
        case OS_IOS:
            return true;
        default:
            return true;
            break;
    }
}

#define IS_MAC select_word_host_is_mac()

// ┌─────────────────────────────────────────────────┐
// │ d e f i n e   l a y e r s                       │
// └─────────────────────────────────────────────────┘

enum totem_layers {
    _BASE,
    _NAV,
    _NUM,
    _SYM,
    _FUN,
    _UTIL,
};

// ┌─────────────────────────────────────────────────┐
// │ d e f i n e   k e y c o d e s                   │
// └─────────────────────────────────────────────────┘

enum custom_keycodes {
    SMTD_KEYCODES_BEGIN = SAFE_RANGE,
    NAV,
    NUM,
    FUN,
    UTIL,
    OS_SWAP,
    SNAP,
    OS_SHFT,
    OS_CTRL,
    OS_ALT,
    OS_CMD,
    // SM_TD Defs
    CKC_A,
    CKC_S,
    CKC_D,
    CKC_F,
    CKC_J,
    CKC_K,
    CKC_L,
    CKC_SCLN,
    CKC_BSPC,
    CKC_RIGHT,
    CKC_LEFT,
    CKC_DOWN,
    CKC_UP,
    // End SM_TD Defs
    PREV_APP,
    NEXT_APP,
    W_LEFT,
    W_RIGHT,
    W_UP,
    W_DOWN,

    SW_WIN,  // Switch to next window         (cmd-tab)
    SW_INST, // Switch to next instance       (cmd+~)
    SMTD_KEYCODES_END,
};


#include "sm_td.h"

// ┌─────────────────────────────────────────────────┐
// │ d e f i n e   m a c r o n a m e s               │
// └─────────────────────────────────────────────────┘
#define OS_SHT OSM(MOD_LSFT)

// LEFT HAND HOME ROW MODS ├───────────────────────────────────┐

#define HYP_V MT(MOD_HYPR, KC_V)
#define MEH_C MT(MOD_MEH, KC_C)

// RIGHT HAND HOME ROW MODS ├───────────────────────────────────┐

#define HYP_M MT(MOD_HYPR, KC_M)
#define MEH_COM MT(MOD_MEH, KC_COMM)

// LAYER TAP KEYS          ├───────────────────────────────────┐

#define NAV LT(_NAV, KC_SPACE)
#define NUM LT(_NUM, KC_BSPC)
#define FUN LT(_FUN, KC_DEL)
#define UTIL LT(_UTIL, KC_ESC)
#define SYM LT(_SYM, OS_SHT)


// OTHER KEY DEFINITIONS   ├───────────────────────────────────┐

#define BACK G(KC_LBRC)
#define FWD G(KC_RBRC)

#define S_CUT G(KC_X)
#define S_COPY G(KC_C)
#define S_PASTE G(KC_V)
#define UNDO G(KC_Z)
#define REDO S(G(KC_Z))


// ┌─────────────────────────────────────────────────┐
// │ d e f i n e   c o m b o s                       │
// └─────────────────────────────────────────────────┘


const uint16_t PROGMEM esc_combo[] = {KC_S, KC_F, COMBO_END};
const uint16_t PROGMEM copy_combo[] = {KC_X, MEH_C, COMBO_END};
const uint16_t PROGMEM paste_combo[] = {MEH_C, HYP_V, COMBO_END};
const uint16_t PROGMEM cut_combo[] = {KC_X, HYP_V, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  COMBO(esc_combo, KC_ESC),
  COMBO(copy_combo, S_COPY),
  COMBO(paste_combo, S_PASTE),
  COMBO(cut_combo, S_CUT)
};


// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ K E Y M A P S                                                                                                          │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT(
    // <deflayer>
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    CKC_A,   CKC_S,   CKC_D,   CKC_F,   KC_G,    KC_H,    CKC_J,   CKC_K,   CKC_L,   KC_SCLN,
    SW_INST, KC_Z,    KC_X,    MEH_C,   HYP_V,   KC_B,    KC_N,    HYP_M,   MEH_COM, KC_DOT, KC_QUOT, KC_TAB,
                      UTIL,    NAV,     SYM,  KC_ENT,  CKC_BSPC,     FUN
    // </deflayer>
  ),

  [_NAV] = LAYOUT(
    // <deflayer nav>

    _______, UNDO,    REDO,    _______, _______, _______, KC_HOME, CKC_UP,   KC_END,  KC_PGUP,
  _______, _______,  _______,  _______, _______, KC_CAPS, CKC_LEFT, CKC_DOWN, CKC_RIGHT,KC_PGDN,
    BACK,    _______, _______, KC_MEH,  KC_HYPR, _______, _______, KC_TILD, _______, KC_SLSH, _______, FWD,
                      _______, _______, _______, KC_ENT,  KC_BSPC, KC_DEL
    // </deflayer>
  ),

  [_NUM] = LAYOUT(
    // <deflayer num>

            KC_PLUS, KC_1,    KC_2,    KC_3,    KC_ASTR, _______, _______, _______, _______, _______,
            KC_DOT,    KC_4,    KC_5,    KC_6,    KC_EQL,  _______, _______, _______,  _______,  _______,
    KC_LPRN, KC_MINS, KC_7,    KC_8,    KC_9,    KC_SLSH, _______, KC_HYPR, KC_MEH,  _______, _______, KC_RPRN,
                      _______, KC_0,  KC_SCLN, _______, _______, _______
    // </deflayer>
  ),



   [_SYM] = LAYOUT(
    // <deflayer sym>

              KC_EXLM,  KC_QUOT,  KC_ASTR,  KC_PLUS,   KC_MINS,  KC_AT,  KC_LBRC,  KC_RBRC,  KC_PIPE,   KC_CIRC,
              _______,  _______,  _______,  _______,   KC_HASH,  KC_DLR,  KC_LPRN,  KC_RPRN,  KC_AMPR,   KC_PERC,
    _______,  _______,  _______,  _______,  _______,   KC_LABK,  KC_RABK,  KC_LCBR,  KC_RCBR,  KC_BSLS,   KC_SLSH, _______,
                                  _______,  _______,   _______,  _______,  _______,  _______
                // </deflayer>
 ),

  [_FUN] = LAYOUT(
    // <deflayer fun>

    KC_F12,  KC_F7,   KC_F8,   KC_F9,   _______, _______, _______, _______, _______, _______,
    KC_F11,  KC_F4,   KC_F5,   KC_F6,   _______, _______, _______, _______,  _______,  _______,
    KC_PSCR, KC_F10,  KC_F1,   KC_F2,   KC_F3,   _______, _______, KC_HYPR, KC_MEH,  DM_REC1, DM_RSTP, DM_PLY1,
                      _______, _______, _______, _______, _______, _______
    // </deflayer>
  ),

  [_UTIL] = LAYOUT(
    // <deflayer util>

    QK_BOOT, DB_TOGG, _______, _______, _______, _______, _______, W_UP, _______, _______,
    _______, _______, _______, _______, _______, _______, W_LEFT, W_DOWN, W_RIGHT, _______,
    _______, OS_SWAP, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MCTL,
                      _______, _______, _______, _______, _______, _______
    // </deflayer>
  )
};


// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ M A C R O S                                                                                                            │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀.

static uint16_t get_arrow_keycode(uint16_t keycode) {
    switch (keycode) {
        case W_LEFT:
            return KC_LEFT;
        case W_RIGHT:
            return KC_RIGHT;
        case W_UP:
            return KC_UP;
        case W_DOWN:
            return KC_DOWN;
        default:
            return KC_NO;
    }
}

bool process_on_change_window(uint16_t keycode) {
  uint16_t base_keycode = get_arrow_keycode(keycode);
  tap_code16(IS_MAC ? MEH(base_keycode) : LCS(base_keycode));
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_smtd(keycode, record)) {
        return false;
    }

    switch (keycode) {
        case OS_SWAP:
            if (record->event.pressed) {
                keymap_config.swap_lctl_lgui = !keymap_config.swap_lctl_lgui;

                eeconfig_update_keymap(&keymap_config);

                clear_keyboard();

                return false;
            }
        break;
    }
// ┌─────────────────────────────────────────────────┐
// │ p r o d u c t i v i t y                         │
// └─────────────────────────────────────────────────┘


  printf("Keycode pressed \n");
  printf("%d\n", keycode);
  printf("\n");
if (keycode >= W_LEFT && keycode <= W_DOWN) {
    printf("User pressed change window");
    process_on_change_window(keycode);
  }

    return true;
}

/*
  ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸


                                                          ██████
                                                            ██  ▄▄▄▄
                                                            ██ ██▀▀██
                                                            ▀▀ ██▄▄██
                                                        ██████  ▀▀▀▀
                                                          ██ ▄▄▄▄▄▄
                                                          ██ ██▀▀▀▀
                                                          ██ ██████
                                                             ██▄▄▄▄
                                                             ▀▀▀▀▀▀
                                                           ████████
                                                           ██ ██ ██
                                                           ██ ██ ██
                                                           ▀▀ ▀▀ ▀▀
                                                          ████████

*/

void on_smart_arrows(uint16_t keycode, smtd_action action, uint8_t tap_count) {
  uint16_t base_keycode = KC_NO;
  switch (keycode) {
  case CKC_LEFT:
    base_keycode = KC_LEFT;
    break;
  case CKC_RIGHT:
    base_keycode = KC_RIGHT;
    break;
  case CKC_UP:
    base_keycode = KC_UP;
    break;
  case CKC_DOWN:
    base_keycode = KC_DOWN;
    break;
  }

  switch (action) {
  case SMTD_ACTION_TOUCH:
    switch (tap_count) {
    case 0:
      tap_code16(base_keycode);
      break;
    case 1:
    case 2:
      tap_code16(IS_MAC ? LALT(base_keycode) : LCTL(base_keycode));
      break;
    default:
      tap_code16(base_keycode);
      break;
    }
    break;
  case SMTD_ACTION_HOLD:
    if (IS_MAC) {
      tap_code16(G(base_keycode));
    } else {
      switch (keycode) {
      case CKC_LEFT:
        tap_code16(KC_HOME);
        break;
      case CKC_RIGHT:
        tap_code16(KC_END);
        break;
      case CKC_UP:
        tap_code16(G(KC_HOME));
        break;
      case CKC_DOWN:
        tap_code16(G(KC_END));
        break;
      }
    }
    break;
  case SMTD_ACTION_RELEASE:
    break;
  case SMTD_ACTION_TAP:
    break;
  }
}

void on_smart_backspace(smtd_action action, uint8_t tap_count) {
  switch (action) {
  case SMTD_ACTION_TAP:
    break;

  case SMTD_ACTION_TOUCH:
    switch (tap_count) {
    case 0:
      tap_code16(KC_BSPC);
      break;
    case 1:
    case 2:
      tap_code16(IS_MAC ? LALT(KC_BSPC) : LCTL(KC_BSPC));
      break;
    default:
      tap_code16(KC_BSPC);
      break;
    }
    break;

  case SMTD_ACTION_HOLD:
    if (tap_count <= 1) {
      layer_move(_NUM);
    } else {
      tap_code16(LGUI(KC_BSPC));
    }
    break;

  case SMTD_ACTION_RELEASE:
    layer_move(0);
    break;
  }
}

void on_smtd_action(uint16_t keycode, smtd_action action, uint8_t tap_count) {
  switch (keycode) {
    SMTD_MT(CKC_A, KC_A, KC_LEFT_GUI)
    SMTD_MT(CKC_S, KC_S, KC_LEFT_ALT)
    SMTD_MT(CKC_D, KC_D, KC_LEFT_CTRL)
    SMTD_MT(CKC_F, KC_F, KC_LSFT)
    SMTD_MT(CKC_J, KC_J, KC_RIGHT_SHIFT)
    SMTD_MT(CKC_K, KC_K, KC_RIGHT_CTRL)
    SMTD_MT(CKC_L, KC_L, KC_RIGHT_ALT)
    SMTD_MT(CKC_SCLN, KC_SCLN, KC_RIGHT_GUI)
  case CKC_BSPC:
    on_smart_backspace(action, tap_count);
    break;
  }
  if (keycode >= CKC_RIGHT && keycode <= CKC_UP) {
    on_smart_arrows(keycode, action, tap_count);
  }
}

/*
<hardware-layout>

!!! Keycap layout and colors
----------------------------

(keycap
  num         _                 sym
  _               defsrc            _
  nav             _                 func
  util           _                 media
)

(colors
  #3498DB   #000000   #D68910
  #000000   #000000   #000000
  #7D3C98   #0000ff   #ff0000
  #239B56   #000000   #5D6D7E
)

!!! Options are based on row column and kle syntax
-------------------------------------------------------
!!! (options row col data)


!!! Override or assign labels
-----------------------------
!!! (label code text)

(label A_GUI A)
(label R_ALT R)
(label S_CTL S)
(label T_SFT T)

(label O_GUI O)
(label I_ALT I)
(label E_CTL E)
(label N_SFT N)

(label L_NUM Num)
(label L_FUN Fn)
(label L_MED Media)
(label L_MOU 🖱)
(label L_NAV Nav)
(label L_SYM Sym)

(label U_REDO ↷)
(label U_UNDO ↶)
(label XKC_N ñ)
(label U_CPY copy)
(label U_PST paste)
(label U_CUT cut)
(label OS_LSFT ⇮)
(label OS_RSFT ⇮)
(label BTN1 LB)
(label BTN2 RB)
(label BTN3 MB)

!!! Add some notes
------------------

</hardware-layout>
*/
