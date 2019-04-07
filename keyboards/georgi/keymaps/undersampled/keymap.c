/* 
UnderSampled's Sandbox. Don't play unless you want sand in your clothes.
 */

#include QMK_KEYBOARD_H
#define IGNORE_MOD_TAP_INTERRUPT

#define LAYER		0

// "Layers"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// Gaming layer with Numpad, Very limited
[LAYER] = LAYOUT_georgi(
_______, MI_C , MI_D , MI_E , MI_Fs, MI_B ,      MI_Cs_1, MI_Fs_1, MI_Gs_1, MI_As_1, MI_C_2 , MI_D_2,
_______, MI_Cs, MI_Ds, MI_F , MI_G , MI_C_1,     MI_D_1 , MI_G_1 , MI_A_1 , MI_B_1 , MI_Cs_2, MI_Ds_2,
                       MI_Gs, MI_A , MI_As,      MI_Ds_1, MI_E_1 , MI_F_1)
};
