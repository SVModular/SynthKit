#include "Subtraction.hpp"

SubtractionModule::SubtractionModule() {
  config(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS);

  configInput(TOP1_INPUT, "A1");
  configInput(TOP2_INPUT, "A2");
  configInput(BOTTOM1_INPUT, "B1");
  configInput(BOTTOM2_INPUT, "B2");

  configOutput(TOP_OUTPUT, "Difference A");
  configOutput(BOTTOM_OUTPUT, "Difference B");
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
