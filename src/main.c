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
Matrix* matrix_create(int colunas, int linhas);


int main(void)
{
    int linhas = 0, colunas = 0;
    printf("Digite a qntd de linhas da matriz:");
    scanf("%d", &linhas);
    printf("Digite a qntd de colunas da matriz:");
    scanf("%d", &colunas);

	Matrix *teste, *ini ;

    ini = matrix_create(colunas, linhas);

    teste = ini;
    
    teste = ini;
    for(int i=1; i<linhas; i++){


        for(int i=1; i<colunas; i++){
            printf("\n/%.02f, l:%d, c:%d/", teste->info, teste->line, teste->column);
            teste = teste->right;
        }
        teste = teste->below;
    }
    free(ini);

}

Matrix* matrix_create( int colunas , int linhas ){
    int  l=-1, c=-1, valor=0 ;
/*    printf("Digite a qntd de linhas da matriz:");
    scanf("%d", &linhas);
    printf("Digite a qntd de colunas da matriz:");
    scanf("%d", &colunas);
*/
//----------------------- inicia cabeças --------------------------------

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

//----------------------------------------------------------------------------------------------
        printf("Digite a linha, coluna e valor a ser guardado na matriz:");
        scanf("%d", &l);

    while(1) {
        if( l == 0 ){
            break;
        }
        scanf("%d", &c);
        scanf("%d", &valor);
        Matrix *aux, *nova = (Matrix*)malloc(sizeof(Matrix));
        nova->info = valor;
        nova->column = c;
        nova->line = l;
        for(int i=0; i<colunas; i++){
            if(ini->info == c){
                if(ini->below == ini){
                    nova->below = ini->below;
                    ini->below = nova;
                }else{
                    aux = ini;
                    for(int i=1; i<colunas; i++){
                        if(ini->below->column < c){
                            ini = ini->below;
                            break;;
                        }else{
                            nova->below = ini->below;
                            ini->below = nova;
                        }
                        ini = ini->below;
                    }
                }
            }
            printf("L: %d", l);
            ini = ini->below;
        }
        
        for(int i=0; i<linhas; i++){
            if(ini->info == l){
                if(ini->right == ini){
                    nova->right = ini->right;
                    ini->right = nova;
                }else{
                    aux = ini;
                    for(int i=1; i<linhas; i++){
                        if(ini->right->column < c){
                            ini = ini->right;
                            break;
                        }else{
                            nova->right = ini->right;
                            ini->right = nova;
                        }
                        ini = ini->right;
                    }
                }
            }
            ini = ini->right;
        }

    
        return ini;
    }

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