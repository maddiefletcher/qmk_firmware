/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "preonic.h"
#include "action_layer.h"

enum preonic_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _MOVE,
  _NUMPAD,
  _ADJUST
};

// Macro IDs
#define _BACKLIGHT 0

// Macro shortcuts
#define BACKLIGHT  M(_BACKLIGHT)

enum preonic_keycodes {
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


#ifdef AUDIO_ENABLE
  float tone_qwerty[][2]      = SONG(QWERTY_SOUND);
  float tone_numpad[][2]      = SONG(SONIC_RING);
  float tone_exit_numpad[][2] = SONG(ZELDA_PUZZLE);
  float tone_capslock_on[][2] = SONG(CAPS_LOCK_ON_SOUND);
  float tone_capslock_off[][2] = SONG(CAPS_LOCK_OFF_SOUND);
#endif


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  Tab |   q  |   w  |   e  |   r  |   t  |   y  |   u  |   i  |   o  |   p  | Bspc |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  Esc |   a  |   s  |   d  |   f  |   g  |   h  |   j  |   k  |   l  |   ;  |   '  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Shft |   z  |   x  |   c  |   v  |   b  |   n  |   m  |   ,  |   .  |   /  | qu/sh|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | MOVE | Ctrl |  Alt |  Cmd | Lower|    Space    | Raise| left | Down |  Up  | Right|
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {KC_MINS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL},
  {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {KC_GESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT},
  {SFT_CAP, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, F(0)},
  {MOVE,    KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  Esc |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |   \  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Shft |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   m  |   ,  |   .  |   '  | Shft |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Caps | Ctrl |  Alt |  Cmd | Lower|     Bspc    | Raise| Home | Pg dn| Pg up|  End |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {_______,     KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     _______},
  {KC_GRV,      KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     _______},
  {_______,     KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_MINS,  KC_EQL,   KC_LBRC,  KC_RBRC,  KC_BSLS},
  {_______,     KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,  _______,  _______,  KC_DQUO,  _______},
  {KC_CAPSLOCK, _______,  _______,  _______,  _______,  KC_BSPC,  KC_BSPC,  _______,  KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END}
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  Esc |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |   |  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Shft |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   m  |   ,  |   .  |   '  | Shft |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |BLight| Ctrl |  Alt |  Cmd | Lower|     bspc    | Raise| Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {_______,     KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,  KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  _______},
  {KC_TILD,     KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,  KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  _______},
  {_______,     KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_UNDS,  KC_PLUS,  KC_LCBR,  KC_RCBR,  KC_PIPE},
  {_______,     KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,  _______,  _______,  KC_QUOT,  _______},
  {BACKLIGHT,   _______,  _______,  _______,  _______,  KC_ENT,   KC_ENT,   _______,  KC_MNXT,  KC_VOLD,  KC_VOLU,  KC_MPLY}
},

/* Vim Movement
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
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
  {_______,     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______},
  {_______,     KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   _______,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  _______,  _______},
  {_______,     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______},
  {_______,     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______}
},

/* Numpad
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
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
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {KC_TAB,  XXXXXXX, XXXXXXX, KC_CIRC, KC_PSLS, KC_P7,   KC_P8,   KC_P9,   KC_PMNS, KC_EQL,  XXXXXXX, _______},
  {KC_ESC,  XXXXXXX, XXXXXXX, KC_PERC, KC_PAST, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_LPRN, KC_RPRN, KC_ENT},
  {KC_LSFT, XXXXXXX, XXXXXXX, KC_DLR,  KC_DEL,  KC_P1,   KC_P2,   KC_P3,   KC_PENT, KC_LBRC, KC_RBRC, KC_RSFT},
  {EXT_NUM, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX, KC_P0,   KC_P0,   KC_PDOT, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},

/* Adjust (Lower + Raise)
 * ,-------------------------------------------------------------------------------------------.
 * |  F1  |  F2   |   F3   |  F4  |  F5  |    F6    |  F7  |  F8  |  F9  |  F10 |  F11  |  F12 |
 * |------+-------+--------+------+------+----------+------+------+------+------+-------+------|
 * |1pass | Qwerty|        |      | Reset|Sourcetree|      |      |iterm |      |Spotify| Del  |
 * |------+-------+--------+------+------+----------+------+------+------+------+-------+------|
 * |      |       | Safari | Dash |Finder|          |      |      |      |Slack |       |      |
 * |------+-------+--------+------+------+----------|------+------+------+------+-------+------|
 * |      |       |Chromium|Chrome|      |          |  Num | Mail |      |      |       |      |
 * |------+-------+--------+------+------+----------+------+------+------+------+-------+------|
 * | Caps |       |        |      |      |                 |      |      |      |       |      |
 * `-------------------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {       KC_F1,   KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,     KC_F10,     KC_F11,    KC_F12},
  {HYPR(KC_TAB),  QWERTY,    _______,    _______,      RESET, HYPR(KC_T),    _______,    _______, HYPR(KC_I),    _______, HYPR(KC_P),    _______},
  {     _______, _______, HYPR(KC_S), HYPR(KC_D), HYPR(KC_F),    _______,    _______,    _______,    _______, HYPR(KC_L),    _______,    _______},
  {     _______, _______, HYPR(KC_X), HYPR(KC_C),    _______,    _______,     NUMPAD, HYPR(KC_M),    _______,    _______,    _______,    _______},
  {     KC_CAPS, _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______}
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
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistant_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case NUMPAD:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_numpad);
        #endif
        layer_off(_RAISE);
        layer_off(_LOWER);
        layer_off(_ADJUST);
        layer_on(_NUMPAD);
      }
      return false;
      break;
    case EXT_NUM:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_exit_numpad);
        #endif
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
