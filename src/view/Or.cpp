#include "../controller/Or.hpp"
#include "../../deps/rack-components/jacks.hpp"
#include "../../deps/rack-components/screws.hpp"

struct OrWidget : ModuleWidget {
  OrWidget(OrModule *module);
};

OrWidget::OrWidget(OrModule *module) {
		setModule(module);
  box.size = Vec(3 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT);

  setPanel(APP->window->loadSvg(asset::plugin(pluginInstance, "res/Or.svg")));

  addChild(createWidget<JLHHexScrew>(Vec(1, 1)));
  addChild(createWidget<JLHHexScrew>(Vec(31, 366)));

  addInput(createInput<RCJackSmallLight>(Vec(10.23, 73), module,
                                          OrModule::TOP1_INPUT));
  addInput(createInput<RCJackSmallLight>(Vec(10.23, 115), module,
                                          OrModule::TOP2_INPUT));

  addOutput(createOutput<RCJackSmallDark>(Vec(10.23, 158), module,
                                          OrModule::TOP_OUTPUT));

  addInput(createInput<RCJackSmallLight>(Vec(10.23, 220), module,
                                          OrModule::BOTTOM1_INPUT));
  addInput(createInput<RCJackSmallLight>(Vec(10.23, 262), module,
                                          OrModule::BOTTOM2_INPUT));

  addOutput(createOutput<RCJackSmallDark>(Vec(10.23, 305), module,
                                          OrModule::BOTTOM_OUTPUT));
}

Model *modelOr =
    createModel<OrModule, OrWidget>("Or");
