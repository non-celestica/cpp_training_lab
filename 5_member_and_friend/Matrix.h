#ifndef MATRIX_H
#define MATRIX_H

class Matrix {
    static int instanceCount;

    int rows, cols;
    int** data;

public:
    Matrix(int r = 2, int c = 2);
    Matrix(const Matrix& other);
    Matrix& operator=(const Matrix& other);
    ~Matrix();

    int* operator[](int index);

    Matrix operator+(const Matrix& rhs);

    static int getInstanceCount();

    void set(int r, int c, int value);
    int get(int r, int c) const;
    inline int getRowCnt() { return rows; }
    inline int getColCnt() { return cols; }

    void print() const;

    friend int sumElements(const Matrix& m);

    static Matrix *createMatrix(int r, int c);
};

#endif
