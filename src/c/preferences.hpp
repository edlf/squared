#ifndef PREFERENCES_HPP
#define PREFERENCES_HPP

#include "pebble.h"
#include "utils.hpp"
#include "resources.hpp"

#define PREFERENCES_KEY 0

typedef struct {
  bool     eu_date; // true == MM/DD, false == DD/MM
  bool     quick_start;
  bool     leading_zero; // true == replaces leading Zero for hour, day, month with a "cycler"
  uint8_t  background_color;
  uint8_t  number_base_color;
  bool     number_variation;
  uint8_t  ornament_base_color;
  bool     ornament_variation;
  bool     invert;
  bool     monochrome;
  bool     center;
  bool     btvibe;
  bool     contrast;
  bool     nightsaver;
  uint8_t  ns_start;
  uint8_t  ns_stop;
  bool     backlight;
  bool     weekday;
  uint8_t  bottomrow;
  uint8_t  wristflick;
  uint16_t stepgoal;
  bool     dynamicstepgoal;
  bool     cheeky;
  bool     battery_saver;
  #ifdef PBL_COLOR
  bool     use_presets;
  uint8_t  bg_preset;
  uint8_t  number_preset;
  uint8_t  ornament_preset;
  #endif
} Preferences;

// Loads preferences from storage or inits defaults if those dont exist
void preferences_load();

// Writes settings received from app + persists them
void preferences_write(const DictionaryIterator*);

const Preferences* get_preferences();

bool preferences_backlight();
bool preferences_bt_vibe();
bool preferences_cheeky();
bool preferences_contrast();
uint32_t preferences_animation_time();

#endif // PREFERENCES_HPP
