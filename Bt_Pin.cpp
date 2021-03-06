//*************************************************************************************************
//
//  BITTAILOR.CH - BtMqttSn, an Arduino library for MQTT-SN over nRF24L01+
//
//-------------------------------------------------------------------------------------------------
//
//  Bt::Pin
//  
//*************************************************************************************************

#include "Bt_Pin.hpp"

#include <Arduino.h>

namespace Bt {

namespace {

uint8_t inline translateMode(Pin::Mode pMode) {
   switch (pMode) {
      case Pin::MODE_INPUT        : return INPUT;
      case Pin::MODE_INPUT_PULLUP : return INPUT_PULLUP;
      case Pin::MODE_OUTPUT       : return OUTPUT;
      default : return OUTPUT;
   }
}

} // namespace

//-------------------------------------------------------------------------------------------------

Pin::Pin(uint8_t iPinId, Mode iInitialMode) : mPinId(iPinId)  {
   mode(iInitialMode);
}

//-------------------------------------------------------------------------------------------------

Pin::~Pin() {

}

//-------------------------------------------------------------------------------------------------

void Pin::mode(Mode iMode) {
   pinMode(mPinId, translateMode(iMode));
}

//-------------------------------------------------------------------------------------------------

void Pin::write(bool iHigh) {
   digitalWrite(mPinId, iHigh ? HIGH : LOW);
}

//-------------------------------------------------------------------------------------------------

bool Pin::read() {
   return digitalRead(mPinId);
}

//-------------------------------------------------------------------------------------------------

} // namespace Bt
