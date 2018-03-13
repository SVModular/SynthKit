#include "RotatingClockDivider2.hpp"

RotatingClockDivider2Module::RotatingClockDivider2Module()
    : Module(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS) {
  clock = new SynthDevKit::Clock(8, 1.7f);
  cv = new SynthDevKit::CV(1.7f);
  count = 0;
}

//float ins[8] = {};
//float outs[8] = {};

int clampInt(const int _in, const int min = 0, const int max = 7)
{
    if (_in > max) return max;
    if (_in < min) return min;
    return _in;
}

void RotatingClockDivider2Module::step() {
  float in = inputs[TOP_INPUT].value;
  float rotation = round(inputs[ROTATE_INPUT].value);
  rotation = clampInt(rotation -1);

  bool *states = clock->update(in);
  cv->update(rotation);

  for (int i = 0; i < 8; i++) {
    int j = (i + rotation);
    if (j >= 8) {
      j -= 8;
    }

    if (states[i] == true) {
      outputs[j].value = in;
      lights[j].value = 1.0f;
    } else {
      outputs[j].value = 0;
      lights[j].value = 0;
    }
  }

  if (count == 8) {
    count = 0;
  }
}
