/*
This layout was created by Jeremy Cowgar (@jcowgar) who is a programmer by trade
that suffers from the beginning stages of RSI. As a programmer, letters, symbols
and cursor navigation are most often used. To prevent strange finger gymnastics,
this layout places the most common non-letter characters (found in JavaScript code)
in the easiest to reach locations. This layout makes heavy use of momentary layer
toggling to achieve this.

The letter layout is in the QWERTY standard, but the author uses a software based map on
OS X to achieve Colemak. THis was done because the laptop keyboard is still used from time
to time.

The 5 layers can be viewed graphically:

1. Letters - http://www.keyboard-layout-editor.com/#/gists/cbed8979bba2df4419c738903a623546
2. Symbols - http://www.keyboard-layout-editor.com/#/gists/8956a18b508a78e93b9c38ec3fcccaa5
3. Navigation - http://www.keyboard-layout-editor.com/#/gists/6ed492b714a7f54eb1c5de09b87fd8c4
4. Numbers - http://www.keyboard-layout-editor.com/#/gists/399ceb5624e8388e48a3a5eacac8e973
5. Function Keys - http://www.keyboard-layout-editor.com/#/gists/7fd7dc24c7048316f3724b1893c64e89
*/

#include "keymap_common.h"

// Reduce the time to decision of a tap or hold
#define TAPPING_TERM 300

// Each layer gets a name for readability, which is then used in the keymap matrix below.
#define BOOT  0 // Bootloader (not to be confused with default layer)
#define ALPH  0 // Alphabet Layer
#define NUMS  1 // Number Layer
#define FKEY  2 // Function Key Layer
#define CURS  3 // Cursor Layer
#define SYMB  4 // Symbol Layer
#define ALBS  5 // ALT or Backspace
#define CTDL  6 // Control or Delete
#define SFSP  7 // Left Shift or Space
#define SFET  8 // Right Shift or Enter
#define SUTB  9 // Control or Tab
#define CTES 10 // Control or Escape

#define FN_BOOT (KC_FN0 + BOOT)
#define FN_NUMS (KC_FN0 + NUMS)
#define FN_FKEY (KC_FN0 + FKEY)
#define FN_CURS (KC_FN0 + CURS)
#define FN_SYMB (KC_FN0 + SYMB)
#define FN_ALBS (KC_FN0 + ALBS)
#define FN_CTDL (KC_FN0 + CTDL)
#define FN_SFSP (KC_FN0 + SFSP)
#define FN_SFET (KC_FN0 + SFET)
#define FN_SUTB (KC_FN0 + SUTB)
#define FN_CTES (KC_FN0 + CTES)

// Some handy macros to keep the keymaps clean and easier to maintain
#define KM_SAVE ACTION_MODS_KEY(MOD_LCTL, KC_S)
#define KM_CLSE ACTION_MODS_KEY(MOD_LCTL, KC_W)
#define KM_OPEN ACTION_MODS_KEY(MOD_LCTL, KC_O)
#define KM_COPY ACTION_MODS_KEY(MOD_LCTL, KC_C)
#define KM_CUT  ACTION_MODS_KEY(MOD_LCTL, KC_X)
#define KM_PAST ACTION_MODS_KEY(MOD_LCTL, KC_V)
#define KM_UNDO ACTION_MODS_KEY(MOD_LCTL, KC_Z)
#define KM_REDO ACTION_MODS_KEY(MOD_LCTL | MOD_LSFT, KC_Z)

