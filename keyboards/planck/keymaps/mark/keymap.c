// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.

#include "planck.h"
#include "action_layer.h"
#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif
#ifdef BACKLIGHT_ENABLE
  #include "backlight.h"
#endif
//#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _MOVE 3
#define _NUMPAD 4
#define _ADJUST 16

// Macro IDs
#define _BACKLIGHT 0
#define _ITERM 1
#define _CHROME 2
#define _CHROMIUM 3
#define _SAFARI 4
#define _DASH 5
#define _SLACK 6
#define _SPOTIFY 7
#define _SOURCETREE 8
#define _MAIL 9
#define _ONEPASS 10
#define _FINDER 11

// Macro shortcuts
#define BACKLIGHT  M(_BACKLIGHT)
#define ITERM      M(_ITERM)
#define CHROME     M(_CHROME)
#define CHROMIUM   M(_CHROMIUM)
#define SAFARI     M(_SAFARI)
#define DASH       M(_DASH)
#define SLACK      M(_SLACK)
#define SPOTIFY    M(_SPOTIFY)
#define SOURCETREE M(_SOURCETREE)
#define MAIL       M(_MAIL)
#define ONEPASS    M(_ONEPASS)
#define FINDER     M(_FINDER)

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  NUMPAD,
  MOVE,
  LOWER,
  RAISE,
  BACKLIT,
  EXT_NUM
};

#define SFT_CAP TD(0)	// Left shift, double tap for caps

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* QWERTY layer
 *
 * ,-----------------------------------------------------------------------------------.
 * |  Tab |   q  |   w  |   e  |   r  |   t  |   y  |   u  |   i  |   o  |   p  | Bspc |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  Esc |   a  |   s  |   d  |   f  |   g  |   h  |   j  |   k  |   l  |   ;  |   '  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Shft |   z  |   x  |   c  |   v  |   b  |   n  |   m  |   ,  |   .  |   /  | En/sh|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | Ctrl |  Alt |  Cmd | Lower|    Space    | Raise| left | Down |  Up  | Right|
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = { /* Qwerty */
  {KC_TAB,       KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC},
  {KC_ESC,       KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_ENT},
  {SFT_CAP,      KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  F(0)},
  {MOVE,         KC_LCTL,  KC_LALT,  KC_LGUI,  LOWER,    KC_SPC,   KC_SPC,   RAISE,    KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT}
},

/* Raised layer
 *
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  Esc |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |   \  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Shft |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   m  |   ,  |   .  |   '  | Shft |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Caps | Ctrl |  Alt |  Cmd | Lower|     Bspc    | Raise| Home | Pg dn| Pg up|  End |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = { /* RAISE */
  {KC_GRV,      KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_DEL},
  {_______,     KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_MINS,  KC_EQL,   KC_LBRC,  KC_RBRC,  KC_BSLS},
  {_______,     KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,  _______,  _______,  KC_DQUO,  _______},
  {KC_CAPSLOCK, _______,  _______,  _______,  _______,  KC_BSPC,  KC_BSPC,  _______,  KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END}
},

/* Lowered layer
 *
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  Esc |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |   |  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Shft |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   m  |   ,  |   .  |   '  | Shft |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |BLight| Ctrl |  Alt |  Cmd | Lower|     bspc    | Raise| Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = { /* LOWER */
  {KC_TILD,     KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,  KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_DEL},
  {_______,     KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_UNDS,  KC_PLUS,  KC_LCBR,  KC_RCBR,  KC_PIPE},
  {_______,     KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,  _______,  _______,  KC_QUOT,  _______},
  {BACKLIGHT,   _______,  _______,  _______,  _______,  KC_ENT,   KC_ENT,   _______,  KC_MNXT,  KC_VOLD,  KC_VOLU,  KC_MPLY}
},

/* Vim Movement
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      | Home | PgDn | PgUp |  End | Left | Down |  Up  | Right|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MOVE] = { /* Use vim keys for cursor movement */
  {_______,     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______},
  {_______,     KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   _______,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  _______,  _______},
  {_______,     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______},
  {_______,     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______}
},

