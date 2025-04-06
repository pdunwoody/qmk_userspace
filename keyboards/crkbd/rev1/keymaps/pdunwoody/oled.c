#include <stdio.h>

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

enum layers { BASE, NUM, SYM, FUN, NAV, MEDIA, MOUSE, EXTRA };

void oled_render_layer_state(void) {
  oled_write("Layer: ", false);

  switch (get_highest_layer(layer_state)) {
  case BASE:
    oled_write("Base", false);
    break;
  case EXTRA:
    oled_write("Extra", false);
    break;
  case NAV:
    oled_write("Navigation", false);
    break;
  case MOUSE:
    oled_write("Mouse", false);
    break;
  case MEDIA:
    oled_write("Media", false);
    break;
  case NUM:
    oled_write("Number", false);
    break;
  case SYM:
    oled_write("Symbol", false);
    break;
  case FUN:
    oled_write("Function", false);
    break;
  }

  oled_write("\n", false);
}

void oled_render_led_state(void) {
  led_t led_state = host_keyboard_led_state();

  oled_write(led_state.caps_lock ? "CAPS " : "      ", false);
  oled_write(led_state.scroll_lock ? "SCROLL " : "       ", false);
  oled_write("\n", false);
}

void oled_render_mod_state(void) {
  uint8_t mod_state = get_mods();

  oled_write((mod_state & MOD_MASK_SHIFT) ? "SHIFT " : "      ", false);
  oled_write((mod_state & MOD_MASK_CTRL) ? "CTRL " : "     ", false);
  oled_write((mod_state & MOD_MASK_ALT) ? "ALT " : "    ", false);
  oled_write((mod_state & MOD_MASK_GUI) ? "GUI" : "   ", false);
  oled_write("\n", false);
}

void oled_render_logo(void) {
  static const char PROGMEM crkbd_logo[] = {
    0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
    0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
    0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
    0};
  oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    oled_render_layer_state();
    oled_render_mod_state();
    oled_render_led_state();
  } else {
    oled_render_logo();
  }
  return false;
}
