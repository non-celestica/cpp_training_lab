#include "Matrix.h"
#include <cstdio>

int sumElements(const Matrix& m) {
    int total = 0;
    for (int i = 0; i < m.rows; ++i)
        for (int j = 0; j < m.cols; ++j)
            total += m.data[i][j];
    return total;
}

int main() {
    Matrix m1(2, 2);
    m1.set(0, 0, 1);
    m1.set(0, 1, 2);
    m1.set(1, 0, 3);
    m1.set(1, 1, 4);

    Matrix m2 = m1;

    printf("m2[1][1] = %d\n", m2[1][1]);

    const Matrix m3 = m1 + m2;
    printf("Matrix m3 (m1 + m2):\n");
    m3.print();

    m1[0][1] = 10;
    printf("After modifying m1:\n");
    m1.print();

    int total = sumElements(m1);
    printf("Sum of m1: %d\n", total);

    printf("Total Matrix instances: %d\n", Matrix::getInstanceCount());

    Matrix *m4 = Matrix::createMatrix(0,3);
    printf("Matrix m4 addr: %p\n", m4);
    m4 = Matrix::createMatrix(2,-1);
    printf("Matrix m4 addr: %p\n", m4);
    m4 = Matrix::createMatrix(1,1);
    printf("Matrix m4 addr: %p\n", m4);

    return 0;
}
