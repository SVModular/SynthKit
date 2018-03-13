#pragma once

#include "asset.hpp"
#include "rack.hpp"

extern Plugin *plugin;

struct SKRoundWhiteKnob : RoundKnob {
  SKRoundWhiteKnob() {
    setSVG(SVG::load(assetPlugin(plugin, "res/components/RoundWhiteKnob.svg")));
  }
};

struct SKRoundSmallWhiteKnob : SKRoundWhiteKnob {
  SKRoundSmallWhiteKnob() {
    setSVG(SVG::load(assetPlugin(plugin, "res/components/RoundSmallWhiteKnob.svg")));
  }
};

struct SKRoundSmallWhiteSnapKnob : SKRoundSmallWhiteKnob {
  SKRoundSmallWhiteSnapKnob() {
    snap = true;
  }
};

struct SKRoundTinyWhiteKnob : SKRoundWhiteKnob {
  SKRoundTinyWhiteKnob() {
    setSVG(SVG::load(assetPlugin(plugin, "res/components/RoundTinyWhiteKnob.svg")));
  }
};

struct SKRoundTinyWhiteSnapKnob : SKRoundTinyWhiteKnob {
  SKRoundTinyWhiteSnapKnob() {
    snap = true;
  }
};
