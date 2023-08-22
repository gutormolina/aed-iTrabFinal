#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main(void)
{
	Matrix *ini1, *ini;

    ini1 = matrix_create( );
    ini = matrix_create( );

    printf("===============");
    matrix_print(ini1);
    printf("===============");
    matrix_print(ini);
    printf("===============");

    Matrix *m = matrix_multiply(ini1, ini);

    matrix_print(m);

    matrix_destroy(ini1);
}
