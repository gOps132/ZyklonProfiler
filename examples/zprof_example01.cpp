#include <ZyklonProfiler.h>

#include <iostream>

int main(int argc, const char **argv)
{
    {
        ZPROF_TRACK_SCOPE("Timer One")
        for (int i = 0; i < 10000; i++)
        {
            for (int y = 0; y < 10000; y++)
            {
            }
        }
    }

    {
        ZPROF_TRACK_SCOPE("Timer Two")
        for (int i = 0; i < 10000; i++)
        {
            for (int y = 0; y < 10000; y++)
            {
            }
        }
    }
}