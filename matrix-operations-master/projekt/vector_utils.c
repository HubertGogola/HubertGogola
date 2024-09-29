#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "vector_utils.h"

#define EPSILON 0.0001

bool initialize_vector(Vector* v, int size) {
	v->size = size;
	v->vector = malloc(size * sizeof(float));
	if (v->vector == NULL) {
		return true;
	}
	return false;
}

void print_vector(Vector* v) {
	for (int i = 0; i < v->size; i++) {
		printf("%8.2f", v->vector[i]);
	}
	printf("\n");
}

bool compare_vectors(Vector* v1, Vector* v2) {
	if (v1->size != v2->size) {
		printf("Rozmiary wektorow sa rozne!\n");
		return false;
	}
	for (int i = 0; i < v1->size; i++) {
		// porównanie z dok³adnoœci¹ do epsilon (0.0001) (ze wzglêdu na b³êdy obliczeñ)
		if (v1->vector[i] - v2->vector[i] > EPSILON || v1->vector[i] - v2->vector[i] < -EPSILON) {
			printf("Wektory sa rozne!\n");
			return false;
		}
	}
	return true;
}

void free_vector(Vector* v) {
	free(v->vector);
	v->vector = NULL;
	free(v);
	v = NULL;
}

int dot_product(Vector* a, Vector* b) {
	if (a->size != b->size) {
		printf("Wektory musza byc tej samej dlugosci!\n");
		return NULL;
	}
	int result = 0;
	for (int i = 0; i < a->size; i++) {
		result += a->vector[i] * b->vector[i];
	}
	return result;
}

int cross_product(Vector* a, Vector* b, Vector* result) {
	if (a->size != 3 || b->size != 3 || result->size != 3) {
		printf("Wektory musza byc trójwymiarowe!\n");
		return 0;
	}

	result->vector[0] = a->vector[1] * b->vector[2] - a->vector[2] * b->vector[1];
	result->vector[1] = a->vector[2] * b->vector[0] - a->vector[0] * b->vector[2];
	result->vector[2] = a->vector[0] * b->vector[1] - a->vector[1] * b->vector[0];

	return 1;
}