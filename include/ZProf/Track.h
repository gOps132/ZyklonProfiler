#ifndef __TRACK_H__
#define __TRACK_H__

#include <vector>
#include <string>

#define ZPROF_DELETE_TRACKS zprof::Track::delete_tracks();

namespace zprof
{

    struct TrackData
    {
        std::string test_name;
        long long int start;
        long long int end;
        long long int duration;
        double duration_ms;

        TrackData(std::string _test_name) : test_name(_test_name) {}
    };
    
    class Track
    {
    protected:
        std::vector<TrackData *> m_Tracks;

    public:
        void log_tracks_data();
        void delete_tracks();
    };

} // namespace zprof

#endif // __TRACK_H__