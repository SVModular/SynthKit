#include "FibonacciClockDivider.hpp"

FibonacciClockDividerModule::FibonacciClockDividerModule() {
  config(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS);

  configInput(TOP_INPUT, "Clock");
  configInput(RESET_INPUT, "Reset");
  for (int i = 0; i < 3; i++) {
    configOutput(DIV_OUTPUT + i, string::f("Div %d", i + 1));
  }
  configOutput(DIV_OUTPUT + 3, "Div 5");
  configOutput(DIV_OUTPUT + 4, "Div 8");
  configOutput(DIV_OUTPUT + 5, "Div 13");
  configOutput(DIV_OUTPUT + 6, "Div 21");
  configOutput(DIV_OUTPUT + 7, "Div 34");

  clock = new SynthDevKit::FibonacciClock(8, 1.7f);
  cv = new SynthDevKit::CV(1.7f);
}

void FibonacciClockDividerModule::process(const ProcessArgs &args) {
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
