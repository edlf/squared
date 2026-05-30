#include "squared_slots.hpp"

namespace slots {

static GRect frame_main_digits(const int8_t i) {
  int16_t x, y;

  if (i % 2) {
    x = constants::origin.w + constants::font_size.w + constants::spacing.w; // i = 1 or 3
  } else {
    x = constants::origin.w; // i = 0 or 2
  }

  if (i < 2) {
    y = constants::origin.h;
  } else {
    y = constants::origin.h + constants::font_size.h + constants::spacing.h;
  }

  return GRect(x, y, constants::font_size.w, constants::font_size.h);
}

static GRect frame_date_digits(const int8_t i) {
  const int16_t digit = i - 4;
  int16_t x, y;

  x = constants::origin.w + (constants::font_size.w + constants::spacing.w) * (digit / 2);

  if (digit % 2) {
    x += (constants::font_size.w - constants::font_small_size.w);
  }

  y = constants::origin.h + (constants::font_size.h + constants::spacing.h) * 2;

  return GRect(x, y, constants::font_small_size.w, constants::font_small_size.h);
}

static GRect frame_round_top_filler(const int8_t i) {
  int16_t x, y;
  if (i % 2) {
    x = constants::origin.w + constants::font_size.w + constants::spacing.w; // i = 1 or 3
  } else {
    x = constants::origin.w; // i = 0 or 2
  }

  y = constants::origin.h - constants::font_size.h - constants::spacing.h;

  return GRect(x, y, constants::font_size.w, constants::font_size.h);
}

static GRect frame_round_side_filler(const int8_t i) {
  int16_t x, y;

  if (i % 2) {
    x = constants::origin.w + constants::font_size.w + constants::spacing.w + constants::font_size.w + constants::spacing.w;
  } else {
    x = constants::origin.w - constants::font_size.w - constants::spacing.w;
  }

  if (i < 12) {
    y = constants::origin.h;
  } else {
    y = constants::origin.h + constants::font_size.h + constants::spacing.h;
  }

  return GRect(x, y, constants::font_size.w, constants::font_size.h);
}

static GRect frame_round_bottom_filler(const int8_t i) {
  int16_t x, y, h;
  h = constants::font_small_size.h;
  x = constants::origin.w + (constants::font_size.w + constants::spacing.w) * (i - 13) / 2; // 13 = 14-1 (skipping invisible slot outside circle)
  y = constants::origin.h + (constants::font_size.h + constants::spacing.h) * 2 + h + (h/6);
  return GRect(x, y, constants::font_small_size.w, h);
}

static GRect frame_round_bottom_side_filler(const int8_t i) {
  int16_t x, y;

  if (i % 2) {
    x = constants::origin.w + constants::font_size.w + constants::spacing.w + constants::font_size.w + constants::spacing.w;
  } else {
    x = constants::origin.w - constants::font_small_size.h - constants::spacing.w/2; // todo: find correct value
  }

  y = constants::origin.h + (constants::font_size.h + constants::spacing.h) * 2;
  return GRect(x, y, constants::font_small_size.w, constants::font_small_size.h);
}

GRect frame(const int8_t slot_no) {
  if (slot_no < 4) { // main digits
    return frame_main_digits(slot_no);
  } else if (slot_no < 8) { // date digits
    return frame_date_digits(slot_no);
  } else if (slot_no < 10) { // top filler for round
    return frame_round_top_filler(slot_no);
  } else if (slot_no < 14) { // side filler for round
    return frame_round_side_filler(slot_no);
  } else if (slot_no < 16) { // bottom filler for round
    return frame_round_bottom_filler(slot_no);
  } else { // bottom side filler for round
    return frame_round_bottom_side_filler(slot_no);
  }
}

} //namespace slots
