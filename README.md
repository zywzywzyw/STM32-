# STM32-Sandglass
2021 Association of Science and Technology Winter Holiday Training Question
Multifunctional electronic hourglass
1、 Task
Design a multifunctional electronic hourglass with functions including but not limited to timing.
2、 Topic requirements
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
