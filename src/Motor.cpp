#include "Motor.h"
#include "Config.h"

Motor motor;

void Motor::begin() {
  pinMode(Config::MOTOR_A_PIN, OUTPUT);
  pinMode(Config::MOTOR_B_PIN, OUTPUT);
  pinMode(Config::MOTOR_C_PIN, OUTPUT);
  pinMode(Config::MOTOR_D_PIN, OUTPUT);
  stop();
  pwm = Config::MOTOR_PWM_BASE;
}

void Motor::forward() {
  // left wheel forward, right wheel forward
  analogWrite(Config::MOTOR_A_PIN, pwm - 29);
  digitalWrite(Config::MOTOR_B_PIN, LOW);
  analogWrite(Config::MOTOR_C_PIN, pwm + 9);
  digitalWrite(Config::MOTOR_D_PIN, LOW);
}

void Motor::backward() {
  analogWrite(Config::MOTOR_A_PIN, pwm + 20);
  digitalWrite(Config::MOTOR_B_PIN, HIGH);
  analogWrite(Config::MOTOR_C_PIN, pwm);
  digitalWrite(Config::MOTOR_D_PIN, HIGH);
}

void Motor::right() {
  analogWrite(Config::MOTOR_A_PIN, pwm - 28);
  digitalWrite(Config::MOTOR_B_PIN, LOW);
  analogWrite(Config::MOTOR_C_PIN, pwm + 35);
  digitalWrite(Config::MOTOR_D_PIN, LOW);
}

void Motor::left() {
  analogWrite(Config::MOTOR_A_PIN, pwm + 10);
  digitalWrite(Config::MOTOR_B_PIN, LOW);
  analogWrite(Config::MOTOR_C_PIN, pwm + 10);
  digitalWrite(Config::MOTOR_D_PIN, LOW);
}

void Motor::stop() {
  digitalWrite(Config::MOTOR_A_PIN, LOW);
  digitalWrite(Config::MOTOR_B_PIN, LOW);
  digitalWrite(Config::MOTOR_C_PIN, LOW);
  digitalWrite(Config::MOTOR_D_PIN, LOW);
}
