#include "1x8.hpp"

M1x8Module::M1x8Module() {
  config(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS);

  configInput(TOP_INPUT, "Signal");
  for (int i = 0; i < NUM_OUTPUTS; i++) {
    configOutput(CH_OUTPUT + i, string::f("Ch %d", i + 1));
  }
}

void M1x8Module::process(const ProcessArgs &args) {
  float in = inputs[TOP_INPUT].getVoltage();

  for (int i = 0; i < NUM_OUTPUTS; i++) {
    outputs[CH_OUTPUT + i].setVoltage(in);
  }
}
