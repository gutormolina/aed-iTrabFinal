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

    Matrix *aux, *nova = (Matrix*)malloc(sizeof(Matrix)), *teste = ini, *anterior = ini;
    nova->info = valor;
    nova->column = c;
    nova->line = l;

    for(int j = 1; j <=c; j++)
    {
     anterior = ini;  
     ini = ini->right;
      
    }
      aux = ini;  
    for(int i = 1; i <= linhas; i++)
    {
        if (ini->below == ini)
        {
            ini->below = nova;
            nova->below = ini;
        } else if (ini->line > nova->line)
        {
            nova->below = ini;
            anterior->below = nova;
            break;
        }else if (ini->below->column == -1)
        {
            anterior = ini;  
            ini = ini->below;
            
            nova->below = ini;
            anterior->below = nova;
            break;
        }
        
         
        anterior = ini;  
        ini = ini->below;
        
    }
//=============
    for(int i = 0; i <= colunas; i++){
printf("\tteste: %d %d %f\n\n", aux->line, aux->column, aux->info);
    aux=aux->below;
    }    
//===========
    anterior = NULL;

    printf("-------------------------\n");
    for(int j = 1; j <=l; j++)
    {
        anterior = teste;
        teste = teste->below;
    }
    
aux = teste;

    for(int j = 1; j <= colunas; j++)
    {
        if ( teste->right == teste )
        {
            teste->right = nova;
            nova->right = teste;
        } else if (teste->column > nova->column )
        {
            anterior->right = nova;
            nova->right = teste;
            break;
        } else if ( teste->right->line == -1)
        {
            anterior = teste;
            teste = teste->right;

            anterior->right = nova;
            nova->right = teste;
            break;
        }        
        anterior = teste;
        teste = teste->right;
    }
    
//=============
    for(int i = 0; i <= colunas; i++){
printf("\tteste: %d %d %f\n\n", aux->line, aux->column, aux->info);
    aux=aux->right;
    }    
//===========

    ini = teste;
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
