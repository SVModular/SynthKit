#include "RotatingClockDivider.hpp"

RotatingClockDividerModule::RotatingClockDividerModule() {
  config(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS);

  configInput(TOP_INPUT, "Clock");
  configInput(ROTATE_INPUT, "Rotate");
  configInput(RESET_INPUT, "Reset");
  for (int i = 0; i < NUM_OUTPUTS; i++) {
    configOutput(DIV_OUTPUT + i, string::f("Div %d", i + 1));
  }

  clock = new SynthDevKit::Clock(8, 1.7f);
  cv = new SynthDevKit::CV(1.7f);
  reset = new SynthDevKit::CV(1.7f);
  count = 0;
}

void RotatingClockDividerModule::process(const ProcessArgs &args) {
  float reset_in = inputs[RESET_INPUT].getVoltage();

  reset->update(reset_in);

  if (reset->newTrigger()) {
    clock->reset();
  }

  float in = inputs[TOP_INPUT].getVoltage();
  float trigger = inputs[ROTATE_INPUT].getVoltage();

  bool *states = clock->update(in);
  cv->update(trigger);

  bool triggered = cv->newTrigger();
  if (triggered) {
    count++;
  }

  for (int i = 0; i < 8; i++) {
    int j = i + count;
    if (j >= 8) {
      j -= 8;
    }

    if (states[i] == true) {
      outputs[j].setVoltage(in);
      lights[j].value = 1.0f;
    } else {
      outputs[j].setVoltage(0);
      lights[j].value = 0;
    }
  }

  if (count == 8) {
    count = 0;
  }
}
