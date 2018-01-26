#include "SynthKit.hpp"


// The plugin-wide instance of the Plugin class
Plugin *plugin;

void init(rack::Plugin *p) {
	plugin = p;
	// This is the unique identifier for your plugin
	p->slug = "SynthKit";
#ifdef VERSION
	p->version = TOSTRING(VERSION);
#endif
	p->website = "https://github.com/JerrySievert/SynthKit";
	p->manual = "https://github.com/JerrySievert/SynthKit/blob/master/README.md";

	// For each module, specify the ModuleWidget subclass, manufacturer slug (for saving in patches), manufacturer human-readable name, module slug, and module name
	p->addModel(createModel<AdditionWidget>("SynthKit", "Addition", "Addition", MIXER_TAG));
	p->addModel(createModel<SubtractionWidget>("SynthKit", "Subtraction", "Subtraction", MIXER_TAG));
	p->addModel(createModel<AndWidget>("SynthKit", "And", "And", MIXER_TAG));
	p->addModel(createModel<OrWidget>("SynthKit", "Or", "Or", MIXER_TAG));
	p->addModel(createModel<M1x8Widget>("SynthKit", "1x8 Splitter", "1x8 Splitter", MIXER_TAG));
	p->addModel(createModel<M1x8CVWidget>("SynthKit", "1x8 Splitter (CV)", "1x8 Splitter (CV)", MIXER_TAG));
	p->addModel(createModel<ClockDividerWidget>("SynthKit", "Clock Divider", "Clock Divider", UTILITY_TAG, CLOCK_TAG));
	p->addModel(createModel<RotatingClockDividerWidget>("SynthKit", "Rotating Clock Divider", "Rotating Clock Divider", UTILITY_TAG, CLOCK_TAG));
	p->addModel(createModel<Seq4Widget>("SynthKit", "4-Step Sequencer", "4-Step Sequencer", SEQUENCER_TAG));
	p->addModel(createModel<Seq8Widget>("SynthKit", "8-Step Sequencer", "8-Step Sequencer", SEQUENCER_TAG));
	p->addModel(createModel<DevKitWidget>("SynthKit", "DevKit", "DevKit", UTILITY_TAG));

	// Any other plugin initialization may go here.
	// As an alternative, consider lazy-loading assets and lookup tables when your module is created to reduce startup times of Rack.
}
