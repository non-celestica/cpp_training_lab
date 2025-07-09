#include <cstdio>
#include "math.h"

namespace Math 
{
    int globalCounter = 0; // Definition
    static int internalCounter = 0; // Internal linkage (can be accessed only in this file)

    int square(int x) {
        globalCounter++;
        internalCounter++; // Internal can be use in file scope
        printf("square(), internalCounter: %d\n", internalCounter);
        return x * x;
    }

    int cube(int x) {
        globalCounter++;
        internalCounter++; // Internal can be use in file scope
        printf("cube(), internalCounter: %d\n", internalCounter);
        return x * x * x;
    }

    // TODO-4: create definition of function getInternalCounter(), that return internalCounter

}