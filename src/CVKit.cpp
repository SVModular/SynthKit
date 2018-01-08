#include "CVKit.hpp"

CVKit::CVKit (float threshold) {
  this->threshold = threshold;
  this->reset();
}

bool CVKit::newTrigger ( ) {
  // check to see if this is a status change, if so reset the states and return true
  if (this->triggered == true && this->lastTriggered == false) {
    this->lastTriggered = true;

    return true;
  }

  this->lastTriggered = this->triggered;

  return false;
}

void CVKit::update (float current) {
  // set the last value to whatever the current value is
  this->lastValue = current;

  // increase the trigger interval count
  this->triggerIntervalCount++;

  // check the threshold, if it meets or is greater, then we make a change
  if (current >= this->threshold) {
    if (this->triggered == false) {
      this->triggered = true;

      // increment the total number of triggers fired
      this->triggerCount++;

      // set the last trigger interval to the interval
      this->lastTriggerInterval = this->triggerIntervalCount;

      // reset the count to 0
      this->triggerIntervalCount = 0;
    }
  } else {
    this->triggered = false;
  }
}

void CVKit::reset ( ) {
  this->triggered = false;
  this->lastTriggered = false;
  this->lastValue = 0;
  this->triggerCount = 0;
  this->triggerIntervalCount = 0;
  this->lastTriggerInterval = 0;
}

float CVKit::currentValue ( ) {
  return this->lastValue;
}

uint32_t CVKit::triggerInterval ( ) {
  return this->lastTriggerInterval;
}

uint32_t CVKit::triggerTotal ( ) {
  return this->triggerCount;
}
