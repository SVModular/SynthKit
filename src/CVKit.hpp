#pragma once

#include <stdint.h>

class CVKit {
  public:
    CVKit (float);
    bool newTrigger( );
    void update (float);
    void reset ( );
    float currentValue ( );
    uint32_t triggerInterval ( );
    uint32_t triggerTotal ( );
  private:
    float threshold;
    bool triggered;
    bool lastTriggered;
    float lastValue;
    uint32_t triggerIntervalCount;
    uint32_t lastTriggerInterval;
    uint32_t triggerCount;
};
