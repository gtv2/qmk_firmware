#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _NUMPAD 3
#define _UTIL 4
#define _ADJUST 5

#define CTLDEL LCTL_T(KC_DEL)

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  NUMPAD,
  UTIL,
  ADJUST,
};

/* TAP DANCE declarations*/

typedef struct {
    bool is_press_action;
    uint8_t state;
} tap;

// Define a type for as many tap dance states as you need
enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP
};

// Custom tap dance keys
enum {
   TD_SHIFT_CAPS,
   TD_ESC_GRAVE,
   TD_COLN_SCLN,
   TD_QUOT_DQT,
   TD_MINUS_PLUS,
   QUOT_LAYR_L,
   QUOT_LAYR_R
   //CT_FLSH,
};

//Aliases for TAP DANCE
#define TD_SFTCAP TD(TD_SHIFT_CAPS)
#define TD_ESCGR TD(TD_ESC_GRAVE)
#define TD_SCLN TD(TD_COLN_SCLN)
#define TD_SDQT TD(TD_QUOT_DQT)
#define TD_MP TD(TD_MINUS_PLUS)
#define TD_QL TD(QUOT_LAYR_L)
#define TD_QR TD(QUOT_LAYR_R)
//#define TD_RESET TD(CT_FLSH)

// Declare the functions to be used with your tap dance key(s)

// Function associated with all tap dances
uint8_t cur_dance(qk_tap_dance_state_t *state);

// Functions associated with individual tap dances
void ql_finished(qk_tap_dance_state_t *state, void *user_data);
void ql_reset(qk_tap_dance_state_t *state, void *user_data);
void qr_finished(qk_tap_dance_state_t *state, void *user_data);
void qr_reset(qk_tap_dance_state_t *state, void *user_data);

/* end of TAP DANCE declarations*/


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     TD_ESCGR, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    TD_MP,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
    TD_SFTCAP, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    TD_SCLN, TD_SDQT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     CTLDEL  , KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_SPC,           KC_MUTE, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                     KC_LALT, KC_RGUI, KC_SPC,                   KC_BSPC,  TD_QL,   TD_QR
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_LOWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
      KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      XXXXXXX, KC_HOME, KC_UP,   KC_END,  KC_HOME, KC_PGUP,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  KC_PGDN,                            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                     _______, _______, XXXXXXX,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_RAISE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LABK, KC_RABK,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      XXXXXXX, KC_HOME, KC_UP,   KC_END,  KC_LPRN, KC_RPRN,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_LBRC, KC_RBRC,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR, _______,          _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                     _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_NUMPAD] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LABK, KC_RABK,                            XXXXXXX, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      XXXXXXX, KC_HOME, KC_UP,   KC_END,  KC_LPRN, KC_RPRN,                            XXXXXXX, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_LBRC, KC_RBRC,                            XXXXXXX, KC_P4,   KC_P5,   KC_P6,   KC_PCMM, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR, _______,          _______, KC_PDOT, KC_P3,   KC_P2,   KC_P1,   KC_PEQL, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                     _______, _______, _______,                   KC_P0, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

    [_UTIL] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
    RESET, LCA(KC_DEL), KC_SLEP, KC_PWR, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                           BL_STEP, RGB_M_P, RGB_M_B, RGB_M_K, RGB_M_SN, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          _______, XXXXXXX, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______,  _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
/*    case KC_1:
      if (record->event.pressed) {
        rgblight_sethsv_at(HSV_CYAN, 3);
      } else {
        rgblight_sethsv_at(HSV_WHITE, 3);
      }
      break;    */
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case NUMPAD:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_NUMPAD);
      }
      return false;
      break;
    case UTIL:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_UTIL);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  } 
  return true;
};

/* ENCODER */
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 1) { // Right encoder
        if (layer_state_cmp(layer_state, _LOWER)) {
            if (clockwise) { // Стрелки вверх-вниз
                tap_code(KC_DOWN);
            } else {
                tap_code(KC_UP);
            }
        } else if (layer_state_cmp(layer_state, _RAISE)) {
            if (clockwise) { // Громкость
                tap_code(KC_VOLD);
            } else {
                tap_code(KC_VOLU);
            }
        } else {
            if (clockwise) { // Стрелки влево-вправо
                tap_code(KC_LEFT);
            } else {
                tap_code(KC_RGHT);
            }
        }
    }
};


