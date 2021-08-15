#include "kb.h"

//Tap Dance Declarations
enum {
  LEFTIE = 0
  ,RIGHTIE
};

enum custom_keycodes {
    SECTION = SAFE_RANGE,
    PARAGRAPH
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case SECTION:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_6) SS_TAP(X_KP_7)));
        } else {
            // when keycode QMKBEST is released
        }
        break;
    case PARAGRAPH:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_8) SS_TAP(X_KP_2)));
        } else {
            // when keycode QMKBEST is released
        }
        break;
    }
    return true;
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [LEFTIE]  = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_LBRC),
// Other declarations would go here, separated by commas, if you have them
    [RIGHTIE]  = ACTION_TAP_DANCE_DOUBLE(KC_RPRN, KC_RBRC)
// Other declarations would go here, separated by commas, if you have them
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	KEYMAP(
		KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, 
		MO(2), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_ENT, 
		KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_BSLS, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_RSFT, 
		KC_LCTL, KC_LALT, MO(1), KC_SPC, KC_RGUI, KC_RCTL),

	KEYMAP(
		KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_MINS, KC_EQL, TD(LEFTIE), TD(RIGHTIE), KC_TRNS, KC_SCLN, KC_QUOT, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, SECTION, KC_TRNS, KC_TRNS, PARAGRAPH, KC_TRNS, KC_TRNS, KC_SLSH, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	KEYMAP(
		KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_PGUP, KC_UP, KC_PGDN, KC_TRNS, KC_DEL, 
		KC_TRNS, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, 
		KC_TRNS, KC_MUTE, KC_VOLD, KC_VOLU, KC_BSLS, KC_TRNS, KC_TRNS, MO(3), KC_TRNS, KC_TRNS, KC_TRNS, KC_CAPS, 
		KC_TRNS, KC_TRNS, MO(3), KC_TRNS, KC_TRNS, KC_TRNS),

	KEYMAP(
		KC_TRNS, KC_LSFT, KC_TRNS, KC_BTN3, KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_MS_U, KC_BTN2, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(4), KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, SECTION, PARAGRAPH),

	KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(5), KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_RALT, KC_TRNS, KC_TRNS),

	KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)

};



void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

void led_set_user(uint8_t usb_led) {

	if (usb_led & (1 << USB_LED_NUM_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_COMPOSE)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_KANA)) {
		
	} else {
		
	}

}