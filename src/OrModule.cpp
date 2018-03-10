#include "SynthKit.hpp"


struct OrModule : Module {
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

	OrModule() : Module(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS) {}
	void step() override;

	// For more advanced Module features, read Rack's engine.hpp header file
	// - toJson, fromJson: serialization of internal data
	// - onSampleRateChange: event triggered by a change of sample rate
	// - reset, randomize: implements special behavior when user clicks these from the context menu
};


void OrModule::step() {
	float top1 = inputs[TOP1_INPUT].value;
	float top2 = inputs[TOP2_INPUT].value;
	float bottom1 = inputs[BOTTOM1_INPUT].value;
	float bottom2 = inputs[BOTTOM2_INPUT].value;

	double val1 = (double) ((long long)(top1 * 10000) | (long long)(top2 * 10000)) / 10000;
	double val2 = (double) ((long long)(bottom1 * 10000) | (long long)(bottom2 * 10000)) / 10000;

	outputs[TOP_OUTPUT].value = (float) val1;
	outputs[BOTTOM_OUTPUT].value = (float) val2;
}


struct OrWidget : ModuleWidget {
	OrWidget(OrModule *module);
};

OrWidget::OrWidget(OrModule *module) : ModuleWidget(module) {
	box.size = Vec(3 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT);

	{
		SVGPanel *panel = new SVGPanel();
		panel->box.size = box.size;
		panel->setBackground(SVG::load(assetPlugin(plugin, "res/Or.svg")));
		addChild(panel);
	}

	addChild(Widget::create<ScrewSilver>(Vec(RACK_GRID_WIDTH, 0)));
	addChild(Widget::create<ScrewSilver>(Vec(RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));

	addInput(Port::create<PJ301MPort>(Vec(10, 45), Port::INPUT, module, OrModule::TOP1_INPUT));
	addInput(Port::create<PJ301MPort>(Vec(10, 94), Port::INPUT, module, OrModule::TOP2_INPUT));

	addOutput(Port::create<PJ301MPort>(Vec(10, 143), Port::OUTPUT, module, OrModule::TOP_OUTPUT));

	addInput(Port::create<PJ301MPort>(Vec(10, 203), Port::INPUT, module, OrModule::BOTTOM1_INPUT));
	addInput(Port::create<PJ301MPort>(Vec(10, 252), Port::INPUT, module, OrModule::BOTTOM2_INPUT));

	addOutput(Port::create<PJ301MPort>(Vec(10, 301), Port::OUTPUT, module, OrModule::BOTTOM_OUTPUT));
}

Model *modelOr = Model::create<OrModule, OrWidget>("SynthKit", "Or", "Or", MIXER_TAG);
