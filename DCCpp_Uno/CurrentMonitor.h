/**********************************************************************

CurrentMonitor.h
COPYRIGHT (c) 2013-2016 Gregg E. Berman
              2016-2020 Harald Barth

Part of DCC++ BASE STATION for the Arduino

**********************************************************************/

#ifndef CurrentMonitor_h
#define CurrentMonitor_h

#include "Arduino.h"

#define  CURRENT_SAMPLE_MAX        1000       // When to turn off tracks (in mA)

class CurrentMonitor {

  static long int sampleTime;
  byte signalpin;
  byte currentpin;
  int current;                    // Real (corrected) current in mA, range 1mA to ~ 30A.
  int conversionPercent;          // Percentvalue to get mA from internal 0-1023 value.
                                  // For a factor of 3 use 300, for 1.5 use 150
  int conversionBias;             // Value to add to get a zero read at no load
  const char *msg;

public:
  CurrentMonitor(byte, byte, const char *);
  void check();
  unsigned int read();
  unsigned int getCurrent();
};

#endif

