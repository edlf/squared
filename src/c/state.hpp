#ifndef STATE_H
#define STATE_H

#include "pebble.hpp"
#include "constants.hpp"
#include "preferences.hpp"

namespace state {

typedef struct {
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
} state_t;

void init(state_t*);
void update(state_t*);
} // namespace state

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
