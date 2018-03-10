#include "SynthKit.hpp"
#include "../deps/SynthDevKit/src/CV.hpp"

struct M1x8CVModule : Module {
	enum ParamIds {
		NUM_PARAMS
	};
	enum InputIds {
		TOP_INPUT,
		FIRST_CV,
		SECOND_CV,
		THIRD_CV,
		FOURTH_CV,
		FIFTH_CV,
		SIXTH_CV,
		SEVENTH_CV,
		EIGHTH_CV,
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

	M1x8CVModule() : Module(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS) {
		for (int i = 0; i < 8; i++) {
			cv[i] = new SynthDevKit::CV(1.7f);
		}
	}
	void step() override;

	SynthDevKit::CV *cv[8];
};


void M1x8CVModule::step() {
	float in = inputs[TOP_INPUT].value;

	cv[0]->update(inputs[FIRST_CV].value);
	cv[1]->update(inputs[SECOND_CV].value);
	cv[2]->update(inputs[THIRD_CV].value);
	cv[3]->update(inputs[FOURTH_CV].value);
	cv[4]->update(inputs[FIFTH_CV].value);
	cv[5]->update(inputs[SIXTH_CV].value);
	cv[6]->update(inputs[SEVENTH_CV].value);
	cv[7]->update(inputs[EIGHTH_CV].value);

	if (cv[0]->isHigh()) {
		outputs[FIRST_OUTPUT].value = in;
		lights[FIRST_LED].value = 1;
	} else {
		outputs[FIRST_OUTPUT].value = 0;
		lights[FIRST_LED].value = 0;
	}

	if (cv[1]->isHigh()) {
		outputs[SECOND_OUTPUT].value = in;
		lights[SECOND_LED].value = 1;
	} else {
		outputs[SECOND_OUTPUT].value = 0;
		lights[SECOND_LED].value = 0;
	}

	if (cv[2]->isHigh()) {
		outputs[THIRD_OUTPUT].value = in;
		lights[THIRD_LED].value = 1;
	} else {
		outputs[THIRD_OUTPUT].value = 0;
		lights[THIRD_LED].value = 0;
	}

	if (cv[3]->isHigh()) {
		outputs[FOURTH_OUTPUT].value = in;
		lights[FOURTH_LED].value = 1;
	} else {
		outputs[FOURTH_OUTPUT].value = 0;
		lights[FOURTH_LED].value = 0;
	}

	if (cv[4]->isHigh()) {
		outputs[FIFTH_OUTPUT].value = in;
		lights[FIFTH_LED].value = 1;
	} else {
		outputs[FIFTH_OUTPUT].value = 0;
		lights[FIFTH_LED].value = 0;
	}

	if (cv[5]->isHigh()) {
		outputs[SIXTH_OUTPUT].value = in;
		lights[SIXTH_LED].value = 1;
	} else {
		outputs[SIXTH_OUTPUT].value = 0;
		lights[SIXTH_LED].value = 0;
	}

	if (cv[6]->isHigh()) {
		outputs[SEVENTH_OUTPUT].value = in;
		lights[SEVENTH_LED].value = 1;
	} else {
		outputs[SEVENTH_OUTPUT].value = 0;
		lights[SEVENTH_LED].value = 0;
	}

	if (cv[7]->isHigh()) {
		outputs[EIGHTH_OUTPUT].value = in;
		lights[EIGHTH_LED].value = 1;
	} else {
		outputs[EIGHTH_OUTPUT].value = 0;
		lights[EIGHTH_LED].value = 0;
	}
}

struct M1x8CVWidget : ModuleWidget {
	M1x8CVWidget(M1x8CVModule *module);
};

M1x8CVWidget::M1x8CVWidget(M1x8CVModule *module) : ModuleWidget(module) {
	box.size = Vec(6 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT);

	{
		SVGPanel *panel = new SVGPanel();
		panel->box.size = box.size;
		panel->setBackground(SVG::load(assetPlugin(plugin, "res/1x8CV.svg")));
		addChild(panel);
	}

	addChild(Widget::create<ScrewSilver>(Vec(RACK_GRID_WIDTH, 0)));
	addChild(Widget::create<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, 0)));
	addChild(Widget::create<ScrewSilver>(Vec(RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
	addChild(Widget::create<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));

	addInput(Port::create<PJ301MPort>(Vec(33, 34), Port::INPUT, module, M1x8CVModule::TOP_INPUT));

	addInput(Port::create<PJ301MPort>(Vec(13, 73), Port::INPUT, module, M1x8CVModule::FIRST_CV));
	addOutput(Port::create<PJ301MPort>(Vec(53, 73), Port::OUTPUT, module, M1x8CVModule::FIRST_OUTPUT));
	addChild(ModuleLightWidget::create<MediumLight<GreenLight>>(Vec(41, 81), module, M1x8CVModule::FIRST_LED));

	addInput(Port::create<PJ301MPort>(Vec(13, 108), Port::INPUT, module, M1x8CVModule::SECOND_CV));
	addOutput(Port::create<PJ301MPort>(Vec(53, 108), Port::OUTPUT, module, M1x8CVModule::SECOND_OUTPUT));
	addChild(ModuleLightWidget::create<MediumLight<GreenLight>>(Vec(41, 116), module, M1x8CVModule::SECOND_LED));

	addInput(Port::create<PJ301MPort>(Vec(13, 143), Port::INPUT, module, M1x8CVModule::THIRD_CV));
	addOutput(Port::create<PJ301MPort>(Vec(53, 143), Port::OUTPUT, module, M1x8CVModule::THIRD_OUTPUT));
	addChild(ModuleLightWidget::create<MediumLight<GreenLight>>(Vec(41, 151), module, M1x8CVModule::THIRD_LED));

	addInput(Port::create<PJ301MPort>(Vec(13, 178), Port::INPUT, module, M1x8CVModule::FOURTH_CV));
	addOutput(Port::create<PJ301MPort>(Vec(53, 178), Port::OUTPUT, module, M1x8CVModule::FOURTH_OUTPUT));
	addChild(ModuleLightWidget::create<MediumLight<GreenLight>>(Vec(41, 186), module, M1x8CVModule::FOURTH_LED));

	addInput(Port::create<PJ301MPort>(Vec(13, 213), Port::INPUT, module, M1x8CVModule::FIFTH_CV));
	addOutput(Port::create<PJ301MPort>(Vec(53, 213), Port::OUTPUT, module, M1x8CVModule::FIFTH_OUTPUT));
	addChild(ModuleLightWidget::create<MediumLight<GreenLight>>(Vec(41, 221), module, M1x8CVModule::FIFTH_LED));

	addInput(Port::create<PJ301MPort>(Vec(13, 248), Port::INPUT, module, M1x8CVModule::SIXTH_CV));
	addOutput(Port::create<PJ301MPort>(Vec(53, 248), Port::OUTPUT, module, M1x8CVModule::SIXTH_OUTPUT));
	addChild(ModuleLightWidget::create<MediumLight<GreenLight>>(Vec(41, 256), module, M1x8CVModule::SIXTH_LED));

	addInput(Port::create<PJ301MPort>(Vec(13, 283), Port::INPUT, module, M1x8CVModule::SEVENTH_CV));
	addOutput(Port::create<PJ301MPort>(Vec(53, 283), Port::OUTPUT, module, M1x8CVModule::SEVENTH_OUTPUT));
	addChild(ModuleLightWidget::create<MediumLight<GreenLight>>(Vec(41, 291), module, M1x8CVModule::SEVENTH_LED));

	addInput(Port::create<PJ301MPort>(Vec(13, 318), Port::INPUT, module, M1x8CVModule::EIGHTH_CV));
	addOutput(Port::create<PJ301MPort>(Vec(53, 318), Port::OUTPUT, module, M1x8CVModule::EIGHTH_OUTPUT));
	addChild(ModuleLightWidget::create<MediumLight<GreenLight>>(Vec(41, 326), module, M1x8CVModule::EIGHTH_LED));
}

Model *modelM1x8CV = Model::create<M1x8CVModule, M1x8CVWidget>("SynthKit", "1x8 Splitter (CV)", "1x8 Splitter (CV)", MIXER_TAG);
