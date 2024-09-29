#pragma once
#include <stdbool.h>

typedef struct {
	int rows;
	int cols;
	float** matrix;
} Matrix;

bool initialize_matrix(Matrix* m, int rows, int cols);
float** allocate_matrix(int rows, int cols);
void free_matrix(Matrix* m);
void fill_matrix(Matrix* m, int start, int end);
void print_matrix(Matrix* m);
bool compare_matrices(Matrix* m1, Matrix* m2);