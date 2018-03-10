#include "SynthKit.hpp"


struct AndModule : Module {
	enum ParamIds {
		NUM_PARAMS
	};
	enum InputIds {
		TOP1_INPUT,
		TOP2_INPUT,
		BOTTOM1_INPUT,
		BOTTOM2_INPUT,
		NUM_INPUTS
	};
	enum OutputIds {
		TOP_OUTPUT,
		BOTTOM_OUTPUT,
		NUM_OUTPUTS
	};
	enum LightIds {
		NUM_LIGHTS
	};

	AndModule() : Module(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS) {}
	void step() override;

	// For more advanced Module features, read Rack's engine.hpp header file
	// - toJson, fromJson: serialization of internal data
	// - onSampleRateChange: event triggered by a change of sample rate
	// - reset, randomize: implements special behavior when user clicks these from the context menu
};


void AndModule::step() {
	float top1 = inputs[TOP1_INPUT].value;
	float top2 = inputs[TOP2_INPUT].value;
	float bottom1 = inputs[BOTTOM1_INPUT].value;
	float bottom2 = inputs[BOTTOM2_INPUT].value;

	double val1 = (double) ((long long)(top1 * 10000) & (long long)(top2 * 10000)) / 10000;
	double val2 = (double) ((long long)(bottom1 * 10000) & (long long)(bottom2 * 10000)) / 10000;

	outputs[TOP_OUTPUT].value = (float) val1;
	outputs[BOTTOM_OUTPUT].value = (float) val2;
}

struct AndWidget : ModuleWidget {
	AndWidget(AndModule *module);
};

AndWidget::AndWidget(AndModule *module) : ModuleWidget(module) {
	box.size = Vec(3 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT);

	{
		SVGPanel *panel = new SVGPanel();
		panel->box.size = box.size;
		panel->setBackground(SVG::load(assetPlugin(plugin, "res/And.svg")));
		addChild(panel);
	}

	addChild(Widget::create<ScrewSilver>(Vec(RACK_GRID_WIDTH, 0)));
	addChild(Widget::create<ScrewSilver>(Vec(RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));

	addInput(Port::create<PJ301MPort>(Vec(10, 45), Port::INPUT, module, AndModule::TOP1_INPUT));
	addInput(Port::create<PJ301MPort>(Vec(10, 95), Port::INPUT, module, AndModule::TOP2_INPUT));

	addOutput(Port::create<PJ301MPort>(Vec(10, 143), Port::OUTPUT, module, AndModule::TOP_OUTPUT));

	addInput(Port::create<PJ301MPort>(Vec(10, 203), Port::INPUT, module, AndModule::BOTTOM1_INPUT));
	addInput(Port::create<PJ301MPort>(Vec(10, 252), Port::INPUT, module, AndModule::BOTTOM2_INPUT));

	addOutput(Port::create<PJ301MPort>(Vec(10, 301), Port::OUTPUT, module, AndModule::BOTTOM_OUTPUT));
}

Model *modelAnd = Model::create<AndModule, AndWidget>("SynthKit", "And", "And", MIXER_TAG);
