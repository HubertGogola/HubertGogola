#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "matrix_utils.h"

#define EPSILON 0.0001

bool initialize_matrix(Matrix* m, int rows, int cols) {
	m->rows = rows;
	m->cols = cols;
	m->matrix = allocate_matrix(rows, cols);
	if (m->matrix == NULL) {
		printf("Memory allocation failed!\n");
		return true;
	}

	return false;
}

float** allocate_matrix(int rows, int cols) {
	float** matrix = malloc(rows * sizeof(*matrix));
	if (matrix == NULL) { return NULL; }
	for (int i = 0; i < rows; ++i) {
		matrix[i] = malloc(cols * sizeof(**matrix));
		if (matrix[i] == NULL) {
			for (int j = 0; j < i; ++j) {
				free(matrix[j]);
			}
			free(matrix);
			matrix = NULL;
			return NULL;
		}
	}
	return matrix;
}

void free_matrix(Matrix* m) {
	for (int i = 0; i < m->rows; ++i) {
		free(m->matrix[i]);
	}
	free(m->matrix);
	m->matrix = NULL;
	free(m);
	m = NULL;
}

void fill_matrix(Matrix* m, int start, int end) {
	for (int i = 0; i < m->rows; ++i) {
		for (int j = 0; j < m->cols; ++j) {
			m->matrix[i][j] = rand() % (end - start + 1) + start;
		}
	}
}

void print_matrix(Matrix* m) {
	for (int i = 0; i < m->rows; ++i) {
		for (int j = 0; j < m->cols; ++j) {
			printf("%8.2f", m->matrix[i][j]);
		}
		printf("\n");
	}
}

bool compare_matrices(Matrix* m1, Matrix* m2) {
	if (m1->rows != m2->rows || m1->cols != m2->cols) {
		return false;
	}
	for (int i = 0; i < m1->rows; ++i) {
		for (int j = 0; j < m1->cols; ++j) {
			// porównanie z dok³adnoœci¹ do epsilon (0.0001) (ze wzglêdu na b³êdy obliczeñ)
			if (m1->matrix[i][j] - m2->matrix[i][j] > EPSILON || m1->matrix[i][j] - m2->matrix[i][j] < -EPSILON) {
				return false;
			}
		}
	}

	return true;
}