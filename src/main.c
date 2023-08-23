#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main(void)
{
	Matrix *ini1;

    ini1 = matrix_create( );
    matrix_print(ini1);
    
    matrix_destroy(ini1);
}