#include "Matrix.hpp"
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

Matrix::Matrix(Matrix &&m)
    :matrix(m.matrix)
     ,rows(m.rows)
     ,cols(m.cols)
{
        std::cout << "called move c-r\n";
        m.matrix = nullptr;
        m.rows = 0;
        m.cols = 0;
}

std::ostream& operator<<(std::ostream& out, const Matrix  &m) {
    for(ui i = 0; i < m.rows; ++i) {
        for(ui j = 0; j < m.cols; ++j) {
            out << m.matrix[i][j] << "   ";
        }
        out << std::endl;
    }
    return out;
}


Matrix Matrix::operator*(const Matrix &m) {
    if(cols != m.rows) {
        std::cout << "This Matrixes can't be multiplied\n";
        Matrix res;
        res.matrix = nullptr;
        return res;
    }
    Matrix res(rows, m.cols);
    for(ui i = 0; i < rows; ++i) {
        for(ui j = 0; j < m.cols; ++j) {
            for(ui k = 0; k < cols; ++k) {
                res.matrix[i][j] += matrix[i][k] * m.matrix[k][j];
            }
        }
    }
    return res;
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

