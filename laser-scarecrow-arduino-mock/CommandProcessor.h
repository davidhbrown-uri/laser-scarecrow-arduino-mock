/**
   A command processor aggregates a Command and a Configuration, handling things
   that need to know about both so they can each focus on their own
   responsibilities.

   Created by David H. Brown, February 25, 2018
   License TBD
   Part of the URI Laser Scarecrow project
*/
#ifndef CommandProcessor_h
#define CommandProcessor_h
#include "Arduino.h"
#include "Command.h"
#include "Configuration.h"
#include "MockRTC.h"

#define CPCODE_Hello 0
#define CPCODE_InterruptRate 101
#define CPCODE_StepperTarget 111
#define CPCODE_RtcHms 252
#define CPCODE_RtcWake 261
#define CPCODE_RtcSleep 262
#define CPCODE_ServoMinimum 131
#define CPCODE_ServoRange 132
#define CPCODE_CycleMode 201
#define CPCODE_LightThrehold 221


enum CPSTATUS {
  CPSTATUS_Ready,
  CPSTATUS_Done,
  CPSTATUS_InvalidLetter,
  CPSTATUS_InvalidCode,
  CPSTATUS_InvalidParameter,
  CPSTATUS_ProcessFailed
};

class CommandProcessor
{
  public:
    CommandProcessor();
    void setCommand(Command *cd);
    void setStream(Stream *st);
    void setConfiguration(Configuration *cf);
    void setRTC(MockRTC *rtc);
    void process();
    static byte getHoursFromTimeWord(word time);
    static byte getMinutesFromTimeWord(word time);
    static word getTimeWord(byte hours, byte minutes);
    CPSTATUS status;
  private:
    void processOK();
    void processError(CPSTATUS cperr);
    void finishProcess();
    Stream* stream;
    bool verbose;
    Command* command;
    Configuration* configuration;
    MockRTC* rtc;
};// class CommandProcessor
#endif


