#include "Matrix.h"
#include <iostream>

typedef unsigned int ui;

Matrix::Matrix()
    :rows(1)
    ,cols(1)
{
    matrix = new double*[rows];
    matrix[0] = new double[cols];
    matrix[0][0] = 0;
}

Matrix::Matrix(ui rows, ui cols)
    :rows(rows)
    ,cols(cols)
{
    matrix = new double*[rows];
    for(ui i = 0; i < rows; ++i) {
        matrix[i] = new double[cols];
        for(ui j = 0; j < cols; ++j) {
            matrix[i][j] = 0;
        }
    }
}

Matrix::Matrix(double** matrix, ui rows, ui cols)
    :rows(rows)
    ,cols(cols)
{
    this->matrix = new double*[rows];
    for(ui i = 0; i < rows; ++i) {
        this->matrix[i] = new double[cols];
        for(ui j = 0; j < cols; ++j) {
            this->matrix[i][j] = matrix[i][j];
        }
    }
}

Matrix::Matrix(const Matrix &matrix)
    :rows(matrix.rows)
    ,cols(matrix.cols)
{
    std::cout << "Copy constructor is called\n";
    this->matrix = new double*[rows];
    for(ui i = 0; i < rows; ++i) {
        this->matrix[i] = new double[cols];
        for(ui j = 0; j < cols; ++j) {
            this->matrix[i][j] = matrix.matrix[i][j];
        }
    }
}

Matrix::~Matrix() {
    std::cout << "destr-r is called\n";
    for(ui i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

ui Matrix::rowCount() {
    return rows;
}

ui Matrix::colCount() {
    return cols;
}

void Matrix::swapRows(ui i, ui j) {
    std::swap(matrix[i], matrix[j]);
}

void Matrix::swapCols(ui first, ui second) {
    for(ui i = 0; i < rows; ++i) {
        std::swap(matrix[i][first], matrix[i][second]);
    }
}

void Matrix::print() {
    for(ui i = 0; i < rows; ++i) {
        for(ui j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << "   ";
        }
        std::cout << std::endl;
    }
}











