#include "testrunner.hpp"
#include "../src/CVKit.hpp"

uint8_t test_trigger_update ( ) {
  CVKit *cv = new CVKit(1.5);

  check(cv->newTrigger() == false, "no trigger before update");

  cv->update(0.1);
  check(cv->newTrigger() == false, "no trigger if low");
  check(cv->currentValue() == 0.1f, "current value is correct");
  check(cv->triggerInterval() == 0, "trigger interval is correct");
  check(cv->triggerTotal() == 0, "trigger total is correct");

  cv->update(1.5);
  check(cv->newTrigger() == true, "trigger is correct after going high");
  check(cv->currentValue() == 1.5f, "current value is correct");
  check(cv->triggerInterval() == 2, "trigger interval is correct");
  check(cv->triggerTotal() == 1, "trigger total is correct");

  cv->update(-1);
  check(cv->newTrigger() == false, "trigger is correct after going low");
  check(cv->currentValue() == -1, "current value is correct");
  check(cv->triggerInterval() == 2, "trigger interval is correct");
  check(cv->triggerTotal() == 1, "trigger total is correct");

  done();
}

uint8_t test_trigger_reset ( ) {
  CVKit *cv = new CVKit(1.5);

  check(cv->newTrigger() == false, "no trigger before update");

  cv->update(0.1);
  check(cv->newTrigger() == false, "no trigger if low");
  check(cv->currentValue() == 0.1f, "current value is correct");
  check(cv->triggerInterval() == 0, "trigger interval is correct");
  check(cv->triggerTotal() == 0, "trigger total is correct");

  cv->reset();
  check(cv->newTrigger() == false, "no trigger after reset");
  check(cv->currentValue() == 0.0f, "current value is reset");
  check(cv->triggerInterval() == 0, "trigger interval is reset");
  check(cv->triggerTotal() == 0, "trigger total is reset");

  done();
}
