#include "../controller/Subtraction.hpp"
#include "../../deps/rack-components/jacks.hpp"
#include "../../deps/rack-components/screws.hpp"

struct SubtractionWidget : ModuleWidget {
  SubtractionWidget(SubtractionModule *module);
};

SubtractionWidget::SubtractionWidget(SubtractionModule *module)
    {
		setModule(module);
  box.size = Vec(3 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT);

  setPanel(APP->window->loadSvg(asset::plugin(pluginInstance, "res/Subtraction.svg")));

  addChild(createWidget<JLHHexScrew>(Vec(1, 1)));
  addChild(createWidget<JLHHexScrew>(Vec(31, 366)));

  addInput(createInput<RCJackSmallLight>(Vec(10.23, 73), module,
                                          SubtractionModule::TOP1_INPUT));
  addInput(createInput<RCJackSmallLight>(Vec(10.23, 115), module,
                                         SubtractionModule::TOP2_INPUT));

  addOutput(createOutput<RCJackSmallDark>(Vec(10.23, 158), module,
                                          SubtractionModule::TOP_OUTPUT));

  addInput(createInput<RCJackSmallLight>(Vec(10.23, 220), module,
                                          SubtractionModule::BOTTOM1_INPUT));
  addInput(createInput<RCJackSmallLight>(Vec(10.23, 262), module,
                                         SubtractionModule::BOTTOM2_INPUT));

  addOutput(createOutput<RCJackSmallDark>(Vec(10.23, 305), module,
                                          SubtractionModule::BOTTOM_OUTPUT));
}

Model *modelSubtraction = createModel<SubtractionModule, SubtractionWidget>("Subtraction");
