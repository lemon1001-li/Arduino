# Arduino — 智能避障小车 / Intelligent obstacle avoidance car

短述
- 中文：基于 VL53L0X（激光测距）和超声模块 + 舵机的教学/DIY 避障小车代码、接线和使用说明。
- English: Teaching/DIY obstacle-avoidance car using VL53L0X (ToF), ultrasonic sensor and a servo for scanning.

主要内容
- 硬件清单（BOM）、接线示意、所需 Arduino 库，以及如何编译/上传。
- 示例代码已模块化：`IntelligentObstacleAvoidance.ino` + `src/` (Motor, Sensor, Config)。

快速开始
1. 在 Arduino IDE 或 PlatformIO 中打开 `IntelligentObstacleAvoidance.ino`。
2. 安装库：
   - Adafruit VL53L0X (and Adafruit BusIO)
   - Servo
3. 连接硬件（见下文“接线”）并选择你的开发板（UNO/Nano/…），上传并打开串口（115200）。

硬件（建议）
- Arduino UNO / Nano / 兼容板
- VL53L0X ToF 模块（I2C）
- HC-SR04 或兼容超声模块
- 舵机（SG90 等）
- 电机驱动模块（L298N / TB6612 / H-bridge），直流电机 ×2
- 电源：电机独立供电（与 Arduino 共地）

接线（示例，UNO）
- VL53L0X: SDA → A4, SCL → A5, VCC → 3.3V/5V(模块), GND → GND
- HC-SR04: Trig → D2, Echo → D3
- 舵机: Signal → D9, Vcc → 5V(注意电流), GND → GND
- Motor driver inputs: 控制引脚映射为 `motor_a_pin = 5` 等（详见 `src/Config.h`）
- 将电机电源与 Arduino GND 共地

调试与注意事项 / Troubleshooting & Notes
- VL53L0X 常见问题：
  - 如果 VL53 返回 "out of range" 或不稳定，检查模块电源（部分模块建议 3.3V）和 I2C 连接（SDA/SCL）。
  - 多个 I2C 设备可能会导致地址冲突；确认没有其他设备占用相同地址或尝试分步排查（单独只连 VL53L0X 测试）。
- 超声 HC-SR04：
  - 超声对软/空心物体（如布、棉）敏感度较低，空洞或斜面会导致错误读数。
  - pulseIn() 有超时参数，长时间无回波会返回 0（代码已把这种情况转为大距离值）。
- 舵机供电：
  - 舵机在动作时电流峰值较大，建议单独 5V 电源并与 Arduino 共地，避免重启或信号异常。
- 电机驱动与电源：
  - 电机电源必须与 Arduino GND 共地；电机电源建议独立供电（避免电流回冲影响主板）。
  - 不同驱动（L298N / TB6612）逻辑电���与 PWM 需求不同，确认驱动接法和 IO 电平适配。
- 参数校准：
  - `src/Config.h` 中的 `MOTOR_PWM_BASE`、`FRONT_CLEAR_MM`、`SIDE_CLEAR_CM` 为默认值，建议在实际车辆上调参以获得稳定表现。
- 调试技巧：
  - 先分别上传并运行 `src/Sensor` 测试（打印 VL53 / 超声读数），再测试 `Motor` 单元（短脉冲前进/后退），最后合并控制回路。
  - 使用串口打印（115200）观察传感器输出与决策路径，便于定位逻辑或硬件问题。
- 非阻塞改进建议：
  - 目前主循环中仍使用部分 `delay()`，这会降低响应速度。建议后续用 `millis()` 重写为非阻塞状态机以提升灵敏度与控制平滑性。

更多细节：见仓库文件列表及代码说明（下面包含将提交的源码文件）。
