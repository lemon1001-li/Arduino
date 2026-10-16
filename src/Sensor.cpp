#include "Sensor.h"
#include "Config.h"
#include <Wire.h>
#include <Adafruit_VL53L0X.h>
#include <Servo.h>

Adafruit_VL53L0X lox;
Servo myservo;
Sensor sensor;

void Sensor::begin() {
  Wire.begin();
  myservo.attach(Config::SERVO_PIN);
  Serial.println("Init VL53L0X...");
  if (!lox.begin()) {
    Serial.println("Failed to boot VL53L0X");
    while (1) { delay(10); }
  }
  // set servo to center
  myservo.write(90);
  pinMode(Config::TRIG_PIN, OUTPUT);
  pinMode(Config::ECHO_PIN, INPUT);
}

unsigned int Sensor::readVL53() {
  VL53L0X_RangingMeasurementData_t measure;
  lox.rangingTest(&measure, false);
  if (measure.RangeStatus != 4) {
    return measure.RangeMilliMeter;
  } else {
    // out of range
    return 4000; // big number
  }
}

float Sensor::readUltrasonicCM() {
  digitalWrite(Config::TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(Config::TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(Config::TRIG_PIN, LOW);
  long duration = pulseIn(Config::ECHO_PIN, HIGH, 30000); // timeout
  if (duration == 0) return 400.0f;
  float cm = (duration * 17.0f) / 1000.0f;
  return cm;
}

float Sensor::sampleUltrasonicMedian(int samples) {
  if (samples <= 0) return readUltrasonicCM();
  float buf[25];
  if (samples > 25) samples = 25;
  for (int i = 0; i < samples; ++i) {
    buf[i] = readUltrasonicCM();
    delay(25);
  }
  // simple bubble sort median (samples <= 25)
  for (int i = 0; i < samples - 1; ++i) {
    for (int j = 0; j < samples - 1 - i; ++j) {
      if (buf[j] > buf[j + 1]) {
        float t = buf[j];
        buf[j] = buf[j + 1];
        buf[j + 1] = t;
      }
    }
  }
  return buf[samples / 2];
}
