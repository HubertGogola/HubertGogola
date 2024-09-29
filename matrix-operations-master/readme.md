# Dokumentacja projektu

## Wektor

### Struct Vector
```C
typedef struct {
    int size;
    float* vector;
} Vector;
```

### Inicjalizacja wektora
```C
bool initialize_vector(Vector* v, int size);
/** 
 * @brief Inicjalizuje wektor o zadanym rozmiarze.
 * @param v Wska�nik na struktur� wektora.
 * @param size Rozmiar wektora.
 * @return Zwraca true, je�li alokacja pami�ci si� nie powiod�a, w przeciwnym razie false.
 */
 ```

 ### Wypisywanie wektora
 ```C
void print_vector(Vector* v);
/**
 * @brief Drukuje zawarto�� wektora.
 * @param v Wska�nik na struktur� wektora.
 */
 ```

 ### Por�wnanie dw�ch wektor�w
 ```C
bool compare_vectors(Vector* v1, Vector* v2);
/**
 * @brief Por�wnuje dwa wektory.
 * @param v1 Wska�nik na pierwszy wektor.
 * @param v2 Wska�nik na drugi wektor.
 * @return Zwraca true, je�li wektory s� identyczne, w przeciwnym razie false.
 */
 ```

 ### Zwalnianie pami�ci zajmowanej przez wektor
 ```C
void free_vector(Vector* v);
/**
 * @brief Zwalnia pami�� zajmowan� przez wektor.
 * @param v Wska�nik na struktur� wektora.
 */
 ```

 ### Iloczyn skalarny
 ```C
int dot_product(Vector* a, Vector* b);
/**
 * @brief Oblicza iloczyn skalarny dw�ch wektor�w.
 * @param a Wska�nik na pierwszy wektor.
 * @param b Wska�nik na drugi wektor.
 * @return Zwraca warto�� iloczynu skalarnego.
 */
 ```

 ### Iloczyn wektorowy
 ```C
int cross_product(Vector* a, Vector* b, Vector* result);
/**
 * @brief Oblicza iloczyn wektorowy dw�ch wektor�w tr�jwymiarowych.
 * @param a Wska�nik na pierwszy wektor.
 * @param b Wska�nik na drugi wektor.
 * @param result Wska�nik na wektor wynikowy.
 * @return Zwraca 1, je�li operacja si� powiod�a, w przeciwnym razie 0.
 */
```

## Macierz

### Struct Matrix
```C
typedef struct {
    int rows;
    int cols;
    float** matrix;
} Matrix;
```

### Inicjalizacja macierzy
```C
bool initialize_matrix(Matrix* m, int rows, int cols);
/**
 * @brief Inicjalizuje macierz o zadanej liczbie wierszy i kolumn.
 * @param m Wska�nik na struktur� macierzy.
 * @param rows Liczba wierszy.
 * @param cols Liczba kolumn.
 * @return Zwraca true, je�li alokacja pami�ci si� nie powiod�a, w przeciwnym razie false.
 */
 ```

 ### Alokuje pami�� dla macierzy
 ```C
float** allocate_matrix(int rows, int cols);
/**
 * @brief Alokuje pami�� dla macierzy.
 * @param rows Liczba wierszy.
 * @param cols Liczba kolumn.
 * @return Wska�nik na zaalokowan� macierz.
 */
 ```

 ### Zwalnianie pami�ci zajmowanej przez macierz
 ```C
void free_matrix(Matrix* m);
/**
 * @brief Zwalnia pami�� zajmowan� przez macierz.
 * @param m Wska�nik na struktur� macierzy.
 */
 ```

 ### Wype�nianie macierzy losowymi warto�ciami
 ```C
void fill_matrix(Matrix* m, int start, int end);
/**
 * @brief Wype�nia macierz losowymi warto�ciami z zakresu [start, end].
 * @param m Wska�nik na struktur� macierzy.
 * @param start Pocz�tek zakresu warto�ci.
 * @param end Koniec zakresu warto�ci.
 */
 ```

 ### Wypisywanie macierzy
 ```C
void print_matrix(Matrix* m);
/**
 * @brief Drukuje zawarto�� macierzy.
 * @param m Wska�nik na struktur� macierzy.
 */
 ```

 ### Por�wnanie dw�ch macierzy
 ```C
bool compare_matrices(Matrix* m1, Matrix* m2);
/**
 * @brief Por�wnuje dwie macierze.
 * @param m1 Wska�nik na pierwsz� macierz.
 * @param m2 Wska�nik na drug� macierz.
 * @return Zwraca true, je�li macierze s� identyczne, w przeciwnym razie false.
 */
 ```