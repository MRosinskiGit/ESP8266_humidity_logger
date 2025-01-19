// logging.cpp

#include <Arduino.h>
#include "logging.h"

LoggerClass::LoggerClass(int baudRate) {
  Serial.begin(baudRate);
  delay(100);
  log("Logger initialized.");
}
