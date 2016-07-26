#include "ui.h"

namespace penrose {
  void Ui::init() {
  }

  void Ui::setLedState(uint8_t n, LedState ledState) {
    ledStates[n] = ledState;
  }
}
