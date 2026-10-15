#include "src/Config.h"
#include "src/Motor.h"
#include "src/Sensor.h"

Motor motor;
Sensor sensor;

void setup() {
  Serial.begin(115200);
  while (!Serial) { delay(1); }
  Serial.println("Starting Intelligent Obstacle Avoidance Car");

  motor.begin();
  sensor.begin();
}

void loop() {
  // Simple control loop:
  // 1) check VL53L0X front distance
  // 2) if clear -> forward, else sample ultrasonic + turn
  unsigned int front_mm = sensor.readVL53();
  Serial.print("VL53 front (mm): "); Serial.println(front_mm);

  if (front_mm >= Config::FRONT_CLEAR_MM) {
    motor.forward();
    delay(200); // movement step; can be later turned non-blocking
  } else {
    motor.stop();
    delay(50);
    // sample ultrasonic (servo-assisted) to get lateral info
    float lateral_cm = sensor.sampleUltrasonicMedian(9); // 9 samples -> median
    Serial.print("Ultrasonic median (cm): "); Serial.println(lateral_cm);

    if (lateral_cm > Config::SIDE_CLEAR_CM) {
      // try turning right first
      motor.right();
      delay(300);
    } else {
      // try left
      motor.left();
      delay(300);
    }
    motor.stop();
    delay(100);
  }
}
