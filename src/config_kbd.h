/*
 * config_kbd.h - This header file provides compilation-time configuration
 *                  for the keyboard_api and <keyboard>_adapter
 *
 * Copyright (C) 2025 Dygma Lab S.L. www.dygma.com
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef __CONFIG_KBD_H_
#define __CONFIG_KBD_H_

/*
 * Kaleidoscope Adapter Default Keymap specification (mandatory)
 */

enum
{
    KEYMAP_ID_QWERTY = 0,
    KEYMAP_ID_NUMPAD,
};

#define KALEIDOSCOPE_ADAPTER_KEYMAP_DEFAULT                                                                 __NL__ \
    [KEYMAP_ID_QWERTY] = KEYMAP_STACKED                                                                     __NL__ \
    (                                                                                                       __NL__ \
        /* Row 0 - Sonshi left side only (c0-c11) */                                                       __NL__ \
        Key_Escape, Key_1, Key_2, Key_3, Key_4, Key_5,                                 Key_6, Key_7, Key_8, Key_9, Key_0, Key_Backspace,                                    __NL__ \
        /* Row 1 - Sonshi left side only (c0-c11) */                                                       __NL__ \
        Key_Tab, Key_Q, Key_W, Key_E, Key_R, Key_T,                                    Key_Y, Key_U, Key_I, Key_O, Key_P, Key_LeftBracket,                                   __NL__ \
        /* Row 2 - Sonshi left side only (c0-c11) */                                                       __NL__ \
        Key_LeftGui, Key_A, Key_S, Key_D, Key_F, Key_G,                               Key_H, Key_J, Key_K, Key_L, Key_Semicolon, Key_Quote,                            __NL__ \
        /* Row 3 - Sonshi left side only (c0-c11) */                                                       __NL__ \
        Key_LeftShift, Key_Z, Key_X, Key_C, Key_V, Key_B,                              Key_N, Key_M, Key_Comma, Key_Period, Key_Slash, Key_Enter,                  __NL__ \
        /* Row 4 - Sonshi left side only (c0-c3, c8-c11 - c4-c7 don't exist) */                            __NL__ \
        Key_LeftAlt, Key_LeftControl, Key_Space, MoveToLayer(KEYMAP_ID_NUMPAD), Key_NoKey, Key_NoKey,Key_NoKey, Key_NoKey,      Key_Enter, Key_Space, Key_RightControl, Key_RightAlt __NL__ \
    ),                                                                                                      __NL__ \
                                                                                                            __NL__ \
    [KEYMAP_ID_NUMPAD] = KEYMAP_STACKED                                                                     __NL__ \
    (                                                                                                       __NL__ \
        /* Row 0 - Sonshi left side only (c0-c11) */                                                       __NL__ \
        Key_Backtick, Key_F1, Key_F2, Key_F3, Key_F4, Key_F5,                                                         Key_F6, Key_F7, Key_F8, Key_F9, Key_F10, Key_Transparent,    __NL__ \
        /* Row 1 - Sonshi left side only (c0-c11) */                                                       __NL__ \
        Key_Transparent, Key_Transparent, Key_Home, Key_UpArrow, Key_End, Key_PageUp,                                 Key_KeypadMultiply, Key_7, Key_8, Key_9, Key_KeypadAdd, Key_RightBracket, __NL__ \
        /* Row 2 - Sonshi left side only (c0-c11) */                                                       __NL__ \
        Key_Transparent, Key_Transparent, Key_LeftArrow, Key_DownArrow, Key_RightArrow, Key_PageDown,                 Key_KeypadDivide, Key_4, Key_5, Key_6, Key_Enter, Key_RightBracket, __NL__ \
        /* Row 3 - Sonshi left side only (c0-c11) */                                                       __NL__ \
        Key_Transparent, Key_Transparent, Key_Transparent, Key_Transparent, Key_Transparent, Key_Transparent,         Key_KeypadSubtract, Key_1, Key_2, Key_3, Key_KeypadDot, Key_Transparent, __NL__ \
        /* Row 4 - Sonshi left side only (c0-c3, c8-c11 - c4-c7 don't exist) */                            __NL__ \
        Key_Transparent, Key_Transparent, Key_Transparent, Key_Transparent,      Key_NoKey, Key_NoKey,Key_NoKey,Key_NoKey,  Key_Transparent, Key_0, Key_Transparent, Key_Transparent __NL__ \
    )

#endif /* __CONFIG_KBD_H_ */
