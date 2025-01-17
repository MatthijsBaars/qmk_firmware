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
        KC_EQL,  KC_1,    KC_2,   KC_3,   KC_4,   KC_5,                       KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,
        KC_ESC,  KC_Q,    KC_W,   KC_F,   KC_P,   KC_B,                       KC_J,   KC_L,   KC_U,   KC_Y,   KC_SCLN,KC_BSLS,
        KC_TAB,  GUI_A,   ALT_R,  SFT_S,  CTR_T,  KC_G,                       KC_M,   CTR_N,  SFT_E,  ALT_I,  GUI_O,  KC_QUOT,
        KC_GRV,  KC_Z,    KC_X,   KC_C,   KC_D,   KC_V,   KC_MUTE,   KC_MPLY, KC_K,   KC_H,   KC_COMM,KC_DOT, KC_SLSH,TG(_NUMPAD),
                 KC_LGUI, KC_LEFT,KC_RGHT,KC_BSPC,KC_DEL,                     KC_ENT, KC_SPC, KC_UP,  KC_DOWN,MO(_SYMBOL)
    ),

/* SYMBOL
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | `    |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | trans|   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | trans|   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   |  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | trans|  =   |  -   |  +   |   {  |   }  |-------|    |-------|   [  |   ]  |   ;  |   :  |   \  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | HOME | END  | DELE | /Bspc   /       \Space \  | Enter|  UP  | DOWN |LAYSYM|
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
  */
    [_SYMBOL] =  LAYOUT(
    //,------------------------------------------------.                    ,---------------------------------------------------.
    KC_GRV,   KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
    //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
    _______,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_F12,
    //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
    _______,  KC_EXLM,KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,KC_PIPE,
    //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
    _______,  KC_EQL,  KC_PMNS,KC_PPLS, KC_LCBR, KC_RCBR,_______,   _______,KC_LBRC,KC_RBRC,  KC_SCLN, KC_COLN, KC_BSLS,XXXXXXX,
    //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
                    _______, KC_HOME,  KC_END, _______,  _______,   _______,  _______,  KC_PGUP,  KC_PGDN, _______
    //             \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
    ),

/* NUMPAD
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |NumLck|      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | trans|      |      |      |      |      |                    |   ^  |   7  |   8  |   9  |   *  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|   -  |   4  |   5  |   6  |      |   |  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|   +  |   1  |   2  |   3  |   \  |LAYBAS|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LEFT | RIGHT| DELE | /Bspc   /       \Space \  | Enter|  0   |  .   |LAYSYM|
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
    [_NUMPAD] = LAYOUT(
    //,------------------------------------------------.                    ,---------------------------------------------------.
    XXXXXXX, XXXXXXX, RGB_TOG, RGB_MOD, RGB_M_P, XXXXXXX,                   XXXXXXX, KC_NUM, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
    _______, XXXXXXX, RGB_VAD, RGB_VAI, XXXXXXX, XXXXXXX,                   KC_CIRC, KC_P7,  KC_P8,   KC_P9,   KC_ASTR, XXXXXXX,
    //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
    XXXXXXX, XXXXXXX, RGB_HUD, RGB_HUI, XXXXXXX, XXXXXXX,                   KC_MINS, KC_P4,  KC_P5,   KC_P6,   KC_EQL,  KC_PIPE,
    //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
    XXXXXXX, XXXXXXX, RGB_SAD, RGB_SAI, XXXXXXX, XXXXXXX,_______,   _______,KC_PLUS, KC_P1,  KC_P2,   KC_P3,   KC_SLSH, TG(_NUMPAD),
    //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
                     _______, _______, _______, _______, _______,   _______, _______,  KC_P0,   KC_PDOT, _______
    //             \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
    )
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[ ][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] =   { ENCODER_CCW_CW(KC_VOLU, KC_VOLD), ENCODER_CCW_CW(KC_PGDN, KC_PGUP)  },
    [1] =   { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(KC_WH_D, KC_WH_U)  },
    [2] =   { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(KC_WH_D, KC_WH_U)  }
};
#endif

#ifdef OLED_ENABLE
// static void render_logo(void) {
//     static const char PROGMEM qmk_logo[] = {
//         0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
//         0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
//         0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
//     };

//     oled_write_P(qmk_logo, false);
// }

static void print_status_narrow(void) {
    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _SYMBOL:
            oled_write_P(PSTR("SYM"), false);
            break;
        case _NUMPAD:
            oled_write_P(PSTR("NUM\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return OLED_ROTATION_270;
    //return rotation;
}

static void print_wpm(void) {
    static char wpm_str[4];
    sprintf(wpm_str, "%03d", get_current_wpm());
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("WPM"), false);
    oled_write(wpm_str, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        print_wpm();
        //render_logo();
    }
    return false;
}

#endif
