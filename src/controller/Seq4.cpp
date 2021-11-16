#include "Seq4.hpp"

Seq4Module::Seq4Module() {
  config(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS);
  cv = new SynthDevKit::CV(1.7f);
  reset = new SynthDevKit::CV(1.7f);
  currentStep = 0;

  configInput(CLOCK_INPUT, "Clock");
  configInput(RESET_INPUT, "Reset");
  configOutput(GATE_OUTPUT, "Note");
  configParam(Seq4Module::OCTAVE_PARAM, 1.0, 8.0, 4.0, "Octave");
  configParam(Seq4Module::SEQ1_PARAM, 0.0, 11.0, 5.0, "Step 1 Pitch");
  configParam(Seq4Module::SEQ2_PARAM, 0.0, 11.0, 5.0, "Step 2 Pitch");
  configParam(Seq4Module::SEQ3_PARAM, 0.0, 11.0, 5.0, "Step 3 Pitch");
  configParam(Seq4Module::SEQ4_PARAM, 0.0, 11.0, 5.0, "Step 4 Pitch");
}

void Seq4Module::process(const ProcessArgs &args) {
  reset->update(inputs[RESET_INPUT].getVoltage());
  if (reset->newTrigger()) {
    currentStep = 0;
  }

  float in = inputs[CLOCK_INPUT].getVoltage();
  cv->update(in);

  if (cv->newTrigger()) {
    float note = octives[(int)params[OCTAVE_PARAM].getValue()] +
                 notes[(int)params[SEQ1_PARAM + currentStep].getValue()];

    outputs[GATE_OUTPUT].setVoltage(note);

    for (int i = 0; i < 4; i++) {
      if (i == currentStep) {
        lights[i].value = 1.0;
      } else {
        lights[i].value = 0.0;
      }
    }
    currentStep++;

    if (currentStep == 4) {
      currentStep = 0;
    }
  }
}