/* TAP DANCE */

// Shift vs. capslock function. From bbaserdem's Planck keymap.
void caps_tap (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code (KC_LSFT);
    } else if (state->count == 2) {
        unregister_code (KC_LSFT);
        register_code (KC_CAPS);
    }
};
void caps_tap_end (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code (KC_LSFT);
    } else {
        unregister_code (KC_CAPS);
    }
};

// ESC vs. grave function.
void esc_gr_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_ESC);
  } else if (state->count == 2) {
    register_code (KC_GRV);
  } else {
    register_code (KC_RSFT);
    register_code (KC_GRV);
  }
};
void esc_gr_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_ESC);
  } else if (state->count == 2) {
    unregister_code (KC_GRV);
  } else {
    unregister_code (KC_RSFT);
    unregister_code (KC_GRV);
  }
};

// ; vs. :
void dance_cln_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code(KC_SCLN);
    } else {
        register_code16(KC_COLN);
    }
}
void dance_cln_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code(KC_SCLN);
    } else {
        unregister_code16(KC_COLN);
    }
}

// ' vs. "
void dance_quo_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code(KC_QUOTE);
    } else {
        register_code16(KC_DOUBLE_QUOTE);
    }
}
void dance_quo_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code(KC_QUOTE);
    } else {
        unregister_code16(KC_DOUBLE_QUOTE);
    }
}

// - vs. =
void dance_mp_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code(KC_MINS);
    } else {
        register_code16(KC_EQUAL);
    }
}
void dance_mp_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code(KC_MINS);
    } else {
        unregister_code16(KC_EQUAL);
    }
}

/*
// On each tap, light up one LED, from right to left
// On the fourth tap, turn them off from right to left
void dance_flsh_each(qk_tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            rgblight_sethsv_at(HSV_RED, 6);
            break;
        case 2:
            rgblight_sethsv_at(HSV_RED, 7);
            break;
        case 3:
            rgblight_sethsv_at(HSV_RED, 8);
            break;     
        case 4:
            rgblight_sethsv_at(HSV_BLUE, 6);
            wait_ms(50);
            rgblight_sethsv_at(HSV_BLUE, 7);
            wait_ms(50);
            rgblight_sethsv_at(HSV_BLUE, 8);            
    }
};

// On the fourth tap, set the keyboard on flash state
void dance_flsh_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count >= 4) {
        reset_keyboard();
    }
};

// If the flash state didn't happen, then turn off LEDs, left to right
void dance_flsh_reset(qk_tap_dance_state_t *state, void *user_data) {
    rgblight_sethsv_at(HSV_BLUE, 8);
    wait_ms(100);
    rgblight_sethsv_at(HSV_BLUE, 7);
    wait_ms(100);
    rgblight_sethsv_at(HSV_BLUE, 6);
};
*/

// Determine the current tap dance state
uint8_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) return DOUBLE_TAP;
    else return 8;
}

// Initialize tap structure associated with example tap dance key
static tap ql_tap_state = {
    .is_press_action = true,
    .state = 0
};
static tap qr_tap_state = {
    .is_press_action = true,
    .state = 0
};
// Functions that control what our tap dance key does
void ql_finished(qk_tap_dance_state_t *state, void *user_data) {
    ql_tap_state.state = cur_dance(state);
    switch (ql_tap_state.state) {
        case SINGLE_TAP:
            // Check to see if the layer is already set
            if (layer_state_is(_LOWER)) {
                // If already set, then switch it off
                layer_off(_LOWER);
            } else {
                // If not already set, then switch the layer on
                layer_on(_LOWER);
            }
            break;
        case SINGLE_HOLD:
            layer_on(_LOWER);
            break;
        case DOUBLE_TAP:
            // Check to see if the layer is already set
            if (layer_state_is(_UTIL)) {
                // If already set, then switch it off
                layer_off(_UTIL);
            } else {
                // If not already set, then switch the layer on
                layer_on(_UTIL);
            }
            break;
    }
}
void ql_reset(qk_tap_dance_state_t *state, void *user_data) {
    // If the key was held down and now is released then switch off the layer
    if (ql_tap_state.state == SINGLE_HOLD) {
        layer_off(_LOWER);
    }
    ql_tap_state.state = 0;
}