// Helpers for my symbol layer
#define KC_EXLM ACTION_MODS_KEY(MOD_LSFT, KC_1)
#define KC_AT   ACTION_MODS_KEY(MOD_LSFT, KC_2)
#define KC_HASH ACTION_MODS_KEY(MOD_LSFT, KC_3)
#define KC_DLR  ACTION_MODS_KEY(MOD_LSFT, KC_4)
#define KC_PERC ACTION_MODS_KEY(MOD_LSFT, KC_5)
#define KC_CIRC ACTION_MODS_KEY(MOD_LSFT, KC_6)
#define KC_AMPR ACTION_MODS_KEY(MOD_LSFT, KC_7)
#define KC_ASTR ACTION_MODS_KEY(MOD_LSFT, KC_8)
#define KC_LPRN ACTION_MODS_KEY(MOD_LSFT, KC_9)
#define KC_RPRN ACTION_MODS_KEY(MOD_LSFT, KC_0)
#define KC_UNDS ACTION_MODS_KEY(MOD_LSFT, KC_MINUS)
#define KC_PLUS ACTION_MODS_KEY(MOD_LSFT, KC_EQL)
#define MY_COLN ACTION_MODS_KEY(MOD_LSFT, KC_SCLN)
#define KC_QUES ACTION_MODS_KEY(MOD_LSFT, KC_SLSH)
#define KC_TILD ACTION_MODS_KEY(MOD_LSFT, KC_GRV)
#define KC_PIPE ACTION_MODS_KEY(MOD_LSFT, KC_BSLS)
#define KC_LCBR ACTION_MODS_KEY(MOD_LSFT, KC_LBRC)
#define KC_RCBR ACTION_MODS_KEY(MOD_LSFT, KC_RBRC)
#define KC_DQT  ACTION_MODS_KEY(MOD_LSFT, KC_QUOT)
#define KC_LABK ACTION_MODS_KEY(MOD_LSFT, KC_COMM)
#define KC_RABK ACTION_MODS_KEY(MOD_LSFT, KC_DOT)
#define KC_ZIN  ACTION_MODS_KEY(MOD_LCTL, KC_PLUS)
#define KC_ZOUT ACTION_MODS_KEY(MOD_LCTL, KC_MINUS)
#define KC_NEXT ACTION_MODS_KEY(MOD_LCTL, KC_PGUP)
#define KC_PREV ACTION_MODS_KEY(MOD_LCTL, KC_PGDN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [ALPH] = KEYMAP( \
                  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, \
                  KC_A,    FN_NUMS, FN_FKEY, KC_F,    KC_G,                      KC_H,    KC_J,    FN_CURS, FN_SYMB, KC_SCLN, \
                  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, \
                  FN_SUTB, KC_LBRC, KC_LCBR, KC_LPRN, FN_SFSP, FN_CTES, FN_ALBS, FN_SFET, KC_RPRN, KC_RCBR, KC_RBRC, FN_CTDL \
                   ),
  [NUMS] = KEYMAP( \
                  KC_TRNS, KC_TRNS, KC_TRNS, KC_ASTR, KC_SLSH,                   KC_TRNS, KC_7,    KC_8,    KC_9,    KC_SLSH, \
                  KC_TRNS, KC_TRNS, KC_EQL,  KC_PLUS, KC_MINS,                   KC_LPRN, KC_4,    KC_5,    KC_6,    KC_ASTR, \
                  KC_TRNS, KC_TRNS, KC_DOT,  KC_COMM, KC_SCLN,                   KC_RPRN, KC_1,    KC_2,    KC_3,    KC_MINS, \
                  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_0,    KC_DOT,  KC_EQL,  KC_PLUS \
                   ),
  [FKEY] = KEYMAP( \
                  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_F9,   KC_F10,  KC_F11,  KC_F12, \
                  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_F5,   KC_F6,   KC_F7,   KC_F8, \
                  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4, \
                  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS \
                   ),
  [CURS] = KEYMAP( \
                  KC_HOME, KC_BSPC, KC_UP,   KC_DEL,  KC_PGUP,                   KC_TRNS, KM_SAVE, KC_TRNS, KM_OPEN, KC_ZIN, \
                  KC_END,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                   KM_UNDO, KC_LALT, KC_TRNS, KC_LGUI, KC_ZOUT, \
                  KC_NEXT, KC_VOLD, KC_MUTE, KC_VOLU, KC_MPLY,                   KM_REDO, KM_CLSE, KC_TRNS, KC_TRNS, KC_TRNS, \
                  KC_PREV, KC_TRNS, FN_BOOT, KC_GRV,  KC_TAB,  KM_COPY,  KM_CUT, KM_PAST, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS \
                   ),
  [SYMB] = KEYMAP ( \
                   KC_BSLS, KC_EXLM, KC_LABK, KC_RABK, MY_COLN,                   KC_UNDS,  KC_DLR,  KC_QUES, KC_TRNS, KC_PERC, \
                   KC_AT,   KC_AMPR, KC_LPRN, KC_RPRN, KC_SCLN,                   KC_COMM,  KC_DOT,  KC_QUOT, KC_TRNS, KC_TILD, \
                   KC_HASH, KC_PIPE, KC_LCBR, KC_RCBR, KC_SLSH,                   KC_MINUS, KC_GRV,  KC_DQT,  KC_TRNS, KC_CIRC, \
                   KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS \
                    )
};

const uint16_t PROGMEM fn_actions[] = {
  [BOOT] = ACTION_FUNCTION(BOOTLOADER),
  [NUMS] = ACTION_LAYER_TAP_KEY(NUMS, KC_S),
  [FKEY] = ACTION_LAYER_TAP_KEY(FKEY, KC_D),
  [CURS] = ACTION_LAYER_TAP_KEY(CURS, KC_K),
  [SYMB] = ACTION_LAYER_TAP_KEY(SYMB, KC_L),
  [ALBS] = ACTION_MODS_TAP_KEY(MOD_LALT, KC_BSPC),
  [CTDL] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_DEL),
  [SFSP] = ACTION_MODS_TAP_KEY(MOD_LSFT, KC_SPC),
  [SFET] = ACTION_MODS_TAP_KEY(MOD_RSFT, KC_ENT),
  [SUTB] = ACTION_MODS_TAP_KEY(MOD_LGUI, KC_TAB),
  [CTES] = ACTION_MODS_TAP_KEY(MOD_RCTL, KC_ESC)
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  if (id == BOOTLOADER) {
    bootloader();
  }
}
