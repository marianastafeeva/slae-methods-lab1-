#include "matrix.h"
#include <random>
#include <cmath>

static std::mt19937 gen(42);

Matrix generateMatrix(int n) {
    Matrix A(n, Vector(n));
    std::uniform_real_distribution<> dist(-1.0, 1.0);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            A[i][j] = dist(gen);

    return A;
}

Vector generateVector(int n) {
    Vector b(n);
    std::uniform_real_distribution<> dist(-1.0, 1.0);

    for (int i = 0; i < n; i++)
        b[i] = dist(gen);

    return b;
}

Matrix hilbert(int n) {
    Matrix H(n, Vector(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            H[i][j] = 1.0 / (i + j + 1);

    return H;
}

Vector multiply(const Matrix &A, const Vector &x) {
    int n = A.size();
    Vector b(n, 0.0);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            b[i] += A[i][j] * x[j];

    return b;
}

double norm(const Vector &v) {
    double s = 0;
    for (double x : v) s += x * x;
    return std::sqrt(s);
}

double residual(const Matrix &A, const Vector &x, const Vector &b) {
    Vector r = multiply(A, x);

    for (size_t i = 0; i < r.size(); i++)
        r[i] -= b[i];

    return norm(r);
}