/* Numpad
 * ,-----------------------------------------------------------------------------------.
 * |  Tab |      |      |   ^  |   /  |   7  |  8   |   9  |  -   |   =  |      | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  Esc |      |      |   %  |   *  |   4  |  5   |   6  |  +   |   (  |   )  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shft |      |      |   $  |  Del |   1  |  2   |   3  |Enter |   [  |   ]  | Shft |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Exit | Ctrl |  Alt |  Gui |      |      0      |   .  | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMPAD] = {
  {KC_TAB,  XXXXXXX, XXXXXXX, KC_CIRC, KC_PSLS, KC_P7,   KC_P8,   KC_P9,   KC_PMNS, KC_EQL, XXXXXXX, KC_BSPC},
  {KC_ESC,  XXXXXXX, XXXXXXX, KC_PERC, KC_PAST, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_LPRN, KC_RPRN, KC_ENT},
  {KC_LSFT, XXXXXXX, XXXXXXX, KC_DLR,  KC_DEL,  KC_P1,   KC_P2,   KC_P3,   KC_PENT, KC_LBRC, KC_RBRC, KC_RSFT},
  {EXT_NUM, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX, KC_P0,   KC_P0,   KC_PDOT, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      |Qwerty|      |      | Reset|      |      |      |      |      |      | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |  Num |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Caps |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {ONEPASS,  QWERTY, _______,  _______,   RESET, SOURCETREE, _______, _______,   ITERM, _______, SPOTIFY, KC_DEL },
  {_______, _______, SAFARI,   DASH,     FINDER, _______,    _______, _______, _______, SLACK,   _______, _______},
  {_______, _______, CHROMIUM, CHROME,  _______, _______,     NUMPAD,    MAIL, _______, _______, _______, _______},
  {KC_CAPS, _______, _______,  _______, _______, _______,    _______, _______, _______, _______, _______, _______}
}

};

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
	[0]  = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS)
};

const uint16_t PROGMEM fn_actions[] = {
  [0]  = ACTION_MODS_TAP_KEY(MOD_RSFT, KC_QUOT),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case _BACKLIGHT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
      } else {
        unregister_code(KC_RSFT);
      }
      break;
    case _ITERM:
      return MACRODOWN(D(LALT), T(SPC), U(LALT), W(100), T(I), T(T), T(E), T(R), T(M), T(ENT), END);
    case _CHROME:
      return MACRODOWN(D(LALT), T(SPC), U(LALT), W(100), T(C), T(H), T(R), T(O), T(M), T(E), T(ENT), END);
    case _CHROMIUM:
      return MACRODOWN(D(LALT), T(SPC), U(LALT), W(100), T(C), T(H), T(R), T(O), T(M), T(I), T(U), T(M), T(ENT), END);
    case _SAFARI:
      return MACRODOWN(D(LALT), T(SPC), U(LALT), W(100), T(S), T(A), T(F), T(A), T(R), T(I), T(ENT), END);
    case _DASH:
      return MACRODOWN(D(LALT), T(SPC), U(LALT), W(100), T(D), T(A), T(S), T(H), T(ENT), END);
    case _SLACK:
      return MACRODOWN(D(LALT), T(SPC), U(LALT), W(100), T(S), T(L), T(A), T(C), T(K), T(ENT), END);
    case _SPOTIFY:
      return MACRODOWN(D(LALT), T(SPC), U(LALT), W(100), T(S), T(P), T(O), T(T), T(I), T(F), T(Y), T(ENT), END);
    case _SOURCETREE:
      return MACRODOWN(D(LALT), T(SPC), U(LALT), W(100), T(S), T(O), T(U), T(R), T(C), T(E), T(T), T(R), T(E), T(E), T(ENT), END);
    case _MAIL:
      return MACRODOWN(D(LALT), T(SPC), U(LALT), W(100), T(M), T(A), T(I), T(L), T(ENT), END);
    case _ONEPASS:
      return MACRODOWN(D(LALT), T(SPC), U(LALT), W(100), T(1), T(P), T(A), T(S), T(S), T(W), T(O), T(R), T(D), T(ENT), END);
    case _FINDER:
      return MACRODOWN(D(LALT), T(SPC), U(LALT), W(100), T(F), T(I), T(N), T(D), T(E), T(R), T(ENT), END);
  };
  return MACRO_NONE;
};

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistant_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case NUMPAD:
      if (record->event.pressed) {
        layer_off(_RAISE);
        layer_off(_LOWER);
        layer_off(_ADJUST);
        layer_on(_NUMPAD);
      }
      return false;
      break;
    case EXT_NUM:
      if (record->event.pressed) {
        layer_off(_NUMPAD);
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
    case MOVE:
      if (record->event.pressed) {
        layer_on(_MOVE);
      } else {
        layer_off(_MOVE);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
      } else {
        unregister_code(KC_RSFT);
      }
      return false;
      break;
  }
  return true;
}
