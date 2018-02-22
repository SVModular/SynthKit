#include <stdint.h>
#include "SynthKit.hpp"
#include "../deps/SynthDevKit/src/PrimeClock.hpp"

struct PrimeClockDividerModule : Module {
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

	PrimeClockDividerModule() : Module(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS) {
    clock = new SynthDevKit::PrimeClock(8, 1.7f);
  }

	void step() override;

  SynthDevKit::PrimeClock *clock;
};


void PrimeClockDividerModule::step() {
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


struct PrimeClockDividerWidget : ModuleWidget {
	PrimeClockDividerWidget(PrimeClockDividerModule *module);
};

PrimeClockDividerWidget::PrimeClockDividerWidget(PrimeClockDividerModule *module) : ModuleWidget(module) {
	box.size = Vec(3 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT);

	{
		SVGPanel *panel = new SVGPanel();
		panel->box.size = box.size;
		panel->setBackground(SVG::load(assetPlugin(plugin, "res/PrimeClockDivider.svg")));
		addChild(panel);
	}

	addChild(Widget::create<ScrewSilver>(Vec(RACK_GRID_WIDTH, 0)));
	addChild(Widget::create<ScrewSilver>(Vec(RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));

	addInput(Port::create<PJ301MPort>(Vec(10, 34), Port::INPUT, module, PrimeClockDividerModule::TOP_INPUT));
	addOutput(Port::create<PJ301MPort>(Vec(10, 73), Port::OUTPUT, module, PrimeClockDividerModule::FIRST_OUTPUT));
	addOutput(Port::create<PJ301MPort>(Vec(10, 108), Port::OUTPUT, module, PrimeClockDividerModule::SECOND_OUTPUT));
	addOutput(Port::create<PJ301MPort>(Vec(10, 143), Port::OUTPUT, module, PrimeClockDividerModule::THIRD_OUTPUT));
	addOutput(Port::create<PJ301MPort>(Vec(10, 178), Port::OUTPUT, module, PrimeClockDividerModule::FOURTH_OUTPUT));
	addOutput(Port::create<PJ301MPort>(Vec(10, 213), Port::OUTPUT, module, PrimeClockDividerModule::FIFTH_OUTPUT));
	addOutput(Port::create<PJ301MPort>(Vec(10, 248), Port::OUTPUT, module, PrimeClockDividerModule::SIXTH_OUTPUT));
	addOutput(Port::create<PJ301MPort>(Vec(10, 283), Port::OUTPUT, module, PrimeClockDividerModule::SEVENTH_OUTPUT));
	addOutput(Port::create<PJ301MPort>(Vec(10, 318), Port::OUTPUT, module, PrimeClockDividerModule::EIGHTH_OUTPUT));

  addChild(ModuleLightWidget::create<MediumLight<GreenLight>>(Vec(35, 81), module, PrimeClockDividerModule::FIRST_LED));
  addChild(ModuleLightWidget::create<MediumLight<GreenLight>>(Vec(35, 116), module, PrimeClockDividerModule::SECOND_LED));
  addChild(ModuleLightWidget::create<MediumLight<GreenLight>>(Vec(35, 151), module, PrimeClockDividerModule::THIRD_LED));
  addChild(ModuleLightWidget::create<MediumLight<GreenLight>>(Vec(35, 186), module, PrimeClockDividerModule::FOURTH_LED));
  addChild(ModuleLightWidget::create<MediumLight<GreenLight>>(Vec(35, 221), module, PrimeClockDividerModule::FIFTH_LED));
  addChild(ModuleLightWidget::create<MediumLight<GreenLight>>(Vec(35, 256), module, PrimeClockDividerModule::SIXTH_LED));
  addChild(ModuleLightWidget::create<MediumLight<GreenLight>>(Vec(35, 291), module, PrimeClockDividerModule::SEVENTH_LED));
  addChild(ModuleLightWidget::create<MediumLight<GreenLight>>(Vec(35, 326), module, PrimeClockDividerModule::EIGHTH_LED));
}

Model *modelPrimeClockDivider = Model::create<PrimeClockDividerModule, PrimeClockDividerWidget>("SynthKit", "Prime Clock Divider", "Prime Clock Divider", UTILITY_TAG, CLOCK_TAG);
