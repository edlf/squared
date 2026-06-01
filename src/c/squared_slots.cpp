#include "squared_slots.hpp"

namespace slots {

#ifdef PBL_ROUND
GRect frame(const int8_t slot_no) {
  if (slot_no < constants::num_slots_main) { // main digits
    return constants::frames_main_digits[slot_no];

  } else if (slot_no < (constants::num_slots_main + constants::num_slots_top_filler)) { // top filler for round
    const uint8_t digit = slot_no - constants::num_slots_main;
    return constants::frames_round_top_filler[digit];

  } else if (slot_no < (constants::num_slots_main + constants::num_slots_top_filler + constants::num_slots_side_filler)) { // side filler for round
    const uint8_t digit = slot_no - constants::num_slots_main - constants::num_slots_top_filler;
    return constants::frames_round_sides_filler[digit];

  } else { // bottom filler for round
    const uint8_t digit = slot_no - constants::num_slots_main - constants::num_slots_top_filler - constants::num_slots_side_filler;
    return constants::frames_round_bottom_filler[digit];
  }
}
#else
GRect frame(const int8_t slot_no) {
  if (slot_no < constants::num_slots_main) { // main digits
    return constants::frames_main_digits[slot_no];

  } else { // date digits
    const uint8_t digit = slot_no - constants::num_slots_main;
    return constants::frames_secondary_digits[digit];
  };
}
#endif

} //namespace slots
