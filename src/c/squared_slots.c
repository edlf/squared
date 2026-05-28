#include "squared_slots.h"

static GRect slot_frame_main_digits(const int8_t i, const int8_t origin_x, const int8_t origin_y) {
  int16_t x, y;

  if (i % 2) {
    x = origin_x + font_width + spacing_x; // i = 1 or 3
  } else {
    x = origin_x; // i = 0 or 2
  }

  if (i < 2) {
    y = origin_y;
  } else {
    y = origin_y + font_height + spacing_y;
  }

  return GRect(x, y, font_width, font_height);
}

static GRect slot_frame_date_digits(const int8_t i, const int8_t origin_x, const int8_t origin_y) {
  const int8_t digit = i - 4;
  int16_t x, y;

  x = origin_x + (font_width + spacing_x) * (digit / 2);

  if (digit % 2) {
    x += (font_width - font_width_small); // font_width_small is wrong somehow
  }

  y = origin_y + (font_height + spacing_y) * 2;

  return GRect(x, y, font_width_small, font_height_small);
}

static GRect slot_frame_round_top_filler(const int8_t i, const int8_t origin_x, const int8_t origin_y) {

  int8_t x;
  if (i % 2) {
    x = origin_x + font_width + spacing_x; // i = 1 or 3
  } else {
    x = origin_x; // i = 0 or 2
  }

  return GRect(x, origin_y - font_height - spacing_y, font_width, font_height);
}

static GRect slot_frame_round_side_filler(const int8_t i, const int8_t origin_x, const int8_t origin_y) {
  int8_t x, y;

  if (i % 2) {
    x = origin_x + font_width + spacing_x + font_width + spacing_x;
  } else {
    x = origin_x - font_width - spacing_x;
  }

  if (i < 12) {
    y = origin_y;
  } else {
    y = origin_y + font_height + spacing_y;
  }

  return GRect(x, y, font_width, font_height);
}

static GRect slot_frame_round_bottom_filler(const int8_t i, const int8_t origin_x, const int8_t origin_y) {
  int16_t x, y, h;
  h = font_height_small;
  x = origin_x + (font_width + spacing_x) * (i - 13) / 2; // 13 = 14-1 (skipping invisible slot outside circle)
  y = origin_y + (font_height + spacing_y) * 2 + h + (h/6);
  return GRect(x, y, font_width_small, h);
}

static GRect slot_frame_round_bottom_side_filler(const int8_t i, const int8_t origin_x, const int8_t origin_y) {
  int16_t x, y, w;
  w = font_height_small;

  if (i % 2) {
    x = origin_x + font_width + spacing_x + font_width + spacing_x;
  } else {
    x = origin_x - w - spacing_x/2; // todo: find correct value
  }

  y = origin_y + (font_height + spacing_y) * 2;
  return GRect(x, y, font_width_small, w);
}

GRect slot_frame(const int8_t i, const State * const state) {
  if (i < 4) { // main digits
    return slot_frame_main_digits(i, state->origin_x, state->origin_y);
  } else if (i < 8) { // date digits
    return slot_frame_date_digits(i, state->origin_x, state->origin_y);
  } else if (i < 10) { // top filler for round
    return slot_frame_round_top_filler(i, state->origin_x, state->origin_y);
  } else if (i < 14) { // side filler for round
    return slot_frame_round_side_filler(i, state->origin_x, state->origin_y);
  } else if (i < 16) { // bottom filler for round
    return slot_frame_round_bottom_filler(i, state->origin_x, state->origin_y);
  } else { // bottom side filler for round
    return slot_frame_round_bottom_side_filler(i, state->origin_x, state->origin_y);
  }
}
