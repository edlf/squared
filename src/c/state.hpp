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
  #endif // PBL_COLOR

  #ifdef PBL_HEALTH
  HealthValue stepgoal;
  uint16_t stepprogress;
  HealthValue heartrate;
  #endif // PBL_HEALTH
} state_t;

void init(void);
void update(void);

void setAllowAnimate(const bool);
void setInitialAnim(const bool);
void setSplashEnded(const bool);
void setInShakeMode(const bool);
void setChargeState(const bool);
#ifdef PBL_COLOR
void setPreviousContrastMode(const bool);
#endif // PBL_COLOR

const state_t& get(void);

#ifdef PBL_HEALTH
void setHeartRate(const HealthValue);
void setStepGoal(const HealthValue);
void updateStepProgress(const HealthValue);
#endif // PBL_HEALTH
} // namespace state

#endif // STATE_H
