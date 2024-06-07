#include QMK_KEYBOARD_H

enum custom_keycodes {
  ALTTAB,
  GUILYR
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// ┏━━━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┓            ┏━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━━━┓
// ┃  ESC  ┃  1  ┃  2  ┃  3  ┃  4  ┃  5  ┃ PLY1┃            ┃PLY2 ┃  6  ┃  7  ┃  8  ┃  9  ┃  0  ┃   -   ┃
// ┣━━━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫            ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━━━┫
// ┃  TAB  ┃  Q  ┃  W  ┃  E  ┃  R  ┃  T  ┃  `  ┃            ┃  [  ┃  Y  ┃  U  ┃  I  ┃  O  ┃  P  ┃   =   ┃
// ┣━━━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫     ┃            ┃     ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━━━┫
// ┃  CTRL ┃  A  ┃  S  ┃  D  ┃  F  ┃  G  ┣━━━━━┫            ┣━━━━━┫  H  ┃  J  ┃  K  ┃  L  ┃  ;  ┃   '   ┃
// ┣━━━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫  \  ┃            ┃  ]  ┃━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━━━┫
// ┃  SHFT ┃  Z  ┃  X  ┃  C  ┃  V  ┃  B  ┃     ┃            ┃     ┃  N  ┃  M  ┃  ,  ┃  .  ┃  /  ┃ SHFT  ┃
// ┗━┳━━━━━╋━━━━━╋━━━━━╋━━━━━┻━━━━━┻━━━━━┻━━━━━┛            ┗━━━━━┻━━━━━┻━━━━━┻━━━━━╋━━━━━╋━━━━━╋━━━━━┳━┛
//   ┃ BRT-┃ BRT+┃ LOCK┃         ┏━━━━━┳━━━━━┓                ┏━━━━━┳━━━━━┓         ┃MUTE ┃VOL- ┃VOL+ ┃
//   ┗━━━━━┻━━━━━┻━━━━━┛         ┃ DEL ┃     ┃                ┃     ┃ BSP ┃         ┗━━━━━┻━━━━━┻━━━━━┛
//                               ┣━━━━━┫ SPC ┃                ┃ ENT ┣━━━━━┫
//                               ┃ GLR ┃     ┃                ┃     ┃ GLR ┃
//                               ┗━━━━━┻━━━━━┛                ┗━━━━━┻━━━━━┛
    [0] = LAYOUT(
  KC_ESC,  KC_1,    KC_2,   KC_3,   KC_4,   KC_5,   DM_PLY1,        DM_PLY2, KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS,
  KC_TAB,  KC_Q,    KC_W,   KC_E,   KC_R,   KC_T,   KC_GRV,         KC_LBRC, KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_EQL,
  KC_LCTL, KC_A,    KC_S,   KC_D,   KC_F,   KC_G,                            KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,   KC_C,   KC_V,   KC_B,   KC_BSLS,        KC_RBRC, KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  KC_BRID, KC_BRIU, LGUI(KC_L),                                                                       KC_MUTE, KC_VOLD, KC_VOLU,
                                            KC_DEL, KC_SPC,         KC_ENT, KC_BSPC,
                                            GUILYR, KC_NO,          KC_NO,  GUILYR
    ),
// LAYER 1: This layer combines the functions of FN, GUI, and ALT
// ┏━━━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┓            ┏━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━━━┓
// ┃  ESC  ┃  F1 ┃  F2 ┃  F3 ┃  F4 ┃  F5 ┃ REC1┃            ┃REC2 ┃ F6  ┃ F7  ┃ F8  ┃ F9  ┃ F10 ┃  F11  ┃
// ┣━━━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫            ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━━━┫
// ┃ ALTTAB┃  Q  ┃  W  ┃  E  ┃  R  ┃  T  ┃  `  ┃            ┃  [  ┃  Y  ┃  U  ┃  ↑  ┃  O  ┃  P  ┃  F12  ┃
// ┣━━━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫     ┃            ┃     ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━━━┫
// ┃  CTRL ┃  A  ┃  S  ┃  D  ┃  F  ┃  G  ┣━━━━━┫            ┣━━━━━┫  H  ┃  ←  ┃  ↓  ┃  →  ┃  ;  ┃   '   ┃
// ┣━━━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫  \  ┃            ┃  ]  ┃━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━━━┫
// ┃  SHFT ┃  Z  ┃  X  ┃  C  ┃  V  ┃  B  ┃     ┃            ┃     ┃  N  ┃  M  ┃  ,  ┃  .  ┃  /  ┃ SHFT  ┃
// ┗━┳━━━━━╋━━━━━╋━━━━━╋━━━━━┻━━━━━┻━━━━━┻━━━━━┛            ┗━━━━━┻━━━━━┻━━━━━┻━━━━━╋━━━━━╋━━━━━╋━━━━━┳━┛
//   ┃ BRT-┃ BRT+┃ N/C ┃         ┏━━━━━┳━━━━━┓                ┏━━━━━┳━━━━━┓         ┃MUTE ┃VOL- ┃VOL+ ┃
//   ┗━━━━━┻━━━━━┻━━━━━┛         ┃ALTDL┃     ┃                ┃     ┃ BSP ┃         ┗━━━━━┻━━━━━┻━━━━━┛
//                               ┣━━━━━┫ SPC ┃                ┃ ENT ┣━━━━━┫
//                               ┃ GUI ┃     ┃                ┃     ┃ GUI ┃
//                               ┗━━━━━┻━━━━━┛                ┗━━━━━┻━━━━━┛
    [1] = LAYOUT(
  _______, KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,        DM_REC1,         DM_REC2,       KC_F6,      KC_F7,      KC_F8,         KC_F9,        KC_F10,        KC_F11,
  ALTTAB,  LGUI(KC_Q), LGUI(KC_W), LGUI(KC_E), LGUI(KC_R), LGUI(KC_T),   LGUI(KC_GRV),    LGUI(KC_LBRC), LGUI(KC_Y), LGUI(KC_U), KC_UP,         LGUI(KC_O),   LGUI(KC_P),    KC_F12,
  _______, LGUI(KC_A), LGUI(KC_S), LGUI(KC_D), LGUI(KC_F), LGUI(KC_G),                                   LGUI(KC_H), KC_LEFT,    KC_DOWN,       KC_RIGHT,     LGUI(KC_SCLN), LGUI(KC_QUOT),
  _______, LGUI(KC_Z), LGUI(KC_X), LGUI(KC_C), LGUI(KC_V), LGUI(KC_B),   LGUI(KC_BSLS),   LGUI(KC_RBRC), LGUI(KC_N), LGUI(KC_M), LGUI(KC_COMM), LGUI(KC_DOT), LGUI(KC_SLSH), _______,
  _______, _______,    _______,                                                                                                                 _______,      _______,       _______,
                                                           LALT(KC_DEL), LGUI(KC_SPC),    LGUI(KC_ENT),  LGUI(KC_BSPC),
                                                           KC_LGUI,      _______,         _______,       KC_LGUI
    )
};

bool is_alt_tab_active = false;
uint16_t bespoke_tap_timer = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case GUILYR:
      if (record->event.pressed) {
        // Records press time.
        bespoke_tap_timer = timer_read();
        // turn on layer 1
        layer_on(1);
      } else if (is_alt_tab_active) {
        // turn off layer 1
        layer_off(1);
        // deactivate ALT+TAB
        unregister_code(KC_LALT);
        is_alt_tab_active = false;
      } else if (timer_elapsed(bespoke_tap_timer) < TAPPING_TERM) {
        // turn off layer 1
        layer_off(1);
        // Sends out 'LGUI' if the key is held for less than tapping term
        tap_code(KC_LGUI);
      } else {
        // turn off layer 1
        layer_off(1);
      } 
      return false;
    case ALTTAB: // ALT+TAB
      if (record->event.pressed) {
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          register_code(KC_LALT);
        }
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
      }
      return false;
  }
  return true;
}
