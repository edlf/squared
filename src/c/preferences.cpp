#include "pebble.hpp"
#include "preferences.hpp"

static Preferences prefs;

static void preferences_set_defaults(){
   prefs.eu_date = true;
   prefs.quick_start = false;
   prefs.leading_zero = false;
   prefs.background_color = GColorBlackARGB8;
   prefs.number_base_color = GColorTiffanyBlueARGB8;
   prefs.number_variation = true;
   prefs.ornament_base_color = GColorPurpleARGB8;
   prefs.ornament_variation = true;
   prefs.invert = false;
   prefs.monochrome = true;
   prefs.center = false;
   prefs.btvibe = false;
   prefs.contrast = false;
   prefs.nightsaver = false;
   prefs.ns_start = 0;
   prefs.ns_stop = 6;
   prefs.backlight = false;
   prefs.weekday = false;
   prefs.bottomrow = 0;
   prefs.wristflick = 0;
   prefs.stepgoal = 10000;
   prefs.dynamicstepgoal = false;
   prefs.cheeky = true;
   prefs.battery_saver = false;
   #ifdef PBL_COLOR
   prefs.use_presets = true;
   prefs.bg_preset = 0;
   prefs.number_preset = 1;
   prefs.ornament_preset = 2;
   #endif
}

static void preferences_load_dict(const DictionaryIterator *iter) {
  Tuple *eu_date_t = dict_find(iter, MESSAGE_KEY_euDate);
  Tuple *quick_start_t = dict_find(iter, MESSAGE_KEY_quickStart);
  Tuple *leading_zero_t = dict_find(iter, MESSAGE_KEY_leadingZero);
  Tuple *background_color_t = dict_find(iter, MESSAGE_KEY_backgroundColor);
  Tuple *number_base_color_t = dict_find(iter, MESSAGE_KEY_numberBaseColor);
  Tuple *number_variation_t = dict_find(iter, MESSAGE_KEY_numberVariation);
  Tuple *ornament_base_color_t = dict_find(iter, MESSAGE_KEY_ornamentBaseColor);
  Tuple *ornament_variation_t = dict_find(iter, MESSAGE_KEY_ornamentVariation);
  Tuple *invert_t = dict_find(iter, MESSAGE_KEY_invert);
  Tuple *monochrome_t = dict_find(iter, MESSAGE_KEY_monochrome);
  Tuple *center_t = dict_find(iter, MESSAGE_KEY_center);
  Tuple *btvibe_t = dict_find(iter, MESSAGE_KEY_btVibe);
  Tuple *contrast_t = dict_find(iter, MESSAGE_KEY_contrast);
  Tuple *nightsaver_t = dict_find(iter, MESSAGE_KEY_nightSaver);
  Tuple *ns_start_t = dict_find(iter, MESSAGE_KEY_nsStart);
  Tuple *ns_stop_t = dict_find(iter, MESSAGE_KEY_nsStop);
  Tuple *backlight_t = dict_find(iter, MESSAGE_KEY_backlight);
  Tuple *weekday_t = dict_find(iter, MESSAGE_KEY_weekday);
  Tuple *bottomrow_t = dict_find(iter, MESSAGE_KEY_bottomRow);
  Tuple *wristflick_t = dict_find(iter, MESSAGE_KEY_wristFlick);
  Tuple *stepgoal_t = dict_find(iter, MESSAGE_KEY_stepGoal);
  Tuple *dynamicstepgoal_t = dict_find(iter, MESSAGE_KEY_cheeky);
  Tuple *cheeky_t = dict_find(iter, MESSAGE_KEY_dynamicStepGoal);
  Tuple *battery_saver_t = dict_find(iter, MESSAGE_KEY_batterySaver);
  #ifdef PBL_COLOR
  Tuple *use_presets_t = dict_find(iter, MESSAGE_KEY_usePresets);
  Tuple *background_preset_t = dict_find(iter, MESSAGE_KEY_backgroundPreset);
  Tuple *number_preset_t = dict_find(iter, MESSAGE_KEY_numbersPreset);
  Tuple *ornament_preset_t = dict_find(iter, MESSAGE_KEY_ornamentsPreset);
  #endif

  if (eu_date_t) {             prefs.eu_date =                eu_date_t->value->int8; }
  if (quick_start_t) {         prefs.quick_start =            quick_start_t->value->int8; }
  if (leading_zero_t) {        prefs.leading_zero =           leading_zero_t->value->int8; }
  if (background_color_t) {    prefs.background_color =       get_GColor8FromInt32(background_color_t->value->int32); }
  if (number_base_color_t) {   prefs.number_base_color =      get_GColor8FromInt32(number_base_color_t->value->int32); }
  if (number_variation_t) {    prefs.number_variation =       number_variation_t->value->int8; }
  if (ornament_base_color_t) { prefs.ornament_base_color =    get_GColor8FromInt32(ornament_base_color_t->value->int32); }
  if (ornament_variation_t) {  prefs.ornament_variation =     ornament_variation_t->value->int8; }
  if (invert_t) {              prefs.invert =                 invert_t->value->int8; }
  if (monochrome_t) {          prefs.monochrome =             monochrome_t->value->int8; }
  if (center_t) {              prefs.center =                 center_t->value->int8; }
  if (btvibe_t) {              prefs.btvibe =                 btvibe_t->value->int8; }
  if (contrast_t) {            prefs.contrast =               contrast_t->value->int8; }
  if (nightsaver_t) {          prefs.nightsaver =             nightsaver_t->value->int8; }
  if (ns_start_t) {            prefs.ns_start =               atoi(ns_start_t->value->cstring); }
  if (ns_stop_t) {             prefs.ns_stop =                atoi(ns_stop_t->value->cstring); }
  if (backlight_t) {           prefs.backlight =              backlight_t->value->int8; }
  if (weekday_t) {             prefs.weekday =                weekday_t->value->int8; }
  if (bottomrow_t) {           prefs.bottomrow =              atoi(bottomrow_t->value->cstring); }
  if (wristflick_t) {          prefs.wristflick =             atoi(wristflick_t->value->cstring); }
  if (stepgoal_t) {            prefs.stepgoal =               atoi(stepgoal_t->value->cstring); }
  if (dynamicstepgoal_t) {     prefs.dynamicstepgoal =        dynamicstepgoal_t->value->int8; }
  if (cheeky_t) {              prefs.cheeky =                 cheeky_t->value->int8; }
  if (battery_saver_t) {       prefs.battery_saver =          battery_saver_t->value->int8; }

  #ifdef PBL_COLOR
  if (use_presets_t) {         prefs.use_presets =            use_presets_t->value->int8; }
  if (background_preset_t) {   prefs.bg_preset =              atoi(background_preset_t->value->cstring); }
  if (number_preset_t) {       prefs.number_preset =          atoi(number_preset_t->value->cstring); }
  if (ornament_preset_t) {     prefs.ornament_preset =        atoi(ornament_preset_t->value->cstring); }

  // If using presets replace colors
  if (prefs.use_presets) {
    if (prefs.bg_preset < NUMBER_OF_BG_PRESETS) {
      prefs.background_color = background_color_presets[prefs.bg_preset];
    }

    if (prefs.number_preset < NUMBER_OF_CHAR_PRESETS) {
      prefs.number_base_color = character_base_color_presets[prefs.number_preset];
      prefs.number_variation = character_variation_presets[prefs.number_preset];
    }

    if (prefs.ornament_preset < NUMBER_OF_CHAR_PRESETS) {
      prefs.ornament_base_color = character_base_color_presets[prefs.ornament_preset];
      prefs.ornament_variation = character_variation_presets[prefs.ornament_preset];
    }
  }
  #endif
}

const Preferences* get_preferences() {
  return &prefs;
}

void preferences_load() {
  if(persist_exists(PREFERENCES_KEY)){
    persist_read_data(PREFERENCES_KEY, &prefs, sizeof(prefs));
  } else {
    preferences_set_defaults();
  }
}

void preferences_write(const DictionaryIterator *iter) {
  preferences_load_dict(iter);
  persist_write_data(PREFERENCES_KEY, &prefs, sizeof(prefs));
}

bool preferences_backlight() {
  return prefs.backlight;
}

bool preferences_bt_vibe() {
  return prefs.btvibe;
}

bool preferences_cheeky() {
  return prefs.cheeky;
}

bool preferences_contrast() {
  return prefs.contrast;
}

uint32_t preferences_animation_time() {
  // TODO add custom animation time
  if (prefs.quick_start) {
    return 700;
  } else {
    return 2000;
  }
}