#include <stdint.h>

#include "SynthKit.hpp"
#include "../deps/SynthDevKit/src/Clock.hpp"

struct ClockDividerModule : Module {
	enum ParamIds {
		NUM_PARAMS
	};
	enum InputIds {
		TOP_INPUT,
		NUM_INPUTS
	};
	enum OutputIds {
		FIRST_OUTPUT,
		SECOND_OUTPUT,
		THIRD_OUTPUT,
		FOURTH_OUTPUT,
		FIFTH_OUTPUT,
		SIXTH_OUTPUT,
		SEVENTH_OUTPUT,
		EIGHTH_OUTPUT,
		NUM_OUTPUTS
	};
	enum LightIds {
    FIRST_LED,
    SECOND_LED,
    THIRD_LED,
    FOURTH_LED,
    FIFTH_LED,
    SIXTH_LED,
    SEVENTH_LED,
    EIGHTH_LED,
		NUM_LIGHTS
	};

	ClockDividerModule() : Module(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS) {
    clock = new SynthDevKit::Clock(8, 1.5);
  }

	void step() override;

  SynthDevKit::Clock *clock;
};


void ClockDividerModule::step() {
	float in = inputs[TOP_INPUT].value;
  bool *states = clock->update(in);

	for (int i = 0; i < 8; i++) {
		if (states[i] == true) {
			outputs[i].value = in;
			lights[i].value = 1.0f;
		} else {
			outputs[i].value = 0;
			lights[i].value = 0;
		}
	}
}


ClockDividerWidget::ClockDividerWidget() {
	ClockDividerModule *module = new ClockDividerModule();
	setModule(module);
	box.size = Vec(3 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT);

	{
		SVGPanel *panel = new SVGPanel();
		panel->box.size = box.size;
		panel->setBackground(SVG::load(assetPlugin(plugin, "res/ClockDivider.svg")));
		addChild(panel);
	}

	addChild(createScrew<ScrewSilver>(Vec(RACK_GRID_WIDTH, 0)));
	addChild(createScrew<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, 0)));

	addInput(createInput<PJ301MPort>(Vec(10, 33), module, ClockDividerModule::TOP_INPUT));
	addOutput(createOutput<PJ301MPort>(Vec(10, 73), module, ClockDividerModule::FIRST_OUTPUT));
	addOutput(createOutput<PJ301MPort>(Vec(10, 107), module, ClockDividerModule::SECOND_OUTPUT));
	addOutput(createOutput<PJ301MPort>(Vec(10, 140), module, ClockDividerModule::THIRD_OUTPUT));
	addOutput(createOutput<PJ301MPort>(Vec(10, 173), module, ClockDividerModule::FOURTH_OUTPUT));
	addOutput(createOutput<PJ301MPort>(Vec(10, 207), module, ClockDividerModule::FIFTH_OUTPUT));
	addOutput(createOutput<PJ301MPort>(Vec(10, 242), module, ClockDividerModule::SIXTH_OUTPUT));
	addOutput(createOutput<PJ301MPort>(Vec(10, 279), module, ClockDividerModule::SEVENTH_OUTPUT));
	addOutput(createOutput<PJ301MPort>(Vec(10, 314), module, ClockDividerModule::EIGHTH_OUTPUT));

  addChild(createLight<MediumLight<GreenLight>>(Vec(35, 81), module, ClockDividerModule::FIRST_LED));
  addChild(createLight<MediumLight<GreenLight>>(Vec(35, 115), module, ClockDividerModule::SECOND_LED));
  addChild(createLight<MediumLight<GreenLight>>(Vec(35, 148), module, ClockDividerModule::THIRD_LED));
  addChild(createLight<MediumLight<GreenLight>>(Vec(35, 181), module, ClockDividerModule::FOURTH_LED));
  addChild(createLight<MediumLight<GreenLight>>(Vec(35, 215), module, ClockDividerModule::FIFTH_LED));
  addChild(createLight<MediumLight<GreenLight>>(Vec(35, 250), module, ClockDividerModule::SIXTH_LED));
  addChild(createLight<MediumLight<GreenLight>>(Vec(35, 287), module, ClockDividerModule::SEVENTH_LED));
  addChild(createLight<MediumLight<GreenLight>>(Vec(35, 322), module, ClockDividerModule::EIGHTH_LED));
}
