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
			cv[i] = new SynthDevKit::CV(1.5f);
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


M1x8CVWidget::M1x8CVWidget() {
	M1x8CVModule *module = new M1x8CVModule();
	setModule(module);
	box.size = Vec(6 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT);

	{
		SVGPanel *panel = new SVGPanel();
		panel->box.size = box.size;
		panel->setBackground(SVG::load(assetPlugin(plugin, "res/1x8CV.svg")));
		addChild(panel);
	}

	addChild(createScrew<ScrewSilver>(Vec(RACK_GRID_WIDTH, 0)));
	addChild(createScrew<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, 0)));
	addChild(createScrew<ScrewSilver>(Vec(RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
	addChild(createScrew<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));

	addInput(createInput<PJ301MPort>(Vec(34, 34), module, M1x8CVModule::TOP_INPUT));

	addInput(createInput<PJ301MPort>(Vec(13, 70), module, M1x8CVModule::FIRST_CV));
	addOutput(createOutput<PJ301MPort>(Vec(53, 70), module, M1x8CVModule::FIRST_OUTPUT));
	addChild(createLight<MediumLight<GreenLight>>(Vec(41, 78), module, M1x8CVModule::FIRST_LED));

	addInput(createInput<PJ301MPort>(Vec(13, 96), module, M1x8CVModule::SECOND_CV));
	addOutput(createOutput<PJ301MPort>(Vec(53, 96), module, M1x8CVModule::SECOND_OUTPUT));
	addChild(createLight<MediumLight<GreenLight>>(Vec(41, 104), module, M1x8CVModule::SECOND_LED));

	addInput(createInput<PJ301MPort>(Vec(13, 122), module, M1x8CVModule::THIRD_CV));
	addOutput(createOutput<PJ301MPort>(Vec(53, 122), module, M1x8CVModule::THIRD_OUTPUT));
	addChild(createLight<MediumLight<GreenLight>>(Vec(41, 130), module, M1x8CVModule::THIRD_LED));

	addInput(createInput<PJ301MPort>(Vec(13, 148), module, M1x8CVModule::FOURTH_CV));
	addOutput(createOutput<PJ301MPort>(Vec(53, 148), module, M1x8CVModule::FOURTH_OUTPUT));
	addChild(createLight<MediumLight<GreenLight>>(Vec(41, 156), module, M1x8CVModule::FOURTH_LED));

	addInput(createInput<PJ301MPort>(Vec(13, 174), module, M1x8CVModule::FIFTH_CV));
	addOutput(createOutput<PJ301MPort>(Vec(53, 174), module, M1x8CVModule::FIFTH_OUTPUT));
	addChild(createLight<MediumLight<GreenLight>>(Vec(41, 182), module, M1x8CVModule::FIFTH_LED));

	addInput(createInput<PJ301MPort>(Vec(13, 200), module, M1x8CVModule::SIXTH_CV));
	addOutput(createOutput<PJ301MPort>(Vec(53, 200), module, M1x8CVModule::SIXTH_OUTPUT));
	addChild(createLight<MediumLight<GreenLight>>(Vec(41, 208), module, M1x8CVModule::SIXTH_LED));

	addInput(createInput<PJ301MPort>(Vec(13, 226), module, M1x8CVModule::SEVENTH_CV));
	addOutput(createOutput<PJ301MPort>(Vec(53, 226), module, M1x8CVModule::SEVENTH_OUTPUT));
	addChild(createLight<MediumLight<GreenLight>>(Vec(41, 234), module, M1x8CVModule::SEVENTH_LED));

	addInput(createInput<PJ301MPort>(Vec(13, 252), module, M1x8CVModule::EIGHTH_CV));
	addOutput(createOutput<PJ301MPort>(Vec(53, 252), module, M1x8CVModule::EIGHTH_OUTPUT));
	addChild(createLight<MediumLight<GreenLight>>(Vec(41, 260), module, M1x8CVModule::EIGHTH_LED));
}
