#include "matrix.h"

int main() {
    double tempo = 0.0;
    clock_t begin = clock();

    Matrix *A = matrix_create();
    printf("matriz a criada\n");
    Matrix *B = matrix_create();
    printf("matriz b criada\n");
    Matrix *C = matrix_add( A, B ); 
    printf("matriz c = add\n");
    matrix_destroy( C );
    printf("matriz c destruida\n");
    C = matrix_multiply( A, B ); 
    printf("matriz c = mult\n");
    matrix_destroy( C );
    printf("matriz c destruida\n");
    C = matrix_transpose( A );
    printf("matriz a transposta\n");
    matrix_destroy( C );
    printf("matriz c destruida\n");
    matrix_destroy( A );
    printf("matriz a destruida\n");
    matrix_destroy( B );
    printf("matriz b destruida\n");

    clock_t end = clock();
    tempo += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("TEMPO: %f s", tempo);
}   

/* 
int main() {
    double tempo = 0.0;
    clock_t begin = clock();

    Matrix *A = regular_matrix_create(255);
    printf("matriz a criada\n");
    Matrix *B = regular_matrix_create(255);
    printf("matriz b criada\n");
    Matrix *C = matrix_add( A, B ); 
    printf("matriz c = add\n");
    matrix_destroy( C );
    printf("matriz c destruida\n");
    C = regular_matrix_multiply( A, B ); 
    printf("matriz c = mult\n");
    matrix_destroy( C );
    printf("matriz c destruida\n");
    C = matrix_transpose( A );
    printf("matriz a transposta\n");
    matrix_destroy( C );
    printf("matriz c destruida\n");
    matrix_destroy( A );
    printf("matriz a destruida\n");
    matrix_destroy( B );
    printf("matriz b destruida\n");

    clock_t end = clock();
    tempo += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("TEMPO: %f s", tempo);
}    */