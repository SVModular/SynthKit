#include "../controller/RotatingClockDivider.hpp"
#include "../../deps/rack-components/jacks.hpp"
#include "../../deps/rack-components/screws.hpp"

struct RotatingClockDividerWidget : ModuleWidget {
  RotatingClockDividerWidget(RotatingClockDividerModule *module);
};

RotatingClockDividerWidget::RotatingClockDividerWidget(
    RotatingClockDividerModule *module)
    {
		setModule(module);
  box.size = Vec(4 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT);

  setPanel(
        APP->window->loadSvg(asset::plugin(pluginInstance, "res/RotatingClockDivider.svg")));

  addChild(createWidget<JLHHexScrew>(Vec(1, 1)));
  addChild(createWidget<JLHHexScrew>(Vec(46, 366)));

  addInput(
      createInput<RCJackSmallLight>(Vec(31.23, 109), module,
                                     RotatingClockDividerModule::ROTATE_INPUT));
  addInput(
      createInput<RCJackSmallLight>(Vec(31.23, 65), module,
                                     RotatingClockDividerModule::TOP_INPUT));
  addInput(
      createInput<RCJackSmallLight>(Vec(3.8, 87), module,
                                     RotatingClockDividerModule::RESET_INPUT));

  addOutput(
      createOutput<RCJackSmallDark>(Vec(17.23, 158), module,
                                    RotatingClockDividerModule::FIRST_OUTPUT));
  addOutput(
      createOutput<RCJackSmallDark>(Vec(17.23, 179), module,
                                    RotatingClockDividerModule::SECOND_OUTPUT));
  addOutput(
      createOutput<RCJackSmallDark>(Vec(17.23, 200), module,
                                    RotatingClockDividerModule::THIRD_OUTPUT));
  addOutput(
      createOutput<RCJackSmallDark>(Vec(17.23, 221), module,
                                    RotatingClockDividerModule::FOURTH_OUTPUT));
  addOutput(
      createOutput<RCJackSmallDark>(Vec(17.23, 242), module,
                                    RotatingClockDividerModule::FIFTH_OUTPUT));
  addOutput(
      createOutput<RCJackSmallDark>(Vec(17.23, 263), module,
                                    RotatingClockDividerModule::SIXTH_OUTPUT));
  addOutput(createOutput<RCJackSmallDark>(
      Vec(17.23, 284), module,
      RotatingClockDividerModule::SEVENTH_OUTPUT));
  addOutput(
      createOutput<RCJackSmallDark>(Vec(17.23, 305), module,
                                    RotatingClockDividerModule::EIGHTH_OUTPUT));

  addChild(createLight<SmallLight<GreenLight>>(
      Vec(44, 167.06), module, RotatingClockDividerModule::FIRST_LED));
  addChild(createLight<SmallLight<GreenLight>>(
      Vec(44, 188.06), module, RotatingClockDividerModule::SECOND_LED));
  addChild(createLight<SmallLight<GreenLight>>(
      Vec(44, 209.06), module, RotatingClockDividerModule::THIRD_LED));
  addChild(createLight<SmallLight<GreenLight>>(
      Vec(44, 230.06), module, RotatingClockDividerModule::FOURTH_LED));
  addChild(createLight<SmallLight<GreenLight>>(
      Vec(44, 251.06), module, RotatingClockDividerModule::FIFTH_LED));
  addChild(createLight<SmallLight<GreenLight>>(
      Vec(44, 272.06), module, RotatingClockDividerModule::SIXTH_LED));
  addChild(createLight<SmallLight<GreenLight>>(
      Vec(44, 293.06), module, RotatingClockDividerModule::SEVENTH_LED));
  addChild(createLight<SmallLight<GreenLight>>(
      Vec(44, 314.06), module, RotatingClockDividerModule::EIGHTH_LED));
}

Model *modelRotatingClockDivider =
    createModel<RotatingClockDividerModule, RotatingClockDividerWidget>("RotatingClockDivider");
