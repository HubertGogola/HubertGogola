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
 * @param v WskaŸnik na strukturê wektora.
 * @param size Rozmiar wektora.
 * @return Zwraca true, jeœli alokacja pamiêci siê nie powiod³a, w przeciwnym razie false.
 */
 ```

 ### Wypisywanie wektora
 ```C
void print_vector(Vector* v);
/**
 * @brief Drukuje zawartoœæ wektora.
 * @param v WskaŸnik na strukturê wektora.
 */
 ```

 ### Porównanie dwóch wektorów
 ```C
bool compare_vectors(Vector* v1, Vector* v2);
/**
 * @brief Porównuje dwa wektory.
 * @param v1 WskaŸnik na pierwszy wektor.
 * @param v2 WskaŸnik na drugi wektor.
 * @return Zwraca true, jeœli wektory s¹ identyczne, w przeciwnym razie false.
 */
 ```

 ### Zwalnianie pamiêci zajmowanej przez wektor
 ```C
void free_vector(Vector* v);
/**
 * @brief Zwalnia pamiêæ zajmowan¹ przez wektor.
 * @param v WskaŸnik na strukturê wektora.
 */
 ```

 ### Iloczyn skalarny
 ```C
int dot_product(Vector* a, Vector* b);
/**
 * @brief Oblicza iloczyn skalarny dwóch wektorów.
 * @param a WskaŸnik na pierwszy wektor.
 * @param b WskaŸnik na drugi wektor.
 * @return Zwraca wartoœæ iloczynu skalarnego.
 */
 ```

 ### Iloczyn wektorowy
 ```C
int cross_product(Vector* a, Vector* b, Vector* result);
/**
 * @brief Oblicza iloczyn wektorowy dwóch wektorów trójwymiarowych.
 * @param a WskaŸnik na pierwszy wektor.
 * @param b WskaŸnik na drugi wektor.
 * @param result WskaŸnik na wektor wynikowy.
 * @return Zwraca 1, jeœli operacja siê powiod³a, w przeciwnym razie 0.
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
 * @param m WskaŸnik na strukturê macierzy.
 * @param rows Liczba wierszy.
 * @param cols Liczba kolumn.
 * @return Zwraca true, jeœli alokacja pamiêci siê nie powiod³a, w przeciwnym razie false.
 */
 ```

 ### Alokuje pamiêæ dla macierzy
 ```C
float** allocate_matrix(int rows, int cols);
/**
 * @brief Alokuje pamiêæ dla macierzy.
 * @param rows Liczba wierszy.
 * @param cols Liczba kolumn.
 * @return WskaŸnik na zaalokowan¹ macierz.
 */
 ```

 ### Zwalnianie pamiêci zajmowanej przez macierz
 ```C
void free_matrix(Matrix* m);
/**
 * @brief Zwalnia pamiêæ zajmowan¹ przez macierz.
 * @param m WskaŸnik na strukturê macierzy.
 */
 ```

 ### Wype³nianie macierzy losowymi wartoœciami
 ```C
void fill_matrix(Matrix* m, int start, int end);
/**
 * @brief Wype³nia macierz losowymi wartoœciami z zakresu [start, end].
 * @param m WskaŸnik na strukturê macierzy.
 * @param start Pocz¹tek zakresu wartoœci.
 * @param end Koniec zakresu wartoœci.
 */
 ```

 ### Wypisywanie macierzy
 ```C
void print_matrix(Matrix* m);
/**
 * @brief Drukuje zawartoœæ macierzy.
 * @param m WskaŸnik na strukturê macierzy.
 */
 ```

 ### Porównanie dwóch macierzy
 ```C
bool compare_matrices(Matrix* m1, Matrix* m2);
/**
 * @brief Porównuje dwie macierze.
 * @param m1 WskaŸnik na pierwsz¹ macierz.
 * @param m2 WskaŸnik na drug¹ macierz.
 * @return Zwraca true, jeœli macierze s¹ identyczne, w przeciwnym razie false.
 */
 ```