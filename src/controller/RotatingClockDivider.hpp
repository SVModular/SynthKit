#include <cstdint>

#include "../../deps/SynthDevKit/src/CV.hpp"
#include "../../deps/SynthDevKit/src/Clock.hpp"
#include "../SynthKit.hpp"

struct RotatingClockDividerModule : Module {
  enum ParamIds { NUM_PARAMS };
  enum InputIds { TOP_INPUT, ROTATE_INPUT, RESET_INPUT, NUM_INPUTS };
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
    ROTATE_LED,
    NUM_LIGHTS
  };

  RotatingClockDividerModule();
  void process(const ProcessArgs &args) override;

  SynthDevKit::Clock *clock;
  SynthDevKit::CV *cv, *reset;
  int count;
};
