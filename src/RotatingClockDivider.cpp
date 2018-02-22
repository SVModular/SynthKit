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
    clock = new SynthDevKit::Clock(8, 1.7f);
		cv = new SynthDevKit::CV(1.7f);
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


struct RotatingClockDividerWidget : ModuleWidget {
	RotatingClockDividerWidget(RotatingClockDividerModule *module);
};

RotatingClockDividerWidget::RotatingClockDividerWidget(RotatingClockDividerModule *module) : ModuleWidget(module) {
	box.size = Vec(4 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT);

	{
		SVGPanel *panel = new SVGPanel();
		panel->box.size = box.size;
		panel->setBackground(SVG::load(assetPlugin(plugin, "res/RotatingClockDivider.svg")));
		addChild(panel);
	}

	addChild(Widget::create<ScrewSilver>(Vec(RACK_GRID_WIDTH + 8, 0)));
	addChild(Widget::create<ScrewSilver>(Vec(RACK_GRID_WIDTH + 8, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));

	addInput(Port::create<PJ301MPort>(Vec(6, 34), Port::INPUT, module, RotatingClockDividerModule::ROTATE_INPUT));
	addInput(Port::create<PJ301MPort>(Vec(30, 34), Port::INPUT, module, RotatingClockDividerModule::TOP_INPUT));
	addOutput(Port::create<PJ301MPort>(Vec(17, 73), Port::OUTPUT, module, RotatingClockDividerModule::FIRST_OUTPUT));
	addOutput(Port::create<PJ301MPort>(Vec(17, 108), Port::OUTPUT, module, RotatingClockDividerModule::SECOND_OUTPUT));
	addOutput(Port::create<PJ301MPort>(Vec(17, 143), Port::OUTPUT, module, RotatingClockDividerModule::THIRD_OUTPUT));
	addOutput(Port::create<PJ301MPort>(Vec(17, 178), Port::OUTPUT, module, RotatingClockDividerModule::FOURTH_OUTPUT));
	addOutput(Port::create<PJ301MPort>(Vec(17, 213), Port::OUTPUT, module, RotatingClockDividerModule::FIFTH_OUTPUT));
	addOutput(Port::create<PJ301MPort>(Vec(17, 248), Port::OUTPUT, module, RotatingClockDividerModule::SIXTH_OUTPUT));
	addOutput(Port::create<PJ301MPort>(Vec(17, 283), Port::OUTPUT, module, RotatingClockDividerModule::SEVENTH_OUTPUT));
	addOutput(Port::create<PJ301MPort>(Vec(17, 318), Port::OUTPUT, module, RotatingClockDividerModule::EIGHTH_OUTPUT));

  addChild(ModuleLightWidget::create<MediumLight<GreenLight>>(Vec(43, 81), module, RotatingClockDividerModule::FIRST_LED));
  addChild(ModuleLightWidget::create<MediumLight<GreenLight>>(Vec(43, 116), module, RotatingClockDividerModule::SECOND_LED));
  addChild(ModuleLightWidget::create<MediumLight<GreenLight>>(Vec(43, 151), module, RotatingClockDividerModule::THIRD_LED));
  addChild(ModuleLightWidget::create<MediumLight<GreenLight>>(Vec(43, 186), module, RotatingClockDividerModule::FOURTH_LED));
  addChild(ModuleLightWidget::create<MediumLight<GreenLight>>(Vec(43, 221), module, RotatingClockDividerModule::FIFTH_LED));
  addChild(ModuleLightWidget::create<MediumLight<GreenLight>>(Vec(43, 256), module, RotatingClockDividerModule::SIXTH_LED));
  addChild(ModuleLightWidget::create<MediumLight<GreenLight>>(Vec(43, 291), module, RotatingClockDividerModule::SEVENTH_LED));
  addChild(ModuleLightWidget::create<MediumLight<GreenLight>>(Vec(43, 326), module, RotatingClockDividerModule::EIGHTH_LED));
}

Model *modelRotatingClockDivider = Model::create<RotatingClockDividerModule, RotatingClockDividerWidget>("SynthKit", "Rotating Clock Divider", "Rotating Clock Divider", UTILITY_TAG, CLOCK_TAG);
