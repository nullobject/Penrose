#ifndef PENROSE_UI_H_
#define PENROSE_UI_H_

#include "avrlib/gpio.h"

#define COL1_PIN PD0
#define COL2_PIN PD1
#define COL3_PIN PD2
#define COL4_PIN PD3

#define COL_PORT PORTD
#define COL_DDR  DDRD

#define SWITCH_ROW1_PIN	PB2
#define SWITCH_ROW2_PIN	PB4
#define SWITCH_ROW3_PIN	PC5

#define SWITCH_INPUT_12	PINB
#define SWITCH_DDR_12		DDRB
#define SWITCH_PORT_12	PORTB
#define SWITCH_INPUT_3	PINC
#define SWITCH_DDR_3		DDRC
#define SWITCH_PORT_3		PORTC

using namespace avrlib;

namespace penrose {
  enum LedState {LED_STATE_OFF, LED_STATE_RED, LED_STATE_GREEN};
  enum ButtonState {BUTTON_STATE_OFF, BUTTON_STATE_ON};

  const uint8_t kNumButtons = 12;

  class Ui {
  public:
    Ui() {}
    ~Ui() {}

    void init();
    void poll();

    void pollButton(uint8_t n);
    void setLedState(uint8_t n, LedState state);

  private:
    uint8_t currentButton;

    bool buttonStates[kNumButtons];
    LedState ledStates[kNumButtons];

    Gpio<PortD, 0> col_1;
    Gpio<PortD, 1> col_2;
    Gpio<PortD, 2> col_3;
    Gpio<PortD, 3> col_4;

    Gpio<PortB, 2> row_1;
    Gpio<PortB, 4> row_2;
    Gpio<PortC, 5> row_3;
  };
}

#endif
