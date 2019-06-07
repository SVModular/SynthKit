#include "Subtraction.hpp"

SubtractionModule::SubtractionModule() {
  config(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS);
}

void SubtractionModule::process(const ProcessArgs &args) {
  float top1 = inputs[TOP1_INPUT].getVoltage();
  float top2 = inputs[TOP2_INPUT].getVoltage();
  float bottom1 = inputs[BOTTOM1_INPUT].getVoltage();
  float bottom2 = inputs[BOTTOM2_INPUT].getVoltage();

  float val1 = top1 - top2;
  float val2 = bottom1 - bottom2;

  outputs[TOP_OUTPUT].setVoltage(val1);
  outputs[BOTTOM_OUTPUT].setVoltage(val2);
}
