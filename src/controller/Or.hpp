#include "../SynthKit.hpp"

struct OrModule : Module {
  enum ParamIds { NUM_PARAMS };
  enum InputIds {
    TOP1_INPUT,
    TOP2_INPUT,
    BOTTOM1_INPUT,
    BOTTOM2_INPUT,
    NUM_INPUTS
  };
  enum OutputIds { TOP_OUTPUT, BOTTOM_OUTPUT, NUM_OUTPUTS };
  enum LightIds { NUM_LIGHTS };

  OrModule();
  void process(const ProcessArgs &args) override;
};
