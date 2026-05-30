#include "resources.hpp"

uint8_t fetch_rect(const uint8_t digit, const uint8_t x, const uint8_t y, const bool mirror) {
  // character_map maps 0-9 (digits), 10-13 (ornaments), ascii codes of uppercase letters and 100-109 (progress) to characters[]
  uint8_t color1 = characters[character_map[digit]][(y*2)]; // get one row of digit colors
  uint8_t color2 = characters[character_map[digit]][(y*2)+1]; // get one row of ornament colors
  uint8_t mask = 0b10000 >> x;

  if (mirror) {
    mask = 0b00001 << x;
  }

  if (color1 & mask) { // check column of row
    return 1;
  } else if (color2 & mask) {
    return 2;
  } else {
    return 0;
  }
}
