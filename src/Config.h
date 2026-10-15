#ifndef CONFIG_H
#define CONFIG_H

namespace Config {
  // Pins
  constexpr int MOTOR_A_PIN = 5; // PWM
  constexpr int MOTOR_B_PIN = 4;
  constexpr int MOTOR_C_PIN = 6; // PWM
  constexpr int MOTOR_D_PIN = 7;
  constexpr int TRIG_PIN = 2;
  constexpr int ECHO_PIN = 3;
  constexpr int SERVO_PIN = 9;

  // Behavior tuning
  constexpr unsigned int FRONT_CLEAR_MM = 300; // VL53 threshold
  constexpr float SIDE_CLEAR_CM = 60.0f;      // ultrasonic threshold

  // Motor base PWM
  constexpr int MOTOR_PWM_BASE = 146;
}

#endif // CONFIG_H
