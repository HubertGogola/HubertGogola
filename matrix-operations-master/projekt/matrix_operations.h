#pragma once
#include "matrix_utils.h"
#include "vector_utils.h"

int multiply_matrices(Matrix* first, Matrix* second, Matrix* result);
void transpose_matrix(Matrix* m, Matrix* reversed);
float matrix_determinant(Matrix* m);
void triangle_decomposition(Matrix* m, Matrix* lower, Matrix* upper);
int inverse_matrix(Matrix* m, Matrix* inversed);
void identity_matrix(Matrix* m);
int multiply_matrix_vector(Matrix* m, Vector* v, Vector* result);