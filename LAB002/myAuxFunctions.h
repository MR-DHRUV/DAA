// FILE: myAuxFunctions.h

// header guard
#ifndef MYAUXFUNCTIONS_H_INCLUDED
#define MYAUXFUNCTIONS_H_INCLUDED

unsigned long StrToULong(const char *x)
{
    unsigned long ans = 0;
    long i = 0;

    while (x[i] != '\0')
        ans = (ans * 10) + (x[i++] - '0');

    return ans;
}

// closing header guard
#endif // MYAUXFUNCTIONS_H_INCLUDED