#pragma once

#include "../../deps/SynthDevKit/src/CV.hpp"
#include "../SynthKit.hpp"

struct M1x8CVModule : Module {
  enum ParamIds { NUM_PARAMS };
  enum InputIds {
    TOP_INPUT,
    ENUMS(CV_INPUT, 8),
    NUM_INPUTS
  };
  enum OutputIds {
    ENUMS(CH_OUTPUT, 8),
    NUM_OUTPUTS
  };
  enum LightIds {
    ENUMS(CH_LED, 8),
    NUM_LIGHTS
  };

  M1x8CVModule();
  void process(const ProcessArgs &args) override;

  SynthDevKit::CV *cv[8];
};
