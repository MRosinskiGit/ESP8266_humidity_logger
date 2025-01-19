// memory_management.cpp
#include <Arduino.h>
#include "logging.h"
extern LoggerClass Logger;

#include "memory_management.h"
#include "humidity_sensor.h"

MemoryManager::MemoryManager() {
}

void MemoryManager::addSampleToMemory(MeasurementSample sample) {
  char logBuffer[200];
  snprintf(logBuffer, sizeof(logBuffer), "Adding to RAM memory at index %d: Timestamp %s, Humidity: %.2f, Temperature: %.2f",
           _lastIndex, sample.measurementTimestamp.c_str(), sample.humidity, sample.temperature);
  Logger.log(logBuffer);

  _lastIndex++;
  if (_lastIndex == MAX_MEMORY_CAPACITY) {
    Logger.log("Saving to SD");

    //place to save data to micrsd card

    // Clear Array with samples
    _lastIndex = 0;
    for (size_t i = 0; i < MAX_MEMORY_CAPACITY; i++) {
      _samplesInMemory[i] = MeasurementSample();
    }
  }
}