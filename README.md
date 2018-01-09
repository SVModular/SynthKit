
# SynthKit

A series of modules for VCVRack.  This are meant to be basic building blocks
of synthesis, that will help you create bigger and more complicated
synthesizers.

### Current Status

These modules are currently under development, but are currently in a working
state.

#### Addition

Takes two inputs, adds them, clips them, and outputs the result.

#### Subtraction

Takes two inputs, subtracts the second one from the first, clips them, and
outputs the result.

#### And

Takes two inputs, calculates a logical AND, and outputs the result.

#### Or

Takes two inputs, calculates a logical OR, and outputs the result.

#### 1x8 Splitter

Takes an input, outputs the same input across 8 outputs.

#### 1x8 Splitter, CV Controlled

Takes an input, outputs the same input across any of the outputs, if the CV
trigger is active.  LED will light up for every active output.

#### DevKit

Development kit (still under development).  Currently displays minimum and
maximum values, CV trigger status (1.5v), number of triggers.
