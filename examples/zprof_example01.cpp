#include "Timer.h"

#include <iostream>

int main(int argc, const char **argv)
{
    // TEST TIMER ONE
    {
        zprof::Timer timer_one("Timer One");
        for (int i = 0; i < 10000; i++)
        {
            for (int y = 0; y < 10000; y++)
            {
            }
        }
    }

    // TEST TIMER ONE
    {
        zprof::Timer timer_two("Timer two");
        for (int i = 0; i < 10000; i++)
        {
            for (int y = 0; y < 10000; y++)
            {
            }
        }
    }
}