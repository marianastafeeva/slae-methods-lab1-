#ifndef GAUSS_H
#define GAUSS_H

#include "matrix.h"

Vector gaussSimple(Matrix A, Vector b);
Vector gaussPivot(Matrix A, Vector b);

#endif