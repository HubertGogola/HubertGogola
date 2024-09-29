#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "matrix_operations.h"
#include "matrix_utils.h"
#include "vector_utils.h"

void test_matrix_multiplication() {
	Matrix* test1 = malloc(sizeof(Matrix));
	if (test1 == NULL) {
		printf("Memory allocation failed!\n");
		return;
	}
	bool initError = initialize_matrix(test1, 2, 2);
	if (initError) {
		printf("Matrix initialization failed!\n");
		return;
	}
	test1->matrix[0][0] = 11; test1->matrix[0][1] = 3;
	test1->matrix[1][0] = 7;  test1->matrix[1][1] = 11;
	printf("Macierz 1:\n");
	print_matrix(test1);

	Matrix* test2 = malloc(sizeof(Matrix));
	if (test2 == NULL) {
		printf("Memory allocation failed!\n");
		return;
	}
	initError = initialize_matrix(test2, 2, 3);
	if (initError) {
		printf("Matrix initialization failed!\n");
		return;
	}

	test2->matrix[0][0] = 8; test2->matrix[0][1] = 0; test2->matrix[0][2] = 1;
	test2->matrix[1][0] = 0; test2->matrix[1][1] = 3; test2->matrix[1][2] = 5;

	printf("Macierz 2:\n");
	print_matrix(test2);

	Matrix* result = malloc(sizeof(Matrix));
	if (result == NULL) {
		printf("Memory allocation failed!\n");
		return;
	}
	initError = initialize_matrix(result, test1->rows, test2->cols);
	if (initError) {
		printf("Matrix initialization failed!\n");
		return;
	}
	multiply_matrices(test1, test2, result);
	printf("Wynik mnozenia macierzy:\n");
	print_matrix(result);

	// correct result
	Matrix* correctResult = malloc(sizeof(Matrix));
	if (correctResult == NULL) {
		printf("Memory allocation failed!\n");
		return;
	}
	initError = initialize_matrix(correctResult, test1->rows, test2->cols);

	correctResult->matrix[0][0] = 88; correctResult->matrix[0][1] = 9;  correctResult->matrix[0][2] = 26;
	correctResult->matrix[1][0] = 56; correctResult->matrix[1][1] = 33; correctResult->matrix[1][2] = 62;

	printf("Oczekiwany wynik mnozenia macierzy:\n");
	print_matrix(correctResult);

	if (compare_matrices(result, correctResult)) {
		printf("Prawidlowy wynik mnozenia macierzy!\n");
	}
	else {
		printf("Nieprawidlowy wynik mnozenia macierzy!\n");
	}

	free_matrix(test1);
	free_matrix(test2);
	free_matrix(result);
	free_matrix(correctResult);
}

void test_matrix_determinant() {
	Matrix* test = malloc(sizeof(Matrix));
	if (test == NULL) {
		printf("Memory allocation failed!\n");
		return;
	}
	bool initError = initialize_matrix(test, 2, 2);
	if (initError) {
		printf("Matrix initialization failed!\n");
		return;
	}
	test->matrix[0][0] = 1; test->matrix[0][1] = 2;
	test->matrix[1][0] = 3; test->matrix[1][1] = 4;

	float result = matrix_determinant(test);
	print_matrix(test);
	printf("Wyznacznik: %.2f\n", result);
	if (result == -2) {
		printf("Matrix determinant test passed!\n");
	}
	else {
		printf("Matrix determinant test failed!\n");
	}

	free_matrix(test);

	Matrix* test2 = malloc(sizeof(Matrix));
	if (test2 == NULL) {
		printf("Memory allocation failed!\n");
		return;
	}
	initError = initialize_matrix(test2, 3, 3);
	if (initError) {
		printf("Matrix initialization failed!\n");
		return;
	}

	test2->matrix[0][0] = 1; test2->matrix[0][1] = 2; test2->matrix[0][2] = 3;
	test2->matrix[1][0] = 4; test2->matrix[1][1] = 5; test2->matrix[1][2] = 6;
	test2->matrix[2][0] = 7; test2->matrix[2][1] = 8; test2->matrix[2][2] = 9;

	print_matrix(test2);
	float result2 = matrix_determinant(test2);
	printf("Wyznacznik: %.2f\n", result2);

	if (matrix_determinant(test2) == 0) {
		printf("Prawidlowe obliczenie wyznacznika macierzy!\n");
	}
	else {
		printf("Nieprawidlowe obliczenie wyznacznika macierzy!\n");
	}

	free_matrix(test2);
}

