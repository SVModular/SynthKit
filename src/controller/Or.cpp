#include "Or.hpp"

OrModule::OrModule() {
  config(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS);
}

void OrModule::process(const ProcessArgs &args) {
  float top1 = inputs[TOP1_INPUT].getVoltage();
  float top2 = inputs[TOP2_INPUT].getVoltage();
  float bottom1 = inputs[BOTTOM1_INPUT].getVoltage();
  float bottom2 = inputs[BOTTOM2_INPUT].getVoltage();

  double val1 =
      (double)((long long)(top1 * 10000) | (long long)(top2 * 10000)) / 10000;
  double val2 =
      (double)((long long)(bottom1 * 10000) | (long long)(bottom2 * 10000)) /
      10000;

  outputs[TOP_OUTPUT].setVoltage((float)val1);
  outputs[BOTTOM_OUTPUT].setVoltage((float)val2);
}
