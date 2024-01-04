# Embedded Directory
Root of source and tools for the ATMEL ATSAMD21 core on the Arduino Vidor MKR

Arduino MKR Vidor 4000 contains an Ateml Arm Cortex-M0 32-bit SAMD21. 

Executable files are (as installed from homebrew https://github.com/osx-cross/homebrew-arm):
- arm-none-eabi-ar
- arm-none-eabi-as
- arm-none-eabi-c++
- arm-none-eabi-cpp
- arm-none-eabi-g++
- arm-none-eabi-nm
- arm-none-eabi-gcc
Etc

We have also installed the ASF drivers which are as much extra library as we get I think.
Unsure how muich we would need - hopefully not too much.

Now attempting to locate the AVRdude equivalent for SAMD devices - looks like it could be a tool called BOSSA (just by watching the verbose arduino download logs lol)
https://www.shumatech.com/web/products/bossa

Looks like this tool will work for flashing from compiled source.