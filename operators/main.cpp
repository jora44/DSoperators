#include "Matrix.hpp"
#include <cstdlib>
#include <time.h>
#include <iostream>

Matrix f(Matrix M) {
    return M;
}

/*
int a = 5;
    int b = 4;
    int c = b*=4 *  a;
    std::cout <<  c << std::endl;
    */
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
    std::cout << "\nx is:\n\n" << x << "\n";
    int i = 1;
    int j = 2;
    std::cout << "x[1][2] == " << x[i][j] << '\n';
    x[i][j] = 44;
    std::cout << "x[1][2] == " << x[i][j] << '\n';
/*delete[] x[i];
    double* tmp = new double[5];
    x[i] = tmp;
    std::cout << "x is : " << x;
*/
    
    /*
    rows = 3;
    cols = 5;
    Matrix y = Matrix(makeMatrix(rows, cols), rows, cols);
    std::cout << "\nx is:\n\n" << x << "\ny is:\n\n" << y;
    Matrix z(makeMatrix(cols, 6), cols, 6);
    
    std::cout << "x * y is :\n" << x * y * z << '\n';
    std::cout << " (x *= y) is : \n" << (x *= y) * z << '\n';

*/


   /*
   Matrix matrix = Matrix(array, rows, cols);
   f(Matrix(makeMatrix(rows, cols), rows, cols));
   Matrix m_copy = matrix;
   std::cout << m_copy; 
   */
}
