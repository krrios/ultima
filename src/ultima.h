#ifndef ULTIMA_ULTIMA_H_
#define ULTIMA_ULTIMA_H_

#include <cstdint>
#include <string>

#ifdef WIN32
	#define PACKED
#else
	#define PACKED __attribute__ ((__packed__))
#endif

#endif