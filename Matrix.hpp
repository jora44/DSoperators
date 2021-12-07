#ifndef MATRIX_HPP_
#define MATRIX_HPP_

#include <iostream>

struct Matrix {
    Matrix();
    Matrix(unsigned, unsigned);
    Matrix(double**, unsigned, unsigned);
    Matrix(const Matrix &);
    Matrix(Matrix &&);
    ~Matrix();
    unsigned rowCount();
    unsigned colCount();
    void swapRows(unsigned, unsigned);
    void swapCols(unsigned, unsigned);
    friend std::ostream& operator<<(std::ostream&, const Matrix &);
    Matrix operator*(const Matrix &);
    Matrix& operator*=(const Matrix &);
    double* operator [] (int) const;

 
  private:
      double** matrix;
      unsigned rows;
      unsigned cols;
};

#endif // MATRIX_HPP_

