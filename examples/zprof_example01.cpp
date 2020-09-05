#include <ZProf/ZyklonProfiler.h>

#include <iostream>

int main(int argc, const char **argv)
{
    {
        zprof::Timer* timer_one = new zprof::Timer("timer one");
        for (int i = 0; i < 10000; i++)
        {
            for (int y = 0; y < 10000; y++)
            {
            }
        }
    }

    {
        zprof::Timer* timer_two = new zprof::Timer("timer one");
        for (int i = 0; i < 10000; i++)
        {
            for (int y = 0; y < 10000; y++)
            {
            }
        }
    }
    
}