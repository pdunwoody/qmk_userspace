/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

//#define USE_MATRIX_I2C

//#define QUICK_TAP_TERM 0
//#define TAPPING_TERM 100

#define CHORDAL_HOLD

#define PERMISSIVE_HOLD
#define TAPPING_TERM 250

#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE

//#define MASTER_RIGHT
#define SPLIT_HAND_PIN GP21
#define	SPLIT_HAND_PIN_LOW_IS_LEFT
#define USE_SERIAL
#define SERIAL_PIO_USE_PIO0
#define SERIAL_USART_TX_PIN   GP1
#define USB_VBUS_PIN 19

/* Reset. */
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP17
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 1000U

#ifdef RGBLIGHT_ENABLE
    #define RGBLIGHT_EFFECT_BREATHING
    #define RGBLIGHT_EFFECT_RAINBOW_MOOD
    #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
    #define RGBLIGHT_EFFECT_SNAKE
    #define RGBLIGHT_EFFECT_KNIGHT
    #define RGBLIGHT_EFFECT_CHRISTMAS
    #define RGBLIGHT_EFFECT_STATIC_GRADIENT
    #define RGBLIGHT_EFFECT_RGB_TEST
    #define RGBLIGHT_EFFECT_ALTERNATING
    #define RGBLIGHT_EFFECT_TWINKLE
    #define RGBLIGHT_LIMIT_VAL 120
    #define RGBLIGHT_HUE_STEP 10
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17
#endif


#ifdef OLED_ENABLE
// settings for the oled keyboard demo with Adafruit 0.91" OLED display on the Stemma QT port
    #define OLED_DISPLAY_128X32
    #define I2C_DRIVER I2CD1
    #define I2C1_SDA_PIN GP2
    #define I2C1_SCL_PIN GP3
    #define OLED_BRIGHTNESS 180
    #define OLED_TIMEOUT 60000
//    #define OLED_FONT_H "lib/glcdfont.c"
    // #define WPM_ESTIMATED_WORD_SIZE 5
    #define SPLIT_LAYER_STATE_ENABLE
    #define SPLIT_LED_STATE_ENABLE
    #define SPLIT_MODS_ENABLE
    #define SPLIT_WPM_ENABLE
    // #define SPLIT_OLED_ENABLE              // 不要打开 打开之后副手OLED就不亮了
#endif

#ifdef RGB_MATRIX_ENABLE
    #define RGB_MATRIX_LED_COUNT          54 // Number of LEDs
    #define DRIVER_LED_TOTAL              RGBLED_NUM
    #define RGB_MATRIX_SPLIT              { 27, 27 }
    #ifdef WS2812_DI_PIN
        #undef WS2812_DI_PIN
    #endif
    #define WS2812_DI_PIN                 GP0
    #define WS2812_PIO_USE_PIO1

    #define SPLIT_TRANSPORT_MIRROR
    #define RGB_MATRIX_FRAMEBUFFER_EFFECTS
    #define RGB_MATRIX_KEYPRESSES
    #define RGB_MATRIX_SLEEP
//    #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 128
    #define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_CYCLE_LEFT_RIGHT

/* Enable the animations you want/need.  You may need to enable only a small number of these because       *
 * they take up a lot of space.  Enable and confirm that you can still successfully compile your firmware. */
// RGB Matrix Animation modes. Explicitly enabled
// For full list of effects, see:
// https://docs.qmk.fm/#/feature_rgb_matrix?id=rgb-matrix-effects
#    define ENABLE_RGB_MATRIX_ALPHAS_MODS
#    define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#    define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#    define ENABLE_RGB_MATRIX_BREATHING
#    define ENABLE_RGB_MATRIX_BAND_SAT
#    define ENABLE_RGB_MATRIX_BAND_VAL
#    define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#    define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
#    define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#    define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#    define ENABLE_RGB_MATRIX_CYCLE_ALL
#    define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#    define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#    define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#    define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
#    define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#    define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
#    define ENABLE_RGB_MATRIX_CYCLE_SPIRAL
#    define ENABLE_RGB_MATRIX_DUAL_BEACON
#    define ENABLE_RGB_MATRIX_RAINBOW_BEACON
#    define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#    define ENABLE_RGB_MATRIX_RAINDROPS
#    define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#    define ENABLE_RGB_MATRIX_HUE_BREATHING
#    define ENABLE_RGB_MATRIX_HUE_PENDULUM
#    define ENABLE_RGB_MATRIX_HUE_WAVE
#    define ENABLE_RGB_MATRIX_PIXEL_RAIN
#    define ENABLE_RGB_MATRIX_PIXEL_FLOW
#    define ENABLE_RGB_MATRIX_PIXEL_FRACTAL
// enabled only if RGB_MATRIX_FRAMEBUFFER_EFFECTS is defined
#    define ENABLE_RGB_MATRIX_TYPING_HEATMAP
#    define ENABLE_RGB_MATRIX_DIGITAL_RAIN
// enabled only of RGB_MATRIX_KEYPRESSES or RGB_MATRIX_KEYRELEASES is defined
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#    define ENABLE_RGB_MATRIX_SPLASH
#    define ENABLE_RGB_MATRIX_MULTISPLASH
#    define ENABLE_RGB_MATRIX_SOLID_SPLASH
#    define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH

#    define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#    define RGB_MATRIX_DEFAULT_HUE 34
#    define RGB_TRIGGER_ON_KEYDOWN
#endif
