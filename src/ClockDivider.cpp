#include <stdint.h>

#include "SynthKit.hpp"
#include "CVKit.hpp"

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
    cv = new CVKit(1.5);

    count = 0;
    ready = false;
    where = 0;
  }

	void step() override;

  CVKit *cv;
  int count;
  bool ready;
  uint64_t where;
};


void ClockDividerModule::step() {
	float in = inputs[TOP_INPUT].value;
  this->cv->update(in);

  // check to see if the module has been init, if not, figure out the first
  // length of the triggers.  by the time the second trigger occurs, there
  // should be an interval figured out
  if (!this->ready) {
    if (this->cv->newTrigger()) {
      this->ready = true;
    }

    return;
  }

  // increment the current position
  this->where++;

  // if this is a trigger event, figure out which to turn on, and do it
  if (this->cv->newTrigger()) {
    // increment the trigger count
    this->count++;

    this->where = 0;

    switch (this->count) {
    case 1:
      outputs[FIRST_OUTPUT].value = in;
      lights[FIRST_LED].value = 1.0;

      break;

    case 2:
      outputs[FIRST_OUTPUT].value = in;
      lights[FIRST_LED].value = 1.0;
      outputs[SECOND_OUTPUT].value = in;
      lights[SECOND_LED].value = 1.0f;

      break;

    case 3:
      outputs[FIRST_OUTPUT].value = in;
      lights[FIRST_LED].value = 1.0f;
      outputs[THIRD_OUTPUT].value = in;
      lights[THIRD_LED].value = 1.0f;

      break;

    case 4:
      outputs[FIRST_OUTPUT].value = in;
      lights[FIRST_LED].value = 1.0f;
      outputs[SECOND_OUTPUT].value = in;
      lights[SECOND_LED].value = 1.0f;
      outputs[FOURTH_OUTPUT].value = in;
      lights[FOURTH_LED].value = 1.0f;

      break;

    case 5:
      outputs[FIRST_OUTPUT].value = in;
      lights[FIRST_LED].value = 1.0f;
      outputs[FIFTH_OUTPUT].value = in;
      lights[FIFTH_LED].value = 1.0f;

      break;

    case 6:
      outputs[FIRST_OUTPUT].value = in;
      lights[FIRST_LED].value = 1.0f;
      outputs[SECOND_OUTPUT].value = in;
      lights[SECOND_LED].value = 1.0f;
      outputs[THIRD_OUTPUT].value = in;
      lights[THIRD_LED].value = 1.0f;
      outputs[SIXTH_OUTPUT].value = in;
      lights[SIXTH_LED].value = 1.0f;

      break;

    case 7:
      outputs[FIRST_OUTPUT].value = in;
      lights[FIRST_LED].value = 1.0f;
      outputs[SEVENTH_OUTPUT].value = in;
      lights[SEVENTH_LED].value = 1.0f;

      break;

    case 8:
      outputs[FIRST_OUTPUT].value = in;
      lights[FIRST_LED].value = 1.0f;
      outputs[SECOND_OUTPUT].value = in;
      lights[SECOND_LED].value = 1.0f;
      outputs[FOURTH_OUTPUT].value = in;
      lights[FOURTH_LED].value = 1.0f;
      outputs[EIGHTH_OUTPUT].value = in;
      lights[EIGHTH_LED].value = 1.0f;

      break;

    case 9:
      outputs[FIRST_OUTPUT].value = in;
      lights[FIRST_LED].value = 1.0f;
      outputs[THIRD_OUTPUT].value = in;
      lights[THIRD_LED].value = 1.0f;

      break;

    case 10:
      outputs[FIRST_OUTPUT].value = in;
      lights[FIRST_LED].value = 1.0f;
      outputs[SECOND_OUTPUT].value = in;
      lights[SECOND_LED].value = 1.0f;
      outputs[FIFTH_OUTPUT].value = in;
      lights[FIFTH_LED].value = 1.0f;

      break;

    case 11:
      outputs[FIRST_OUTPUT].value = in;
      lights[FIRST_LED].value = 1.0f;

      break;

    case 12:
      outputs[FIRST_OUTPUT].value = in;
      lights[FIRST_LED].value = 1.0f;
      outputs[SECOND_OUTPUT].value = in;
      lights[SECOND_LED].value = 1.0f;
      outputs[THIRD_OUTPUT].value = in;
      lights[THIRD_LED].value = 1.0f;
      outputs[FOURTH_OUTPUT].value = in;
      lights[FOURTH_LED].value = 1.0f;
      outputs[SIXTH_OUTPUT].value = in;
      lights[SIXTH_LED].value = 1.0f;

      break;

    case 13:
      outputs[FIRST_OUTPUT].value = in;
      lights[FIRST_LED].value = 1.0f;

      break;

    case 14:
      outputs[FIRST_OUTPUT].value = in;
      lights[FIRST_LED].value = 1.0f;
      outputs[SECOND_OUTPUT].value = in;
      lights[SECOND_LED].value = 1.0f;
      outputs[SEVENTH_OUTPUT].value = in;
      lights[SEVENTH_LED].value = 1.0f;

      break;

    case 15:
      outputs[FIRST_OUTPUT].value = in;
      lights[FIRST_LED].value = 1.0f;
      outputs[THIRD_OUTPUT].value = in;
      lights[THIRD_LED].value = 1.0f;
      outputs[FIFTH_OUTPUT].value = in;
      lights[FIFTH_LED].value = 1.0f;

      break;

    case 16:
      outputs[FIRST_OUTPUT].value = in;
      lights[FIRST_LED].value = 1.0f;
      outputs[SECOND_OUTPUT].value = in;
      lights[SECOND_LED].value = 1.0f;
      outputs[FOURTH_OUTPUT].value = in;
      lights[FOURTH_LED].value = 1.0f;
      outputs[EIGHTH_OUTPUT].value = in;
      lights[EIGHTH_LED].value = 1.0f;

      break;
    }
  } else {
    // check to see if this is an interval / 2
    if (this->where >= cv->triggerInterval() / 2) {
      // turn everything off
      outputs[FIRST_OUTPUT].value = 0;
      lights[FIRST_LED].value = 0;
      outputs[SECOND_OUTPUT].value = 0;
      lights[SECOND_LED].value = 0;
      outputs[THIRD_OUTPUT].value = 0;
      lights[THIRD_LED].value = 0;
      outputs[FOURTH_OUTPUT].value = 0;
      lights[FOURTH_LED].value = 0;
      outputs[FIFTH_OUTPUT].value = 0;
      lights[FIFTH_LED].value = 0;
      outputs[SIXTH_OUTPUT].value = 0;
      lights[SIXTH_LED].value = 0;
      outputs[SEVENTH_OUTPUT].value = 0;
      lights[SEVENTH_LED].value = 0;
      outputs[EIGHTH_OUTPUT].value = 0;
      lights[EIGHTH_LED].value = 0;

      this->where = 0;
    }
  }

  // check to see if this is the end of a loop
  if (this->count == 16) {
    this->count = 0;
  }
}


