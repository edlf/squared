#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include "pebble.hpp"

// #define DEBUG

namespace constants {

// Screen resolution
#if defined(PBL_DISPLAY_WIDTH) && defined(PBL_DISPLAY_HEIGHT)
// 200x228 for PT2
constexpr GSize screen_size = {PBL_DISPLAY_WIDTH, PBL_DISPLAY_HEIGHT};
#else
// "Standard" Pebble resolution
constexpr GSize screen_size = {144, 168};
#endif // PBL_DISPLAY_WIDTH, PBL_DISPLAY_HEIGHT

// Drawing constants
// Base tile size
constexpr uint8_t tile_size = (screen_size.w / 14); // 14 for PT2
// Small tile size, half the size as a regular tile -1 for width compensation
constexpr uint8_t tile_size_small = (screen_size.w / 14) / 2 - 1; // 6 for PT2

// Font blocks
constexpr uint8_t font_width_blocks = 5;
constexpr uint8_t font_height_blocks = 5;
constexpr uint8_t font_total_blocks = font_width_blocks * font_height_blocks; //25

// Fonts (px)
constexpr GSize font_size = {font_width_blocks * tile_size,
                             font_height_blocks * tile_size};
constexpr GSize font_small_size = {font_width_blocks * tile_size_small,
                                   font_height_blocks * tile_size_small};

// Spacing
constexpr GSize spacing = {tile_size, tile_size};

// Calculate total size
constexpr GSize active_area = {(font_size.w + spacing.w + font_size.w),
                               (font_size.h + spacing.h + font_size.h + spacing.h + font_small_size.h)};

// Origin
#ifdef PBL_RECT
constexpr GSize origin = {(screen_size.w - active_area.w) / 2,
                          (screen_size.h - active_area.h) / 2};
#else
// TODO: Fix new bigger round
constexpr GSize origin = {(screen_size.w - active_area.w) / 2,
                          static_cast<int16_t>(tile_size * 2.2)};
#endif // PBL_RECT

constexpr uint8_t num_slots_main = 4;
constexpr GRect frames_main_digits[num_slots_main] = {
  {
    origin.w,
    origin.h,
    font_size.w,
    font_size.h
  }, {
    origin.w + font_size.w + spacing.w,
    origin.h,
    font_size.w,
    font_size.h
  }, {
    origin.w,
    origin.h + font_size.h + spacing.h,
    font_size.w,
    font_size.h
  }, {
    origin.w + font_size.w + spacing.w,
    origin.h + font_size.h + spacing.h,
    font_size.w,
    font_size.h
  }
};

#ifdef PBL_ROUND
constexpr uint8_t num_slots_top_filler = 2;
constexpr GRect frames_round_top_filler[num_slots_top_filler] = {
  {
    origin.w,
    origin.h - font_size.h - spacing.h,
    font_size.w,
    font_size.h
  },{
    origin.w + font_size.w + spacing.w,
    origin.h - font_size.h - spacing.h,
    font_size.w,
    font_size.h
  }
};

constexpr uint8_t num_slots_side_filler = 4;
constexpr GRect frames_round_sides_filler[num_slots_side_filler] = {
  {
    origin.w - font_size.w - spacing.w,
    origin.h,
    font_size.w,
    font_size.h
  },{
    origin.w + font_size.w + spacing.w + font_size.w + spacing.w,
    origin.h,
    font_size.w,
    font_size.h
  },{
    origin.w - font_size.w - spacing.w,
    origin.h + font_size.h + spacing.h,
    font_size.w,
    font_size.h
  },{
    origin.w + font_size.w + spacing.w + font_size.w + spacing.w,
    origin.h + font_size.h + spacing.h,
    font_size.w,
    font_size.h
  }
};

constexpr uint8_t num_slots_bottom_filler = 2;
constexpr GRect frames_round_bottom_filler[num_slots_bottom_filler] = {
  {
    origin.w,
    origin.h + (font_size.h + spacing.h) * 2,
    font_size.w,
    font_size.h
  },{
    origin.w + font_size.w + spacing.w,
    origin.h + (font_size.h + spacing.h) * 2,
    font_size.w,
    font_size.h
  }
};

constexpr uint8_t num_slots = num_slots_main + num_slots_top_filler + num_slots_side_filler + num_slots_bottom_filler;
#else
// Only square(ish) Pebbles get secondary slots
constexpr uint8_t num_slots_secondary = 4;
constexpr GRect frames_secondary_digits[num_slots_secondary] = {
  {
    origin.w + (font_size.w + spacing.w) * (0 / 2),
    origin.h + (font_size.h + spacing.h) * 2,
    font_small_size.w,
    font_small_size.h
  }, {
    origin.w + (font_size.w + spacing.w) * (1 / 2) + (font_size.w - font_small_size.w),
    origin.h + (font_size.h + spacing.h) * 2,
    font_small_size.w,
    font_small_size.h
  }, {
    origin.w + (font_size.w + spacing.w) * (2 / 2),
    origin.h + (font_size.h + spacing.h) * 2,
    font_small_size.w,
    font_small_size.h
  }, {
    origin.w + (font_size.w + spacing.w) * (3 / 2) + (font_size.w - font_small_size.w),
    origin.h + (font_size.h + spacing.h) * 2,
    font_small_size.w,
    font_small_size.h
  }
};

constexpr uint8_t num_slots = num_slots_main + num_slots_secondary;
#endif // PBL_ROUND

} // namespace constants

#endif // CONSTANTS_HPP