#include "SynthKit.hpp"

// The plugin-wide instance of the Plugin class
Plugin *pluginInstance;

void init(rack::Plugin *p) {
  pluginInstance = p;
  // For each module, specify the ModuleWidget subclass, manufacturer slug (for
  // saving in patches), manufacturer human-readable name, module slug, and
  // module name
  p->addModel(modelAddition);
  p->addModel(modelSubtraction);
  p->addModel(modelAnd);
  p->addModel(modelOr);
  p->addModel(modelM1x8);
  p->addModel(modelM1x8CV);
  p->addModel(modelClockDivider);
  p->addModel(modelRotatingClockDivider);
  p->addModel(modelRotatingClockDivider2);
  p->addModel(modelPrimeClockDivider);
  p->addModel(modelFibonacciClockDivider);
  p->addModel(modelSeq4);
  p->addModel(modelSeq8);

  // Any other plugin initialization may go here.
  // As an alternative, consider lazy-loading assets and lookup tables when your
  // module is created to reduce startup times of Rack.
}
