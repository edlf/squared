#include "state.hpp"

namespace state {

void init(state_t *state) {
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

void update(state_t* state) {
  const Preferences* const preferences = get_preferences();

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

} // namespace state
