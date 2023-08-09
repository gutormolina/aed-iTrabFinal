#include <stdio.h>
#include <stdlib.h>

struct matrix {
	struct matrix* right;   // aponta o prÃ³ximo elemento diferente de zero na mesma linha
	struct matrix* below;   // aponta o prÃ³ximo elemento diferente de zero na mesma coluna
	int line;
	int column;
	float info;
};

typedef struct matrix Matrix;
Matrix* iniciaCabecas(int linhas, int colunas);


int main(void)
{
	Matrix *teste, *ini ;

    ini = iniciaCabecas(2, 4);

    teste = ini;
    for(int i=1; i<5; i++){
        printf(" /%.02f, l:%d, c:%d/  ", teste->info, teste->line, teste->column);
        teste = teste->right;
    }
    teste = ini;
    for(int i=1; i<6; i++){
        printf("\n/%.02f, l:%d, c:%d/", teste->info,  teste->line, teste->column);
        teste = teste->below;
    }
    free(ini);
}

Matrix* iniciaCabecas(int linhas, int colunas){
    Matrix *ini = (Matrix*)malloc( sizeof(Matrix));
    
    ini->column = -1;
    ini->line = -1;
    ini->info = 666;
    ini->right = ini;
    ini->below = ini;
  
    for(int j=linhas; j>0; j--){
        Matrix *nova = (Matrix*)malloc(sizeof(Matrix));
        nova->info = j;
        nova->line = -1;
        nova->column = 0;

            nova->right = ini->right;
            ini->right = nova;
        }

    for(int j=colunas; j>0; j--){
        Matrix  *nova1 = (Matrix*)malloc(sizeof(Matrix));
        nova1->info = j;
        nova1->line = 0;
        nova1->column = -1;

            nova1->below = ini->below;
            ini->below = nova1;
        
    }
    
        return ini;
}


/*

void matrix_destroy( Matrix* m ){

}

void matrix_print( Matrix* m ){
	while(1){
		if(m->info != 0){
			printf("[ %d, %d, %f]", m->line, m->column, m->info);
		}
	}
}

Matrix* matrix_add( Matrix* m, Matrix* n ){

}

Matrix* matrix_multiply( Matrix* m, Matrix* n ){

}

Matrix* matrix_transpose( Matrix* m ){

}

float matrix_getelem( Matrix* m, int x, int y ){

}

void matrix_setelem( Matrix* m, int x, int y, float elem ){

    
}


*/