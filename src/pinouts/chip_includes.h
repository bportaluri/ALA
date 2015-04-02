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

#ifndef TLC_CHIP_INCLUDES_H
#define TLC_CHIP_INCLUDES_H

/** \file
    Includes the chip-specfic defaults and pin definitions. */

#include <avr/io.h>

#ifndef PB0
#define PB0     PORTB0
#define PB1     PORTB1
#define PB2     PORTB2
#define PB3     PORTB3
#define PB4     PORTB4
#define PB5     PORTB5
#define PB6     PORTB6
#define PB7     PORTB7
#endif
#ifndef PC0
#define PC0     PORTC0
#define PC1     PORTC1
#define PC2     PORTC2
#define PC3     PORTC3
#define PC4     PORTC4
#define PC5     PORTC5
#define PC6     PORTC6
#define PC7     PORTC7
#endif
#ifndef PD0
#define PD0     PORTD0
#define PD1     PORTD1
#define PD2     PORTD2
#define PD3     PORTD3
#define PD4     PORTD4
#define PD5     PORTD5
#define PD6     PORTD6
#define PD7     PORTD7
#endif
#ifndef PH0
#define PH0     PORTH0
#define PH1     PORTH1
#define PH2     PORTH2
#define PH3     PORTH3
#define PH4     PORTH4
#define PH5     PORTH5
#define PH6     PORTH6
#define PH7     PORTH7
#endif

/* Chip Specific Pinouts */
#if defined (__AVR_ATmega168__)  \
 || defined (__AVR_ATmega168P__) \
 || defined (__AVR_ATmega88P__)  \
 || defined (__AVR_ATmega88__)   \
 || defined (__AVR_ATmega48P__)  \
 || defined (__AVR_ATmega48__)   \
 || defined (__AVR_ATmega328P__)

/* Diecimila / Duemilanove / almost everything */
#include "ATmega_xx8.h"

#elif defined (__AVR_ATmega8__)

/* ATmega8 */
#include "ATmega_8.h"

#elif defined (__AVR_ATmega164P__) \
   || defined (__AVR_ATmega324P__) \
   || defined (__AVR_ATmega644__)  \
   || defined (__AVR_ATmega644P__)

/* Sanguino */
#include "ATmega_xx4.h"

#elif defined (__AVR_ATmega640__)  \
   || defined (__AVR_ATmega1280__) \
   || defined (__AVR_ATmega1281__) \
   || defined (__AVR_ATmega2560__) \
   || defined (__AVR_ATmega2561__)
   
/* Arduino Mega */
#include "Arduino_Mega.h"

#elif defined (__AVR_ATmega32U4__)

/* Teensy 2.0 */
#include "Teensy_xxU4.h"

#elif defined (__AVR_AT90USB646__) \
   || defined (__AVR_AT90USB1286__)

/* Teensy++ 2.0 */
#include "Teensypp_xxx6.h"

#else
#error "Unknown Chip!"
#endif

#endif

