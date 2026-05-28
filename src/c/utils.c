#include <pebble.h>
#include "utils.h"

uint8_t get_GColor8FromInt32(const int32_t color) {
  const uint8_t a = 192;
  const uint8_t r = (((color >> 16) & 0xFF) >> 6) << 4;
  const uint8_t g = (((color >>  8) & 0xFF) >> 6) << 2;
  const uint8_t b = (((color >>  0) & 0xFF) >> 6) << 0;
  return a+r+g+b;
}

uint8_t get_display_hour(const uint8_t hour) {
    if (clock_is_24h_style()) {
        return hour;
    }

    uint8_t display_hour = hour % 12;

    return display_hour ? display_hour : 12;
}
