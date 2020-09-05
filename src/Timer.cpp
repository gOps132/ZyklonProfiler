#include "ZProf/Timer.h"

#include <iostream>

namespace zprof
{

    Timer::Timer(std::string prof_name)
    {
        m_data = new TrackData(prof_name);

        // start timer
        std::chrono::high_resolution_clock::now();
    }

    Timer::~Timer()
    {
        auto endTimePoint = std::chrono::high_resolution_clock::now();

        m_data->start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimepoint).time_since_epoch().count();
        m_data->end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimePoint).time_since_epoch().count();

        m_data->duration = m_data->end - m_data->start;
        m_data->duration_ms = m_data->duration * 0.001;

        // add new track
        m_Tracks.push_back(m_data);
        log_tracks_data();
    }

} // namespace zprof
