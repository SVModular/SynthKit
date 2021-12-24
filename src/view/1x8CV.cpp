#include "../controller/1x8CV.hpp"
#include "../../deps/rack-components/jacks.hpp"
#include "../../deps/rack-components/screws.hpp"

struct M1x8CVWidget : ModuleWidget {
  M1x8CVWidget(M1x8CVModule *module);
};

M1x8CVWidget::M1x8CVWidget(M1x8CVModule *module) {
  setModule(module);
  box.size = Vec(4 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT);

  setPanel(APP->window->loadSvg(asset::plugin(pluginInstance, "res/1x8CV.svg")));

  addChild(createWidget<JLHHexScrew>(Vec(1, 1)));
  addChild(createWidget<JLHHexScrew>(Vec(46, 366)));

  addInput(createInput<RCJackSmallLight>(Vec(17.73, 73), module,
                                          M1x8CVModule::TOP_INPUT));

  addInput(createInput<RCJackSmallLight>(Vec(0.48, 158), module,
                                          M1x8CVModule::CV_INPUT + 0));
  addOutput(createOutput<RCJackSmallDark>(Vec(25.23, 158), module,
                                          M1x8CVModule::CH_OUTPUT + 0));
  addChild(createLight<SmallLight<GreenLight>>(
      Vec(51.5, 167.06), module, M1x8CVModule::CH_LED + 0));

  addInput(createInput<RCJackSmallLight>(Vec(0.48, 179), module,
                                          M1x8CVModule::CV_INPUT + 1));
  addOutput(createOutput<RCJackSmallDark>(Vec(25.23, 179), module,
                                          M1x8CVModule::CH_OUTPUT + 1));
  addChild(createLight<SmallLight<GreenLight>>(
      Vec(51.5, 188.06), module, M1x8CVModule::CH_LED + 1));

  addInput(createInput<RCJackSmallLight>(Vec(0.48, 200), module,
                                          M1x8CVModule::CV_INPUT + 2));
  addOutput(createOutput<RCJackSmallDark>(Vec(25.23, 200), module,
                                          M1x8CVModule::CH_OUTPUT + 2));
  addChild(createLight<SmallLight<GreenLight>>(
      Vec(51.5, 209.06), module, M1x8CVModule::CH_LED + 2));

  addInput(createInput<RCJackSmallLight>(Vec(0.48, 221), module,
                                          M1x8CVModule::CV_INPUT + 3));
  addOutput(createOutput<RCJackSmallDark>(Vec(25.23, 221), module,
                                          M1x8CVModule::CH_OUTPUT + 3));
  addChild(createLight<SmallLight<GreenLight>>(
      Vec(51.5, 230.06), module, M1x8CVModule::CH_LED + 3));

  addInput(createInput<RCJackSmallLight>(Vec(0.48, 242), module,
                                          M1x8CVModule::CV_INPUT + 4));
  addOutput(createOutput<RCJackSmallDark>(Vec(25.23, 242), module,
                                          M1x8CVModule::CH_OUTPUT + 4));
  addChild(createLight<SmallLight<GreenLight>>(
      Vec(51.5, 251.06), module, M1x8CVModule::CH_LED + 4));

  addInput(createInput<RCJackSmallLight>(Vec(0.48, 263), module,
                                          M1x8CVModule::CV_INPUT + 5));
  addOutput(createOutput<RCJackSmallDark>(Vec(25.23, 263), module,
                                          M1x8CVModule::CH_OUTPUT + 5));
  addChild(createLight<SmallLight<GreenLight>>(
      Vec(51.5, 272.06), module, M1x8CVModule::CH_LED + 5));

  addInput(createInput<RCJackSmallLight>(Vec(0.48, 284), module,
                                          M1x8CVModule::CV_INPUT + 6));
  addOutput(createOutput<RCJackSmallDark>(Vec(25.23, 284), module,
                                          M1x8CVModule::CH_OUTPUT + 6));
  addChild(createLight<SmallLight<GreenLight>>(
      Vec(51.5, 293.06), module, M1x8CVModule::CH_LED + 6));

  addInput(createInput<RCJackSmallLight>(Vec(0.48, 305), module,
                                          M1x8CVModule::CV_INPUT + 7));
  addOutput(createOutput<RCJackSmallDark>(Vec(25.23, 305), module,
                                          M1x8CVModule::CH_OUTPUT + 7));
  addChild(createLight<SmallLight<GreenLight>>(
      Vec(51.5, 314.06), module, M1x8CVModule::CH_LED + 7));
}

Model *modelM1x8CV = createModel<M1x8CVModule, M1x8CVWidget>("1x8SplitterCV");
