#include <stdio.h>
#include <stdlib.h>

struct matrix {
	struct matrix* right;   // aponta o proximo elemento diferente de zero na mesma linha
	struct matrix* below;   // aponta o proximo elemento diferente de zero na mesma coluna
	int line;
	int column;
	float info;
};

typedef struct matrix Matrix;
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

    free(ini);

}

void imprime(Matrix *ini, int linhas, int colunas){
    Matrix *teste = ini;

    for(int j=1; j<=linhas+1; j++){
        for(int i=1; i<=colunas+1; i++){
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

            nova->below = ini->below;
            ini->below = nova;
        }

    for(int j=colunas; j>0; j--){
        Matrix  *nova1 = (Matrix*)malloc(sizeof(Matrix));
        nova1->info = j;
        nova1->line = 0;
        nova1->column = -1;

            nova1->right = ini->right;
            ini->right = nova1;
    }
    return ini;
}

void insere(Matrix *ini, int linhas, int colunas, int l, int c, float valor){

//    printf("\n insere: valor:%f, linha:%d, coluna: %d", valor, l, c);
    if(linhas < l || colunas < c){
        printf("\n\tERRO!");
        return 0;
    }


    Matrix *aux, *nova = (Matrix*)malloc(sizeof(Matrix)),   *teste = ini;
    nova->info = valor;
    nova->column = c;
    nova->line = l;
    
    printf("\n insere: valor:%f, linha:%d, coluna: %d\n\n", nova->info, nova->line, nova->column);
    
    for(int i=0; i<=l; i++){
       if(ini->info == l){
            for(int j=0; j<=c; j++){
                if (j == c)
                {
                    aux = ini->right;
                    ini->right = nova;
                    nova->right = aux;

                    aux = ini->below;
                    ini->below = nova;
                    nova->below = aux;
                }
                j++;
                ini = ini->right;
            }
       }
       i++;
       ini = ini->below;
    }
    //imprime(teste, linhas, colunas);
}

Matrix* matrix_create( int colunas , int linhas ){
    int  l=-1, c=-1, valor=0;
    Matrix *ini;

    ini = criaCabecas(linhas, colunas);

    while( 1 ) {
        printf("Digite a linha, coluna e valor a ser guardado na matriz.\n");
        printf("DIgite a linha:");
        scanf("%d", &l);
        if( l == 0 ){
            break;
        }
        printf("DIgite a coluna:");
        scanf("%d", &c);
        printf("DIgite o valor:");
        scanf("%d", &valor);

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
