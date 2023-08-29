// Copyright 2022 Matthew Dews (@matthew-dews)
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H
#include "6x7_track.h"
enum custom_layer {
    _QWERTY,
    _LOWER,
    _RAISE,
};

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_6x7(
        KC_ESC , KC_F1   , KC_F2  , KC_F3 , KC_F4 , KC_F5 , KC_F6 ,                         KC_F7 , KC_F8  , KC_F9  , KC_F10, KC_F11, KC_F12   , _______,
        DRGSCRL, KC_GRV  , KC_1   , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7   , KC_8   , KC_9  , KC_0  , KC_LBRC  , KC_RBRC,
        SNIPING, KC_TAB  , KC_Q   , KC_W  , KC_E  , KC_R  , KC_T  ,                         KC_Y  , KC_U   , KC_I   , KC_O  , KC_P  , KC_QUOT  , KC_BACKSLASH,
        KC_BTN3, KC_LSFT , KC_A   , KC_S  , KC_D  , KC_F  , KC_G  ,                         KC_H  , KC_J   , KC_K   , KC_L  ,KC_SCLN, KC_LSFT  , DRGSCRL,
        KC_BTN1, KC_LCTL , KC_Z   , KC_X  , KC_C  , KC_V  , KC_B  ,                         KC_N  , KC_M   , KC_COMM, KC_DOT,KC_SLSH, KC_LCTL  , KC_BTN1,
                                    KC_LBRC,KC_RBRC,                                                         KC_PLUS, KC_EQL,
                                                    RAISE,  KC_SPC, KC_BSPC, KC_TAB,          LOWER,
                                                                                              KC_ENTER,
                                                                                     KC_LGUI, KC_LALT
        ),

    [_LOWER] = LAYOUT_6x7(
        KC_ESC , KC_F1  , KC_F2 , KC_F3 , KC_F4 , KC_F5 , KC_F6  ,                       KC_F7 , KC_F8  , KC_F9 ,KC_F10 ,KC_F11 ,KC_F12 , _______,
        _______, KC_TILD,KC_EXLM, KC_AT ,KC_HASH,KC_DLR ,KC_PERC,                        KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_DEL , _______,
        _______, _______,_______,_______,_______,_______,KC_LBRC,                        KC_RBRC, KC_P7 , KC_P8 , KC_P9 ,_______,KC_PLUS, _______,
        _______, _______,KC_HOME,KC_PGUP,KC_PGDN,KC_END ,KC_LPRN,                        KC_RPRN, KC_P4 , KC_P5 , KC_P6 ,KC_MINS,KC_PIPE, _______,
        _______, _______,_______,_______,_______,_______,_______,                        _______, KC_P1 , KC_P2 , KC_P3 ,KC_EQL ,KC_UNDS, _______,
                                 _______,KC_PSCR,                                                        _______, KC_P0,
                                                    SNIPING,DRGSCRL,KC_BTN1,KC_BTN3,         _______,
                                                                                             _______,
                                                                                    QK_BOOT, _______
        ),

    [_RAISE] = LAYOUT_6x7(
        _______,KC_F12 , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,                        KC_F6  , KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,KC_F11 , _______,
        _______,_______,_______,_______,_______,_______,KC_LBRC,                        KC_RBRC,_______,KC_NLCK,KC_INS ,KC_SLCK,KC_MUTE, _______,
        _______,_______,KC_LEFT,KC_UP  ,KC_DOWN,KC_RGHT,KC_LPRN,                        KC_RPRN,KC_MPRV,KC_MPLY,KC_MNXT,_______,KC_VOLU, _______,
        _______,_______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,KC_VOLD, _______,
        _______,_______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______, _______,
                                _______,_______,                                                        KC_EQL ,_______,
                                                   _______,_______,_______,QK_BOOT,          _______,
                                                                                             _______,
                                                                                     _______,_______
        )
};

void keyboard_post_init_user(void) {
#ifdef CONSOLE_ENABLE
    debug_enable=true;
    debug_matrix=true;
    debug_keyboard=true;
    debug_mouse=true;
#else
    debug_enable=false;
    debug_matrix=false;
    debug_keyboard=false;
    debug_mouse=false;
#endif
}
