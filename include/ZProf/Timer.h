#ifndef __TIMER_H__
#define __TIMER_H__


#include "Track.h"

#include <chrono>
#include <string>

#define ZPROF_TRACK_SCOPE_START(name) { zprof::Timer* name = new zprof::Timer(name);
#define ZPROF_TRACK_SCOPE_END }

namespace zprof
{
    class Timer : public Track
    {
    private:
        std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimepoint;

    public:
        TrackData *m_data;

        Timer(std::string prof_name);
        ~Timer();
    };

} // namespace zprof
#endif // __TIMER_H__