#include "Matrix.h"
#include <cstdio>
#include <cstdlib>

int Matrix::instanceCount = 0;

Matrix::Matrix(int r, int c) : rows(r), cols(c) {
    instanceCount++;
    data = new int*[rows];
    for (int i = 0; i < rows; ++i)
        data[i] = new int[cols]();
}

Matrix::Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
    instanceCount++;
    data = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        data[i] = new int[cols];
        for (int j = 0; j < cols; ++j)
            data[i][j] = other.data[i][j];
    }
}

// TODO-2: complete the assignment overload operator
Matrix& Matrix::operator=(const Matrix& other) {
    if (this != &other) {
        // This function release all allocated memory and allocate new one,
        // then assign each data from other to it
    }
    // operator= return reference to this object (*this)
    return *this;
}

Matrix::~Matrix() {
    for (int i = 0; i < rows; ++i)
        delete[] data[i];
    delete[] data;
    instanceCount--;
}

int* Matrix::operator[](int index) {
    return data[index];
}

Matrix Matrix::operator+(const Matrix& rhs) {
    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            result.data[i][j] = data[i][j] + rhs.data[i][j];
    return result;
}

void Matrix::set(int r, int c, int value) {
    data[r][c] = value;
}

int Matrix::get(int r, int c) const {
    return data[r][c];
}

void Matrix::print() const {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j)
            printf("%d ", data[i][j]);
        printf("\n");
    }
}

int Matrix::getInstanceCount() {
    return instanceCount;
}

Matrix *Matrix::createMatrix(int r, int c)
{
    return nullptr;
}