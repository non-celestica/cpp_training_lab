#include <cstdio>
#include "math.h"

static int staticCounter = 0; // File-scope static

void scopeDemo() {
    int local = 10;
    staticCounter++;
    printf("Inside scopeDemo: local = %d, staticCounter = %d\n", local, staticCounter);
}

// Declaration only — no definition provided
void dummyFunc();

int main() {
    printf("=== Scope and Static Demo ===\n");
    scopeDemo();
    scopeDemo();

    printf("\n=== Declaration vs Definition & Namespace Demo ===\n");
    // TODO-1: print out globalCounter from math.h and observe its value
    printf("square(4) = %d\n", Math::square(4));
    // TODO-2: print out globalCounter from math.h and observe its value
    printf("cube(3) = %d\n", Math::cube(3));
    // TODO-3: print out globalCounter from math.h and observe its value

    // Linkage
    // TODO-5: print internalCounter value from using function getInternalCounter()
    // printf("internalCounter = %d\n", ...); 

    // The following would cause linker error (undefined reference):
    // dummyFunc();

    printf("Math::offset: %d\n", Math::offset);
    // TODO-6: try assign Math::offset value to 500 and observe the result

    return 0;
}