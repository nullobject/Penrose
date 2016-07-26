#include "ui.h"

namespace penrose {
  void Ui::init() {
    col_1.set_mode(DIGITAL_OUTPUT);
    col_2.set_mode(DIGITAL_OUTPUT);
    col_3.set_mode(DIGITAL_OUTPUT);
    col_4.set_mode(DIGITAL_OUTPUT);

    row_1.set_mode(DIGITAL_INPUT);
    row_2.set_mode(DIGITAL_INPUT);
    row_1.High();
    row_2.High();
  }

  void Ui::poll() {
    pollButton(currentButton++);

    if (currentButton >= kNumButtons) {
      currentButton = 0;
    }
  }

  void Ui::pollButton(uint8_t n) {
    // uint8_t row = n / 4;
    // uint8_t col = n % 4;

    col_1.High();
    col_2.High();
    col_3.High();
    col_4.High();

    row_1.value();
  }

  void Ui::setLedState(uint8_t n, LedState state) {
    ledStates[n] = state;
  }
}
