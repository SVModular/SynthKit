#include "../controller/And.hpp"
#include "../../deps/rack-components/jacks.hpp"
#include "../../deps/rack-components/screws.hpp"

struct AndWidget : ModuleWidget {
  AndWidget(AndModule *module);
};

AndWidget::AndWidget(AndModule *module) {
		setModule(module);
  box.size = Vec(3 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT);

  setPanel(APP->window->loadSvg(asset::plugin(pluginInstance, "res/And.svg")));

  addChild(createWidget<JLHHexScrew>(Vec(1, 1)));
  addChild(createWidget<JLHHexScrew>(Vec(31, 366)));

  addInput(createInput<RCJackSmallLight>(Vec(10.23, 73), module,
                                          AndModule::TOP1_INPUT));
  addInput(createInput<RCJackSmallLight>(Vec(10.23, 115), module,
                                          AndModule::TOP2_INPUT));

  addOutput(createOutput<RCJackSmallDark>(Vec(10.23, 158), module,
                                          AndModule::TOP_OUTPUT));

  addInput(createInput<RCJackSmallLight>(Vec(10.23, 220), module,
                                          AndModule::BOTTOM1_INPUT));
  addInput(createInput<RCJackSmallLight>(Vec(10.23, 262), module,
                                          AndModule::BOTTOM2_INPUT));

  addOutput(createOutput<RCJackSmallDark>(Vec(10.23, 305), module,
                                          AndModule::BOTTOM_OUTPUT));
}

Model *modelAnd =
    createModel<AndModule, AndWidget>("And");
