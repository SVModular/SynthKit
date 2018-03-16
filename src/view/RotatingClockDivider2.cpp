#include "../controller/RotatingClockDivider2.hpp"

struct RotatingClockDivider2Widget : ModuleWidget {
  RotatingClockDivider2Widget(RotatingClockDivider2Module *module);
};

RotatingClockDivider2Widget::RotatingClockDivider2Widget(
    RotatingClockDivider2Module *module)
    : ModuleWidget(module) {
  box.size = Vec(4 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT);

  {
    SVGPanel *panel = new SVGPanel();
    panel->box.size = box.size;
    panel->setBackground(
        SVG::load(assetPlugin(plugin, "res/RotatingClockDivider2.svg")));
    addChild(panel);
  }

  addChild(Widget::create<ScrewSilver>(Vec(RACK_GRID_WIDTH + 8, 0)));
  addChild(Widget::create<ScrewSilver>(
      Vec(RACK_GRID_WIDTH + 8, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));

  addInput(Port::create<PJ301MPort>(Vec(6, 34), Port::INPUT, module,
                                    RotatingClockDivider2Module::ROTATE_INPUT));
  addInput(Port::create<PJ301MPort>(Vec(30, 34), Port::INPUT, module,
                                    RotatingClockDivider2Module::TOP_INPUT));
  addOutput(Port::create<PJ301MPort>(Vec(17, 73), Port::OUTPUT, module,
                                     RotatingClockDivider2Module::FIRST_OUTPUT));
  addOutput(
      Port::create<PJ301MPort>(Vec(17, 108), Port::OUTPUT, module,
                               RotatingClockDivider2Module::SECOND_OUTPUT));
  addOutput(Port::create<PJ301MPort>(Vec(17, 143), Port::OUTPUT, module,
                                     RotatingClockDivider2Module::THIRD_OUTPUT));
  addOutput(
      Port::create<PJ301MPort>(Vec(17, 178), Port::OUTPUT, module,
                               RotatingClockDivider2Module::FOURTH_OUTPUT));
  addOutput(Port::create<PJ301MPort>(Vec(17, 213), Port::OUTPUT, module,
                                     RotatingClockDivider2Module::FIFTH_OUTPUT));
  addOutput(Port::create<PJ301MPort>(Vec(17, 248), Port::OUTPUT, module,
                                     RotatingClockDivider2Module::SIXTH_OUTPUT));
  addOutput(
      Port::create<PJ301MPort>(Vec(17, 283), Port::OUTPUT, module,
                               RotatingClockDivider2Module::SEVENTH_OUTPUT));
  addOutput(
      Port::create<PJ301MPort>(Vec(17, 318), Port::OUTPUT, module,
                               RotatingClockDivider2Module::EIGHTH_OUTPUT));

  addChild(ModuleLightWidget::create<MediumLight<GreenLight>>(
      Vec(43, 81), module, RotatingClockDivider2Module::FIRST_LED));
  addChild(ModuleLightWidget::create<MediumLight<GreenLight>>(
      Vec(43, 116), module, RotatingClockDivider2Module::SECOND_LED));
  addChild(ModuleLightWidget::create<MediumLight<GreenLight>>(
      Vec(43, 151), module, RotatingClockDivider2Module::THIRD_LED));
  addChild(ModuleLightWidget::create<MediumLight<GreenLight>>(
      Vec(43, 186), module, RotatingClockDivider2Module::FOURTH_LED));
  addChild(ModuleLightWidget::create<MediumLight<GreenLight>>(
      Vec(43, 221), module, RotatingClockDivider2Module::FIFTH_LED));
  addChild(ModuleLightWidget::create<MediumLight<GreenLight>>(
      Vec(43, 256), module, RotatingClockDivider2Module::SIXTH_LED));
  addChild(ModuleLightWidget::create<MediumLight<GreenLight>>(
      Vec(43, 291), module, RotatingClockDivider2Module::SEVENTH_LED));
  addChild(ModuleLightWidget::create<MediumLight<GreenLight>>(
      Vec(43, 326), module, RotatingClockDivider2Module::EIGHTH_LED));
}

Model *modelRotatingClockDivider2 =
    Model::create<RotatingClockDivider2Module, RotatingClockDivider2Widget>(
        "SynthKit", "Rotating Clock Divider CV", "Rotating Clock Divider CV",
        UTILITY_TAG, CLOCK_TAG);
