#include "../controller/FibonacciClockDivider.hpp"
#include "../../deps/rack-components/jacks.hpp"
#include "../../deps/rack-components/screws.hpp"

struct FibonacciClockDividerWidget : ModuleWidget {
  FibonacciClockDividerWidget(FibonacciClockDividerModule *module);
};

FibonacciClockDividerWidget::FibonacciClockDividerWidget(
    FibonacciClockDividerModule *module)
    {
		setModule(module);
  box.size = Vec(3 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT);

  setPanel(
      APP->window->loadSvg(asset::plugin(pluginInstance, "res/FibonacciClockDivider.svg")));

  addChild(createWidget<JLHHexScrew>(Vec(1, 1)));
  addChild(createWidget<JLHHexScrew>(Vec(31, 366)));

  addInput(
      createInput<RCJackSmallLight>(Vec(10.23, 73), module,
                                     FibonacciClockDividerModule::TOP_INPUT));
  addInput(
      createInput<RCJackSmallLight>(Vec(10.23, 115), module,
                                     FibonacciClockDividerModule::RESET_INPUT));
  addOutput(
      createOutput<RCJackSmallDark>(Vec(10.23, 158), module,
                                    FibonacciClockDividerModule::FIRST_OUTPUT));
  addOutput(createOutput<RCJackSmallDark>(
      Vec(10.23, 179), module,
      FibonacciClockDividerModule::SECOND_OUTPUT));
  addOutput(
      createOutput<RCJackSmallDark>(Vec(10.23, 200), module,
                                    FibonacciClockDividerModule::THIRD_OUTPUT));
  addOutput(createOutput<RCJackSmallDark>(
      Vec(10.23, 221), module,
      FibonacciClockDividerModule::FOURTH_OUTPUT));
  addOutput(
      createOutput<RCJackSmallDark>(Vec(10.23, 242), module,
                                    FibonacciClockDividerModule::FIFTH_OUTPUT));
  addOutput(
      createOutput<RCJackSmallDark>(Vec(10.23, 263), module,
                                    FibonacciClockDividerModule::SIXTH_OUTPUT));
  addOutput(createOutput<RCJackSmallDark>(
      Vec(10.23, 284), module,
      FibonacciClockDividerModule::SEVENTH_OUTPUT));
  addOutput(createOutput<RCJackSmallDark>(
      Vec(10.23, 305), module,
      FibonacciClockDividerModule::EIGHTH_OUTPUT));

  addChild(createLight<SmallLight<GreenLight>>(
      Vec(36.5, 167.06), module, FibonacciClockDividerModule::FIRST_LED));
  addChild(createLight<SmallLight<GreenLight>>(
      Vec(36.5, 188.06), module, FibonacciClockDividerModule::SECOND_LED));
  addChild(createLight<SmallLight<GreenLight>>(
      Vec(36.5, 209.06), module, FibonacciClockDividerModule::THIRD_LED));
  addChild(createLight<SmallLight<GreenLight>>(
      Vec(36.5, 230.06), module, FibonacciClockDividerModule::FOURTH_LED));
  addChild(createLight<SmallLight<GreenLight>>(
      Vec(36.5, 251.06), module, FibonacciClockDividerModule::FIFTH_LED));
  addChild(createLight<SmallLight<GreenLight>>(
      Vec(36.5, 272.06), module, FibonacciClockDividerModule::SIXTH_LED));
  addChild(createLight<SmallLight<GreenLight>>(
      Vec(36.5, 293.06), module, FibonacciClockDividerModule::SEVENTH_LED));
  addChild(createLight<SmallLight<GreenLight>>(
      Vec(36.5, 314.06), module, FibonacciClockDividerModule::EIGHTH_LED));
}

Model *modelFibonacciClockDivider =
    createModel<FibonacciClockDividerModule, FibonacciClockDividerWidget>("FibonacciClockDivider");
