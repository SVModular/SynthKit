#include "Seq8.hpp"

Seq8Module::Seq8Module() {
  config(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS);
  cv = new SynthDevKit::CV(1.7f);
  reset = new SynthDevKit::CV(1.7f);
  currentStep = 0;

  configInput(CLOCK_INPUT, "Clock");
  configInput(RESET_INPUT, "Reset");
  configOutput(GATE_OUTPUT, "Note");
  configParam(Seq8Module::OCTAVE1_PARAM, 1.0, 8.0, 4.0, "Step 1 Octave");
  configParam(Seq8Module::OCTAVE2_PARAM, 1.0, 8.0, 4.0, "Step 2 Octave");
  configParam(Seq8Module::OCTAVE3_PARAM, 1.0, 8.0, 4.0, "Step 3 Octave");
  configParam(Seq8Module::OCTAVE4_PARAM, 1.0, 8.0, 4.0, "Step 4 Octave");
  configParam(Seq8Module::OCTAVE5_PARAM, 1.0, 8.0, 4.0, "Step 5 Octave");
  configParam(Seq8Module::OCTAVE6_PARAM, 1.0, 8.0, 4.0, "Step 6 Octave");
  configParam(Seq8Module::OCTAVE7_PARAM, 1.0, 8.0, 4.0, "Step 7 Octave");
  configParam(Seq8Module::OCTAVE8_PARAM, 1.0, 8.0, 4.0, "Step 8 Octave");
  configParam(Seq8Module::SEQ1_PARAM, 0.0, 11.0, 5.0, "Step 1 Pitch");
  configParam(Seq8Module::SEQ2_PARAM, 0.0, 11.0, 5.0, "Step 2 Pitch");
  configParam(Seq8Module::SEQ3_PARAM, 0.0, 11.0, 5.0, "Step 3 Pitch");
  configParam(Seq8Module::SEQ4_PARAM, 0.0, 11.0, 5.0, "Step 4 Pitch");
  configParam(Seq8Module::SEQ5_PARAM, 0.0, 11.0, 5.0, "Step 5 Pitch");
  configParam(Seq8Module::SEQ6_PARAM, 0.0, 11.0, 5.0, "Step 6 Pitch");
  configParam(Seq8Module::SEQ7_PARAM, 0.0, 11.0, 5.0, "Step 7 Pitch");
  configParam(Seq8Module::SEQ8_PARAM, 0.0, 11.0, 5.0, "Step 8 Pitch");
}

void Seq8Module::process(const ProcessArgs &args) {
  reset->update(inputs[RESET_INPUT].getVoltage());
  if (reset->newTrigger()) {
    currentStep = 0;
  }
  float in = inputs[CLOCK_INPUT].getVoltage();
  cv->update(in);

  if (cv->newTrigger()) {
    float note_param = params[SEQ1_PARAM + currentStep].getValue();
    float oct_param = params[OCTAVE1_PARAM + currentStep].getValue();

    outputs[GATE_OUTPUT].setVoltage(notes[(int)note_param] + octives[(int)oct_param]);

    for (int i = 0; i < 8; i++) {
      if (i == currentStep) {
        lights[i].value = 1.0;
      } else {
        lights[i].value = 0.0;
      }
    }

    currentStep++;

    if (currentStep == 8) {
      currentStep = 0;
    }
  }
}
