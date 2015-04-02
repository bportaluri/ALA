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

#ifndef ARDUINO_MEGA_H
#define ARDUINO_MEGA_H

/** \file
    SPI and timer pins for the Arduino Mega.  Don't edit these.  All
    changeable pins are defined in tlc_config.h */

/** VPRG (Mega pin 50) -> VPRG (TLC pin 27) */
#define DEFAULT_VPRG_PIN    PB3
#define DEFAULT_VPRG_PORT   PORTB
#define DEFAULT_VPRG_DDR    DDRB

/** XERR (Mega pin 10) -> XERR (TLC pin 16) */
#define DEFAULT_XERR_PIN    PB4
#define DEFAULT_XERR_PORT   PORTB
#define DEFAULT_XERR_DDR    DDRB
#define DEFAULT_XERR_PINS   PINB

/** SIN (Mega pin 51) -> SIN (TLC pin 26) */
#define DEFAULT_BB_SIN_PIN      PB2
#define DEFAULT_BB_SIN_PORT     PORTB
#define DEFAULT_BB_SIN_DDR      DDRB
/** SCLK (Mega pin 52) -> SCLK (TLC pin 25) */
#define DEFAULT_BB_SCLK_PIN     PB1
#define DEFAULT_BB_SCLK_PORT    PORTB
#define DEFAULT_BB_SCLK_DDR     DDRB

/** MOSI (Mega pin 51) -> SIN (TLC pin 26) */
#define TLC_MOSI_PIN     PB2
#define TLC_MOSI_PORT    PORTB
#define TLC_MOSI_DDR     DDRB

/** SCK (Mega pin 52) -> SCLK (TLC pin 25) */
#define TLC_SCK_PIN      PB1
#define TLC_SCK_PORT     PORTB
#define TLC_SCK_DDR      DDRB

// SS (Mega pin 53)
/** SS will be set to output as to not interfere with SPI master operation.
    If you have changed the pin-outs and the library doesn't seem to work
    or works intermittently, make sure this pin is set correctly.  This pin
    will not be used by the library other than setting its direction to
    output. */
#define TLC_SS_PIN       PB0
#define TLC_SS_DDR       DDRB

/** OC1A (Mega pin 11) -> XLAT (TLC pin 24) */
#define XLAT_PIN     PB5
#define XLAT_PORT    PORTB
#define XLAT_DDR     DDRB

/** OC1B (Mega pin 12) -> BLANK (TLC pin 23) */
#define BLANK_PIN    PB6
#define BLANK_PORT   PORTB
#define BLANK_DDR    DDRB

/** OC2B (Mega pin 9) -> GSCLK (TLC pin 18) */
#define GSCLK_PIN    PH6
#define GSCLK_PORT   PORTH
#define GSCLK_DDR    DDRH

#endif

