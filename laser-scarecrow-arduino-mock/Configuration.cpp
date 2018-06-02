/**
   @see Configuration.h

*/
#include "Configuration.h"
Configuration::Configuration()
{
  init();
}
void Configuration::init() {
  cycle_mode = 0;
#ifdef AMBIENTLIGHTSENSOR_DEFAULT_THRESHOLD
  light_sensor_threshold = AMBIENTLIGHTSENSOR_DEFAULT_THRESHOLD;
#else
  light_sensor_threshold =  250 ; // AMBIENTLIGHTSENSOR_DEFAULT_THRESHOLD defined in LaserScarecrow's config.h
#endif
  // selection of defaults based on twilight extremes in June and July 2018 from:
  // https://www.sunrisesunset.com/USA/RhodeIsland/
  rtc_wake = 278; // 4:38 AM... 4h * 60 + 38m = 278 minutes
  rtc_sleep = 1258; // 8:58pm... 20h * 60 + 58m = 1258 minutes
  interrupt_rate = 100;
  stepper_target = 0;
  servo_min = 200;
  servo_range = 300;
}

