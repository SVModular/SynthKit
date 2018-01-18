#include <stdint.h>

#include "SynthKit.hpp"
#include "../deps/SynthDevKit/src/CV.hpp"
#include "components/knobs.hpp"

struct Seq4Module : Module {
	enum ParamIds {
    OCTAVE_PARAM,
    SEQ1_PARAM,
    SEQ2_PARAM,
    SEQ3_PARAM,
    SEQ4_PARAM,
		NUM_PARAMS
	};
	enum InputIds {
		CLOCK_INPUT,
		NUM_INPUTS
	};
	enum OutputIds {
		GATE_OUTPUT,
		NUM_OUTPUTS
	};
	enum LightIds {
    FIRST_LED,
    SECOND_LED,
    THIRD_LED,
    FOURTH_LED,
		NUM_LIGHTS
	};

	Seq4Module() : Module(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS) {
    cv = new SynthDevKit::CV(1.7f);
    currentStep = 0;
  }

	void step() override;

  SynthDevKit::CV *cv;

  float notes[12] = { 0, 0.08, 0.17, 0.25, 0.33, 0.42, 0.5, 0.58, 0.67, 0.75, 0.83, 0.92 };
  int octives[9] = { -5, -4, -3, -2, -1, 0, 1, 2, 3 };
  int currentStep;
};


void Seq4Module::step() {
	float in = inputs[CLOCK_INPUT].value;
  cv->update(in);

  if (cv->newTrigger()) {
    float note = octives[(int) params[OCTAVE_PARAM].value] + notes[(int) params[OCTAVE_PARAM + currentStep + 1].value];

    outputs[GATE_OUTPUT].value = note;

    for (int i = 0; i < 4; i++) {
      if (i == currentStep) {
        lights[i].value = 1.0;
      } else {
        lights[i].value = 0.0;
      }
    }
    currentStep++;

    if (currentStep == 4) {
      currentStep = 0;
    }
  }
}


Seq4Widget::Seq4Widget() {
	Seq4Module *module = new Seq4Module();
	setModule(module);
	box.size = Vec(3 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT);

	{
		SVGPanel *panel = new SVGPanel();
		panel->box.size = box.size;
		panel->setBackground(SVG::load(assetPlugin(plugin, "res/Seq4.svg")));
		addChild(panel);
	}

	addChild(createScrew<ScrewSilver>(Vec(RACK_GRID_WIDTH, 0)));
	addChild(createScrew<ScrewSilver>(Vec(RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));

	addInput(createInput<PJ301MPort>(Vec(10, 34), module, Seq4Module::CLOCK_INPUT));

  addParam(createParam<SKRoundSmallWhiteSnapKnob>(Vec(9, 80), module, Seq4Module::OCTAVE_PARAM, 0.0, 8.0, 4.0));
  addParam(createParam<SKRoundSmallWhiteSnapKnob>(Vec(9, 130), module, Seq4Module::SEQ1_PARAM, 0.0, 11.0, 5.0));
  addParam(createParam<SKRoundSmallWhiteSnapKnob>(Vec(9, 170), module, Seq4Module::SEQ2_PARAM, 0.0, 11.0, 5.0));
  addParam(createParam<SKRoundSmallWhiteSnapKnob>(Vec(9, 210), module, Seq4Module::SEQ3_PARAM, 0.0, 11.0, 5.0));
  addParam(createParam<SKRoundSmallWhiteSnapKnob>(Vec(9, 250), module, Seq4Module::SEQ4_PARAM, 0.0, 11.0, 5.0));

  addChild(createLight<MediumLight<GreenLight>>(Vec(29, 157), module, Seq4Module::FIRST_LED));
  addChild(createLight<MediumLight<GreenLight>>(Vec(29, 197), module, Seq4Module::SECOND_LED));
  addChild(createLight<MediumLight<GreenLight>>(Vec(29, 237), module, Seq4Module::THIRD_LED));
  addChild(createLight<MediumLight<GreenLight>>(Vec(29, 277), module, Seq4Module::FOURTH_LED));

  addOutput(createOutput<PJ301MPort>(Vec(10, 310), module, Seq4Module::GATE_OUTPUT));
}
