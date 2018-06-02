
#include "Configuration.h"
#include "Command.h"
#include "CommandProcessor.h"
#include "MockRTC.h"

#define BT_PIN_RXD 1
#define BT_PIN_TXD 0
#define BT_PIN_STATE 5
#define BT_DATA_RATE 38400
// default BT HC-05 module UART data rate is 9600,0,0
// I've been changing it to 38400,0,0; see commands below
// default BT HC-05 module password is 1234
/* Laser Scarecrow useful AT command list

    ---confirms communication, responding OK
    AT
    ---inquire passkey for pairing (default 1234)
    AT+PSWD?
    ---set passkey to 0000 (for example)
    AT+PSWD=0000
    ---display serial settings (default 9600,0,0)
    AT+UART?
    ---set faster communication speed e.g., for use with Arduino
    AT+UART=38400,0,0
    ---set module name
    AT+NAME=LS-305-JC
*/

Configuration configuration;
Command sCommand, btCommand;
CommandProcessor sProcessor, btProcessor;
MockRTC rtc;

#define SERIAL_DATARATE 57600

void setup() {
  // put your setup code here, to run once:
  configuration.init();

  // Serial (developer only?? Farmers with notebooks but no Android BT device?)
  Serial.begin(SERIAL_DATARATE);
  sCommand.init();
  sProcessor.setCommand(&sCommand);
  sProcessor.setConfiguration(&configuration);
  sProcessor.setRTC(&rtc);
  sProcessor.setStream(&Serial);
  // BlueTooth
  // pinMode(BT_PIN_STATE, INPUT);// Should be high when connected, low when not
  pinMode(BT_PIN_RXD, INPUT); // is this going to be handled by Serial1.begin?
  pinMode(BT_PIN_TXD, OUTPUT);// is this going to be handled by Serial1.begin?
  Serial1.begin(BT_DATA_RATE);
  btCommand.init();
  btProcessor.setCommand(&btCommand);
  btProcessor.setConfiguration(&configuration);
  btProcessor.setRTC(&rtc);
  btProcessor.setStream(&Serial1);
}

void loop() {
  
  sProcessor.process();
  btProcessor.process();
  
}


