#include <stdio.h>
#include "SynthKit.hpp"
#include "../deps/SynthDevKit/src/CV.hpp"

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
		BLINK_LIGHT,
		NUM_LIGHTS
	};

	DevKitModule() : Module(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS) {
		min = 0;
		max = 0;
		minimum = new TextField();
		maximum = new TextField();
		count = 0;
		cvcount = new TextField();
		cv = new SynthDevKit::CV(1.5f);
		interval = new TextField();
	}

	void step() override;
  TextField *minimum;
	TextField *maximum;
  float min, max;
	int count;
	TextField *cvcount;
	SynthDevKit::CV *cv;
	TextField *interval;
};


void DevKitModule::step() {
	float in = inputs[DEV_INPUT].value;

  if (min > in) {
    min = in;
  }

  if (max < in) {
    max = in;
  }

  char buf1[25];
  sprintf(buf1, "%0.5f", min);

  minimum->text = buf1;

  char buf2[25];
  sprintf(buf2, "%0.5f", max);

  maximum->text = buf2;

	cv->update(in);
	lights[BLINK_LIGHT].value = cv->isHigh() ? 1.0 : 0.0;

	if (cv->newTrigger()) {
		count++;
		char buf3[25];
	  sprintf(buf3, "%d", count);
		cvcount->text = buf3;

		sprintf(buf3, "%d", cv->triggerInterval());
		interval->text = buf3;
	}
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
  module->minimum->box.pos = Vec(14, 78);
  module->maximum->box.pos = Vec(14, 126);

  module->minimum->text = "minimum";
  module->maximum->text = "maximum";

  addChild(module->minimum);
  addChild(module->maximum);

	addChild(createScrew<ScrewSilver>(Vec(RACK_GRID_WIDTH, 0)));
	addChild(createScrew<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, 0)));
	addChild(createScrew<ScrewSilver>(Vec(RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
	addChild(createScrew<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));

	addChild(createLight<MediumLight<RedLight>>(Vec(40, 173), module, DevKitModule::BLINK_LIGHT));

	module->cvcount->box.size = Vec(60, 20);
	module->cvcount->box.pos = Vec(14, 214);
	module->cvcount->text = "count";

	addChild(module->cvcount);

	module->interval->box.size = Vec(60, 20);
	module->interval->box.pos = Vec(14, 264);
	module->interval->text = "interval";

	addChild(module->interval);

	addInput(createInput<PJ301MPort>(Vec(33, 34), module, DevKitModule::DEV_INPUT));
}
