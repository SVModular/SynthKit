#include "../controller/Seq8.hpp"
#include "../../deps/rack-components/jacks.hpp"
#include "../../deps/rack-components/screws.hpp"
#include "knobs.hpp"

struct Seq8Widget : ModuleWidget {
  Seq8Widget(Seq8Module *module);
};

Seq8Widget::Seq8Widget(Seq8Module *module) {
  setModule(module);
  box.size = Vec(5 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT);

  setPanel(APP->window->loadSvg(asset::plugin(pluginInstance, "res/Seq8.svg")));

  addChild(createWidget<JLHHexScrew>(Vec(1, 1)));
  addChild(createWidget<JLHHexScrew>(Vec(61, 1)));
  addChild(createWidget<JLHHexScrew>(Vec(1, 366)));
  addChild(createWidget<JLHHexScrew>(Vec(61, 366)));

  addInput(createInput<RCJackSmallLight>(Vec(8.25, 73), module,
                                         Seq8Module::CLOCK_INPUT));
  addInput(createInput<RCJackSmallLight>(Vec(41, 73), module,
                                         Seq8Module::RESET_INPUT));
  addOutput(createOutput<RCJackSmallDark>(Vec(25.23, 305), module,
                                          Seq8Module::GATE_OUTPUT));

  addParam(createParam<Knob19Snap>(
      Vec(15, 118), module, Seq8Module::OCTAVE1_PARAM));
  addParam(createParam<Knob19Snap>(
      Vec(15, 139), module, Seq8Module::OCTAVE2_PARAM));
  addParam(createParam<Knob19Snap>(
      Vec(15, 160), module, Seq8Module::OCTAVE3_PARAM));
  addParam(createParam<Knob19Snap>(
      Vec(15, 181), module, Seq8Module::OCTAVE4_PARAM));
  addParam(createParam<Knob19Snap>(
      Vec(15, 202), module, Seq8Module::OCTAVE5_PARAM));
  addParam(createParam<Knob19Snap>(
      Vec(15, 223), module, Seq8Module::OCTAVE6_PARAM));
  addParam(createParam<Knob19Snap>(
      Vec(15, 244), module, Seq8Module::OCTAVE7_PARAM));
  addParam(createParam<Knob19Snap>(
      Vec(15, 265), module, Seq8Module::OCTAVE8_PARAM));

  addParam(createParam<Knob19Snap>(
      Vec(41, 118), module, Seq8Module::SEQ1_PARAM));
  addParam(createParam<Knob19Snap>(
      Vec(41, 139), module, Seq8Module::SEQ2_PARAM));
  addParam(createParam<Knob19Snap>(
      Vec(41, 160), module, Seq8Module::SEQ3_PARAM));
  addParam(createParam<Knob19Snap>(
      Vec(41, 181), module, Seq8Module::SEQ4_PARAM));
  addParam(createParam<Knob19Snap>(
      Vec(41, 202), module, Seq8Module::SEQ5_PARAM));
  addParam(createParam<Knob19Snap>(
      Vec(41, 223), module, Seq8Module::SEQ6_PARAM));
  addParam(createParam<Knob19Snap>(
      Vec(41, 244), module, Seq8Module::SEQ7_PARAM));
  addParam(createParam<Knob19Snap>(
      Vec(41, 265), module, Seq8Module::SEQ8_PARAM));

  addChild(createLight<SmallLight<GreenLight>>(
      Vec(66.5, 124.28), module, Seq8Module::FIRST_LED));
  addChild(createLight<SmallLight<GreenLight>>(
      Vec(66.5, 145.28), module, Seq8Module::SECOND_LED));
  addChild(createLight<SmallLight<GreenLight>>(
      Vec(66.5, 166.28), module, Seq8Module::THIRD_LED));
  addChild(createLight<SmallLight<GreenLight>>(
      Vec(66.5, 187.28), module, Seq8Module::FOURTH_LED));
  addChild(createLight<SmallLight<GreenLight>>(
      Vec(66.5, 208.28), module, Seq8Module::FIFTH_LED));
  addChild(createLight<SmallLight<GreenLight>>(
      Vec(66.5, 229.28), module, Seq8Module::SIXTH_LED));
  addChild(createLight<SmallLight<GreenLight>>(
      Vec(66.5, 250.28), module, Seq8Module::SEVENTH_LED));
  addChild(createLight<SmallLight<GreenLight>>(
      Vec(66.5, 271.28), module, Seq8Module::EIGHTH_LED));
}

Model *modelSeq8 = createModel<Seq8Module, Seq8Widget>("8-StepSequencer");
