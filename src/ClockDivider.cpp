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
    clock = new SynthDevKit::Clock(8, 1.7f);
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


struct ClockDividerWidget : ModuleWidget {
	ClockDividerWidget(ClockDividerModule *module);
};

ClockDividerWidget::ClockDividerWidget(ClockDividerModule *module) : ModuleWidget(module) {
	box.size = Vec(3 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT);

	{
		SVGPanel *panel = new SVGPanel();
		panel->box.size = box.size;
		panel->setBackground(SVG::load(assetPlugin(plugin, "res/ClockDivider.svg")));
		addChild(panel);
	}

	addChild(Widget::create<ScrewSilver>(Vec(RACK_GRID_WIDTH, 0)));
	addChild(Widget::create<ScrewSilver>(Vec(RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));

	addInput(Port::create<PJ301MPort>(Vec(10, 34), Port::INPUT, module, ClockDividerModule::TOP_INPUT));
	addOutput(Port::create<PJ301MPort>(Vec(10, 73), Port::OUTPUT, module, ClockDividerModule::FIRST_OUTPUT));
	addOutput(Port::create<PJ301MPort>(Vec(10, 108), Port::OUTPUT, module, ClockDividerModule::SECOND_OUTPUT));
	addOutput(Port::create<PJ301MPort>(Vec(10, 143), Port::OUTPUT, module, ClockDividerModule::THIRD_OUTPUT));
	addOutput(Port::create<PJ301MPort>(Vec(10, 178), Port::OUTPUT, module, ClockDividerModule::FOURTH_OUTPUT));
	addOutput(Port::create<PJ301MPort>(Vec(10, 213), Port::OUTPUT, module, ClockDividerModule::FIFTH_OUTPUT));
	addOutput(Port::create<PJ301MPort>(Vec(10, 248), Port::OUTPUT, module, ClockDividerModule::SIXTH_OUTPUT));
	addOutput(Port::create<PJ301MPort>(Vec(10, 283), Port::OUTPUT, module, ClockDividerModule::SEVENTH_OUTPUT));
	addOutput(Port::create<PJ301MPort>(Vec(10, 318), Port::OUTPUT, module, ClockDividerModule::EIGHTH_OUTPUT));

  addChild(ModuleLightWidget::create<MediumLight<GreenLight>>(Vec(35, 81), module, ClockDividerModule::FIRST_LED));
  addChild(ModuleLightWidget::create<MediumLight<GreenLight>>(Vec(35, 116), module, ClockDividerModule::SECOND_LED));
  addChild(ModuleLightWidget::create<MediumLight<GreenLight>>(Vec(35, 151), module, ClockDividerModule::THIRD_LED));
  addChild(ModuleLightWidget::create<MediumLight<GreenLight>>(Vec(35, 186), module, ClockDividerModule::FOURTH_LED));
  addChild(ModuleLightWidget::create<MediumLight<GreenLight>>(Vec(35, 221), module, ClockDividerModule::FIFTH_LED));
  addChild(ModuleLightWidget::create<MediumLight<GreenLight>>(Vec(35, 256), module, ClockDividerModule::SIXTH_LED));
  addChild(ModuleLightWidget::create<MediumLight<GreenLight>>(Vec(35, 291), module, ClockDividerModule::SEVENTH_LED));
  addChild(ModuleLightWidget::create<MediumLight<GreenLight>>(Vec(35, 326), module, ClockDividerModule::EIGHTH_LED));
}

Model *modelClockDivider = Model::create<ClockDividerModule, ClockDividerWidget>("SynthKit", "Clock Divider", "Clock Divider", UTILITY_TAG, CLOCK_TAG);
