#include "ui.h"

// An array of LED pin pairs to charlieplex the LED matrix.
static const uint8_t charlieplex[][2] = {
  {1, 2}, {1, 3}, {1, 4},
  {2, 3}, {2, 4}, {2, 5},
  {3, 4}, {3, 5}, {3, 6},
  {4, 5}, {4, 6},
  {5, 6}
};

void Ui::init() {
  col_1.set_mode(DIGITAL_OUTPUT);
  col_2.set_mode(DIGITAL_OUTPUT);
  col_3.set_mode(DIGITAL_OUTPUT);
  col_4.set_mode(DIGITAL_OUTPUT);

  col_1.High();
  col_2.High();
  col_3.High();
  col_4.High();

  row_1.set_mode(DIGITAL_INPUT);
  row_2.set_mode(DIGITAL_INPUT);

  row_1.High();
  row_2.High();

  turnLedsOff();
}

void Ui::poll() {
  pollButton(currentButton);
  refreshLed(currentButton);

  if (++currentButton >= kNumButtons) {
    currentButton = 0;
  }
}

void Ui::setColumn(uint8_t n) {
  if (n == 0) {
    col_1.Low();
    col_2.High();
    col_3.High();
    col_4.High();
  } else if (n == 1) {
    col_1.High();
    col_2.Low();
    col_3.High();
    col_4.High();
  } else if (n == 2) {
    col_1.High();
    col_2.High();
    col_3.Low();
    col_4.High();
  } else if (n == 3) {
    col_1.High();
    col_2.High();
    col_3.High();
    col_4.Low();
  }
}

uint8_t Ui::getRow(uint8_t n) {
  if (n == 0) {
    return !row_1.value();
  } else if (n == 1) {
    return !row_2.value();
  } else if (n == 2) {
    return !row_3.value();
  }
}

void Ui::pollButton(uint8_t n) {
  uint8_t row = n / 4;
  uint8_t col = n % 4;

  setColumn(col);
  bool value = getRow(row);

  if (value && buttonState[n] != value) {
    if (ledState[n] == LED_STATE_OFF) {
      ledState[n] = LED_STATE_GREEN;
    } else {
      ledState[n] = LED_STATE_OFF;
    }
  }

  buttonState[n] = value;
}

void Ui::turnLedsOff() {
  // Set hi-Z state.
  led_1.set_mode(DIGITAL_INPUT);
  led_2.set_mode(DIGITAL_INPUT);
  led_3.set_mode(DIGITAL_INPUT);
  led_4.set_mode(DIGITAL_INPUT);
  led_5.set_mode(DIGITAL_INPUT);
  led_6.set_mode(DIGITAL_INPUT);

  led_1.Low();
  led_2.Low();
  led_3.Low();
  led_4.Low();
  led_5.Low();
  led_6.Low();
}

void Ui::refreshLed(uint8_t n) {
  turnLedsOff();

  uint8_t pinA = charlieplex[n][0];
  uint8_t pinB = charlieplex[n][1];

  if (ledState[n] == LED_STATE_RED) {
    setLedPin(pinA, 1);
    setLedPin(pinB, 0);
  } else if (ledState[n] == LED_STATE_GREEN) {
    setLedPin(pinA, 0);
    setLedPin(pinB, 1);
  }
}

void Ui::setLedPin(uint8_t n, uint8_t value) {
  if (n == 1) {
    led_1.set_mode(DIGITAL_OUTPUT);
    led_1.set_value(value);
  } else if (n == 2) {
    led_2.set_mode(DIGITAL_OUTPUT);
    led_2.set_value(value);
  } else if (n == 3) {
    led_3.set_mode(DIGITAL_OUTPUT);
    led_3.set_value(value);
  } else if (n == 4) {
    led_4.set_mode(DIGITAL_OUTPUT);
    led_4.set_value(value);
  } else if (n == 5) {
    led_5.set_mode(DIGITAL_OUTPUT);
    led_5.set_value(value);
  } else if (n == 6) {
    led_6.set_mode(DIGITAL_OUTPUT);
    led_6.set_value(value);
  }
}

void Ui::setLedState(uint8_t n, LedState state) {
  ledState[n] = state;
}
