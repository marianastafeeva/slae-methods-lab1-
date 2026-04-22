#include "lu.h"

void luDecomposition(const Matrix &A, Matrix &L, Matrix &U) {
    int n = A.size();

    L.assign(n, Vector(n, 0));
    U.assign(n, Vector(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            double sum = 0;
            for (int k = 0; k < i; k++)
                sum += L[i][k] * U[k][j];

            U[i][j] = A[i][j] - sum;
        }

        for (int j = i; j < n; j++) {
            if (i == j)
                L[i][i] = 1;
            else {
                double sum = 0;
                for (int k = 0; k < i; k++)
                    sum += L[j][k] * U[k][i];

                L[j][i] = (A[j][i] - sum) / U[i][i];
            }
        }
    }
}

Vector forwardSubstitution(const Matrix &L, const Vector &b) {
    int n = L.size();
    Vector y(n);

    for (int i = 0; i < n; i++) {
        y[i] = b[i];
        for (int j = 0; j < i; j++)
            y[i] -= L[i][j] * y[j];
    }

    return y;
}

Vector backwardSubstitution(const Matrix &U, const Vector &y) {
    int n = U.size();
    Vector x(n);

    for (int i = n - 1; i >= 0; i--) {
        x[i] = y[i];
        for (int j = i + 1; j < n; j++)
            x[i] -= U[i][j] * x[j];
        x[i] /= U[i][i];
    }

    return x;
}