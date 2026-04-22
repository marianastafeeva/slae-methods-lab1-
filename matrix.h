#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

using Matrix = std::vector<std::vector<double>>;
using Vector = std::vector<double>;

Matrix generateMatrix(int n);
Vector generateVector(int n);
Matrix hilbert(int n);
Vector multiply(const Matrix &A, const Vector &x);

double norm(const Vector &v);
double residual(const Matrix &A, const Vector &x, const Vector &b);

#endif