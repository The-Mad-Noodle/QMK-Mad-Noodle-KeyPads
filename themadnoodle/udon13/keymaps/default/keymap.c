// Copyright 2023 The Mad Noodle(@the_mad_noodle)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum custom_keycodes {
#ifdef VIA_ENABLE   // If you are using VIA, you can use the same keycodes as the default keymap
    L_CYC = QK_KB_0 // Cycle through the layers
#else               // If you are not using VIA, you can use your own keycodes
    L_CYC = SAFE_RANGE
#endif
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*Layer 0*/
    [0] = LAYOUT(
        KC_MUTE,
        KC_MPLY, KC_MPRV, KC_MNXT, KC_MSEL, 
        KC_UNDO, KC_CALC, KC_MAIL, KC_MYCM, 
        KC_COPY, KC_CUT, KC_PSTE, TO(3)
        ),

/*Layer 1*/
    [1] = LAYOUT(
        RGB_TOG, 
        RGB_SAD, RGB_SAI, RGB_HUD, RGB_HUI, 
        RGB_MOD, RGB_RMOD, RGB_M_P, RGB_M_B, 
        RGB_M_SW, RGB_SPD, RGB_SPI, TO(0)
        ),

/*Layer 2*/ 
    [2] = LAYOUT(
        KC_NO, 
        KC_NO, KC_NO, KC_NO, KC_NO, 
        KC_NO, KC_NO, KC_NO, KC_NO, 
        KC_NO, KC_NO, KC_NO, TO(0)
        ),

/*Layer 3*/       
    [3] = LAYOUT(
        KC_NO, 
        TO(1), TO(2), KC_NO, KC_NO, 
        KC_NO, KC_NO, KC_NO, KC_NO, 
        KC_NO, KC_NO, KC_NO, TO(0)
        ),

};

/*Encoder Mapping*/
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] =  {ENCODER_CCW_CW(KC_VOLD,  KC_VOLU)},
    [1] =  { ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [2] =  { ENCODER_CCW_CW(KC_LEFT, KC_RGHT)},
    [3] =  { ENCODER_CCW_CW(KC_DOWN,   KC_UP)},
   
};
#endif

//  ======================Custom Keycodes==========================

// 1st layer on the cycle
#define LAYER_CYCLE_START 0
// Last layer on the cycle
#define LAYER_CYCLE_END 3

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case L_CYC:
            // Our logic will happen on presses, nothing is done on releases
            if (!record->event.pressed) {
                // We've already handled the keycode (doing nothing), let QMK know so no further code is run unnecessarily
                return false;
            }

            uint8_t current_layer = get_highest_layer(layer_state);

            // Check if we are within the range, if not quit
            if (current_layer > LAYER_CYCLE_END || current_layer < LAYER_CYCLE_START) {
                return false;
            }

            uint8_t next_layer = current_layer + 1;
            if (next_layer > LAYER_CYCLE_END) {
                next_layer = LAYER_CYCLE_START;
            }
            layer_move(next_layer);
            return false;

        default:
            return true; // Process all other keycodes normally
    }
}