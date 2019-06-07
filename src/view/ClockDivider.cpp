#include "../controller/ClockDivider.hpp"
#include "../../deps/rack-components/jacks.hpp"
#include "../../deps/rack-components/screws.hpp"

struct ClockDividerWidget : ModuleWidget {
  ClockDividerWidget(ClockDividerModule *module);
};

ClockDividerWidget::ClockDividerWidget(ClockDividerModule *module)
    {
		setModule(module);
  box.size = Vec(3 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT);

  setPanel(
        APP->window->loadSvg(asset::plugin(pluginInstance, "res/ClockDivider.svg")));

  addChild(createWidget<JLHHexScrew>(Vec(1, 1)));
  addChild(createWidget<JLHHexScrew>(Vec(31, 366)));

  addInput(createInput<RCJackSmallLight>(Vec(10.23, 73), module,
                                          ClockDividerModule::TOP_INPUT));
  addInput(createInput<RCJackSmallLight>(Vec(10.23, 115), module,
                                          ClockDividerModule::RESET_INPUT));
  addOutput(createOutput<RCJackSmallDark>(Vec(10.23, 158), module,
                                          ClockDividerModule::FIRST_OUTPUT));
  addOutput(createOutput<RCJackSmallDark>(Vec(10.23, 179), module,
                                          ClockDividerModule::SECOND_OUTPUT));
  addOutput(createOutput<RCJackSmallDark>(Vec(10.23, 200), module,
                                          ClockDividerModule::THIRD_OUTPUT));
  addOutput(createOutput<RCJackSmallDark>(Vec(10.23, 221), module,
                                          ClockDividerModule::FOURTH_OUTPUT));
  addOutput(createOutput<RCJackSmallDark>(Vec(10.23, 242), module,
                                          ClockDividerModule::FIFTH_OUTPUT));
  addOutput(createOutput<RCJackSmallDark>(Vec(10.23, 263), module,
                                          ClockDividerModule::SIXTH_OUTPUT));
  addOutput(createOutput<RCJackSmallDark>(Vec(10.23, 284), module,
                                          ClockDividerModule::SEVENTH_OUTPUT));
  addOutput(createOutput<RCJackSmallDark>(Vec(10.23, 305), module,
                                          ClockDividerModule::EIGHTH_OUTPUT));

  addChild(createLight<SmallLight<GreenLight>>(
      Vec(36.5, 167.06), module, ClockDividerModule::FIRST_LED));
  addChild(createLight<SmallLight<GreenLight>>(
      Vec(36.5, 188.06), module, ClockDividerModule::SECOND_LED));
  addChild(createLight<SmallLight<GreenLight>>(
      Vec(36.5, 209.06), module, ClockDividerModule::THIRD_LED));
  addChild(createLight<SmallLight<GreenLight>>(
      Vec(36.5, 230.06), module, ClockDividerModule::FOURTH_LED));
  addChild(createLight<SmallLight<GreenLight>>(
      Vec(36.5, 251.06), module, ClockDividerModule::FIFTH_LED));
  addChild(createLight<SmallLight<GreenLight>>(
      Vec(36.5, 272.06), module, ClockDividerModule::SIXTH_LED));
  addChild(createLight<SmallLight<GreenLight>>(
      Vec(36.5, 293.06), module, ClockDividerModule::SEVENTH_LED));
  addChild(createLight<SmallLight<GreenLight>>(
      Vec(36.5, 314.06), module, ClockDividerModule::EIGHTH_LED));
}

Model *modelClockDivider =
    createModel<ClockDividerModule, ClockDividerWidget>("ClockDivider");
