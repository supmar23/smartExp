#include "TemperatureSensor.h"
#include "Arduino.h"
#include "DHT.h"

#define DHTPIN 9 
#define DHTTYPE 11 

DHT dht(DHTPIN, DHTTYPE);

TemperatureSensor::TemperatureSensor() {
  dht.begin();
}

int TemperatureSensor::getTemperature() {
  return dht.readTemperature();
}
