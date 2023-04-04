// FILE: myRandom.h
#ifndef MYRANDOM_H_INCLUDED
#define MYRANDOM_H_INCLUDED
#define ul unsigned long

class myRandom
{
    ul _min;
    ul _max;
    ul _a;
    ul _c;
    ul _mod;
    ul _seed;

public:
    myRandom(ul min, ul max, ul a, ul c, ul mod) : _min(min), _max(max), _a(a), _c(c), _mod(mod) { _seed = 8462817L; };

    ul operator()()
    {
        // lgc function
        _seed = (_a * _seed + _c) % _mod;

        // bound to limit
        return (_seed % (_max - _min + 1)) + _min;
    }

    ul getCurVal() { return _seed; };
    void setSeed(unsigned long s) { _seed = s; }
};

#endif // MYRANDOM_H_INCLUDED