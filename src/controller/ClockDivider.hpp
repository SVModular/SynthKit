#pragma once

#include <cstdint>

#include "../../deps/SynthDevKit/src/CV.hpp"
#include "../../deps/SynthDevKit/src/Clock.hpp"
#include "../SynthKit.hpp"

struct ClockDividerModule : Module {
  enum ParamIds { NUM_PARAMS };
  enum InputIds { TOP_INPUT, RESET_INPUT, NUM_INPUTS };
  enum OutputIds {
    ENUMS(DIV_OUTPUT, 8),
    NUM_OUTPUTS
  };
  enum LightIds {
    FIRST_LED,
    SECOND_LED,
    THIRD_LED,
    FOURTH_LED,
    FIFTH_LED,
    SIXTH_LED,
    SEVENTH_LED,
    EIGHTH_LED,
    NUM_LIGHTS
  };

  ClockDividerModule();
  void process(const ProcessArgs &args) override;

  SynthDevKit::Clock *clock;
  SynthDevKit::CV *cv;
};
