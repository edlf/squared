#ifndef STATE_H
#define STATE_H

#include <pebble.h>
#include "preferences.h"

#ifdef PBL_ROUND
#define NUM_SLOTS 18
#else
#define NUM_SLOTS 8
#endif

#ifdef PBL_DISPLAY_WIDTH
// 200x228 for PT2
#define SCREEN_SIZE_X PBL_DISPLAY_WIDTH
#define SCREEN_SIZE_Y PBL_DISPLAY_HEIGHT
#else
// "Standard" Pebble resolution
#define SCREEN_SIZE_X 144
#define SCREEN_SIZE_Y 168
#endif

// Constants
// Base tile size
extern const uint8_t tile_size;
extern const uint8_t tile_size_small;

// Font blocks
extern const uint8_t font_width_blocks;
extern const uint8_t font_height_blocks;
extern const uint8_t font_total_blocks;

extern const uint8_t font_width;
extern const uint8_t font_height;

extern const uint8_t font_width_small;
extern const uint8_t font_height_small;

// Spacing
extern const uint8_t spacing_x;
extern const uint8_t spacing_y;

// Calculate total size
extern const uint8_t tiles_x;
extern const uint8_t tiles_y;

typedef struct {
  uint8_t origin_x;
  uint8_t origin_y;

  bool splashEnded;
  bool in_shake_mode;
  bool chargestate;
  bool contrastmode;
  bool allow_animate;
  bool initial_anim;

  GColor8 background_color;
  uint16_t animation_time;

  #ifdef PBL_COLOR
  bool previous_contrastmode;
  #endif

  #ifdef PBL_HEALTH
  uint16_t stepgoal;
  uint16_t stepprogress;
  uint8_t heartrate;
  #endif
} State;

void state_init(State*);
void state_update(State*, Preferences*);

typedef struct {
  Layer            *layer;
  bool              mirror;
  uint8_t           prevDigit;
  uint8_t           curDigit;
  uint8_t           sizeType;
  AnimationProgress normTime;
  uint8_t           slotIndex;
} digitSlot;

#endif
