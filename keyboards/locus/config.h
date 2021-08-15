#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x7366
#define PRODUCT_ID      0x6C63
#define DEVICE_VER      0x0001
#define MANUFACTURER    Soft
#define PRODUCT         Locus

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 12

/* key matrix pins */
#define MATRIX_ROW_PINS { D5, F5, F6, D6 }
#define MATRIX_COL_PINS { F0, F1, B3, B2, B1, B0, C7, C6, B6, B5, B4, D7 }
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* disable these deprecated features by default */
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
