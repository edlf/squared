#include "state.h"

// Drawing constants
// Base tile size
const uint8_t tile_size = (SCREEN_SIZE_X / 14); // 14 for PT2
// Small tile size, half the size as a regular tile -1 for width compensation
const uint8_t tile_size_small = (SCREEN_SIZE_X / 14) / 2 - 1; // 6 for PT2

// Font blocks
const uint8_t font_width_blocks = 5;
const uint8_t font_height_blocks = 5;
const uint8_t font_total_blocks = font_width_blocks * font_height_blocks; //25

const uint8_t font_width = font_width_blocks * tile_size; // 70
const uint8_t font_height = font_height_blocks * tile_size;

const uint8_t font_width_small = font_width_blocks * tile_size_small; // 30
const uint8_t font_height_small = font_height_blocks * tile_size_small;

// Spacing
const uint8_t spacing_x = tile_size;
const uint8_t spacing_y = tile_size;

// Calculate total size
const uint8_t active_area_x = font_width + spacing_x + font_width;
const uint8_t active_area_y = font_height + spacing_y + font_height + spacing_y + font_height_small;


void state_init(State *state) {
  #ifdef PBL_RECT
  state->origin_x = (SCREEN_SIZE_X - active_area_x) / 2;
  state->origin_y = (SCREEN_SIZE_Y - active_area_y) / 2;
  #else
  // TODO: Fix new bigger round
  state->origin_x = (180 - active_area_x) / 2;
  state->origin_y = tile_size * 2.2;
  #endif

  state->splashEnded = false;
  state->in_shake_mode = false;
  state->chargestate = false;
  state->contrastmode = false;
  state->allow_animate = true;
  state->initial_anim = false;
  state->animation_time = 2000;

  #ifdef PBL_COLOR
  state->previous_contrastmode = false;
  #endif

  #ifdef PBL_HEALTH
  state->stepgoal = 0;
  state->stepprogress = 0;
  state->heartrate = 0;
  #endif
}

void state_update(State* state, const Preferences* const preferences) {
  state->background_color = (GColor8) { .argb = preferences->background_color };

  #ifdef PBL_COLOR
  if (preferences->contrast == true && battery_state_service_peek().is_plugged) {
    state->contrastmode = true;
    state->previous_contrastmode = true;
    state->background_color = GColorBlack;
  } else {
    state->contrastmode = false;
    state->previous_contrastmode = false;
  }

  #else
  if (preferences->invert) {
    state->background_color = GColorWhite;
  } else {
    state->background_color = GColorBlack;
  }
  #endif

  if (preferences->quick_start) {
    state->animation_time = 1500;
  } else {
    state->animation_time = 2000;
  }
}
