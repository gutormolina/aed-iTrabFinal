#include "matrix.h"

int main(void)
{
    double tempo = 0.0;
    clock_t begin = clock();

	Matrix *ini1, *ini2, *m;

    ini1 = matrix_create();
    ini2 = matrix_create();

    m = matrix_multiply(ini1, ini2);
    
    matrix_print(m);

    matrix_destroy(ini1);
    matrix_destroy(ini2);
    matrix_destroy(m);

    clock_t end = clock();
    tempo += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nTEMPO: %f", tempo);
}