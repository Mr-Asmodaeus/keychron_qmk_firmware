/* Copyright 2024 @ Keychron (https://www.keychron.com)
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
#include "keychron_common.h"


enum layers {
    MAC_BASE,
    MAC_FN,
    WIN_BASE,
    WIN_FN,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_tkl_ansi(
        KC_ESC,   KC_BRID,  KC_BRIU,  KC_MCTRL, KC_LNPAD, RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,    KC_MUTE,    KC_SNAP,  KC_SIRI,  RGB_MOD,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,    KC_INS,   KC_HOME,  KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,    KC_BSLS,    KC_DEL,   KC_END,   KC_PGDN,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,              KC_UP,
        KC_LCTL,  KC_LOPTN, KC_LCMMD,                               KC_SPC,                                 KC_RCMMD, KC_ROPTN, MO(MAC_FN), KC_RCTL,    KC_LEFT,  KC_DOWN,  KC_RGHT),

    [MAC_FN] = LAYOUT_tkl_ansi(
        _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,     RGB_TOG,    _______,  _______,  RGB_TOG,
        _______,  BT_HST1,  BT_HST2,  BT_HST3,  P2P4G,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,              _______,
        _______,            _______,  _______,  _______,  _______,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,              _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,    _______,  _______,  _______),

    [WIN_BASE] = LAYOUT_tkl_ansi(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,     KC_MUTE,    KC_SCRL,  KC_PAUS, QK_LEAD,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,    KC_INS,   KC_HOME,  KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,    KC_BSLS,    KC_DEL,   KC_END,   KC_PGDN,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,              KC_UP,
        KC_LCTL,  KC_LCMD,  KC_LALT,                                KC_SPC,                                 KC_RALT,  KC_RWIN,  MO(WIN_FN), KC_RCTL,    KC_LEFT,  KC_DOWN,  KC_RGHT),

    [WIN_FN] = LAYOUT_tkl_ansi(
        _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,    RGB_TOG,    _______,  _______,  QK_LEAD,
        _______,  BT_HST1,  BT_HST2,  BT_HST3,  P2P4G,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,              _______,
        _______,            _______,  _______,  _______,  _______,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,              _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,    _______,  _______,  _______),
};

// clang-format on
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [MAC_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [MAC_FN]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [WIN_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [WIN_FN]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
};
#endif // ENCODER_MAP_ENABLE

extern void process_rgb_matrix_typing_heatmap_user (uint8_t row, uint8_t col, bool pressed);


bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    uint8_t mod_state = get_mods();
    switch (keycode){
        case KC_DOT:
        {
            if ((mod_state & MOD_MASK_SHIFT ) && (mod_state & MOD_MASK_ALT ) )
            {
                if (record->event.pressed)
                {
                    del_mods(mod_state);
                    SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_6) SS_TAP(X_KP_6)));
                    add_mods(mod_state);
                    return false;
                }
            }
            else
            if (mod_state & MOD_MASK_ALT)
            {
                if (record->event.pressed)
                {
                    del_mods(mod_state);
                    SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_6) SS_TAP(X_KP_7)));
                    add_mods(mod_state);
                    return false;
                }
            }

            return true;
        }
        default:
            return true; // Process all other keycodes normally
    }

    if (!process_record_keychron_common(keycode, record))
    {
        return false;
    }

    process_rgb_matrix_typing_heatmap_user(record->event.key.row,record->event.key.col,record->event.pressed);
    return true;
}


/*************************/
/* MACROS AND LEADER KEY */
/*************************/
#include "mystrings.h"

#ifndef LM_UG
#define  LM_UG ""
#endif
#ifndef LM_UB
#define  LM_UB ""
#endif
#ifndef LM_UC
#define  LM_UC ""
#endif
#ifndef LM_U4
#define  LM_U4 ""
#endif

#ifndef LM_P7
#define  LM_P7 ""
#endif
#ifndef LM_PK
#define  LM_PK ""
#endif
#ifndef LM_EG
#define  LM_EG ""
#endif
#ifndef LM_EB
#define  LM_EB ""
#endif

#define SEND_STRING_DELAY_VALUE 5


static int rgb_matrix_previous_mode;
static int rgb_matrix_previous_speed;
static HSV rgb_matrix_previous_hsv;

extern uint16_t leader_time;

void leader_start_user(void) {
    rgb_matrix_previous_mode = rgb_matrix_get_mode();
    rgb_matrix_previous_speed = rgb_matrix_get_speed();
    rgb_matrix_previous_hsv = rgb_matrix_get_hsv();


    rgb_matrix_mode_noeeprom(RGB_MATRIX_BREATHING );
    rgb_matrix_set_speed_noeeprom(255);
    rgb_matrix_sethsv_noeeprom(0,255,255);
}

void leader_end_user(void) {

    if (leader_sequence_two_keys(KC_U, KC_G)) {
        SEND_STRING_DELAY(LM_UG,SEND_STRING_DELAY_VALUE);
    }else
    if (leader_sequence_two_keys(KC_U, KC_B)) {
        SEND_STRING_DELAY(LM_UB,SEND_STRING_DELAY_VALUE);
    }else
    if (leader_sequence_two_keys(KC_U, KC_C)) {
        SEND_STRING_DELAY(LM_UC,SEND_STRING_DELAY_VALUE);
    }else

    if (leader_sequence_two_keys(KC_P, KC_7)) {
        SEND_STRING_DELAY(LM_P7,SEND_STRING_DELAY_VALUE);
    }else
    if (leader_sequence_two_keys(KC_P, KC_K)) {
        SEND_STRING_DELAY(LM_PK,SEND_STRING_DELAY_VALUE);
    }else
    if (leader_sequence_two_keys(KC_E, KC_G)) {
        SEND_STRING_DELAY(LM_EG,SEND_STRING_DELAY_VALUE);
    }else
    if (leader_sequence_two_keys(KC_E, KC_V)) {
        SEND_STRING_DELAY(LM_EV,SEND_STRING_DELAY_VALUE);
    }else
    if (leader_sequence_two_keys(KC_E, KC_B)) {
        SEND_STRING_DELAY(LM_EB,SEND_STRING_DELAY_VALUE);
    }
    rgb_matrix_mode_noeeprom (rgb_matrix_previous_mode);
    rgb_matrix_sethsv_noeeprom (rgb_matrix_previous_hsv.h,rgb_matrix_previous_hsv.s,rgb_matrix_previous_hsv.v);
    rgb_matrix_set_speed_noeeprom(rgb_matrix_previous_speed);
}
/****************************/
/* MACROS AND LEADER KEY END*/
/****************************/
