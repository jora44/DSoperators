#include "Matrix.h"
#include <cstdlib>
#include <time.h>
#include <iostream>

Matrix f(Matrix M) {
    return M;
}

int main() {
    //srand(time(NULL));
    unsigned rows = 8;
    unsigned cols = 8;
    double** array = new double*[rows];
    for(unsigned i = 0; i < rows; ++i) {
        array[i] = new double[cols];
        for(unsigned j = 0; j < cols; ++j) {
            int tmp = rand() % 100 + 1;
            array[i][j] = tmp;
        }
    }
    
   Matrix matrix = Matrix(array, rows, cols);
   f(matrix);
   Matrix m_copy = matrix;
/*   matrix.print();
   std::cout << "\n\n";
   matrix.swapCols(cols - 1, 0);
//  matrix.print();
*/
    
}