#ifndef MATH_H
#define MATH_H

namespace Math 
{
    int square(int x);           // Declaration
    int cube(int x);             // Declaration
    int getInternalCounter();

    extern int globalCounter;    // Declaration (external linkage)
    const int offset = 1234;
}

#endif