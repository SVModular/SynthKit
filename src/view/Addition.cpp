#include "../controller/Addition.hpp"
#include "../../deps/rack-components/jacks.hpp"
#include "../../deps/rack-components/screws.hpp"

struct AdditionWidget : ModuleWidget {
  AdditionWidget(AdditionModule *module);
};

AdditionWidget::AdditionWidget(AdditionModule *module) {
		setModule(module);
  box.size = Vec(3 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT);

  setPanel(APP->window->loadSvg(asset::plugin(pluginInstance, "res/Addition.svg")));

  addChild(createWidget<JLHHexScrew>(Vec(1, 1)));
  addChild(createWidget<JLHHexScrew>(Vec(31, 366)));

  addInput(createInput<RCJackSmallLight>(Vec(10.23, 73), module,
                                          AdditionModule::TOP1_INPUT));
  addInput(createInput<RCJackSmallLight>(Vec(10.23, 115), module,
                                         AdditionModule::TOP2_INPUT));

  addOutput(createOutput<RCJackSmallDark>(Vec(10.23, 158), module,
                                          AdditionModule::TOP_OUTPUT));

  addInput(createInput<RCJackSmallLight>(Vec(10.23, 220), module,
                                          AdditionModule::BOTTOM1_INPUT));
  addInput(createInput<RCJackSmallLight>(Vec(10.23, 262), module,
                                         AdditionModule::BOTTOM2_INPUT));

  addOutput(createOutput<RCJackSmallDark>(Vec(10.23, 305), module,
                                          AdditionModule::BOTTOM_OUTPUT));
}

Model *modelAddition = createModel<AdditionModule, AdditionWidget>("Addition");
