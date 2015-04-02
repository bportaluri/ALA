/*  Copyright (c) 2009 by Alex Leone <acleone ~AT~ gmail.com>

    This file is part of the Arduino TLC5940 Library.

    The Arduino TLC5940 Library is free software: you can redistribute it
    and/or modify it under the terms of the GNU General Public License as
    published by the Free Software Foundation, either version 3 of the
    License, or (at your option) any later version.

    The Arduino TLC5940 Library is distributed in the hope that it will be
    useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with The Arduino TLC5940 Library.  If not, see
    <http://www.gnu.org/licenses/>. */

#ifndef TLC_ATMEGA_XX8_H
#define TLC_ATMEGA_XX8_H

/** \file
    SPI and timer pins for the ATmega164/324/644.  Don't edit these.  All
    changeable pins are defined in tlc_config.h */

/** VPRG (Sanguino digital pin 15) -> VPRG (TLC pin 27) */
#define DEFAULT_VPRG_PIN    PD7
#define DEFAULT_VPRG_PORT   PORTD
#define DEFAULT_VPRG_DDR    DDRD

/** XERR (Sanguino digital pin 6) -> XERR (TLC pin 16) */
#define DEFAULT_XERR_PIN    PB6
#define DEFAULT_XERR_PORT   PORTB
#define DEFAULT_XERR_DDR    DDRB
#define DEFAULT_XERR_PINS   PINB

/** SIN (Sanguino digital pin 5) -> SIN (TLC pin 26) */
#define DEFAULT_BB_SIN_PIN      PB5
#define DEFAULT_BB_SIN_PORT     PORTB
#define DEFAULT_BB_SIN_DDR      DDRB
/** SCLK (Sanguino digital pin 7) -> SCLK (TLC pin 25) */
#define DEFAULT_BB_SCLK_PIN     PB7
#define DEFAULT_BB_SCLK_PORT    PORTB
#define DEFAULT_BB_SCLK_DDR     DDRB

/** MOSI (Sanguino digital pin 5) -> SIN (TLC pin 26) */
#define TLC_MOSI_PIN     PB5
#define TLC_MOSI_PORT    PORTB
#define TLC_MOSI_DDR     DDRB

/** SCK (Sanguino digital pin 7) -> SCLK (TLC pin 25) */
#define TLC_SCK_PIN      PB7
#define TLC_SCK_PORT     PORTB
#define TLC_SCK_DDR      DDRB

/** SS will be set to output as to not interfere with SPI master operation.
    If you have changed the pin-outs and the library doesn't seem to work
    or works intermittently, make sure this pin is set correctly.  This pin
    will not be used by the library other than setting its direction to
    output. */
#define TLC_SS_PIN       PB4
#define TLC_SS_DDR       DDRB

/** OC1A (Sanguino digital pin 13) -> XLAT (TLC pin 24) */
#define XLAT_PIN     PD5
#define XLAT_PORT    PORTD
#define XLAT_DDR     DDRD

/** OC1B (Sanguino digital pin 12) -> BLANK (TLC pin 23) */
#define BLANK_PIN    PD4
#define BLANK_PORT   PORTD
#define BLANK_DDR    DDRD

/** OC2B (Sanguino digital pin 14) -> GSCLK (TLC pin 18) */
#define GSCLK_PIN    PD6
#define GSCLK_PORT   PORTD
#define GSCLK_DDR    DDRD

#endif

