#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "matrix_utils.h"
#include "vector_utils.h"

int multiply_matrices(Matrix* first, Matrix* second, Matrix* result) {
	if (first->cols != second->rows) {
		printf("Mnozenie nie jest mozliwe!\n");
		return 0;
	}
	for (int i = 0; i < first->rows; i++) {
		for (int j = 0; j < second->cols; j++) {
			result->matrix[i][j] = 0;
			for (int k = 0; k < first->cols; k++) {
				result->matrix[i][j] += first->matrix[i][k] * second->matrix[k][j];
			}
		}
	}

	return 1;
}

int transpose_matrix(Matrix* m, Matrix* transposed) {
	if (m->rows != transposed->cols && m->cols != transposed->rows) {
		printf("Rozmiary macierzy s¹ nieprawid³owe!\n");
		return 0;
	}
	for (int i = 0; i < m->rows; i++) {
		for (int j = 0; j < m->cols; j++) {
			transposed->matrix[j][i] = m->matrix[i][j];
		}
	}

	return 1;
}

float matrix_determinant(Matrix* m) {
	if (m->rows != m->cols) {
		printf("Macierz nie jest kwadratowa!\n");
		return;
	}
	float det = 0;
	Matrix* submatrix = malloc(sizeof(Matrix));
	if (submatrix == NULL) {
		printf("Memory allocation failed!\n");
		return;
	}
	bool initError = initialize_matrix(submatrix, m->rows - 1, m->cols - 1);
	if (initError) {
		printf("Matrix initialization failed!\n");
		return;
	}

	if (m->rows == 1) {
		return m->matrix[0][0];
	}
	if (m->rows == 2) {
		return ((m->matrix[0][0] * m->matrix[1][1]) - (m->matrix[0][1] * m->matrix[1][0]));
	}
	else {
		for (int x = 0; x < m->rows; x++) {
			int subi = 0;
			for (int i = 1; i < m->rows; i++) {
				int subj = 0;
				for (int j = 0; j < m->rows; j++) {
					if (j == x)
						continue;
					submatrix->matrix[subi][subj] = m->matrix[i][j];
					subj++;
				}
				subi++;
			}
			det = det + (float)(pow(-1, x) * m->matrix[0][x] * matrix_determinant(submatrix));
		}
	}
	return det;
}

void triangle_decomposition(Matrix* m, Matrix* lower, Matrix* upper) {
	int i, j, k;
	int n = m->rows;

	// Inicjalizacja macierzy dolnej i górnej do 0
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			lower->matrix[i][j] = 0;
			upper->matrix[i][j] = 0;
		}
	}

	// Rozk³ad trójk¹tny
	for (i = 0; i < n; i++) {
		// Górna trójk¹tna
		for (k = i; k < n; k++) {
			float sum = 0;
			for (j = 0; j < i; j++) {
				sum += (lower->matrix[i][j] * upper->matrix[j][k]);
			}
			upper->matrix[i][k] = m->matrix[i][k] - sum;
		}

		// Dolna trójk¹tna
		for (k = i; k < n; k++) {
			if (i == k)
				lower->matrix[i][i] = 1; // Diagonala dolnej trójk¹tnej na 1
			else {
				float sum = 0;
				for (j = 0; j < i; j++) {
					sum += (lower->matrix[k][j] * upper->matrix[j][i]);
				}
				lower->matrix[k][i] = (m->matrix[k][i] - sum) / upper->matrix[i][i];
			}
		}
	}
}

int inverse_matrix(Matrix* m, Matrix* inversed) {
	int n = m->rows;
	if (m->rows != m->cols) {
		printf("Macierz nie jest kwadratowa!\n");
		return 0;
	}

	// tworzenie macierzy blokowej (rozszerzonej)
	Matrix* augmented = malloc(sizeof(Matrix));
	if (augmented == NULL) {
		printf("Memory allocation failed!\n");
		return 0;
	}
	bool initError = initialize_matrix(augmented, n, 2 * n);
	if (initError) {
		printf("Matrix initialization failed!\n");
		return 0;
	}
	// wype³nienie macierzy blokowej
	// macierz wyjœciowa po lewej | macierz jednostkowa po prawej stronie
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			augmented->matrix[i][j] = m->matrix[i][j];
			augmented->matrix[i][j + n] = (i == j) ? 1.0f : 0.0f;
		}
	}

	// eliminacja Gaussa-Jordana
	for (int i = 0; i < n; ++i) {
		// sprawdzenie czy element diagonalny jest zerowy
		float pivot = augmented->matrix[i][i];
		if (pivot == 0) {
			printf("Macierz jest nieodwracalna!\n");
			return 0;
		}

		// normalizacja wiersza
		for (int j = 0; j < 2 * n; ++j) {
			augmented->matrix[i][j] /= pivot;
		}

		// eliminacja kolumny w pozosta³ych wierszach
		for (int k = 0; k < n; ++k) {
			if (k != i) {
				float factor = augmented->matrix[k][i];
				for (int l = 0; l < 2 * n; ++l) {
					augmented->matrix[k][l] -= factor * augmented->matrix[i][l];
				}
			}
		}
	}

	// przepisanie prawej czêœci macierzy blokowej do macierzy odwrotnej
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			inversed->matrix[i][j] = augmented->matrix[i][j + n];
		}
	}

	return 1;
}

void identity_matrix(Matrix* m) {
	if (m->rows != m->cols) {
		printf("Macierz nie jest kwadratowa!\n");
		return;
	}
	for (int i = 0; i < m->rows; i++) {
		for (int j = 0; j < m->cols; j++) {
			if (i == j) {
				m->matrix[i][j] = 1;
			}
			else {
				m->matrix[i][j] = 0;
			}
		}
	}
}

int multiply_matrix_vector(Matrix* m, Vector* v, Vector* result) {
	if (m->cols != v->size || m->rows != result->size) {
		printf("Macierz musi byc kwadratowa i miec rpzmiar rowny dlugosci wektora.\n");
		return 0;
	}

	for (int i = 0; i < m->rows; ++i) {
		result->vector[i] = 0.0f;
		for (int j = 0; j < m->cols; ++j) {
			result->vector[i] += m->matrix[i][j] * v->vector[j];
		}
	}

	return 1;
}