#include "../controller/1x8.hpp"
#include "../../deps/rack-components/jacks.hpp"
#include "../../deps/rack-components/screws.hpp"

struct M1x8Widget : ModuleWidget {
  M1x8Widget(M1x8Module *module);
};

M1x8Widget::M1x8Widget(M1x8Module *module) {
		setModule(module);
  box.size = Vec(3 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT);

  setPanel(APP->window->loadSvg(asset::plugin(pluginInstance, "res/1x8.svg")));

  addChild(createWidget<JLHHexScrew>(Vec(1, 1)));
  addChild(createWidget<JLHHexScrew>(Vec(31, 366)));

  addInput(createInput<RCJackSmallLight>(Vec(10.23, 73), module,
                                          M1x8Module::TOP_INPUT));
  addOutput(createOutput<RCJackSmallDark>(Vec(10.23, 158), module,
                                          M1x8Module::FIRST_OUTPUT));
  addOutput(createOutput<RCJackSmallDark>(Vec(10.23, 179), module,
                                          M1x8Module::SECOND_OUTPUT));
  addOutput(createOutput<RCJackSmallDark>(Vec(10.23, 200), module,
                                          M1x8Module::THIRD_OUTPUT));
  addOutput(createOutput<RCJackSmallDark>(Vec(10.23, 221), module,
                                          M1x8Module::FOURTH_OUTPUT));
  addOutput(createOutput<RCJackSmallDark>(Vec(10.23, 242), module,
                                          M1x8Module::FIFTH_OUTPUT));
  addOutput(createOutput<RCJackSmallDark>(Vec(10.23, 263), module,
                                          M1x8Module::SIXTH_OUTPUT));
  addOutput(createOutput<RCJackSmallDark>(Vec(10.23, 284), module,
                                          M1x8Module::SEVENTH_OUTPUT));
  addOutput(createOutput<RCJackSmallDark>(Vec(10.23, 305), module,
                                          M1x8Module::EIGHTH_OUTPUT));
}

Model *modelM1x8 = createModel<M1x8Module, M1x8Widget>("1x8Splitter");
