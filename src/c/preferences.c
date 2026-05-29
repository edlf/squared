#include "preferences.h"

void preferences_set_defaults(Preferences *preferences){
   preferences->eu_date = true;
   preferences->quick_start = false;
   preferences->leading_zero = false;
   preferences->background_color = GColorBlackARGB8;
   preferences->number_base_color = GColorTiffanyBlueARGB8;
   preferences->number_variation = true;
   preferences->ornament_base_color = GColorPurpleARGB8;
   preferences->ornament_variation = true;
   preferences->invert = false;
   preferences->monochrome = true;
   preferences->center = false;
   preferences->btvibe = false;
   preferences->contrast = false;
   preferences->nightsaver = false;
   preferences->ns_start = 0;
   preferences->ns_stop = 6;
   preferences->backlight = false;
   preferences->weekday = false;
   preferences->bottomrow = 0;
   preferences->wristflick = 0;
   preferences->stepgoal = 10000;
   preferences->dynamicstepgoal = false;
   preferences->cheeky = true;
   preferences->battery_saver = false;
   #ifdef PBL_COLOR
   preferences->use_presets = true;
   preferences->bg_preset = 0;
   preferences->number_preset = 1;
   preferences->ornament_preset = 2;
   #endif
}

void preferences_load(DictionaryIterator *iter, Preferences *preferences) {
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

  if (eu_date_t) {             preferences->eu_date =                eu_date_t->value->int8; }
  if (quick_start_t) {         preferences->quick_start =            quick_start_t->value->int8; }
  if (leading_zero_t) {        preferences->leading_zero =           leading_zero_t->value->int8; }
  if (background_color_t) {    preferences->background_color =       get_GColor8FromInt32(background_color_t->value->int32); }
  if (number_base_color_t) {   preferences->number_base_color =      get_GColor8FromInt32(number_base_color_t->value->int32); }
  if (number_variation_t) {    preferences->number_variation =       number_variation_t->value->int8; }
  if (ornament_base_color_t) { preferences->ornament_base_color =    get_GColor8FromInt32(ornament_base_color_t->value->int32); }
  if (ornament_variation_t) {  preferences->ornament_variation =     ornament_variation_t->value->int8; }
  if (invert_t) {              preferences->invert =                 invert_t->value->int8; }
  if (monochrome_t) {          preferences->monochrome =             monochrome_t->value->int8; }
  if (center_t) {              preferences->center =                 center_t->value->int8; }
  if (btvibe_t) {              preferences->btvibe =                 btvibe_t->value->int8; }
  if (contrast_t) {            preferences->contrast =               contrast_t->value->int8; }
  if (nightsaver_t) {          preferences->nightsaver =             nightsaver_t->value->int8; }
  if (ns_start_t) {            preferences->ns_start =               atoi(ns_start_t->value->cstring); }
  if (ns_stop_t) {             preferences->ns_stop =                atoi(ns_stop_t->value->cstring); }
  if (backlight_t) {           preferences->backlight =              backlight_t->value->int8; }
  if (weekday_t) {             preferences->weekday =                weekday_t->value->int8; }
  if (bottomrow_t) {           preferences->bottomrow =              atoi(bottomrow_t->value->cstring); }
  if (wristflick_t) {          preferences->wristflick =             atoi(wristflick_t->value->cstring); }
  if (stepgoal_t) {            preferences->stepgoal =               atoi(stepgoal_t->value->cstring); }
  if (dynamicstepgoal_t) {     preferences->dynamicstepgoal =        dynamicstepgoal_t->value->int8; }
  if (cheeky_t) {              preferences->cheeky =                 cheeky_t->value->int8; }
  if (battery_saver_t) {       preferences->battery_saver =          battery_saver_t->value->int8; }

  #ifdef PBL_COLOR
  if (use_presets_t) {         preferences->use_presets =            use_presets_t->value->int8; }
  if (background_preset_t) {   preferences->bg_preset =              atoi(background_preset_t->value->cstring); }
  if (number_preset_t) {       preferences->number_preset =          atoi(number_preset_t->value->cstring); }
  if (ornament_preset_t) {     preferences->ornament_preset =        atoi(ornament_preset_t->value->cstring); }

  // If using presets replace colors
  if (preferences->use_presets) {
    if (preferences->bg_preset < NUMBER_OF_BG_PRESETS) {
      preferences->background_color = background_color_presets[preferences->bg_preset];
    }

    if (preferences->number_preset < NUMBER_OF_CHAR_PRESETS) {
      preferences->number_base_color = character_base_color_presets[preferences->number_preset];
      preferences->number_variation = character_variation_presets[preferences->number_preset];
    }

    if (preferences->ornament_preset < NUMBER_OF_CHAR_PRESETS) {
      preferences->ornament_base_color = character_base_color_presets[preferences->ornament_preset];
      preferences->ornament_variation = character_variation_presets[preferences->ornament_preset];
    }
  }
  #endif
}
