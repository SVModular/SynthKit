#include "rack.hpp"


using namespace rack;


extern Plugin *plugin;

////////////////////
// module widgets
////////////////////

struct AdditionWidget : ModuleWidget {
	AdditionWidget();
};

struct SubtractionWidget : ModuleWidget {
	SubtractionWidget();
};

struct AndWidget : ModuleWidget {
	AndWidget();
};

struct OrWidget : ModuleWidget {
	OrWidget();
};
