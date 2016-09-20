#include "process_steno.h"

uint32_t steno_chord = 0;
uint8_t steno_keys_down = 0;

const char steno_tape[] = "STKPWHRAO*EUFRPBLGTSDZ#";

bool type_steno_tape(uint32_t chord) {
  for (int i = 0 ; i < 23 ; i ++) {
    if (chord & (1UL << i)) {
      uint16_t keycode;
      if (steno_tape[i] == '*')
        keycode = KC_8;
      else if (steno_tape[i] == '#')
        keycode = KC_3;
      else
        keycode = steno_tape[i] - 61;

      register_code(KC_LSFT);
      register_code(keycode);
      unregister_code(keycode);
      unregister_code(KC_LSFT);
    }
  }
  return true;
}

bool process_steno(uint16_t keycode, keyrecord_t *record) {
  if (keycode >= ST_L_S && keycode <= ST_NUM) {
    if (record->event.pressed) {
      steno_chord |= 1UL << (keycode - ST_L_S);
      steno_keys_down += 1;
      return false;
    } else {
      steno_keys_down -= 1;
      if (steno_keys_down == 0) {
        type_steno_tape(steno_chord);
        steno_chord = 0;
      } else {
        return false;
      }
    }
  }
  return true;
}