void test_triangle_decomposition() {
	Matrix* test = malloc(sizeof(Matrix));
	if (test == NULL) {
		printf("Memory allocation failed!\n");
		return;
	}
	bool initError = initialize_matrix(test, 3, 3);
	if (initError) {
		printf("Matrix initialization failed!\n");
		return;
	}

	Matrix* lower = malloc(sizeof(Matrix));
	if (lower == NULL) {
		printf("Memory allocation failed!\n");
		return;
	}
	initError = initialize_matrix(lower, 3, 3);
	if (initError) {
		printf("Matrix initialization failed!\n");
		return;
	}

	Matrix* upper = malloc(sizeof(Matrix));
	if (upper == NULL) {
		printf("Memory allocation failed!\n");
		return;
	}
	initError = initialize_matrix(upper, 3, 3);
	if (initError) {
		printf("Matrix initialization failed!\n");
		return;
	}

	fill_matrix(test, 0, 10);
	triangle_decomposition(test, lower, upper);
	printf("Macierz testowa:\n");
	print_matrix(test);
	printf("Macierz dolna:\n");
	print_matrix(lower);
	printf("Macierz gorna:\n");
	print_matrix(upper);

	Matrix* result = malloc(sizeof(Matrix));
	if (result == NULL) {
		printf("Memory allocation failed!\n");
		return;
	}
	initError = initialize_matrix(result, 3, 3);
	if (initError) {
		printf("Matrix initialization failed!\n");
		return;
	}

	multiply_matrices(lower, upper, result);
	printf("Mnozenie macierzy dolnej i gornej (powinna byc taka jak testowa):\n");
	print_matrix(result);
	if (compare_matrices(result, test)) {
		printf("Prawidlowy rozklad macierzy na macierze trojkatne!\n");
	}
	else {
		printf("Nieprawidlowy rozklad macierzy na macierze trojkatne!\n");
	}

	free_matrix(test);
	free_matrix(lower);
	free_matrix(upper);
}

void test_transpose_matrix() {
	Matrix* test = malloc(sizeof(Matrix));
	if (test == NULL) {
		printf("Memory allocation failed!\n");
		return;
	}
	bool initError = initialize_matrix(test, 3, 4);
	if (initError) {
		printf("Matrix initialization failed!\n");
		return;
	}
	fill_matrix(test, 0, 10);
	printf("Macierz testowa:\n");
	print_matrix(test);

	Matrix* transposed = malloc(sizeof(Matrix));
	if (transposed == NULL) {
		printf("Memory allocation failed!\n");
		return;
	}
	initError = initialize_matrix(transposed, 4, 3);
	if (initError) {
		printf("Matrix initialization failed!\n");
		return;
	}

	transpose_matrix(test, transposed);

	printf("Macierz transponowana:\n");
	print_matrix(transposed);
}

void test_inverse_matrix() {
	Matrix* test = malloc(sizeof(Matrix));
	if (test == NULL) {
		printf("Memory allocation failed!\n");
		return;
	}
	bool initError = initialize_matrix(test, 3, 3);
	if (initError) {
		printf("Matrix initialization failed!\n");
		return;
	}
	fill_matrix(test, 0, 10);
	printf("Macierz testowa:\n");
	print_matrix(test);

	Matrix* inverse = malloc(sizeof(Matrix));
	if (inverse == NULL) {
		printf("Memory allocation failed!\n");
		return;
	}
	initError = initialize_matrix(inverse, test->rows, test->cols);
	if (initError) {
		printf("Matrix initialization failed!\n");
		return;
	}

	if (!inverse_matrix(test, inverse)) {
		printf("Matrix is not invertible!\n");
		return;
	}
	printf("Macierz odwrotna:\n");
	print_matrix(inverse);

	// sprawdzanie czy mnozenie macierzy przez odwrotna daje macierz jednostkowa
	Matrix* result = malloc(sizeof(Matrix));
	if (result == NULL) {
		printf("Memory allocation failed!\n");
		return;
	}
	initError = initialize_matrix(result, test->rows, test->cols);
	if (initError) {
		printf("Matrix initialization failed!\n");
		return;
	}
	if (!multiply_matrices(test, inverse, result)) {
		printf("Matrix multiplication failed!\n");
		return;
	}

	Matrix* identity = malloc(sizeof(Matrix));
	if (identity == NULL) {
		printf("Memory allocation failed!\n");
		return;
	}
	initError = initialize_matrix(identity, test->rows, test->cols);
	if (initError) {
		printf("Matrix initialization failed!\n");
		return;
	}
	identity_matrix(identity);

	printf("Mnozenie macierzy przez odwrotna:\n");
	print_matrix(result);

	if (compare_matrices(result, identity)) {
		printf("Wyznaczona prawidlowa macierz odwrotna!\n");
	}
	else {
		printf("Wyznaczona nieprawidlowa macierz odwrotna!\n");
	}
}

