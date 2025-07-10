#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
#include <sstream>

struct Coord {
    int x;
    int y;
    bool operator>(Coord &other) {
        printf("Coord operator overloading\n");
        return (x+y) > (other.x+other.y);
    }
};

// === Function Template ===
template<typename T>
T maxValue(T a, T b) {
    return (a > b) ? a : b;
}

Coord maxValue(Coord a, Coord b) {
    printf("Coorc template overloading\n");
    return (a.x + a.y) > (b.x + b.y) ? a:b;
}

// TODO-3: create function template
// like: T myPower(T base, int exponent)
// you can use simple for loop to do power, just want you to familiarize with function template
template<typename T>
T myPower(T base, int exponent) {
    T result = static_cast<T>(1);
    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }
    return result;
}

// === Class Template ===
template<typename T>
class Record {
private:
    int id;
    T value;
public:
    Record(int i, T v) : id(i), value(v) {}

    void print() const {
        // Just for easy example we use stringstream that support any generic type
        // It's not recommended to use stream operator in Embedded system
        std::stringstream oss;
        oss << value;
        std::string valStr = oss.str();
        printf("Record #%d: %s\n", id, valStr.c_str());
    }

    T getValue() const {
        return value;
    }
};

// Specialization for int to use printf directly
template<>
void Record<int>::print() const {
    printf("Record #%d: %d\n", id, value);
}

// Specialization for std::string to use printf directly
template<>
void Record<std::string>::print() const {
    printf("Record #%d: %s\n", id, value.c_str());
}

// === Helper Function ===
bool containsLetterB(const Record<std::string>& r) {
    return r.getValue().find('B') != std::string::npos;
}

int main() {
    // Function template demo
    printf("Max of 3 and 7: %d\n", maxValue(3, 7));
    printf("Max of 2.5 and 1.8: %.2f\n", maxValue(2.5, 1.8));
    /**
     * TODO-1: try parsing std::string to maxValue, and see if it work
     *
     * It use operator > in string to evaluate, if you want custom logic
     * you can overload the template function to accept string, and modify logic accordingly
     */
    std::string a = "abdef";
    std::string b = "abcdef";
    printf("Max of %s and %s: %s\n", a.c_str(), b.c_str(), maxValue(a, b).c_str());

    // Class template demo
    Record<int> r1(1, 100);
    Record<std::string> r2(2, "Data");

    r1.print();
    r2.print();

    // Using standard containers
    std::vector<Record<std::string>> records = {
        {3, "Apple"},
        {4, "Banana"},
        {5, "Cherry"}
    };

    printf("\nIterating with iterator:\n");
    // TODO-2: loop each record and call function print() using iterator
    for (std::vector<Record<std::string>>::iterator it=records.begin(); it!=records.end(); ++it) {
        it->print();
    }

    // Using standard algorithms
    printf("\nSearching for record with letter 'B'...\n");
    std::vector<Record<std::string>>::iterator found = std::find_if(records.begin(), records.end(), containsLetterB);
    if (found != records.end()) {
        printf("Found:\n");
        found->print();
    } else {
        printf("No record contains 'B'\n");
    }

    /**
     * TODO-4: make template maxValue() work with Coord object, 
     * just use simple logic like: max is (x1+y1) > (x2+y2)
     * Hint: you can either overload operator in Coord, or create new template function to support Coord
     *
     * Note: if you add both operator overloading and template function, it will go to template first,
     * because it detect that maxValue has version that accept Coord as input parameters
     */
    Coord c1 = {3, 4};
    Coord c2 = {2, 3};
    Coord maxC = maxValue(c1, c2);
    printf("Max coord x: %d y: %d\n", maxC.x, maxC.y);

    return 0;
}
