// humidity_sensor.h
#ifndef HUMIDITY_H
#define HUMIDITY_H
#include <DHT.h>
#include "logging.h"
extern LoggerClass Logger;


class HumiditySensorClass {
public:
  HumiditySensorClass(int dataGPIO, int dhtType);
  void perforMeasurement();
  float getHumidity();
  float getTemperature();

private:
  float _humidity;
  float _temperature;
  DHT _dhtObject;
};


struct MeasurementSample {
  String measurementTimestamp;
  float humidity;
  float temperature;
};


#endif
