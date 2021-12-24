#include "RotatingClockDivider2.hpp"

RotatingClockDivider2Module::RotatingClockDivider2Module() {
  config(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS);

  configInput(TOP_INPUT, "Clock");
  configInput(ROTATE_INPUT, "Shift");
  configInput(RESET_INPUT, "Reset");
  for (int i = 0; i < NUM_OUTPUTS; i++) {
    configOutput(DIV_OUTPUT + i, string::f("Div %d", i + 1));
  }

  clock = new SynthDevKit::Clock(8, 1.7f);
  cv = new SynthDevKit::CV(1.7f);
  reset = new SynthDevKit::CV(1.7f);
}

void RotatingClockDivider2Module::process(const ProcessArgs &args) {
  float reset_in = inputs[RESET_INPUT].getVoltage();

  reset->update(reset_in);

  if (reset->newTrigger()) {
    clock->reset();
  }

  float in = inputs[TOP_INPUT].getVoltage();
  float rotation =
      round(inputs[ROTATE_INPUT].getVoltage()); // name this variable rotation rather
                                         // than trigger, and round it to an int
  rotation = clamp((rotation - 1), 0.0f, 7.0f); // subtract 1 from rotation to
                                                // give some headroom for the
                                                // first rotation, then restrict
                                                // to between 0

  bool *states = clock->update(in);
  cv->update(rotation);

  for (int i = 0; i < 8; i++) {
    int j = (i + rotation);
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
}
