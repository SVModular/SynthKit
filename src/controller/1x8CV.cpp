#include "1x8CV.hpp"

M1x8CVModule::M1x8CVModule() {
  config(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS);

  configInput(TOP_INPUT, "Signal");
  for (int i = 0; i < NUM_OUTPUTS; i++) {
    configInput(CV_INPUT + i, string::f("Ch %d CV", i + 1));
    configOutput(CH_OUTPUT + i, string::f("Ch %d", i + 1));
  }

  for (int i = 0; i < 8; i++) {
    cv[i] = new SynthDevKit::CV(1.7f);
  }
}

void M1x8CVModule::process(const ProcessArgs &args) {
  float in = inputs[TOP_INPUT].getVoltage();

  for (int i = 0; i < NUM_OUTPUTS; i++) {
    cv[i]->update(inputs[CV_INPUT + i].getVoltage());
    if (cv[i]->isHigh()) {
      outputs[CH_OUTPUT + i].setVoltage(in);
      lights[CH_LED + i].value = 1;
    } else {
      outputs[CH_OUTPUT + i].setVoltage(0);
      lights[CH_LED + i].value = 0;
    }
  }
}
