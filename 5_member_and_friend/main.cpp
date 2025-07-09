#include "Matrix.h"
#include <cstdio>

// TODO-1: try to access Matrix m data directly using 'friend' function concept
// like m.rows, m.cols, m.data
int sumElements(Matrix& m) {
    int total = 0;
    for (int i = 0; i < m.getRowCnt(); ++i)
        for (int j = 0; j < m.getColCnt(); ++j)
            total += m.get(i, j);
    return total;
}

int main() {
    Matrix m1(2, 2);
    m1.set(0, 0, 1);
    m1.set(0, 1, 2);
    m1.set(1, 0, 3);
    m1.set(1, 1, 4);

    Matrix m2 = m1;

    // TODO-3: check how subscript operator overloading work
    printf("m2[1][1] = %d\n", m2[1][1]);

    const Matrix m3 = m1 + m2;
    printf("Matrix m3 (m1 + m2):\n");
    m3.print();
    /**
     * TODO-5: try using subscript operator with m3
     * Uncomment the line below and test it out, if it does not work plz fix it
     * Hint: const Matrix need associated subscription operator overloading, try adding it in Matrix class
     */
    // printf("m3[0][0] = %d\n", m3[0][0]);

    m1[0][1] = 10;
    printf("After modifying m1:\n");
    m1.print();

    int total = sumElements(m1);
    printf("Sum of m1: %d\n", total);

    // TODO-4: static function can access static member of the class without object
    printf("Total Matrix instances: %d\n", Matrix::getInstanceCount());

    /**
     * TODO-6: the matrix constructor receive 2 integer, but what will happen if any is negetive?
     * Add definition for static Matrix *createMatrix(int r, int c); in Matrix.cpp
     * In that function, we should validate value of r and c, if any is negative return nullptr
     * 
     * This is another usage of static member function, we can use it to create class object
     * along with validating the input parameters
     */
    // Matrix *m4 = Matrix::createMatrix(3,3);

    return 0;
}
