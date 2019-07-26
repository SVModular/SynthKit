#include "../controller/Seq4.hpp"
#include "../../deps/rack-components/jacks.hpp"
#include "../../deps/rack-components/screws.hpp"
#include "knobs.hpp"

struct Seq4Widget : ModuleWidget {
  Seq4Widget(Seq4Module *module);
};

Seq4Widget::Seq4Widget(Seq4Module *module) {
		setModule(module);
  box.size = Vec(3 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT);

  setPanel(APP->window->loadSvg(asset::plugin(pluginInstance, "res/Seq4.svg")));

  addChild(createWidget<JLHHexScrew>(Vec(1, 1)));
  addChild(createWidget<JLHHexScrew>(Vec(31, 366)));

  addInput(createInput<RCJackSmallLight>(Vec(10.23, 56), module,
                                          Seq4Module::CLOCK_INPUT));

  addInput(createInput<RCJackSmallLight>(Vec(10.23, 96), module,
                                          Seq4Module::RESET_INPUT));

  addParam(createParam<Knob30Snap>(
      Vec(7.5, 136.5), module, Seq4Module::OCTAVE_PARAM));
  addParam(createParam<Knob19Snap>(
      Vec(13, 185), module, Seq4Module::SEQ1_PARAM));
  addParam(createParam<Knob19Snap>(
      Vec(13, 211), module, Seq4Module::SEQ2_PARAM));
  addParam(createParam<Knob19Snap>(
      Vec(13, 237), module, Seq4Module::SEQ3_PARAM));
  addParam(createParam<Knob19Snap>(
      Vec(13, 263), module, Seq4Module::SEQ4_PARAM));

  addChild(createLight<SmallLight<GreenLight>>(
      Vec(36.5, 191.28), module, Seq4Module::FIRST_LED));
  addChild(createLight<SmallLight<GreenLight>>(
      Vec(36.5, 217.28), module, Seq4Module::SECOND_LED));
  addChild(createLight<SmallLight<GreenLight>>(
      Vec(36.5, 243.28), module, Seq4Module::THIRD_LED));
  addChild(createLight<SmallLight<GreenLight>>(
      Vec(36.5, 269.28), module, Seq4Module::FOURTH_LED));

  addOutput(createOutput<RCJackSmallDark>(Vec(10.23, 305), module,
                                          Seq4Module::GATE_OUTPUT));
}

Model *modelSeq4 = createModel<Seq4Module, Seq4Widget>("4-StepSequencer");
