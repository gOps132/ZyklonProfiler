#include "ZProf/Track.h"

#include <iostream>
#include <vector>

namespace zprof
{

    void Track::log_tracks_data()
    {
        for (int i = 0; i < m_Tracks.size(); i++)
        {
            std::cout << "TEST_NAME:        " << m_Tracks[i]->test_name << std::endl;
            std::cout << "START:            " << m_Tracks[i]->start << std::endl;
            std::cout << "END:              " << m_Tracks[i]->end << std::endl;
            std::cout << "DURATION:         " << m_Tracks[i]->duration << std::endl;
            std::cout << "DURATION (MS):    " << m_Tracks[i]->duration_ms << std::endl;

            std::cout << std::endl;
            std::cout << std::endl;
        }
    }

    void Track::delete_tracks()
    {
        for (int i = 0; i < m_Tracks.size(); i++)
        {
            delete m_Tracks[i];       
        }
    }

} // namespace zprof
