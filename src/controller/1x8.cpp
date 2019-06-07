#include "1x8.hpp"

M1x8Module::M1x8Module() {
  config(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS);
}

void M1x8Module::process(const ProcessArgs &args) {
  float in = inputs[TOP_INPUT].getVoltage();

  outputs[FIRST_OUTPUT].setVoltage(in);
  outputs[SECOND_OUTPUT].setVoltage(in);
  outputs[THIRD_OUTPUT].setVoltage(in);
  outputs[FOURTH_OUTPUT].setVoltage(in);
  outputs[FIFTH_OUTPUT].setVoltage(in);
  outputs[SIXTH_OUTPUT].setVoltage(in);
  outputs[SEVENTH_OUTPUT].setVoltage(in);
  outputs[EIGHTH_OUTPUT].setVoltage(in);
}
