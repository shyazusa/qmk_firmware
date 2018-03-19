#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

#define G_A(kc) (kc | QK_LGUI | QK_LALT)

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  |   `  |           |   `  |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   BS   |   Q  |   W  |   E  |   R  |   T  |  [   |           |   ]  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  Ctrl  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------|  L2  |           |   B  |------+------+------+------+------+--------|
 * | Ctrl+L |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | Ctrl+R |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Alt  |   |  |AltShf|  Up  |Enter |                                       | Left | Down |  UP  |Right | Enter|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,--------------.       ,-------------.
 *                                        | Play  | Next |       | VolD | VolU |
 *                                ,-------|-------|------|       |------+------+------.
 *                                |       |       |Enter |       | Space|      |      |
 *                                | Space |  GUI  |------|       |------| Tab  |Enter |
 *                                |-> Sft |       | ESC  |       |  BS  |-> GUI|-> L2 |
 *                                `----------------------'       `--------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_EQL,        KC_1,    KC_2,          KC_3,  KC_4,    KC_5,    KC_GRV,
        KC_BSPC,       KC_Q,    KC_W,          KC_E,  KC_R,    KC_T,    KC_LBRC,
        KC_LCTL,       KC_A,    KC_S,          KC_D,  KC_F,    KC_G,
        LCTL(KC_LEFT), KC_Z,    KC_X,          KC_C,  KC_V,    KC_B,    TG(2),
        KC_LALT,       KC_PIPE, LALT(KC_LSFT), KC_UP, KC_ENT,
                                                               KC_MPLY, KC_MNXT,
                                                                        KC_ENT,
                                                SFT_T(KC_SPC), KC_LGUI, KC_ESC,
        // right hand
        KC_GRV,  KC_6,    KC_7,    KC_8,    KC_9,   KC_0,     KC_MINS,
        KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,     KC_BSLS,
                 KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN,  KC_QUOT,
        KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH,  LCTL(KC_RIGHT),
                          KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT, KC_ENT,
        KC_VOLD, KC_VOLU,
        KC_SPC,
        KC_BSPC, GUI_T(KC_TAB), LT(2, KC_ENT)
    ),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      |      |  Up  |      |      |      |           |      |      |      |      |      |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      | Left | Down | Right|      |------|           |------| Left | Down |  UP  | Right|      |  Enter |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      | Space|      |      |      |           |      |      |      |      |      |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | Space|Enter |------|       |------| Space|Enter |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = KEYMAP(
       // left hand
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_UP,   KC_TRNS,  KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_SPC,  KC_TRNS,  KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                     KC_MPRV, KC_MPLY,
                                                              KC_TRNS,
                                           KC_SPC,   KC_ENT,  KC_TRNS,
       // right hand
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
                KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_TRNS, KC_ENT,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
                         KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_SPC,  KC_ENT
),
/* Keymap 2: Media and mouse keys
 *
 * ,-----------------------------------------------------.           ,---------------------------------------------------.
 * |        |       |       |      |      |       | RESET|           |      |      |      |      |      |       |        |
 * |--------+-------+-------+------+------+--------------|           |------+------+------+------+------+-------+--------|
 * |        | Gui+Q | Gui+W | MsUp |      | Gui+T |      |           |      | yank | Lclk | WhUp | Rclk | Past  |        |
 * |--------+-------+-------+------+------+-------|      |           |      |------+------+------+------+-------+--------|
 * |  Ctrl  |GuiAltL|MsLeft |MsDown|MsRght|       |------|           |------| Left | Down |  Up  | Right|GuiAltR|  Ctrl  |
 * |--------+-------+-------+------+------+-------|      |           |      |------+------+------+------+-------+--------|
 * |        |       |  BS   |      |      |       |      |           |      |      |      |WhDown|      |       |        |
 * `--------+-------+-------+------+------+--------------'           `-------------+------+------+------+-------+--------'
 *   |      |       |       | Lclk | Rclk |                                       |      |      |      |       |      |
 *   `------------------------------------'                                       `-----------------------------------'
 *                                        ,------------.       ,-------------.
 *                                        |     |      |       |      |      |
 *                                 ,------|-----|------|       |------+------+------.
 *                                 |      |     |      |       |      |      |      |
 *                                 | Shift| GUI |------|       |------|      |      |
 *                                 |      |     |      |       |  BS  |      |      |
 *                                 `-------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = KEYMAP(
        // left hand
        KC_TRNS,       KC_TRNS,      KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,    RESET,
        KC_TRNS,       LGUI(KC_Q),   LGUI(KC_W), KC_MS_U, KC_TRNS, LGUI(KC_T), KC_TRNS,
        KC_LCTL,       G_A(KC_LEFT), KC_MS_L,    KC_MS_D, KC_MS_R, KC_TRNS,
        KC_TRNS,       KC_TRNS,      KC_DELT,    KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,
        KC_TRNS,       KC_TRNS,      KC_TRNS,    KC_BTN1, KC_BTN2,
                                                                   KC_MPRV,    KC_MPLY,
                                                                               KC_TRNS,
                                                 SFT_T(KC_SPC), GUI_T(KC_SPC), KC_ESC,
        // right hand
        KC_TRNS,  KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,       KC_TRNS,
        KC_TRNS,  LGUI(KC_C), KC_BTN1, KC_WH_U, KC_BTN2,  LGUI(KC_V),    KC_TRNS,
                  KC_LEFT,    KC_DOWN, KC_UP,   KC_RIGHT, G_A(KC_RIGHT), KC_LCTL,
        KC_TRNS,  KC_TRNS,    KC_TRNS, KC_WH_D, KC_TRNS,  KC_TRNS,       KC_TRNS,
                              KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,       KC_TRNS,
        KC_TRNS, KC_TRNS,
        KC_TRNS,
        KC_TRNS, KC_BTN1, KC_TRNS
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
        case 1:
        if (record->event.pressed) { // For resetting EEPROM
          eeconfig_init();
        }
        break;
      }
    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
