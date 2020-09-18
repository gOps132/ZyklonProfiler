#ifndef __TIMER_H__
#define __TIMER_H__


#include "Track.h"

#include <chrono>
#include <string>

#define ZPROF_TRACK_SCOPE(name) zprof::Timer* name = new zprof::Timer(name);

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

        // template<size_t T, typename TN>
        // void compare();
    };

} // namespace zprof
#endif // __TIMER_H__