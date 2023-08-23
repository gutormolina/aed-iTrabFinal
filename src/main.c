#include "matrix.h"

int main(void)
{
    double tempo = 0.0;
    clock_t begin = clock();
	Matrix *ini1;

    ini1 = matrix_create( );
    
    matrix_destroy(ini1);
    clock_t end = clock();
    tempo+= (double)(end - begin) / CLOCKS_PER_SEC;
    printf("TEMPO: %f", tempo);
}