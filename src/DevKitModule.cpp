#include <stdio.h>
#include "SynthKit.hpp"

struct DevKitModule : Module {
	enum ParamIds {
		NUM_PARAMS
	};
	enum InputIds {
		DEV_INPUT,
		NUM_INPUTS
	};
	enum OutputIds {
		NUM_OUTPUTS
	};
	enum LightIds {
		NUM_LIGHTS
	};

	DevKitModule() : Module(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS) { min = 0; max = 0; minimum = new TextField(); maximum = new TextField(); }
	void step() override;
  TextField *minimum;
	TextField *maximum;
  float min, max;
};


void DevKitModule::step() {
	float in = inputs[DEV_INPUT].value;

  if (min > in) {
    min = in;
  }

  if (max < in) {
    max = in;
  }

  char buf1[255];
  sprintf(buf1, "%f", min);

  minimum->text = buf1;

  char buf2[255];
  sprintf(buf2, "%f", max);

  maximum->text = buf2;
}


DevKitWidget::DevKitWidget() {
	DevKitModule *module = new DevKitModule();
	setModule(module);
	box.size = Vec(6 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT);

	{
		SVGPanel *panel = new SVGPanel();
		panel->box.size = box.size;
		panel->setBackground(SVG::load(assetPlugin(plugin, "res/DevKit.svg")));
		addChild(panel);
	}

  module->minimum->box.size = Vec(60, 20);
  module->maximum->box.size = Vec(60, 20);
  module->minimum->box.pos = Vec(14, 100);
  module->maximum->box.pos = Vec(14, 125);

  module->minimum->text = "minimum";
  module->maximum->text = "maximum";

  addChild(module->minimum);
  addChild(module->maximum);

	addChild(createScrew<ScrewSilver>(Vec(RACK_GRID_WIDTH, 0)));
	addChild(createScrew<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, 0)));
	addChild(createScrew<ScrewSilver>(Vec(RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
	addChild(createScrew<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));


	addInput(createInput<PJ301MPort>(Vec(33, 49), module, DevKitModule::DEV_INPUT));
}
