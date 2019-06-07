#include "../controller/RotatingClockDivider2.hpp"
#include "../../deps/rack-components/jacks.hpp"
#include "../../deps/rack-components/screws.hpp"

struct RotatingClockDivider2Widget : ModuleWidget {
  RotatingClockDivider2Widget(RotatingClockDivider2Module *module);
};

RotatingClockDivider2Widget::RotatingClockDivider2Widget(
    RotatingClockDivider2Module *module)
    {
		setModule(module);
  box.size = Vec(4 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT);

  setPanel(
        APP->window->loadSvg(asset::plugin(pluginInstance, "res/RotatingClockDivider2.svg")));

  addChild(createWidget<JLHHexScrew>(Vec(1, 1)));
  addChild(createWidget<JLHHexScrew>(Vec(46, 366)));

  addInput(createInput<RCJackSmallLight>(
      Vec(31.23, 109), module,
      RotatingClockDivider2Module::ROTATE_INPUT));
  addInput(
      createInput<RCJackSmallLight>(Vec(31.23, 65), module,
                                     RotatingClockDivider2Module::TOP_INPUT));
  addInput(
      createInput<RCJackSmallLight>(Vec(3.8, 87), module,
                                     RotatingClockDivider2Module::RESET_INPUT));

  addOutput(
      createOutput<RCJackSmallDark>(Vec(10.23, 158), module,
                                    RotatingClockDivider2Module::FIRST_OUTPUT));
  addOutput(createOutput<RCJackSmallDark>(
      Vec(10.23, 179), module,
      RotatingClockDivider2Module::SECOND_OUTPUT));
  addOutput(
      createOutput<RCJackSmallDark>(Vec(10.23, 200), module,
                                    RotatingClockDivider2Module::THIRD_OUTPUT));
  addOutput(createOutput<RCJackSmallDark>(
      Vec(10.23, 221), module,
      RotatingClockDivider2Module::FOURTH_OUTPUT));
  addOutput(
      createOutput<RCJackSmallDark>(Vec(10.23, 242), module,
                                    RotatingClockDivider2Module::FIFTH_OUTPUT));
  addOutput(
      createOutput<RCJackSmallDark>(Vec(10.23, 263), module,
                                    RotatingClockDivider2Module::SIXTH_OUTPUT));
  addOutput(createOutput<RCJackSmallDark>(
      Vec(10.23, 284), module,
      RotatingClockDivider2Module::SEVENTH_OUTPUT));
  addOutput(createOutput<RCJackSmallDark>(
      Vec(10.23, 305), module,
      RotatingClockDivider2Module::EIGHTH_OUTPUT));

  addChild(createLight<SmallLight<GreenLight>>(
      Vec(36.5, 167.06), module, RotatingClockDivider2Module::FIRST_LED));
  addChild(createLight<SmallLight<GreenLight>>(
      Vec(36.5, 188.06), module, RotatingClockDivider2Module::SECOND_LED));
  addChild(createLight<SmallLight<GreenLight>>(
      Vec(36.5, 209.06), module, RotatingClockDivider2Module::THIRD_LED));
  addChild(createLight<SmallLight<GreenLight>>(
      Vec(36.5, 230.06), module, RotatingClockDivider2Module::FOURTH_LED));
  addChild(createLight<SmallLight<GreenLight>>(
      Vec(36.5, 251.06), module, RotatingClockDivider2Module::FIFTH_LED));
  addChild(createLight<SmallLight<GreenLight>>(
      Vec(36.5, 272.06), module, RotatingClockDivider2Module::SIXTH_LED));
  addChild(createLight<SmallLight<GreenLight>>(
      Vec(36.5, 293.06), module, RotatingClockDivider2Module::SEVENTH_LED));
  addChild(createLight<SmallLight<GreenLight>>(
      Vec(36.5, 314.06), module, RotatingClockDivider2Module::EIGHTH_LED));
}

Model *modelRotatingClockDivider2 =
    createModel<RotatingClockDivider2Module, RotatingClockDivider2Widget>("ShiftingClockDividerCV");
