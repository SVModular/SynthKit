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

struct DevKitWidget : ModuleWidget {
	DevKitWidget();
};

struct M1x8Widget : ModuleWidget {
	M1x8Widget();
};

struct M1x8CVWidget : ModuleWidget {
	M1x8CVWidget();
};

struct ClockDividerWidget : ModuleWidget {
	ClockDividerWidget();
};

struct PrimeClockDividerWidget : ModuleWidget {
	PrimeClockDividerWidget();
};

struct FibonacciClockDividerWidget : ModuleWidget {
	FibonacciClockDividerWidget();
};

struct Seq4Widget : ModuleWidget {
	Seq4Widget();
};

struct Seq8Widget : ModuleWidget {
	Seq8Widget();
};

struct RotatingClockDividerWidget : ModuleWidget {
	RotatingClockDividerWidget();
};
