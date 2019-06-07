#include "../controller/PrimeClockDivider.hpp"
#include "../../deps/rack-components/jacks.hpp"
#include "../../deps/rack-components/screws.hpp"

struct PrimeClockDividerWidget : ModuleWidget {
  PrimeClockDividerWidget(PrimeClockDividerModule *module);
};

PrimeClockDividerWidget::PrimeClockDividerWidget(
    PrimeClockDividerModule *module)
    {
		setModule(module);
  box.size = Vec(3 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT);

  setPanel(
      APP->window->loadSvg(asset::plugin(pluginInstance, "res/PrimeClockDivider.svg")));

  addChild(createWidget<JLHHexScrew>(Vec(1, 1)));
  addChild(createWidget<JLHHexScrew>(Vec(31, 366)));

  addInput(createInput<RCJackSmallLight>(Vec(10.23, 73), module,
                                          PrimeClockDividerModule::TOP_INPUT));
  addInput(
      createInput<RCJackSmallLight>(Vec(10.23, 115), module,
                                     PrimeClockDividerModule::RESET_INPUT));
  addOutput(
      createOutput<RCJackSmallDark>(Vec(10.23, 158), module,
                                    PrimeClockDividerModule::FIRST_OUTPUT));
  addOutput(
      createOutput<RCJackSmallDark>(Vec(10.23, 179), module,
                                    PrimeClockDividerModule::SECOND_OUTPUT));
  addOutput(
      createOutput<RCJackSmallDark>(Vec(10.23, 200), module,
                                    PrimeClockDividerModule::THIRD_OUTPUT));
  addOutput(
      createOutput<RCJackSmallDark>(Vec(10.23, 221), module,
                                    PrimeClockDividerModule::FOURTH_OUTPUT));
  addOutput(
      createOutput<RCJackSmallDark>(Vec(10.23, 242), module,
                                    PrimeClockDividerModule::FIFTH_OUTPUT));
  addOutput(
      createOutput<RCJackSmallDark>(Vec(10.23, 263), module,
                                    PrimeClockDividerModule::SIXTH_OUTPUT));
  addOutput(
      createOutput<RCJackSmallDark>(Vec(10.23, 284), module,
                                    PrimeClockDividerModule::SEVENTH_OUTPUT));
  addOutput(
      createOutput<RCJackSmallDark>(Vec(10.23, 305), module,
                                    PrimeClockDividerModule::EIGHTH_OUTPUT));

  addChild(createLight<SmallLight<GreenLight>>(
      Vec(36.5, 167.06), module, PrimeClockDividerModule::FIRST_LED));
  addChild(createLight<SmallLight<GreenLight>>(
      Vec(36.5, 188.06), module, PrimeClockDividerModule::SECOND_LED));
  addChild(createLight<SmallLight<GreenLight>>(
      Vec(36.5, 209.06), module, PrimeClockDividerModule::THIRD_LED));
  addChild(createLight<SmallLight<GreenLight>>(
      Vec(36.5, 230.06), module, PrimeClockDividerModule::FOURTH_LED));
  addChild(createLight<SmallLight<GreenLight>>(
      Vec(36.5, 251.06), module, PrimeClockDividerModule::FIFTH_LED));
  addChild(createLight<SmallLight<GreenLight>>(
      Vec(36.5, 272.06), module, PrimeClockDividerModule::SIXTH_LED));
  addChild(createLight<SmallLight<GreenLight>>(
      Vec(36.5, 293.06), module, PrimeClockDividerModule::SEVENTH_LED));
  addChild(createLight<SmallLight<GreenLight>>(
      Vec(36.5, 314.06), module, PrimeClockDividerModule::EIGHTH_LED));
}

Model *modelPrimeClockDivider =
    createModel<PrimeClockDividerModule, PrimeClockDividerWidget>("PrimeClockDivider");
