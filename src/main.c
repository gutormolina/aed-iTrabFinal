#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

void imprime(Matrix *ini, int linhas, int colunas);
Matrix* criaCabecas( int linhas, int colunas);
void insere(Matrix *ini, int linhas, int colunas, int l, int c, float valor);
Matrix* matrix_create( int colunas , int linhas );
void matrix_print( Matrix* m );

int main(void)
{
    int linhas = 0, colunas = 0;
    printf("Digite a qntd de linhas da matriz:");
    scanf("%d", &linhas);
    printf("Digite a qntd de colunas da matriz:");
    scanf("%d", &colunas);

	Matrix *ini ;

    ini = matrix_create(colunas, linhas);

//    imprime(ini, linhas, colunas);
    matrix_print( ini );

    free(ini);

}

void imprime(Matrix *ini, int linhas, int colunas){
    Matrix *teste = ini;

    for(int j=0; j<=linhas; j++){
        for(int i=0; i<=colunas; i++){
            printf(" (%.02f, l:%d, c:%d)  ", teste->info, teste->line, teste->column);
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

    Matrix *nova = (Matrix*)malloc(sizeof(Matrix)), *teste = ini, *anterior = ini;
    nova->info = valor;
    nova->column = c;
    nova->line = l;

    for(int j = 1; j <=c; j++)
    {
    anterior = ini;  
    ini = ini->right;
     
    }

    for(int i = 1; i <= linhas; i++)
    {
        if (ini->below == ini)
        {
            ini->below = nova;
            nova->below = ini;
            break;
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
    
    anterior = NULL;

    for(int j = 1; j <=l; j++)
    {
        anterior = teste;
        teste = teste->below;
    }

    for(int j = 1; j <= colunas; j++)
    {
        if ( teste->right == teste )
        {
            teste->right = nova;
            nova->right = teste;
            break;
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
}

Matrix* matrix_create( int colunas , int linhas ){
    int  l=-1, c=-1, leituras = 0;
    float valor=0;
    Matrix *ini;

    ini = criaCabecas(linhas, colunas);

    while( 1 ) {
        printf("Digite a linha, coluna e valor a ser guardado na matriz.\n");
        printf("DIgite a linha:");
        scanf("%d %d %f", &l, &c, &valor);
        if( l == 0 )
            return ini;
        
        if(linhas < l || colunas < c)
        {
            printf("\n\tERRO!\n\n");
        } else {
            
            insere( ini, linhas, colunas, l, c, valor );
            leituras++;

            if(leituras == (linhas * colunas) )
            {
            return ini;
            }
        }
    }

return ini;
}

void matrix_print( Matrix* m ){
    int linhas = 0, colunas = 0;
    Matrix * aux = m;
    while (1)   // conta a qntd de linhas da matriz
    {
        m = m->below;
        if(m->column != -1){
            linhas++;
        }else{
            break;
        }
    }
    while (1)   // conta a qntd de colunas da matriz
    {
         m = m->right;
        if(m->line != -1){
            colunas++;
        }else{
            break;
        }
    }

    m = aux;
    printf("%d %d\n", linhas, colunas);

	while(1){
        m = m->below;
             while(1){
                m = m->right;
                if(m->column != -1 && m->line != -1){
                    printf("%d, %d, %.2f \n", m->line, m->column, m->info);
                } else if (m->line == -1)
                {
                   break;
                }
            }  
        if(m->column == -1 && m->line == -1)  
            return;
	}
}

/*

void matrix_destroy( Matrix* m ){

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
