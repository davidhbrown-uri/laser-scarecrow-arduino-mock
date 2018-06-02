/**
   A Configuration stores the configuration of the Laser Scarecrow
   It really isn't much more than a struct, so its properties are public
   Created by David H. Brown, February 25, 2018
   License TBD
   Part of the URI Laser Scarecrow project
*/
#ifndef Configuration_h
#define Configuration_h
#include "Arduino.h"
class Configuration {
  public:
    Configuration();
    void init();

    //properties
    byte cycle_mode;
    word light_sensor_threshold;
    word rtc_wake;
    word rtc_sleep;
    word stepper_target;
    word interrupt_rate;
    word servo_min;
    word servo_range;
}; //class Configuration
#endif

