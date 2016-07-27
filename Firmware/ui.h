#ifndef PENROSE_UI_H_
#define PENROSE_UI_H_

#include "avrlib/gpio.h"

using namespace avrlib;

const uint8_t kNumButtons = 12;

class Ui {
public:
  Ui() {}
  ~Ui() {}

  void init();
  void poll();
  void setActiveButton(uint8_t n);
  bool buttonSelected(uint8_t n);
  bool hasSelectedButtons();

private:
  uint16_t ledState;
  bool buttonState[kNumButtons];
  uint16_t pressTime[kNumButtons];
  uint8_t activeButton;

  Gpio<PortD, 0> col_1;
  Gpio<PortD, 1> col_2;
  Gpio<PortD, 2> col_3;
  Gpio<PortD, 3> col_4;

  Gpio<PortB, 2> row_1;
  Gpio<PortB, 4> row_2;
  Gpio<PortC, 5> row_3;

  Gpio<PortC, 1> led_1;
  Gpio<PortC, 2> led_2;
  Gpio<PortC, 3> led_3;
  Gpio<PortD, 4> led_4;
  Gpio<PortD, 5> led_5;
  Gpio<PortD, 6> led_6;

  void pollButton(uint8_t n);
  void toggleButton(uint8_t n);
  void turnLedsOff();
  void refreshLed(uint8_t n);
  void setLedPin(uint8_t n, uint8_t value);
  void setColumn(uint8_t n);
  bool getRow(uint8_t n);
};

#endif
