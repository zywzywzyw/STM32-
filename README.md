# STM32-Sandglass
2021科协寒假训练题
多功能电子沙漏
一、	任务
设计一个功能包含但不限于计时的多功能电子沙漏。
二、	题目要求
1. 基础要求
（1） 实现可视化的基本计时功能；
（2） 计时完毕播放音乐；
（3） 通过按键触发外部中断实现沙漏倒置；
（4） 实现重力控制沙漏转置、启动、停止；
（5） 根据外部环境亮度实现沙漏自适应调光。
2. 进阶要求
（6） 设计UI界面，实现人机交互；
（7） 设计机械结构，实现计时完成后自动倒置；
（8） 捕获外界声音，实现音乐频谱显示；
（9） 实现沙漏的立体化；
（10）为沙漏制作3D打印的外壳。

主控使用STM32F103C8T6，硬件通过AD绘制，3D建模使用C4D。
漏沙的部分先在visual studio上进行模拟后译码到led点阵上，把上下两个三角部分组织为一个8x8的点阵

基础要求部分使用直插LED显示，74系列芯片进行译码，蜂鸣器进行音乐播放，MPU6050实现重力控制，光敏传感器进行自适应调光。
涉及74HC595的串行通讯、蜂鸣器PWM调节，后两者传感器的IIC通讯，MPU6050的DMP库使用与调试。

进阶要求使用0.96寸oled与按钮实现UI界面、人机交互，舵机翻转自动倒置，咪头麦克风获取声音，FFT分析频谱后在oled上动态显示，3D打印底座后插上LED PCB，实现立体化。
涉及IIC通讯，中断，舵机PWM产生与调制，ADC读取，FFT实现，3D建模，PCB绘制。

由于板载硬件资源不足，使用两块c8分别实现前后两套要求，使用蓝牙进行数据交换。

文件中提供了oled、mpu6050、fft等单独的.c .h文件，以及最后的完整程序于final中，包括物理漏沙部分与人机交互部分。

## STM32-Sandglass
2021 Association of Science and Technology Winter Holiday Training Question
Multifunctional electronic hourglass
#1、 Task
Design a multifunctional electronic hourglass with functions including but not limited to timing.
#2、 Topic requirements

1. Basic requirements

(1) Realize visual basic timing function;

(2) Play music after the timing is completed;

(3) Inverting the hourglass by triggering an external interrupt with a key;

(4) Realize gravity control hourglass rotation, start, and stop;

(5) Adaptive dimming of the hourglass based on external ambient brightness.

2. Advanced requirements

(6) Design UI interface to achieve human-computer interaction;

(7) Design a mechanical structure to achieve automatic inversion after the timing is completed;

(8) Capturing external sounds to achieve music spectrum display;

(9) Realize three-dimensional hourglass;

(10) Create a 3D printing shell for the hourglass.

The master controller uses STM32F103C8T6, the hardware is drawn through AD, and 3D modeling uses C4D.
The sand leakage part is first simulated on visual studio and then decoded onto an LED lattice. The upper and lower triangular parts are organized into an 8x8 lattice

The basic requirements section uses in-line LED display, 74 series chips for decoding, buzzers for music playback, MPU6050 for gravity control, and photosensitive sensors for adaptive dimming.
It involves serial communication of the 74HC595, buzzer PWM regulation, IIC communication of the latter two sensors, and use and debugging of the DMP library of the MPU6050.

Advanced requirements include using a 0.96 inch oled and buttons to achieve UI interface and human-computer interaction, automatic inversion of the steering gear, microphone acquisition of sound, FFT analysis of the spectrum and dynamic display on the oled, and insertion of LED PCB behind the 3D printing base to achieve three-dimensional.
It involves IIC communication, interruption, servo PWM generation and modulation, ADC reading, FFT implementation, 3D modeling, and PCB rendering.

Due to insufficient onboard hardware resources, two c8s are used to achieve the front and back sets of requirements, and Bluetooth is used for data exchange.

The file provides separate. c. h files such as oled, mpu 6050, and fft, as well as the final complete program in the final, including the physical sand leakage section and the human-computer interaction section.
