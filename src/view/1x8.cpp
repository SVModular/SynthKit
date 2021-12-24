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
                                          M1x8Module::CH_OUTPUT + 0));
  addOutput(createOutput<RCJackSmallDark>(Vec(10.23, 179), module,
                                          M1x8Module::CH_OUTPUT + 1));
  addOutput(createOutput<RCJackSmallDark>(Vec(10.23, 200), module,
                                          M1x8Module::CH_OUTPUT + 2));
  addOutput(createOutput<RCJackSmallDark>(Vec(10.23, 221), module,
                                          M1x8Module::CH_OUTPUT + 3));
  addOutput(createOutput<RCJackSmallDark>(Vec(10.23, 242), module,
                                          M1x8Module::CH_OUTPUT + 4));
  addOutput(createOutput<RCJackSmallDark>(Vec(10.23, 263), module,
                                          M1x8Module::CH_OUTPUT + 5));
  addOutput(createOutput<RCJackSmallDark>(Vec(10.23, 284), module,
                                          M1x8Module::CH_OUTPUT + 6));
  addOutput(createOutput<RCJackSmallDark>(Vec(10.23, 305), module,
                                          M1x8Module::CH_OUTPUT + 7));
}

Model *modelM1x8 = createModel<M1x8Module, M1x8Widget>("1x8Splitter");