ClockDividerWidget::ClockDividerWidget() {
	ClockDividerModule *module = new ClockDividerModule();
	setModule(module);
	box.size = Vec(3 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT);

	{
		SVGPanel *panel = new SVGPanel();
		panel->box.size = box.size;
		panel->setBackground(SVG::load(assetPlugin(plugin, "res/ClockDivider.svg")));
		addChild(panel);
	}

	addChild(createScrew<ScrewSilver>(Vec(RACK_GRID_WIDTH, 0)));
	addChild(createScrew<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, 0)));

	addInput(createInput<PJ301MPort>(Vec(10, 33), module, ClockDividerModule::TOP_INPUT));
	addOutput(createOutput<PJ301MPort>(Vec(10, 73), module, ClockDividerModule::FIRST_OUTPUT));
	addOutput(createOutput<PJ301MPort>(Vec(10, 107), module, ClockDividerModule::SECOND_OUTPUT));
	addOutput(createOutput<PJ301MPort>(Vec(10, 140), module, ClockDividerModule::THIRD_OUTPUT));
	addOutput(createOutput<PJ301MPort>(Vec(10, 173), module, ClockDividerModule::FOURTH_OUTPUT));
	addOutput(createOutput<PJ301MPort>(Vec(10, 207), module, ClockDividerModule::FIFTH_OUTPUT));
	addOutput(createOutput<PJ301MPort>(Vec(10, 242), module, ClockDividerModule::SIXTH_OUTPUT));
	addOutput(createOutput<PJ301MPort>(Vec(10, 279), module, ClockDividerModule::SEVENTH_OUTPUT));
	addOutput(createOutput<PJ301MPort>(Vec(10, 314), module, ClockDividerModule::EIGHTH_OUTPUT));

  addChild(createLight<MediumLight<GreenLight>>(Vec(35, 81), module, ClockDividerModule::FIRST_LED));
  addChild(createLight<MediumLight<GreenLight>>(Vec(35, 115), module, ClockDividerModule::SECOND_LED));
  addChild(createLight<MediumLight<GreenLight>>(Vec(35, 148), module, ClockDividerModule::THIRD_LED));
  addChild(createLight<MediumLight<GreenLight>>(Vec(35, 181), module, ClockDividerModule::FOURTH_LED));
  addChild(createLight<MediumLight<GreenLight>>(Vec(35, 215), module, ClockDividerModule::FIFTH_LED));
  addChild(createLight<MediumLight<GreenLight>>(Vec(35, 250), module, ClockDividerModule::SIXTH_LED));
  addChild(createLight<MediumLight<GreenLight>>(Vec(35, 287), module, ClockDividerModule::SEVENTH_LED));
  addChild(createLight<MediumLight<GreenLight>>(Vec(35, 322), module, ClockDividerModule::EIGHTH_LED));
}
