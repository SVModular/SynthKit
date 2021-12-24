#pragma once

#include "../SynthKit.hpp"

struct M1x8Module : Module {
  enum ParamIds { NUM_PARAMS };
  enum InputIds { TOP_INPUT, NUM_INPUTS };
  enum OutputIds {
    ENUMS(CH_OUTPUT, 8),
    NUM_OUTPUTS
  };
  enum LightIds { NUM_LIGHTS };

  M1x8Module();
  void process(const ProcessArgs &args) override;
};
