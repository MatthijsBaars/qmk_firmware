/* Copyright 2023 Brian Low
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
#include QMK_KEYBOARD_H

#define _BASE 0
#define _SYMBOL 1
#define _NUMPAD 2

// Left-hand home row mods
#define GUI_A LGUI_T(KC_A)
#define ALT_R LALT_T(KC_R)
#define SFT_S LSFT_T(KC_S)
#define CTR_T LCTL_T(KC_T)

// Right-hand home row mods
#define CTR_N RCTL_T(KC_N)
#define SFT_E RSFT_T(KC_E)
#define ALT_I LALT_T(KC_I)
#define GUI_O RGUI_T(KC_O)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* COLMAK-DH
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  =   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |   ;  |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   R  |   S  |   T  |   G  |-------.    ,-------|   M  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|  Mute |    | Pause |------+------+------+------+------+------|
 * |  `   |   Z  |   X  |   C  |   D  |   V  |-------|    |-------|   K  |   H  |   ,  |   .  |   /  |LAYNUM|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LEFT | RIGHT| DELE | /Bspc   /       \Space \  | Enter|  UP  | DOWN |LAYSYM|
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

    [_BASE] = LAYOUT(
        KC_EQL,  KC_1,    KC_2,   KC_3,   KC_4,   KC_5,                       KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_PMNS,
        KC_ESC,  KC_Q,    KC_W,   KC_F,   KC_P,   KC_B,                       KC_J,   KC_L,   KC_U,   KC_Y,   KC_SCLN,KC_BSLS,
        KC_TAB,  GUI_A,   ALT_R,  SFT_S,  CTR_T,  KC_G,                       KC_M,   CTR_N,  SFT_E,  ALT_I,  GUI_O,  KC_QUOT,
        KC_GRV,  KC_Z,    KC_X,   KC_C,   KC_D,   KC_V,   KC_MUTE,   KC_MPLY, KC_K,   KC_H,   KC_COMM,KC_DOT, KC_SLSH,TG(_NUMPAD),
                 KC_LGUI, KC_LEFT,KC_RGHT,KC_DEL, KC_BSPC,                    KC_SPC, KC_ENT, KC_UP,  KC_DOWN,MO(_SYMBOL)
    ),

/* SYMBOL
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | trans|  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | trans|   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   |  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | trans|  =   |  -   |  +   |   {  |   }  |-------|    |-------|   [  |   ]  |   ;  |   :  |   \  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LEFT | RIGHT| DELE | /Bspc   /       \Space \  | Enter|  UP  | DOWN |LAYBAS|
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
  */
    [_SYMBOL] =  LAYOUT(
    //,------------------------------------------------.                    ,---------------------------------------------------.
    _______,  KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
    //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
    KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_F12,
    //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
    _______,  KC_EXLM,KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,KC_PIPE,
    //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
    _______,  KC_EQL,  KC_PMNS,KC_PPLS, KC_LCBR, KC_RCBR,_______,   _______,KC_LBRC,KC_RBRC,  KC_SCLN, KC_COLN, KC_BSLS,KC_LSFT,
    //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
                    _______, _______, _______, _______, _______,     _______, _______, _______, _______, TG(_BASE)
    //             \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
    ),

/* NUMPAD
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | trans|      |      |      |      |      |                    |      |NumLck|      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |   ^  |   7  |   8  |   9  |   *  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | trans|      |      |      |      |      |-------.    ,-------|   -  |   4  |   5  |   6  |      |   |  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | trans|      |      |      |      |      |-------|    |-------|   +  |   1  |   2  |   3  |   \  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LEFT | RIGHT| DELE | /Bspc   /       \Space \  | Enter|  0   |  .   |LAYBAS|
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
    [_NUMPAD] = LAYOUT(
    //,------------------------------------------------.                    ,---------------------------------------------------.
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   _______, KC_NUM, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_CIRC, KC_P7,  KC_P8,   KC_P9,   KC_ASTR, XXXXXXX,
    //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_MINS, KC_P4,  KC_P5,   KC_P6,   KC_EQL,  KC_PIPE,
    //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,_______,   _______,KC_PLUS, KC_P1,  KC_P2,   KC_P3,   KC_SLSH, KC_LSFT,
    //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
                     _______, _______, _______, _______, _______,   _______, _______,  KC_P0,   KC_PDOT, TG(_BASE)
    //             \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[ ][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] =   { ENCODER_CCW_CW(KC_VOLU, KC_VOLD), ENCODER_CCW_CW(KC_PGUP, KC_PGDN)  },
    [1] =   { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(KC_WH_D, KC_WH_U)  },
    [2] =   { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)  }
};
#endif
