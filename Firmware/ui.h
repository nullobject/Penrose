#ifndef PENROSE_UI_H_
#define PENROSE_UI_H_

#include <avr/io.h>

enum LedState {off, red, green};

namespace penrose {
  class Ui {
  public:
    Ui() {}
    ~Ui() {}

    void init();
    void setLedState(uint8_t n, LedState ledState);

  private:
    LedState ledStates[10];
  };
}

#endif
