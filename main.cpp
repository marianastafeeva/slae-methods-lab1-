#include <iostream>
#include <iomanip>
#include <chrono>

#include "matrix.h"
#include "gauss.h"
#include "lu.h"

int main() {
    using clock = std::chrono::high_resolution_clock;

    std::cout << "=== Time comparison ===\n";
    std::cout << std::setw(8) << "n"
              << std::setw(20) << "method"
              << std::setw(15) << "time(s)" << std::endl;

    for (int n : {100, 200, 500, 1000}) {
        Matrix A = generateMatrix(n);
        Vector b = generateVector(n);

        auto t1 = clock::now();
        gaussSimple(A, b);
        auto t2 = clock::now();

        std::cout << std::setw(8) << n
                  << std::setw(20) << "Gauss simple"
                  << std::setw(15)
                  << std::chrono::duration<double>(t2 - t1).count()
                  << std::endl;

        t1 = clock::now();
        gaussPivot(A, b);
        t2 = clock::now();

        std::cout << std::setw(8) << n
                  << std::setw(20) << "Gauss pivot"
                  << std::setw(15)
                  << std::chrono::duration<double>(t2 - t1).count()
                  << std::endl;

        Matrix L, U;

        t1 = clock::now();
        luDecomposition(A, L, U);
        auto mid = clock::now();

        Vector y = forwardSubstitution(L, b);
        backwardSubstitution(U, y);

        t2 = clock::now();

        std::cout << std::setw(8) << n
                  << std::setw(20) << "LU decomp"
                  << std::setw(15)
                  << std::chrono::duration<double>(mid - t1).count()
                  << std::endl;

        std::cout << std::setw(8) << n
                  << std::setw(20) << "LU solve"
                  << std::setw(15)
                  << std::chrono::duration<double>(t2 - mid).count()
                  << std::endl;
    }

    return 0;
}