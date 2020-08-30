#ifndef __ZYKLONPROFILER_H__
#define __ZYKLONPROFILER_H__

/*
 * Single Header Macro wrappers for functions
*/

#include "Timer.h"

#define ZPROF_TRACK_SCOPE(...)  zprof::Timer timer_one(__VA_ARGS__);

/*
 * TODO LIST == TODO:
 *  Comparison timer
 *  Json Output data structure
*/

#endif // __ZYKLONPROFILER_H__