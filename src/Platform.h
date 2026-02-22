#ifndef ROVECOMM_PLATFORM_H
#define ROVECOMM_PLATFORM_H

#if defined(ENERGIA)
#define ROVECOMM_TIVA 1

#elif defined(ARDUINO_TEENSY41)
#define ROVECOMM_TEENSY 1

#elif defined(ESP32)
#define ROVECOMM_ESP32 1

#elif defined(ARDUINO_WIZNET_5500_EVB_PICO)
#define ROVECOMM_PI_PICO 1

#else
#warning "Warning: RoveComm may not be supported on this platform!"

#endif // Platform

#endif // ROVECOMM_PLATFORM_H