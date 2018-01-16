#include <stdint.h>
#include <stdio.h>
#include "SynthKit.hpp"
#include "../deps/SynthDevKit/src/Clock.hpp"
#include "../deps/SynthDevKit/src/CV.hpp"

struct RotatingClockDividerModule : Module {
	enum ParamIds {
		NUM_PARAMS
	};
	enum InputIds {
		TOP_INPUT,
		ROTATE_INPUT,
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
		ROTATE_LED,
		NUM_LIGHTS
	};

	RotatingClockDividerModule() : Module(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS) {
    clock = new SynthDevKit::Clock(8, 1.5);
		cv = new SynthDevKit::CV(1.5);
		count = 0;
  }

	void step() override;

  SynthDevKit::Clock *clock;
	SynthDevKit::CV *cv;
	int count;
};


void RotatingClockDividerModule::step() {
	float in = inputs[TOP_INPUT].value;
	float trigger = inputs[ROTATE_INPUT].value;

  bool *states = clock->update(in);
	cv->update(trigger);

	bool triggered = cv->newTrigger();
	if (triggered) {
		count++;
	}

	for (int i = 0; i < 8; i++) {
		int j = i + count;
		if (j >= 8) {
			j -= 8;
		}

		if (states[i] == true) {
			outputs[j].value = in;
			lights[j].value = 1.0f;
		} else {
			outputs[j].value = 0;
			lights[j].value = 0;
		}
	}

	if (count == 8) {
		count = 0;
	}
}


RotatingClockDividerWidget::RotatingClockDividerWidget() {
	RotatingClockDividerModule *module = new RotatingClockDividerModule();
	setModule(module);
	box.size = Vec(4 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT);

	{
		SVGPanel *panel = new SVGPanel();
		panel->box.size = box.size;
		panel->setBackground(SVG::load(assetPlugin(plugin, "res/RotatingClockDivider.svg")));
		addChild(panel);
	}

	addChild(createScrew<ScrewSilver>(Vec(RACK_GRID_WIDTH + 8, 0)));
	addChild(createScrew<ScrewSilver>(Vec(RACK_GRID_WIDTH + 8, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));

	addInput(createInput<PJ301MPort>(Vec(6, 34), module, RotatingClockDividerModule::ROTATE_INPUT));
	addInput(createInput<PJ301MPort>(Vec(30, 34), module, RotatingClockDividerModule::TOP_INPUT));
	addOutput(createOutput<PJ301MPort>(Vec(17, 73), module, RotatingClockDividerModule::FIRST_OUTPUT));
	addOutput(createOutput<PJ301MPort>(Vec(17, 108), module, RotatingClockDividerModule::SECOND_OUTPUT));
	addOutput(createOutput<PJ301MPort>(Vec(17, 143), module, RotatingClockDividerModule::THIRD_OUTPUT));
	addOutput(createOutput<PJ301MPort>(Vec(17, 178), module, RotatingClockDividerModule::FOURTH_OUTPUT));
	addOutput(createOutput<PJ301MPort>(Vec(17, 213), module, RotatingClockDividerModule::FIFTH_OUTPUT));
	addOutput(createOutput<PJ301MPort>(Vec(17, 248), module, RotatingClockDividerModule::SIXTH_OUTPUT));
	addOutput(createOutput<PJ301MPort>(Vec(17, 283), module, RotatingClockDividerModule::SEVENTH_OUTPUT));
	addOutput(createOutput<PJ301MPort>(Vec(17, 318), module, RotatingClockDividerModule::EIGHTH_OUTPUT));

  addChild(createLight<MediumLight<GreenLight>>(Vec(43, 81), module, RotatingClockDividerModule::FIRST_LED));
  addChild(createLight<MediumLight<GreenLight>>(Vec(43, 116), module, RotatingClockDividerModule::SECOND_LED));
  addChild(createLight<MediumLight<GreenLight>>(Vec(43, 151), module, RotatingClockDividerModule::THIRD_LED));
  addChild(createLight<MediumLight<GreenLight>>(Vec(43, 186), module, RotatingClockDividerModule::FOURTH_LED));
  addChild(createLight<MediumLight<GreenLight>>(Vec(43, 221), module, RotatingClockDividerModule::FIFTH_LED));
  addChild(createLight<MediumLight<GreenLight>>(Vec(43, 256), module, RotatingClockDividerModule::SIXTH_LED));
  addChild(createLight<MediumLight<GreenLight>>(Vec(43, 291), module, RotatingClockDividerModule::SEVENTH_LED));
  addChild(createLight<MediumLight<GreenLight>>(Vec(43, 326), module, RotatingClockDividerModule::EIGHTH_LED));
}
