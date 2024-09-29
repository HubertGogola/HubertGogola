#pragma once
#include <stdbool.h>

typedef struct {
	int size;
	float* vector;
} Vector;

bool initialize_vector(Vector* v, int size);
void print_vector(Vector* v);
bool compare_vectors(Vector* v1, Vector* v2);
void free_vector(Vector* v);
int dot_product(Vector* a, Vector* b);
int cross_product(Vector* a, Vector* b, Vector* result);