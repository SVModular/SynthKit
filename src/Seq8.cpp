#include <stdint.h>

#include "SynthKit.hpp"
#include "../deps/SynthDevKit/src/CV.hpp"
#include "components/knobs.hpp"

struct Seq8Module : Module {
	enum ParamIds {
    OCTAVE1_PARAM,
    OCTAVE2_PARAM,
    OCTAVE3_PARAM,
    OCTAVE4_PARAM,
    OCTAVE5_PARAM,
    OCTAVE6_PARAM,
    OCTAVE7_PARAM,
    OCTAVE8_PARAM,
    SEQ1_PARAM,
    SEQ2_PARAM,
    SEQ3_PARAM,
    SEQ4_PARAM,
    SEQ5_PARAM,
    SEQ6_PARAM,
    SEQ7_PARAM,
    SEQ8_PARAM,
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
    FIFTH_LED,
    SIXTH_LED,
    SEVENTH_LED,
    EIGHTH_LED,
		NUM_LIGHTS
	};

	Seq8Module() : Module(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS) {
    cv = new SynthDevKit::CV(1.7f);
    currentStep = 0;
  }

	void step() override;

  SynthDevKit::CV *cv;

  float notes[12] = { 0, 0.08, 0.17, 0.25, 0.33, 0.42, 0.5, 0.58, 0.67, 0.75, 0.83, 0.92 };
  int octives[9] = { -5, -4, -3, -2, -1, 0, 1, 2, 3 };
  int currentStep;
};


void Seq8Module::step() {
	float in = inputs[CLOCK_INPUT].value;
  cv->update(in);

  if (cv->newTrigger()) {
    for (int i = 0; i < 8; i++) {

      if (i == currentStep) {
        float note = octives[(int) params[i].value] + notes[(int) params[i + currentStep + 1].value];
        outputs[GATE_OUTPUT].value = note;
        lights[i].value = 1.0;
      } else {
        lights[i].value = 0.0;
      }
    }
    currentStep++;

    if (currentStep == 8) {
      currentStep = 0;
    }
  }
}


struct Seq8Widget : ModuleWidget {
	Seq8Widget(Seq8Module *module);
};

Seq8Widget::Seq8Widget(Seq8Module *module) : ModuleWidget(module) {
	box.size = Vec(4 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT);

	{
		SVGPanel *panel = new SVGPanel();
		panel->box.size = box.size;
		panel->setBackground(SVG::load(assetPlugin(plugin, "res/Seq8.svg")));
		addChild(panel);
	}

	addChild(Widget::create<ScrewSilver>(Vec(RACK_GRID_WIDTH, 0)));
	addChild(Widget::create<ScrewSilver>(Vec(RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
  addChild(Widget::create<ScrewSilver>(Vec(RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
	addChild(Widget::create<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));

	addInput(Port::create<PJ301MPort>(Vec(5, 34), Port::INPUT, module, Seq8Module::CLOCK_INPUT));
  addOutput(Port::create<PJ301MPort>(Vec(30, 34), Port::OUTPUT, module, Seq8Module::GATE_OUTPUT));

  addParam(ParamWidget::create<SKRoundTinyWhiteSnapKnob>(Vec(6, 76), module, Seq8Module::OCTAVE1_PARAM, 0.0, 8.0, 4.0));
  addParam(ParamWidget::create<SKRoundTinyWhiteSnapKnob>(Vec(6, 112), module, Seq8Module::OCTAVE2_PARAM, 0.0, 8.0, 4.0));
  addParam(ParamWidget::create<SKRoundTinyWhiteSnapKnob>(Vec(6, 146), module, Seq8Module::OCTAVE3_PARAM, 0.0, 8.0, 4.0));
  addParam(ParamWidget::create<SKRoundTinyWhiteSnapKnob>(Vec(6, 182), module, Seq8Module::OCTAVE4_PARAM, 0.0, 8.0, 4.0));
  addParam(ParamWidget::create<SKRoundTinyWhiteSnapKnob>(Vec(6, 216), module, Seq8Module::OCTAVE5_PARAM, 0.0, 8.0, 4.0));
  addParam(ParamWidget::create<SKRoundTinyWhiteSnapKnob>(Vec(6, 252), module, Seq8Module::OCTAVE6_PARAM, 0.0, 8.0, 4.0));
  addParam(ParamWidget::create<SKRoundTinyWhiteSnapKnob>(Vec(6, 286), module, Seq8Module::OCTAVE7_PARAM, 0.0, 8.0, 4.0));
  addParam(ParamWidget::create<SKRoundTinyWhiteSnapKnob>(Vec(6, 322), module, Seq8Module::OCTAVE8_PARAM, 0.0, 8.0, 4.0));

  addParam(ParamWidget::create<SKRoundTinyWhiteSnapKnob>(Vec(26, 76), module, Seq8Module::SEQ1_PARAM, 0.0, 11.0, 5.0));
  addParam(ParamWidget::create<SKRoundTinyWhiteSnapKnob>(Vec(26, 112), module, Seq8Module::SEQ2_PARAM, 0.0, 11.0, 5.0));
  addParam(ParamWidget::create<SKRoundTinyWhiteSnapKnob>(Vec(26, 146), module, Seq8Module::SEQ3_PARAM, 0.0, 11.0, 5.0));
  addParam(ParamWidget::create<SKRoundTinyWhiteSnapKnob>(Vec(26, 182), module, Seq8Module::SEQ4_PARAM, 0.0, 11.0, 5.0));
  addParam(ParamWidget::create<SKRoundTinyWhiteSnapKnob>(Vec(26, 216), module, Seq8Module::SEQ5_PARAM, 0.0, 11.0, 5.0));
  addParam(ParamWidget::create<SKRoundTinyWhiteSnapKnob>(Vec(26, 252), module, Seq8Module::SEQ6_PARAM, 0.0, 11.0, 5.0));
  addParam(ParamWidget::create<SKRoundTinyWhiteSnapKnob>(Vec(26, 286), module, Seq8Module::SEQ7_PARAM, 0.0, 11.0, 5.0));
  addParam(ParamWidget::create<SKRoundTinyWhiteSnapKnob>(Vec(26, 322), module, Seq8Module::SEQ8_PARAM, 0.0, 11.0, 5.0));

  addChild(ModuleLightWidget::create<MediumLight<GreenLight>>(Vec(47, 81), module, Seq8Module::FIRST_LED));
  addChild(ModuleLightWidget::create<MediumLight<GreenLight>>(Vec(47, 116), module, Seq8Module::SECOND_LED));
  addChild(ModuleLightWidget::create<MediumLight<GreenLight>>(Vec(47, 151), module, Seq8Module::THIRD_LED));
  addChild(ModuleLightWidget::create<MediumLight<GreenLight>>(Vec(47, 186), module, Seq8Module::FOURTH_LED));
  addChild(ModuleLightWidget::create<MediumLight<GreenLight>>(Vec(47, 221), module, Seq8Module::FIFTH_LED));
  addChild(ModuleLightWidget::create<MediumLight<GreenLight>>(Vec(47, 256), module, Seq8Module::SIXTH_LED));
  addChild(ModuleLightWidget::create<MediumLight<GreenLight>>(Vec(47, 291), module, Seq8Module::SEVENTH_LED));
  addChild(ModuleLightWidget::create<MediumLight<GreenLight>>(Vec(47, 326), module, Seq8Module::EIGHTH_LED));

}

Model *modelSeq8 = Model::create<Seq8Module, Seq8Widget>("SynthKit", "8-Step Sequencer", "8-Step Sequencer", SEQUENCER_TAG);
