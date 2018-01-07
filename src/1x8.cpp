#include "SynthKit.hpp"


struct M1x8Module : Module {
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
		NUM_LIGHTS
	};

	M1x8Module() : Module(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS) {}
	void step() override;

	// For more advanced Module features, read Rack's engine.hpp header file
	// - toJson, fromJson: serialization of internal data
	// - onSampleRateChange: event triggered by a change of sample rate
	// - reset, randomize: implements special behavior when user clicks these from the context menu
};


void M1x8Module::step() {
	float in = inputs[TOP_INPUT].value;

	outputs[FIRST_OUTPUT].value = in;
	outputs[SECOND_OUTPUT].value = in;
	outputs[THIRD_OUTPUT].value = in;
	outputs[FOURTH_OUTPUT].value = in;
	outputs[FIFTH_OUTPUT].value = in;
	outputs[SIXTH_OUTPUT].value = in;
	outputs[SEVENTH_OUTPUT].value = in;
	outputs[EIGHTH_OUTPUT].value = in;
}


M1x8Widget::M1x8Widget() {
	M1x8Module *module = new M1x8Module();
	setModule(module);
	box.size = Vec(3 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT);

	{
		SVGPanel *panel = new SVGPanel();
		panel->box.size = box.size;
		panel->setBackground(SVG::load(assetPlugin(plugin, "res/1x8.svg")));
		addChild(panel);
	}

	addChild(createScrew<ScrewSilver>(Vec(RACK_GRID_WIDTH, 0)));
	addChild(createScrew<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, 0)));
	addChild(createScrew<ScrewSilver>(Vec(RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
	addChild(createScrew<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));

	addInput(createInput<PJ301MPort>(Vec(10, 34), module, M1x8Module::TOP_INPUT));
	addOutput(createOutput<PJ301MPort>(Vec(10, 70), module, M1x8Module::FIRST_OUTPUT));
	addOutput(createOutput<PJ301MPort>(Vec(10, 96), module, M1x8Module::SECOND_OUTPUT));
	addOutput(createOutput<PJ301MPort>(Vec(10, 122), module, M1x8Module::THIRD_OUTPUT));
	addOutput(createOutput<PJ301MPort>(Vec(10, 148), module, M1x8Module::FOURTH_OUTPUT));
	addOutput(createOutput<PJ301MPort>(Vec(10, 174), module, M1x8Module::FIFTH_OUTPUT));
	addOutput(createOutput<PJ301MPort>(Vec(10, 200), module, M1x8Module::SIXTH_OUTPUT));
	addOutput(createOutput<PJ301MPort>(Vec(10, 226), module, M1x8Module::SEVENTH_OUTPUT));
	addOutput(createOutput<PJ301MPort>(Vec(10, 252), module, M1x8Module::EIGHTH_OUTPUT));
}
