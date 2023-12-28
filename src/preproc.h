#pragma once

// Define CXXBEGIN and CXXEND to be empty for C and have content for C++
#ifdef __cplusplus
#define CXXBEGIN extern "C" {
#define CXXEND   }
#else
#define CXXBEGIN
#define CXXEND
#endif
