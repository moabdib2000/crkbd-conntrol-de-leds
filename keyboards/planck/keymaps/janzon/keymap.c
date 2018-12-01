#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _RAISE 1
#define _LOWER 2

#define KC_SWLBRC LALT(KC_LBRC)
#define KC_SWQUOT LALT(KC_QUOT)
#define KC_SWSCLN LALT(KC_SCLN)
#define KC_MYCAPS MT(MOD_LCTL, KC_ESC)
#define KC_MYLOWER MT(LOWER, KC_ENT)
#define KC_MYSFT MT(MOD_LSFT, KC_BSPC)
#define KC_MYZERO MT(MOD_RCTL, KC_0)
#define SE_SLASH S(KC_7)
#define SE_AT RALT(KC_2)
#define SE_AMPR S(KC_6)
#define SE_LPRN S(KC_8)
#define SE_RPRN S(KC_9)
#define SE_DQUO S(KC_2)
#define SE_DLR RALT(KC_4)
#define SE_LCBR RALT(KC_7)
#define SE_RCBR RALT(KC_0)
#define SE_LBRC RALT(KC_8)
#define SE_RBRC RALT(KC_9)
#define SE_EQAL S(KC_0)
#define SE_GBP RALT(KC_3)
#define SE_TILD RALT(KC_RBRC)
#define SE_EURO RALT(KC_E)


enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  RAISE,
  LOWER,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,-----------------------------------------.   ,-----------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   |   Y  |   U  |   I  |   O  |   P  |  Å   |
 * |------+------+------+------+------+-------   |------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   |   H  |   J  |   K  |   L  |   Ö  |  Ä   |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * | Ctrl |   Z  |   X  |   C  |   V  |   B  |   |   N  |   M  |   ,  |   .  |   -  | Enter|
 * |------+------+------+------+------+------+   |------+------+------+------+------+------|
 * | Shift| Shift| Shift| LAlt | Raise| Shift|   | Space|Ent/lw| GUI | Shift| Shift| Shift|
 * `-----------------------------------------'   `-----------------------------------------'
 *  alt acts as enter when tapped
 *  middle shift acts as backspace when tapped
 *  , . / becomes < > ? when shift is pressed, as usual
 */

[_QWERTY] = LAYOUT_ortho_4x12(
    KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,      KC_T,        KC_Y,      KC_U,    KC_I,    KC_O,     KC_P, KC_LBRC, \
      KC_ESC,    KC_A,    KC_S,    KC_D,    KC_F,      KC_G,        KC_H,      KC_J,    KC_K,    KC_L,  KC_SCLN,  KC_QUOT, \
     KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,      KC_B,        KC_N,      KC_M, KC_COMM,  KC_DOT,  KC_SLSH,  KC_ENT, \
      SH_MON, KC_RSFT, KC_RSFT, KC_LALT,   RAISE,  KC_MYSFT,      KC_SPC,  KC_MYLOWER, KC_LGUI, KC_RSFT,  KC_RSFT,  KC_RSFT  \
),

/* Raise
 * ,-----------------------------------------.   ,-----------------------------------------.
 * |   €  |   !  |   @  |   {  |   }  |   ´  |   |   %  |   7  |   8  |   9  |   +  |   ?  |
 * |------+------+------+------+------+-------   |------+------+------+------+------+------|
 * |   $  |   '  |   "  |   (  |   )  |   `  |   |   >  |   4  |   5  |   6  |   *  |   =  |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * |   £  |   #  |   ^  |   [  |   ]  |   &  |   |   <  |   1  |   2  |   3  |   /  |   \  |
 * |------+------+------+------+------+------+   |------+------+------+------+------+------|
 * | RESET| Game |      |   §  |      | Del  |   |   ½  |   ~  |   0  |      |      |      |
 * `-----------------------------------------'   `-----------------------------------------'
 */

[_RAISE] = LAYOUT_ortho_4x12( \
    SE_EURO,  KC_EXLM, SE_AT,  SE_LCBR, SE_RCBR, KC_EQL,  KC_PERC,    KC_7,    KC_8,     KC_9, KC_MINS,  S(KC_MINS), \
    SE_DLR,   KC_BSLS, SE_DQUO, SE_LPRN, SE_RPRN, KC_PLUS, S(KC_NUBS), KC_4,    KC_5,     KC_6, KC_PIPE,  SE_EQAL, \
    SE_GBP,  KC_HASH, KC_RCBR, SE_LBRC, SE_RBRC, SE_AMPR, KC_NUBS,    KC_1,    KC_2,     KC_3, SE_SLASH, RALT(KC_MINS), \
    RESET,  _______, _______,KC_GRAVE, _______, KC_DEL,  KC_TILD,   SE_TILD, KC_0, _______, _______, _______  \
),

/* Lower
 * ,-----------------------------------------.   ,-----------------------------------------.
 * |      |      |      |      |      |      |   |      |      |      |      |      |      |
 * |------+------+------+------+------+-------   |------+------+------+------+------+------|
 * |      |      |      |      |      |      |   | left | down |  up  | down |      |      |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * |      |      |      |      |      |      |   |      |      |      |      |      |      |
 * |------+------+------+------+------+------+   |------+------+------+------+------+------|
 * |      |      |      |      |      |      |   |      |      |      |      |      |      |
 * `-----------------------------------------'   `-----------------------------------------'
 */

[_LOWER] = LAYOUT_ortho_4x12( 
    _______, _______, _______, _______, _______, _______,    	     _______,  _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,    		 KC_LEFT,  KC_DOWN,   KC_UP, KC_RIGHT, _______, _______, \
    _______, _______, _______, _______, _______, _______, 			 _______,  _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, 			 _______,  _______, _______, _______, _______, _______ \
),

};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  switch (keycode) {
  

    // The following two cases handle layer switching
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
      } else {
        layer_off(_RAISE);
      }
      return false;
      break;
	case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
      } else {
        layer_off(_LOWER);
      }
      return false;
      break;
  }
  return true;
}
