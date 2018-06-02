#include "MockRTC.h"

#define SECOND 1000L
#define MINUTE 60000L
#define HOUR 3600000L
#define DAY 86400000L

MockRTC::MockRTC(){
  offset = 0L;
}

long MockRTC::getMillisSinceMidnight() {
  //Adding DAY to ensure calculations are done in positive realm... mixing regular Long with unsigned long
  return (DAY + (millis() % DAY) - offset) % DAY;  
}
byte MockRTC::getHours(){
  return (byte) ((getMillisSinceMidnight()) / HOUR);
}
byte MockRTC::getMinutes(){
  return (byte) ((getMillisSinceMidnight() % HOUR) / MINUTE);
}
byte MockRTC::getSeconds(){
  return (byte) ((getMillisSinceMidnight() % MINUTE) / SECOND);
}

void MockRTC::setTime(int h, int m, int s) {
  offset = ( DAY + (millis() % DAY) - (HOUR * h + MINUTE * m + SECOND * s) ) % DAY;
}


