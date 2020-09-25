#pragma once

class Matrix {
  public:
    Matrix();
    Matrix(unsigned, unsigned);
    Matrix(double**, unsigned, unsigned);
    Matrix(const Matrix &);
    ~Matrix();
    unsigned rowCount();
    unsigned colCount();
    void swapRows(unsigned, unsigned);
    void swapCols(unsigned, unsigned);
    void print();
  private:
      double** matrix;
      unsigned rows;
      unsigned cols;
};