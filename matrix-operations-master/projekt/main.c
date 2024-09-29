// Projekt z przedmiotu Programowanie Komputerów
// Temat: Operacje macierzowe
// Autorzy: Jakub Bajer, Hubert Gogola
// AGH WZ, IiE nstcj., rok 1, grupa 1
// 08.06.2024 r.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix_utils.h"
#include "matrix_operations.h"
#include "tests.h"
#include "vector_utils.h"

int main(int argc, char** argv) {
	// Seedowanie generatora liczb pseudolosowych
	srand((unsigned int)time(0));

	printf("Projekt z przedmiotu Programowanie Komputerow: Operacje Macierzowe\n");

	int option = 0;
	do {
		printf("Wybierz opcje <1-8> i nacisnij enter:\n");
		printf("\t1. Test mnozenia macierzy\n");
		printf("\t2. Test obliczania wyznacznika macierzy\n");
		printf("\t3. Test rozkladu na macierze trojkatne\n");
		printf("\t4. Test transponowania macierzy\n");
		printf("\t5. Test obliczania macierzy odwrotnej\n");
		printf("\t6. Test mnozenia macierzy przez wektor\n");
		printf("\t7. Test iloczynu wektorowego\n");
		printf("\t8. Test iloczynu skalarnego\n");
		printf("\t9. Wyjscie\n");

		if (scanf_s("%d", &option) != 1) {
			printf("Niepoprawna opcja!\n");
			return 1;
		}
		switch (option) {
		case 1:
			test_matrix_multiplication();
			break;
		case 2:
			test_matrix_determinant();
			break;
		case 3:
			test_triangle_decomposition();
			break;
		case 4:
			test_transpose_matrix();
			break;
		case 5:
			test_inverse_matrix();
			break;
		case 6:
			test_multiply_matrix_vector();
			break;
		case 7:
			test_cross_product();
			break;
		case 8:
			test_dot_product();
			break;
		case 9:
			return 0;
		default:
			printf("Niepoprawna opcja!\n");
			return 1;
		}

		printf("\n");
	} while (1);

	return 0;
}