void qr_finished(qk_tap_dance_state_t *state, void *user_data) {
    qr_tap_state.state = cur_dance(state);
    switch (qr_tap_state.state) {
        case SINGLE_TAP:
            // Check to see if the layer is already set
            if (layer_state_is(_RAISE)) {
                // If already set, then switch it off
                layer_off(_RAISE);
            } else {
                // If not already set, then switch the layer on
                layer_on(_RAISE);
            }
            break;
        case SINGLE_HOLD:
            layer_on(_RAISE);
            break;
        case DOUBLE_TAP:
            // Check to see if the layer is already set
            if (layer_state_is(_NUMPAD)) {
                // If already set, then switch it off
                layer_off(_NUMPAD);
            } else {
                // If not already set, then switch the layer on
                layer_on(_NUMPAD);
            }
            break;
    }
}
void qr_reset(qk_tap_dance_state_t *state, void *user_data) {
    // If the key was held down and now is released then switch off the layer
    if (qr_tap_state.state == SINGLE_HOLD) {
        layer_off(_RAISE);
    }
    qr_tap_state.state = 0;
}

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Shift, twice for Caps Lock
  [TD_SHIFT_CAPS] = ACTION_TAP_DANCE_FN_ADVANCED(caps_tap, NULL, caps_tap_end),
  //Tap once for ESC, twice for `, thrice for ~
  [TD_ESC_GRAVE] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, esc_gr_finished, esc_gr_reset),
  //Tap once for ; twice for :
  [TD_COLN_SCLN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, dance_cln_reset),
  //Tap once for ' twice for "
  [TD_QUOT_DQT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_quo_finished, dance_quo_reset),
  //Tap once for - twice for =
  [TD_MINUS_PLUS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_mp_finished, dance_mp_reset),
  //On each tap, light up one LED, from right to left. On the fourth tap, set the keyboard on flash state
  //[CT_FLSH] = ACTION_TAP_DANCE_FN_ADVANCED(dance_flsh_each, dance_flsh_finished, dance_flsh_reset),
  //Set up MO(_LOWER) on single-tap, as TG(_LOWER) on single-hold, and TG(_UTIL) on double-tap
  [QUOT_LAYR_L] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ql_finished, ql_reset),
  //Set up MO(_RAISE) on single-tap, as TG(_RAISE) on single-hold, and TG(_NUMPAD) on double-tap
  [QUOT_LAYR_R] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, qr_finished, qr_reset)
};

/* end of TAP DANCE */


/* Lighting Layers */

// Light LEDs 3 white when caps lock is active.
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {3, 1, HSV_WHITE}       // Light 1 LEDs, starting with LED 3
);
// Light all LEDs in cyan when keyboard layer 1 is active
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_CYAN}
);
// Light all LEDs in purple when keyboard layer 2 is active
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_PURPLE}
);

// Light all LEDs in purple when keyboard layer 3 is active
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {3, 1, HSV_BLUE}
);

// Light all LEDs in red when keyboard layer 4 is active
const rgblight_segment_t PROGMEM my_layer4_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {3, 1, HSV_RED}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_capslock_layer,
    my_layer1_layer,    // LOWER -> CYAN
    my_layer2_layer,    // RAISE -> PURPLE
    my_layer3_layer,    // NUMPAD -> BLUE
    my_layer4_layer     // UTIL -> RED
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    // Both layers will light up if both kb layers are active
    rgblight_set_layer_state(1, layer_state_cmp(state, 1));
    rgblight_set_layer_state(2, layer_state_cmp(state, 2));
    rgblight_set_layer_state(3, layer_state_cmp(state, 3));
    rgblight_set_layer_state(4, layer_state_cmp(state, 4));
    return state;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}

/* end of Lighting Layers */
