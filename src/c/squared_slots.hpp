#ifndef SQUARED_SLOTS_H
#define SQUARED_SLOTS_H

#include "pebble.h"
#include "state.hpp"

namespace slots {

typedef struct {
  Layer            *layer;
  bool              mirror;
  uint8_t           prevDigit;
  uint8_t           curDigit;
  uint8_t           sizeType;
  AnimationProgress normTime;
  uint8_t           slotIndex;
} digit;

GRect frame(const int8_t slot_no);
};

#endif // SQUARED_SLOTS_H
