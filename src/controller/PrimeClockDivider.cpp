#include "PrimeClockDivider.hpp"

PrimeClockDividerModule::PrimeClockDividerModule() {
  config(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS);
  clock = new SynthDevKit::PrimeClock(8, 1.7f);
  cv = new SynthDevKit::CV(1.7f);
}

void PrimeClockDividerModule::process(const ProcessArgs &args) {
  float reset_in = inputs[RESET_INPUT].getVoltage();

  cv->update(reset_in);

  if (cv->newTrigger()) {
    clock->reset();
  }

  float in = inputs[TOP_INPUT].getVoltage();
  bool *states = clock->update(in);

  for (int i = 0; i < 8; i++) {
    if (states[i] == true) {
      outputs[i].setVoltage(in);
      lights[i].value = 1.0f;
    } else {
      outputs[i].setVoltage(0);
      lights[i].value = 0;
    }
  }
}
