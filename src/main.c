#include <stdio.h>
#include <stdlib.h>

struct matrix
{
    struct matrix *right; // aponta o proximo elemento diferente de zero na mesma linha
    struct matrix *below; // aponta o proximo elemento diferente de zero na mesma coluna
    int line;
    int column;
    float info;
};

typedef struct matrix Matrix;
//void imprime(Matrix *ini, int linhas, int colunas);
Matrix *criaCabecas(int linhas, int colunas);
void insere(Matrix *ini, int linhas, int colunas, int l, int c, float valor);
Matrix *matrix_create(int colunas, int linhas);
void matrix_print(Matrix *m);

int main(void)
{
    int linhas = 0, colunas = 0;
    printf("Digite a qntd de linhas da matriz: ");
    scanf("%d", &linhas);
    printf("Digite a qntd de colunas da matriz: ");
    scanf("%d", &colunas);

    Matrix *ini;

    ini = matrix_create(colunas, linhas);

    matrix_print(ini);
    //imprime(ini, linhas, colunas);

    free(ini);
}

void imprime(Matrix *ini, int linhas, int colunas)
{
    Matrix *teste = ini;

    for (int j = 1; j <= linhas; j++)
    {
        for (int i = 1; i <= colunas; i++)
        {
            printf(" /%.02f, l:%d, c:%d/  ", teste->info, teste->line, teste->column);
            teste = teste->right;
        }

        printf("\n");
        teste = teste->below;
    }
}

Matrix *criaCabecas(int linhas, int colunas)
{ // Função cria cabeças         <=======
    Matrix *ini = (Matrix *)malloc(sizeof(Matrix));

    ini->column = -1;
    ini->line = -1;
    ini->info = 666;
    ini->right = NULL;
    ini->below = NULL;

    for (int j = linhas; j > 0; j--)
    {
        Matrix *nova = (Matrix *)malloc(sizeof(Matrix));
        nova->info = j;
        nova->line = -1;
        nova->column = 0;

        nova->below = ini->below;
        ini->below = nova;
    }

    for (int j = colunas; j > 0; j--)
    {
        Matrix *nova1 = (Matrix *)malloc(sizeof(Matrix));
        nova1->info = j;
        nova1->line = 0;
        nova1->column = -1;

        nova1->right = ini->right;
        ini->right = nova1;
    }

    return ini;
}

void insere(Matrix *ini, int linhas, int colunas, int l, int c, float valor)
{

    if (linhas < l || colunas < c)
    {
        printf("\n\tERRO!\n\n");
        return;
    }

    Matrix *aux = ini;
    for (int i = 0; i < l; i++)
    {
        aux = aux->below;
    }

    for (int i = 0; i < c; i++)
    {
        aux = aux->right;
    }

    Matrix *nova = (Matrix *)malloc(sizeof(Matrix));
    nova->info = valor;
    nova->column = c;
    nova->line = l;
    nova->below = NULL;
    nova->right = NULL;

    Matrix *ins = ini;
    for (int i = 0; i < l - 1; i++)
    {
        ins = ins->below;
    }
    
    for (int i = 0; i < c - 1; i++)
    {
        ins = ins->right;
    }
    
    while (ins->below != aux)
    {
        ins = ins->below;
    }
    ins->below = nova;
    nova->below = aux;

    while (ins->right != aux)
    {
        ins = ins->right;
    }
    ins->right = nova;
    nova->right = aux;

    printf("\n insere: valor: %.3f, linha: %d, coluna: %d\n\n", nova->info, nova->line, nova->column);

    matrix_print(ini);
}

Matrix *matrix_create(int colunas, int linhas)
{
    int l = -1, c = -1;
    float valor = 0;
    Matrix *ini;

    ini = criaCabecas(linhas, colunas);

    while (1)
    {
        printf("\nDigite a linha, coluna e valor a ser guardado na matriz: ");
        scanf("%d %d %f", &l, &c, &valor);
        if (l == 0)
        {
            break;
        }

        insere(ini, linhas, colunas, l, c, valor);
    }

    return ini;
}

/*

void matrix_destroy( Matrix* m ){

}
*/
void matrix_print( Matrix* m ){
    Matrix *col = m->below;
    
    while (col) {
        Matrix *imprimir = col->right;
        
        while (imprimir) {
            printf("[ %d, %d, %.2f] ", imprimir->line, imprimir->column, imprimir->info);
            imprimir = imprimir->right;
        }
        
        printf("\n");
        col = col->below;
    }
}/*

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
