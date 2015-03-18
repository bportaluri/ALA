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

#ifndef TLC_CONFIG_H
#define TLC_CONFIG_H

#include <stdint.h>

/** \file
    Configuration for the Arduino Tlc5940 library.  After making changes to
    this file, delete Tlc5940.o in this folder so the changes are applied.

    A summary of all the options:
    - Number of TLCs daisy-chained: NUM_TLCS (default 1)
    - Enable/Disable VPRG functionality: VPRG_ENABLED (default 0)
    - Enable/Disable XERR functionality: XERR_ENABLED (default 0)
    - Should the library use bit-banging (any pins) or hardware SPI (faster):
        DATA_TRANSFER_MODE (default TLC_SPI)
    - Which pins to use for bit-banging: SIN_PIN, SIN_PORT, SIN_DDR and
        SCLK_PIN, SCLK_PORT, SCLK_DDR
    - The PWM period: TLC_PWM_PERIOD (be sure to change TLC_GSCLK_PERIOD
        accordingly!)

    How to change the pin mapping:
    - Arduino digital pin 0-7  = PORTD, PD0-7
    - Arduino digital pin 8-13 = PORTB, PB0-5
    - Arduino analog pin  0-5  = PORTC, PC0-5 */

/** Bit-bang using any two i/o pins */
#define TLC_BITBANG        1
/** Use the much faster hardware SPI module */
#define TLC_SPI            2

/* ------------------------ START EDITING HERE ----------------------------- */

/** Number of TLCs daisy-chained.  To daisy-chain, attach the SOUT (TLC pin 17)
    of the first TLC to the SIN (TLC pin 26) of the next.  The rest of the pins
    are attached normally.
    \note Each TLC needs it's own IREF resistor */
#define NUM_TLCS    1

/** Determines how data should be transfered to the TLCs.  Bit-banging can use
    any two i/o pins, but the hardware SPI is faster.
    - Bit-Bang = TLC_BITBANG
    - Hardware SPI = TLC_SPI (default) */
#define DATA_TRANSFER_MODE    TLC_SPI

/* This include is down here because the files it includes needs the data
   transfer mode */
#include "pinouts/chip_includes.h"

/* Set DATA_TRANSFER_MODE to TLC_BITBANG and change the pins below if you need
   to use different pins for sin and sclk.  The defaults are defined in
   pinouts/ATmega_xx8.h for most Arduino's. */

#if DATA_TRANSFER_MODE == TLC_BITBANG
/** SIN (TLC pin 26) */
#define SIN_PIN        DEFAULT_BB_SIN_PIN
#define SIN_PORT       DEFAULT_BB_SIN_PORT
#define SIN_DDR        DEFAULT_BB_SIN_DDR
/** SCLK (TLC pin 25) */
#define SCLK_PIN       DEFAULT_BB_SCLK_PIN
#define SCLK_PORT      DEFAULT_BB_SCLK_PORT
#define SCLK_DDR       DEFAULT_BB_SCLK_DDR
#endif


/** If more than 16 TLCs are daisy-chained, the channel type has to be uint16_t.
    Default is uint8_t, which supports up to 16 TLCs. */
#define TLC_CHANNEL_TYPE    uint8_t

/** Determines how long each PWM period should be, in clocks.
    \f$\displaystyle f_{PWM} = \frac{f_{osc}}{2 * TLC\_PWM\_PERIOD} Hz \f$
    \f$\displaystyle TLC\_PWM\_PERIOD = \frac{f_{osc}}{2 * f_{PWM}} \f$
    This is related to TLC_GSCLK_PERIOD:
    \f$\displaystyle TLC\_PWM\_PERIOD =
       \frac{(TLC\_GSCLK\_PERIOD + 1) * 4096}{2} \f$
    \note The default of 8192 means the PWM frequency is 976.5625Hz */
#define TLC_PWM_PERIOD    8192

/** Determines how long each period GSCLK is.
    This is related to TLC_PWM_PERIOD:
    \f$\displaystyle TLC\_GSCLK\_PERIOD =
       \frac{2 * TLC\_PWM\_PERIOD}{4096} - 1 \f$
    \note Default is 3 */
#define TLC_GSCLK_PERIOD    3

/** Enables/disables VPRG (TLC pin 27) functionality.  If you need to set dot
    correction data, this needs to be enabled.
    - 0 VPRG is not connected.  <em>TLC pin 27 must be grounded!</em> (default)
    - 1 VPRG is connected
    \note VPRG to GND inputs grayscale data, VPRG to Vcc inputs dot-correction
          data */
#define VPRG_ENABLED    0

/** Enables/disables XERR (TLC pin 16) functionality to check for shorted/broken
    LEDs
    - 0 XERR is not connected (default)
    - 1 XERR is connected
    \note XERR is active low */
#define XERR_ENABLED    0

/*  You can change the VPRG and XERR pins freely.  The defaults are defined in
    the chip-specific pinouts:  see pinouts/ATmega_xx8.h for most Arduino's. */

#if     VPRG_ENABLED
/** VPRG (TLC pin 27) */
#define VPRG_PIN        DEFAULT_VPRG_PIN
#define VPRG_PORT       DEFAULT_VPRG_PORT
#define VPRG_DDR        DEFAULT_VPRG_DDR
#endif

#if     XERR_ENABLED
/** XERR (TLC pin 16) */
#define XERR_PIN        DEFAULT_XERR_PIN
#define XERR_PORT       DEFAULT_XERR_PORT
#define XERR_DDR        DEFAULT_XERR_DDR
#define XERR_PINS       DEFAULT_XERR_PINS
#endif

/* ------------------------- STOP EDITING HERE ----------------------------- */

#if DATA_TRANSFER_MODE == TLC_SPI
/** SIN (TLC pin 26) */
#define SIN_PIN        TLC_MOSI_PIN
#define SIN_PORT       TLC_MOSI_PORT
#define SIN_DDR        TLC_MOSI_DDR
/** SCLK (TLC pin 25) */
#define SCLK_PIN       TLC_SCK_PIN
#define SCLK_PORT      TLC_SCK_PORT
#define SCLK_DDR       TLC_SCK_DDR
#endif



#if !(DATA_TRANSFER_MODE == TLC_BITBANG \
 || DATA_TRANSFER_MODE == TLC_SPI)
#error "Invalid DATA_TRANSFER_MODE specified, see DATA_TRANSFER_MODE"
#endif

/* Various Macros */

/** Arranges 2 grayscale values (0 - 4095) in the packed array format (3 bytes).
    This is for array initializers only: the output is three comma seperated
    8-bit values. */
#define GS_DUO(a, b)    ((a) >> 4), ((a) << 4) | ((b) >> 8), (b)


#if VPRG_ENABLED
/** Arranges 4 dot correction values (0 - 63) in the packed array format.
    \see setDCtoProgmemArray */
#define DC_QUARTET(a, b, c, d)   ((a) << 2) | ((b) >> 4), \
                                 ((b) << 4) | ((c) >> 2), \
                                 ((c) << 6) | (d)
#endif

#endif

