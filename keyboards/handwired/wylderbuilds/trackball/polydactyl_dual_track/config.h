//
// Created by nethe on 11/9/2022.
//
//#define PRODUCT_ID 0x0001

#ifndef WYLD_QMK_FIRMWARE_CONFIG_H
#define WYLD_QMK_FIRMWARE_CONFIG_H

#endif // WYLD_QMK_FIRMWARE_CONFIG_H

// Dactyl Manuform Hotswap
#pragma once

//#include QMK_KEYBOARD_H
// Basic Config

#define SPLIT_HAND_PIN      GP26  // high = left, low = right
#define SPLIT_LAYER_STATE_ENABLE

//#define SCROLL_DIVIDER 12
//#define CPI_1 2000
//#define CPI_2 4000
//#define CPI_3 8000

#define SPLIT_POINTING_ENABLE
//#define ROTATIONAL_TRANSFORM_ANGLE  -25
//#define POINTING_DEVICE_INVERT_Y
#define POINTING_DEVICE_ROTATION_90
//#define POINTING_DEVICE_ROTATION_90_RIGHT // TESTING RIGHT COMMENTED OUT
#define ROTATIONAL_TRANSFORM_ANGLE  -45 // TESTING RIGHT SHIFTED FROM -35 TO -45 TO TEST LEFT
#define POINTING_DEVICE_INVERT_Y_RIGHT
#define POINTING_DEVICE_INVERT_Y
#define POINTING_DEVICE_INVERT_X
#define POINTING_DEVICE_COMBINED
#define PMW33XX_CS_PIN GP21
#define POINTING_DEVICE_TASK_THROTTLE_MS 1
#define PMW33XX_LIFTOFF_DISTANCE 0x02

#define SPLIT_TRANSACTION_IDS_KB RPC_ID_KB_CONFIG_SYNC

#define POINTING_DEVICE_AUTO_MOUSE_ENABLE
// only required if not setting mouse layer elsewhere
#define AUTO_MOUSE_DEFAULT_LAYER 3
//#define POINTING_DEVICE_ROTATION_90
////#define POINTING_DEVICE_ROTATION_90_RIGHT // TESTING RIGHT COMMENTED OUT
//#define ROTATIONAL_TRANSFORM_ANGLE  -45 // TESTING RIGHT SHIFTED FROM -35 TO -45 TO TEST LEFT
//#define POINTING_DEVICE_INVERT_Y_RIGHT
//#define POINTING_DEVICE_INVERT_Y
//#define POINTING_DEVICE_INVERT_X
//#define POINTING_DEVICE_INVERT_X_RIGHT

//#define POINTING_DEVICE_TASK_THROTTLE_MS 1
//#define PMW33XX_LIFTOFF_DISTANCE 0x02

//#define POINTING_DEVICE_DEBUG
//#define USE_SERIAL
// Using Serial instead of I2C
#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TX_PIN GP0
#define SERIAL_USART_RX_PIN GP1

#define SERIAL_PIO_USE_PIO0
#define SERIAL_USART_TIMEOUT     100  // USART driver timeout. default 100
#define SERIAL_USART_SPEED 921600
//#define SERIAL_USART_PIN_SWAP

// RP2040 Settings
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 200U
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED_MASK 0U
// More RP2040 Settings
//#define RP2040_FLASH_AT25SF128A
//#define RP2040_FLASH_GD25Q64CS
//#define RP2040_FLASH_W25X10CL
//#define RP2040_FLASH_IS25LP080
//#define RP2040_FLASH_GENERIC_03H
/* key matrix size */
// Rows are doubled-up
//#define MATRIX_ROWS 14
//#define MATRIX_COLS 7

#define MATRIX_COL_PINS { GP8, GP7, GP6, GP5, GP4, GP3, GP2 }
#define MATRIX_ROW_PINS { GP9, GP10, GP11, GP12, GP13, GP14, GP15 }
#define DIODE_DIRECTION COL2ROW

#    define SPLIT_LED_STATE_ENABLE

// USE PINS 27 AND 28 TO USE 4 PIN JST, IF AVAILABLE
#ifdef ENCODER_ENABLE
#define ENCODERS_PAD_A { GP28 }
#define ENCODERS_PAD_B { GP27 }
#define ENCODER_RESOLUTIONS { 2 }
#define ENCODERS_PAD_A_RIGHT { GP28 }
#define ENCODERS_PAD_B_RIGHT { GP27 }
#define ENCODER_RESOLUTIONS_RIGHT { 2 }
#endif

//// OLED Pins and Driver

#ifdef OLED_ENABLE
#define SPLIT_OLED_ENABLE
#define SPLIT_MODS_ENABLE
#define I2C_DRIVER I2CD0
#define I2C1_SDA_PIN GP16
#define I2C1_SCL_PIN GP17
#define RGBLIGHT_LAYERS
// OLED Options
#define SPLIT_OLED_ENABLE
#define SPLIT_WPM_ENABLE
#define OLED_DISPLAY_WIDTH 128
#define OLED_DISPLAY_HEIGHT 32
#define OLED_MATRIX_SIZE 512
#define OLED_RESET -1
#define OLED_DISPLAY_ADDRESS 0x3C
#define OLED_BRIGHTNESS 255
#define OLED_TIMEOUT 32000
#define OLED_FADE_OUT
#define OLED_FADE_OUT_INTERVAL 0
#endif

#ifdef RGB_MATRIX_ENABLE

#    define RGB_MATRIX_LED_COUNT 88
#    define WS2812_PIO_USE_PIO1 // Force the usage of PIO1 peripheral, by default the WS2812 implementation uses the PIO0 peripheral
#    define SPLIT_TRANSPORT_MIRROR
#    define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_REACTIVE // Sets the default mode, if none has been set
#    define RGB_MATRIX_DEFAULT_HUE 33 // Sets the default hue value, if none has been set
#    define RGB_MATRIX_DEFAULT_SAT 255 // Sets the default saturation value, if none has been set
#    define RGB_MATRIX_DEFAULT_SPD 50
#    define WS2812_DI_PIN GP22 // can use trackball jack if not used
#    define RGB_MATRIX_DEFAULT_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS
#    define RGB_DISABLE_WHEN_USB_SUSPENDED
#    define RGB_MATRIX_KEYPRESSES
#    define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define NOP_FUDGE 0.4  // may not be needed if ws driver loaded
#endif