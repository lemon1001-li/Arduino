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

视频
- 已收到你的视频链接；仓库中会保留完整视频链接，并可在需要时把前 30 秒的小片段加入仓库（请确认你拥有该片段的上传权限）。

贡献与许可
- 我会默认添加 MIT LICENSE（如需其他许可请告诉我）。

更多细节：见仓库文件列表及代码说明（下面包含将提交的源码文件）。
