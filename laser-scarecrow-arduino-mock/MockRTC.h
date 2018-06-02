#ifndef MockRTC_h
#define MockRTC_h
#include "Arduino.h"
class MockRTC {
  public:
    MockRTC();
    void setTime(int hours, int minutes, int seconds);
    byte getHours();
    byte getMinutes();
    byte getSeconds();

    //properties
//  private:
    long offset;
    long getMillisSinceMidnight();
}; //class MockRTC
#endif
