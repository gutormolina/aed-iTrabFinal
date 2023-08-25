#include "matrix.h"

int main( void ) {
/* Inicializacao da aplicacao ... */

    Matrix *A = matrix_create();
    matrix_print( A );
    Matrix *B = matrix_create(); 
    matrix_print( B );

    printf("\n");

    Matrix *C = matrix_add( A, B ); 
    matrix_print( C );
    matrix_destroy( C );

    printf("\n");

    C = matrix_multiply( A, B ); 
    matrix_print( C );
    matrix_destroy( C );

    printf("\n");

    C = matrix_transpose( A ); 
    matrix_print( C );

    matrix_destroy( C );
    matrix_destroy( A );
    matrix_destroy( B );
    
    return 0;
}   
