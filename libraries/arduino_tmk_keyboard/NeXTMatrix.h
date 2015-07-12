/*
NeXT non-ADB Keyboard USB Converter
 
Copyright 2013, Benjamin Gould (bgould@github.com)

Based on:
TMK firmware code Copyright 2011,2012 Jun WAKO <wakojun@gmail.com>
Arduino code by "Ladyada" Limor Fried (http://ladyada.net/, http://adafruit.com/), released under BSD license

Timing reference thanks to http://m0115.web.fc2.com/ (dead link), http://cfile7.uf.tistory.com/image/14448E464F410BF22380BB
Pinouts thanks to http://www.68k.org/~degs/nextkeyboard.html
Keycodes from http://ftp.netbsd.org/pub/NetBSD/NetBSD-release-6/src/sys/arch/next68k/dev/

This software is licensed with a Modified BSD License.
All of this is supposed to be Free Software, Open Source, DFSG-free,
GPL-compatible, and OK to use in both free and proprietary applications.
Additions and corrections to this file are welcome.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright
  notice, this list of conditions and the following disclaimer.

* Redistributions in binary form must reproduce the above copyright
  notice, this list of conditions and the following disclaimer in
  the documentation and/or other materials provided with the
  distribution.

* Neither the name of the copyright holders nor the names of
  contributors may be used to endorse or promote products derived
  from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
POSSIBILITY OF SUCH DAMAGE.

*/
#ifndef NEXTMATRIX_H
#define NEXTMATRIX_H 1

#include "KeyboardFirmware.h"

#ifdef __cplusplus
extern "C" {
#endif

/* This is the physical layout that I am starting with:
 *   Note: there is some strangeness on the number pad; 
 *         the equal sign shifts to pipe and forward slash shifts to backslash
 * ,-----------------------------------------------------------. ,-----------. ,---------------.
 * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|   BS  | |VUp|Pwr|BrU| |`  |  =|  /|  *|
 * |-----------------------------------------------------------| |-----------| |---------------|
 * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|     | |VDn|   |BrD| |  7|  8|  9|  -|
 * |------------------------------------------------------     | `---'   `---' |-----------|---|
 * |Ctrl  |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|  Return|               |  4|  5|  6|  +|
 * |-----------------------------------------------------------|     ,---.     |---------------|
 * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift     |     |Up |     |  1|  2|  3|   |
 * |-----------------------------------------------------------| ,-----------. |-----------|Ent|
 * |Alt  |Cmd  |              Space                |Cmd  |Alt  | |Lef|Dow|Rig| |      0|  .|   |
 * `-----------------------------------------------------------' `-----------' `---------------'
 *
 * Keymap array:
 *     8 bytes
 *   +---------+
 *  0|         |
 *  :|         | 0x00-0x87
 *  ;|         |
 * 11|         |
 *   +---------+
 */
#define NEXT_KBD_KEYMAP( \
    K49,K4A,K4B,K4C,K4D,K50,K4F,K4E,K1E,K1F,K20,K1D,K1C,K1B,  K1A,K58,K19,  K26,K27,K28,K25, \
    K41,K42,K43,K44,K45,K48,K47,K46,K06,K07,K08,K05,K04,K03,  K02,    K01,  K21,K22,K23,K24, \
    K57,K39,K3A,K3B,K3C,K3D,K40,K3F,K3E,K2D,K2C,K2B,    K2A,                K12,K18,K13,K15, \
    K56,    K31,K32,K33,K34,K35,K37,K36,K2E,K2F,K30,    K55,      K16,      K11,K17,K14,     \
    K52,K54,                  K38,                  K53,K51,  K09,K0F,K10,  K0B,    K0C,K0D  \
) { \
    { KC_NO,    KC_##K01, KC_##K02, KC_##K03, KC_##K04, KC_##K05, KC_##K06, KC_##K07 }, \
    { KC_##K08, KC_##K09, KC_##K10, KC_##K0B, KC_##K0C, KC_##K0D, KC_NO,    KC_##K0F }, \
    { KC_##K10, KC_##K11, KC_##K12, KC_##K13, KC_##K14, KC_##K15, KC_##K16, KC_##K17 }, \
    { KC_##K18, KC_##K19, KC_##K1A, KC_##K1B, KC_##K1C, KC_##K1D, KC_##K1E, KC_##K1F }, \
    { KC_##K20, KC_##K21, KC_##K22, KC_##K23, KC_##K24, KC_##K25, KC_##K26, KC_##K27 }, \
    { KC_##K28, KC_NO,    KC_##K2A, KC_##K2B, KC_##K2C, KC_##K2D, KC_##K2E, KC_##K2F }, \
    { KC_##K30, KC_##K31, KC_##K32, KC_##K33, KC_##K34, KC_##K35, KC_##K36, KC_##K37 }, \
    { KC_##K38, KC_##K39, KC_##K3A, KC_##K3B, KC_##K3C, KC_##K3D, KC_##K3E, KC_##K3F }, \
    { KC_##K40, KC_##K41, KC_##K42, KC_##K43, KC_##K44, KC_##K45, KC_##K46, KC_##K47 }, \
    { KC_##K48, KC_##K49, KC_##K4A, KC_##K4B, KC_##K4C, KC_##K4D, KC_##K4E, KC_##K4F }, \
    { KC_##K50, KC_##K51, KC_##K52, KC_##K53, KC_##K54, KC_##K55, KC_##K56, KC_##K57 }, \
    { KC_##K58, KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,   }, \
}

#ifdef __cplusplus
}
#endif

class NeXTMatrix : public KeyboardMatrix
{
    public:
        NeXTMatrix();
        virtual void begin();
        virtual uint8_t scan();
        virtual uint8_t getRows();
        virtual uint8_t getCols();
        virtual bool isOn(uint8_t row, uint8_t col);
        bool isGhostInRow(uint8_t row);
        virtual matrix_row_t getRow(uint8_t row);
        virtual void debugPrint(void);
    protected:
        void _make(uint8_t code);
        void _break(uint8_t code); 
        uint8_t _matrix[MATRIX_ROWS];
        bool _is_modified;
        bool _power_state = false;
};

#endif
