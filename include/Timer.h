#pragma once

#include "Track.h"

#include <chrono>
#include <string>


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

        void Stop();  
    };

} // namespace zprof