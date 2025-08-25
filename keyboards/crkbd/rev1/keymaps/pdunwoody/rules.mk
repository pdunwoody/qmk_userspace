# Build Options
#   change yes to no to disable
#
#MCU = RP2040
#BOOTLOADER = rp2040
# CONVERT_TO = promicro_rp2040

BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = yes           # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output
CAPS_WORD_ENABLE = yes

SPLIT_KEYBOARD = yes
SERIAL_DRIVER = vendor

RGB_MATRIX_SUPPORTED = yes
RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = ws2812
WS2812_DRIVER = vendor

OLED_ENABLE     = yes
OLED_DRIVER     = ssd1306
WPM_ENABLE      = yes

LTO_ENABLE          =  yes      # ?????

LAYOUTS = split_3x6_3
