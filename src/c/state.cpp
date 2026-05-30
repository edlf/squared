#include "state.hpp"

namespace state {

static state::state_t state_struct;

void init() {
  state_struct.splashEnded = false;
  state_struct.in_shake_mode = false;
  state_struct.chargestate = false;
  state_struct.contrastmode = false;
  state_struct.allow_animate = true;
  state_struct.initial_anim = false;
  state_struct.animation_time = 2000;

  #ifdef PBL_COLOR
  state_struct.previous_contrastmode = false;
  #endif

  #ifdef PBL_HEALTH
  state_struct.stepgoal = 0;
  state_struct.stepprogress = 0;
  state_struct.heartrate = 0;
  #endif
}

void update() {
  const Preferences* const preferences = get_preferences();

  state_struct.background_color = (GColor8) { .argb = preferences->background_color };

  #ifdef PBL_COLOR
  if (preferences->contrast == true && battery_state_service_peek().is_plugged) {
    state_struct.contrastmode = true;
    state_struct.previous_contrastmode = true;
    state_struct.background_color = GColorBlack;
  } else {
    state_struct.contrastmode = false;
    state_struct.previous_contrastmode = false;
  }

  #else
  if (preferences->invert) {
    state_struct.background_color = GColorWhite;
  } else {
    state_struct.background_color = GColorBlack;
  }
  #endif

  if (preferences->quick_start) {
    state_struct.animation_time = 1500;
  } else {
    state_struct.animation_time = 2000;
  }
}

void setAllowAnimate(const bool aa) {
  state_struct.allow_animate = aa;
}

void setInitialAnim(const bool ia) {
  state_struct.initial_anim = ia;
}

void setSplashEnded(const bool se) {
  state_struct.splashEnded = se;
}

void setInShakeMode(const bool sm) {
  state_struct.in_shake_mode = sm;
}

void setChargeState(const bool cs) {
  state_struct.chargestate = cs;
}

#ifdef PBL_COLOR
void setPreviousContrastMode(const bool pcm) {
  state_struct.previous_contrastmode = pcm;
}
#endif

const state_t& get() {
  return state_struct;
}

#ifdef PBL_HEALTH
void setHeartRate(const HealthValue hr) {
  state_struct.heartrate = hr;
}

void setStepGoal(const HealthValue stepgoal) {
  state_struct.stepgoal = stepgoal;
}

void updateStepProgress(const HealthValue stepcount) {
  uint16_t sp = (((float)stepcount/(float)state_struct.stepgoal)*100);
  if (sp > 100) {
    sp = 100;
  }
  state_struct.stepprogress = sp;
}

#endif
} // namespace state
