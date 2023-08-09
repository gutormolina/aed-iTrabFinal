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
Matrix* inicia(int linhas, int colunas);


int main(void)
{
	Matrix *teste, *ini ;

    ini = inicia(2, 3);

    teste = ini;
    for(int i=1; i<4; i++){
        printf(" /%.02f, l:%d, c:%d/  ", teste->info, teste->line, teste->column);
        teste = teste->right;
    }
    for(int i=1; i<4; i++){
        printf("\n/%.02f, l:%d, c:%d/", teste->info,  teste->line, teste->column);
        teste = teste->below;
    }
    free(ini);
}

Matrix* inicia(int linhas, int colunas){
    Matrix *ini = (Matrix*)malloc( sizeof(Matrix));
    Matrix *aux, *nova = (Matrix*)malloc(sizeof(Matrix));

    ini->column = -1;
    ini->line = -1;
    ini->info = 666;
    ini->right = ini;
    ini->below = ini;

    for(int i=1; i<linhas; i++){
       
        nova->info = i;
        nova->line = -1;
        nova->column = 0;

        if (ini->right == ini)
        {
            nova->right = ini->right;
            ini->right = nova;
        }else{
            aux = ini;
            for(int i=0; i<5; i++){
                if(ini->right == aux){
                    aux = ini->right;
                    ini->right = nova;
                    nova->right = aux;
                }
                ini=ini->right;
            }
        }
        }

        for(int j=1; j<colunas; j++){
            nova->info = j;
            nova->line = 0;
            nova->column = -1;

            if (ini->below == ini)
            {
                nova->below = ini->below;
                ini->below = nova;
            }else{
                aux = ini;
                for(int i=0; i<5; i++){
                    if(ini->below == aux){
                        aux = ini->below;
                        ini->below = nova;
                        nova->below = aux;
                    }
                    ini=ini->below;
                }
            }
        }
        ini=ini->below;
        return ini;
}




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
