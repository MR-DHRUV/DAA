// FILE: myTimer.h
#ifndef MYTIMER_H_INCLUDED
#define MYTIMER_H_INCLUDED
#include <windows.h>

class myTimer
{
    LARGE_INTEGER Frequency;
    LARGE_INTEGER startTime;
    LARGE_INTEGER endTime;
    long double interval;

public:

    myTimer() { QueryPerformanceFrequency(&Frequency); }
    void StartTimer() { QueryPerformanceCounter(&startTime); }
    void EndTimer() { QueryPerformanceCounter(&endTime); }

    long double GetInterval()
    {
        return (long double)(endTime.QuadPart - startTime.QuadPart) / Frequency.QuadPart;
    }
};

#endif // MYTIMER_H_INCLUDED