// logging.h
#ifndef LOGGING_H
#define LOGGING_H

#include <Arduino.h>

class LoggerClass {
public:
  LoggerClass(int baudRate = 9600);

  template<typename T>
  void log(T message, bool newLine = true) {
    String output = convertToString(message);
    if (newLine) {
      output += "\n\r";
    }
    Serial.print(output);
  }

private:
  template<typename T>
  String convertToString(T value) {
    return String(value);
  }

  String convertToString(bool value) {
    return value ? "true" : "false";
  }
};

#endif
