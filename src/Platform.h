#ifndef ROVECOMM_PLATFORM_H
#define ROVECOMM_PLATFORM_H

#define TEENSY41 // for testing
//#include "IPAddress.h"

#if defined(ENERGIA)
#define ROVECOMM_TIVA 1

#elif defined(TEENSY41)
#define ROVECOMM_TEENSY 1

#elif defined(ESP32)
#define ROVECOMM_ESP32

#endif // Platform

#endif // ROVECOMM_PLATFORM_H