void test_multiply_matrix_vector() {
	Matrix* test = malloc(sizeof(Matrix));
	if (test == NULL) {
		printf("Memory allocation failed!\n");
		return;
	}
	bool initError = initialize_matrix(test, 3, 3);
	if (initError) {
		printf("Matrix initialization failed!\n");
		return;
	}
	test->matrix[0][0] = 1; test->matrix[0][1] = 2; test->matrix[0][2] = 3;
	test->matrix[1][0] = 4; test->matrix[1][1] = 5; test->matrix[1][2] = 6;
	test->matrix[2][0] = 7; test->matrix[2][1] = 8; test->matrix[2][2] = 9;

	printf("Macierz testowa:\n");
	print_matrix(test);

	Vector* vector = malloc(sizeof(Vector));
	if (vector == NULL) {
		printf("Memory allocation failed!\n");
		return;
	}
	initError = initialize_vector(vector, 3);
	if (initError) {
		printf("Vector initialization failed!\n");
		return;
	}
	vector->vector[0] = 2; vector->vector[1] = 1; vector->vector[2] = 3;
	printf("Wektor testowy:\n");
	print_vector(vector);

	Vector* result = malloc(sizeof(Vector));
	if (result == NULL) {
		printf("Memory allocation failed!\n");
		return;
	}
	initError = initialize_vector(result, 3);
	if (initError) {
		printf("Vector initialization failed!\n");
		return;
	}

	multiply_matrix_vector(test, vector, result);
	printf("Wynik mnozenia macierzy przez wektor:\n");
	print_vector(result);

	// correct result
	Vector* correctResult = malloc(sizeof(Vector));
	if (correctResult == NULL) {
		printf("Memory allocation failed!\n");
		return;
	}
	initError = initialize_vector(correctResult, 3);
	if (initError) {
		printf("Vector initialization failed!\n");
		return;
	}
	correctResult->vector[0] = 13; correctResult->vector[1] = 31; correctResult->vector[2] = 49;

	if (compare_vectors(result, correctResult)) {
		printf("Prawidlowe mnozenie macierzy przez wektor!\n");
	}
	else {
		printf("Nieprawidlowe mnozenie macierzy przez wektor!\n");
	}

	free_matrix(test);
	free_vector(vector);
	free_vector(result);
	free_vector(correctResult);
}

void test_cross_product() {
	Vector* a = malloc(sizeof(Vector));
	if (a == NULL) {
		printf("Memory allocation failed!\n");
		return;
	}
	bool initError = initialize_vector(a, 3);
	if (initError) {
		printf("Vector initialization failed!\n");
		return;
	}
	a->vector[0] = 1; a->vector[1] = 2; a->vector[2] = 3;
	printf("Wektor a:\n");
	print_vector(a);

	Vector* b = malloc(sizeof(Vector));
	if (b == NULL) {
		printf("Memory allocation failed!\n");
		return;
	}
	initError = initialize_vector(b, 3);
	if (initError) {
		printf("Vector initialization failed!\n");
		return;
	}
	b->vector[0] = 4; b->vector[1] = 5; b->vector[2] = 6;
	printf("Wektor b:\n");
	print_vector(b);

	Vector* result = malloc(sizeof(Vector));
	if (result == NULL) {
		printf("Memory allocation failed!\n");
		return;
	}
	initError = initialize_vector(result, 3);
	if (initError) {
		printf("Vector initialization failed!\n");
		return;
	}

	cross_product(a, b, result);
	printf("Iloczyn wektorowy:\n");
	print_vector(result);

	// correct result
	Vector* correctResult = malloc(sizeof(Vector));
	if (correctResult == NULL) {
		printf("Memory allocation failed!\n");
		return;
	}
	initError = initialize_vector(correctResult, 3);
	if (initError) {
		printf("Vector initialization failed!\n");
		return;
	}
	correctResult->vector[0] = -3; correctResult->vector[1] = 6; correctResult->vector[2] = -3;

	if (compare_vectors(result, correctResult)) {
		printf("Obliczony prawidlowy iloczyn wektorowy!\n");
	}
	else {
		printf("Obliczony nieprawidlowy iloczyn wektorowy!\n");
	}

	free_vector(a);
	free_vector(b);
	free_vector(result);
	free_vector(correctResult);
}

void test_dot_product() {
	Vector* a = malloc(sizeof(Vector));
	if (a == NULL) {
		printf("Memory allocation failed!\n");
		return;
	}
	bool initError = initialize_vector(a, 3);
	if (initError) {
		printf("Vector initialization failed!\n");
		return;
	}
	a->vector[0] = 1; a->vector[1] = 2; a->vector[2] = 3;
	printf("Wektor a:\n");
	print_vector(a);

	Vector* b = malloc(sizeof(Vector));
	if (b == NULL) {
		printf("Memory allocation failed!\n");
		return;
	}
	initError = initialize_vector(b, 3);
	if (initError) {
		printf("Vector initialization failed!\n");
		return;
	}
	b->vector[0] = 4; b->vector[1] = 5; b->vector[2] = 6;
	printf("Wektor b:\n");
	print_vector(b);

	int result = dot_product(a, b);
	printf("Iloczyn skalarny: %d\n", result);

	if (result == 32) {
		printf("Obliczony prawidlowy iloczyn skalarny!\n");
	}
	else {
		printf("Obliczony nieprawidlowy iloczyn skalarny!\n");
	}

	free_vector(a);
	free_vector(b);
}