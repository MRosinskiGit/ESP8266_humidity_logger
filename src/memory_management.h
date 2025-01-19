// memory_management.h
#ifndef MEMORY_H
#define MEMORY_H
#include <Arduino.h>
#include "logging.h"
extern LoggerClass Logger;
#include "humidity_sensor.h"

#define MAX_MEMORY_CAPACITY 1440  //24*60

class MemoryManager {
public:
  MemoryManager();
  void addSampleToMemory(MeasurementSample sample);
private:
  MeasurementSample _samplesInMemory[MAX_MEMORY_CAPACITY];
  uint16_t _lastIndex = 0;
};


#endif
