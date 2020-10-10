#pragma once
#include <iostream>

class Matrix {
  public:
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
    void operator*=(const Matrix &);
 
  private:
      double** matrix;
      unsigned rows;
      unsigned cols;
};
