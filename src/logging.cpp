// logging.cpp
#include <Arduino.h>
#include "logging.h"

LoggerClass::LoggerClass(int baudRate){
	Serial.begin(baudRate);
  delay(100);
  log("");
  log("Logger initialized.");
	
}

void LoggerClass::log(String str, bool newLine){
	if (newLine) {
		str += "\n\r";
	}
	Serial.print(str);
}