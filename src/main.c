#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

void imprime(Matrix *ini, int linhas, int colunas);
Matrix* criaCabecas( int linhas, int colunas);
void insere(Matrix *ini, int linhas, int colunas, int l, int c, float valor);
Matrix* matrix_create( int colunas , int linhas );

int main(void)
{
    int linhas = 0, colunas = 0;
    printf("Digite a qntd de linhas da matriz:");
    scanf("%d", &linhas);
    printf("Digite a qntd de colunas da matriz:");
    scanf("%d", &colunas);

	Matrix *ini ;

    ini = matrix_create(colunas, linhas);

    imprime(ini, linhas, colunas);
    printf("\n\n");
    imprime(ini, linhas, colunas);

    free(ini);

}

void imprime(Matrix *ini, int linhas, int colunas){
    Matrix *teste = ini;

    for(int j=0; j<=linhas; j++){
        for(int i=0; i<=colunas; i++){
            printf(" /%.02f, l:%d, c:%d/  ", teste->info, teste->line, teste->column);
            teste = teste->right;
        }
        printf("\n");
        teste = teste->below;
    }
}

Matrix* criaCabecas( int linhas, int colunas){          // Função cria cabeças         <=======
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
        nova->right = nova;

            nova->below = ini->below;
            ini->below = nova;
        }

    for(int j=colunas; j>0; j--){
        Matrix  *nova1 = (Matrix*)malloc(sizeof(Matrix));
        nova1->info = j;
        nova1->line = 0;
        nova1->column = -1;
        nova1->below = nova1;

            nova1->right = ini->right;
            ini->right = nova1;
    }
    return ini;
}

void insere(Matrix *ini, int linhas, int colunas, int l, int c, float valor){

    if(linhas < l || colunas < c){
        printf("\n\tERRO!\n\n");
        return;
    } else{

    Matrix *aux, *nova = (Matrix*)malloc(sizeof(Matrix)), *teste = ini;
    nova->info = valor;
    nova->column = c;
    nova->line = l;

    for(int j = 1; j <=c; j++)
        ini = ini->right;
        
    for(int i = 1; i <= linhas; i++)
    {
        if ((ini->below->column == -1) || (teste->below->column > nova->column))
        {
            nova->below = ini->below;
            ini->below = nova;
        }
        ini = ini->below;
    }
    printf("\t %d %d %f\n\n", ini->line, ini->column, ini->info);
    //===========
    aux = ini;
    
    for(int j = 1; j <=l; j++)
        teste = teste->below;
    for(int j = 1; j <= colunas; j++)
    {
        if ( (teste->right->line == -1) || (teste->right->line > nova->line) )
        {
            aux->right = teste->right;
            teste->right = aux;            
        }
        teste = teste->right;
    }
    printf("\t %d %d %f\n\n", teste->line, teste->column, teste->info);
    ini = teste;
    imprime(ini, linhas, colunas);
    }
}

Matrix* matrix_create( int colunas , int linhas ){
    int  l=-1, c=-1;
    float valor=0;
    Matrix *ini;

    ini = criaCabecas(linhas, colunas);
//    imprime(ini, linhas, colunas);
    while( 1 ) {
        printf("Digite a linha, coluna e valor a ser guardado na matriz.\n");
        printf("DIgite a linha:");
        scanf("%d %d %f", &l, &c, &valor);
        if( l == 0 ){
            break;
        }

        insere( ini, linhas, colunas, l, c, valor );
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
