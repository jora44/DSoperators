#include "Matrix.hpp"
#include <cstdlib>
#include <time.h>
#include <iostream>

Matrix f(Matrix M) {
    return M;
}

double** makeMatrix(unsigned rows, unsigned cols) {
    double** array = new double*[rows];
    for(unsigned i = 0; i < rows; ++i) {
        array[i] = new double[cols];
        for(unsigned j = 0; j < cols; ++j) {
            int tmp = rand() % 10 + 1;
            array[i][j] = tmp;
        }
    }
    return array;
}

int main() {
    unsigned rows = 4;
    unsigned cols = 3;
    Matrix x = Matrix(makeMatrix(rows, cols), rows, cols);
    rows = 3;
    cols = 5;
    Matrix y = Matrix(makeMatrix(rows, cols), rows, cols);
    std::cout << "x is:\n\n" << x << "y is:\n\n" << y;
    Matrix z = x * y;
    std::cout << "x * y is:\n\n" << z;
   /*
   Matrix matrix = Matrix(array, rows, cols);
   f(Matrix(makeMatrix(rows, cols), rows, cols));
   Matrix m_copy = matrix;
   std::cout << m_copy; 
   */
}
