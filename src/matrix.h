struct matrix
{
    struct matrix *right; // aponta o proximo elemento diferente de zero na mesma linha
    struct matrix *below; // aponta o proximo elemento diferente de zero na mesma coluna
    int line;
    int column;
    float info;
};

typedef struct matrix Matrix;
Matrix *criaCabecas(int linhas, int colunas);
void insere(Matrix *ini, int linhas, int colunas, int l, int c, float valor);
Matrix *matrix_create();
void matrix_print(Matrix *m);
float matrix_getelem(Matrix *m, int x, int y);
int cont_linhas(Matrix *m);
int cont_colunas(Matrix *m);
void matrix_setelem(Matrix *m, int x, int y, float elem);
void matrix_destroy(Matrix *m);
Matrix *matrix_transpose(Matrix *m);
Matrix *matrix_add(Matrix *m, Matrix *n);
Matrix *matrix_multiply(Matrix *m, Matrix *n);

Matrix *criaCabecas(int linhas, int colunas)
{ // Função cria cabeças         <=======
    Matrix *ini = (Matrix *)malloc(sizeof(Matrix));

    ini->column = -1;
    ini->line = -1;
    ini->info = 666;
    ini->right = ini;
    ini->below = ini;

    for (int j = linhas; j > 0; j--)
    {
        Matrix *nova = (Matrix *)malloc(sizeof(Matrix));
        nova->info = j;
        nova->line = -1;
        nova->column = 0;
        nova->right = nova;

        nova->below = ini->below;
        ini->below = nova;
    }

    for (int j = colunas; j > 0; j--)
    {
        Matrix *nova1 = (Matrix *)malloc(sizeof(Matrix));
        nova1->info = j;
        nova1->line = 0;
        nova1->column = -1;
        nova1->below = nova1;

        nova1->right = ini->right;
        ini->right = nova1;
    }
    return ini;
}

void insere(Matrix *ini, int linhas, int colunas, int l, int c, float valor)
{

    if (valor == 0)
    {
        return;
    }

    Matrix *nova = (Matrix *)malloc(sizeof(Matrix)), *teste = ini, *anterior = ini;
    nova->info = valor;
    nova->column = c;
    nova->line = l;

    for (int j = 1; j <= c; j++)
    {
        anterior = ini;
        ini = ini->right;
    }

    for (int i = 1; i <= linhas; i++)
    {
        if (ini->below == ini)
        {
            ini->below = nova;
            nova->below = ini;
            break;
        }
        else if (ini->line > nova->line)
        {
            nova->below = ini;
            anterior->below = nova;
            break;
        }
        else if (ini->below->column == -1)
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
    ini = teste;

    for (int j = 1; j <= l; j++)
    {
        anterior = ini;
        ini = ini->below;
    }

    for (int j = 1; j <= colunas; j++)
    {
        if (ini->right == ini)
        {
            ini->right = nova;
            nova->right = ini;
            break;
        }
        else if (ini->column > nova->column)
        {
            anterior->right = nova;
            nova->right = ini;
            break;
        }
        else if (ini->right->line == -1)
        {
            anterior = ini;
            ini = ini->right;

            anterior->right = nova;
            nova->right = ini;
            break;
        }

        anterior = ini;
        ini = ini->right;
    }

    anterior = NULL;
    teste = NULL;
    free(teste);
    free(anterior);
}

Matrix *matrix_create()
{
    int linhas = 0, colunas = 0;
    printf("Digite a qntd de linhas e colunas da matriz:");
    scanf("%d %d", &linhas, &colunas);

    int l = -1, c = -1, leituras = 0;
    float valor = 0;
    Matrix *ini;

    ini = criaCabecas(linhas, colunas);

    while (1)
    {
        printf("Digite a linha, coluna e valor a ser guardado na matriz.\n");
        scanf("%d %d %f", &l, &c, &valor);
        if (l == 0)
            return ini;

        if (linhas < l || colunas < c)
        {
            printf("\n\tERRO!\n\n");
        }
        else
        {
            insere(ini, linhas, colunas, l, c, valor);
            leituras++;

            if (leituras == (linhas * colunas))
            {
                return ini;
            }
        }
    }

    return ini;
}

void matrix_print(Matrix *m)
{
    if (m->line != -1 && m->column != -1)
    {
        printf("\tMatriz vazia!\n");
        return;
    }
    else
    {
        int linhas = 0, colunas = 0;

        linhas = cont_linhas(m);
        colunas = cont_colunas(m);

        printf("%d %d <=tam\n", linhas, colunas);
        while (1)
        {
            m = m->below;
            while (1)
            {
                m = m->right;
                if (m->column != -1 && m->line != -1)
                {
                    printf("%d, %d, %.2f \n", m->line, m->column, m->info);
                }
                else if (m->line == -1)
                {
                    break;
                }
            }
            if (m->column == -1 && m->line == -1)
                return;
        }
    }
}

float matrix_getelem(Matrix *m, int x, int y)
{
    int linhas = 0, colunas = 0;

    linhas = cont_linhas(m);
    colunas = cont_colunas(m);

    if (x <= linhas && y <= colunas)
    {
        for (int i = 1; i <= y; i++)
            m = m->right;

        for (int i = 0; i <= x; i++)
        {
            if (m->line == x && m->column == y)
            {
                return m->info;
            }
            else if (m->below->column == -1)
            {
                return 0;
            }
            m = m->below;
        }
    }
    else
    {
        printf("\tInvalido!");
        return 0;
    }

    return 0;
}

void matrix_setelem(Matrix *m, int x, int y, float elem)
{
    Matrix *aux = m;
    int linhas = 0, colunas = 0;
    linhas = cont_linhas(m);
    colunas = cont_colunas(m);

    for (int i = 1; i <= y; i++)
        m = m->right;
    for (int i = 0; i <= x; i++)
    {
        if (m->line == x && m->column == y)
        {
            m->info = elem;
        }
        else if (m->below->column == -1)
        { // celula vazia. malloc em novo elemento
            insere(aux, linhas, colunas, x, y, elem);
        }

        m = m->below;
    }
}

void matrix_destroy(Matrix *m)
{ //      revisar a logica e arrumar leak de memoria

    int l = cont_linhas(m), cont = 0;

    Matrix *cabeca, *proximo;
    while (1)
    { // free em td que não for cabeça (conteúdo da matriz)
        cabeca = m;
        m = m->right;
        while (1)
        {
            if (m->line != -1)
            {
                proximo = m->right;
                free(m);
                m = proximo;
            }
            else if (m->line == -1 && m == cabeca)
            {
                proximo = m->below;
                free(m);
                m = proximo;
                cont++;
                break;
            }
            else
            {
                m = m->right;
            }
        }

        if (cont == l + 1)
            break;
    }

    proximo = NULL;
    m = NULL;
}

Matrix *matrix_transpose(Matrix *m)
{
    Matrix *mt;
    int linhas = 0, colunas = 0;
    linhas = cont_colunas(m);
    colunas = cont_linhas(m);

    mt = criaCabecas(linhas, colunas);

    while (1) // pula linha da matriz m
    {
        m = m->below;
        while (1)
        {
            m = m->right;
            if (m->line != -1 && m->column != -1)
            {
                insere(mt, linhas, colunas, m->column, m->line, m->info);
            }
            else if ((m->line == -1 && m->column == 0) || (m->line == -1 && m->column == -1))
            {
                break;
            }
        }
        if (m->line == -1 && m->column == -1)
            break;
    }
    
    return mt;
}

Matrix *matrix_add(Matrix *m, Matrix *n)
{
    Matrix *result;
    int m_linhas = 0, m_colunas = 0, n_linhas = 0, n_colunas = 0;
    float soma = 0;
    m_linhas = cont_linhas(m);
    m_colunas = cont_colunas(m);
    n_linhas = cont_linhas(n);
    n_colunas = cont_colunas(n);

    if ((m_linhas == n_linhas) && m_colunas == n_colunas)
    {

        result = criaCabecas(m_linhas, m_colunas);

        for (int i = 1; i <= m_linhas; i++)
        {
            for (int j = 1; j <= m_colunas; j++)
            {
                soma = 0;
                soma += matrix_getelem(m, i, j);
                soma += matrix_getelem(n, i, j);
                printf("(s = %f)\n", soma);
                if (soma != 0)
                {
                    insere(result, m_linhas, m_colunas, i, j, soma);
                }
            }
        }
    }
    else
    {
        printf("\n\tNao foi possivel fazer a soma!\n");
    }

    return result;
}

Matrix *matrix_multiply(Matrix *m, Matrix *n)
{
    int m_linhas = cont_linhas(m),
        m_colunas = cont_colunas(m),
        n_linhas = cont_linhas(n),
        n_colunas = cont_colunas(n);

    if (m_colunas != n_linhas)
    {
        printf("\n\tNao foi possivel multiplicar estas matrizes!\n");
        return NULL;
    }

    Matrix *result = criaCabecas(m_linhas, n_colunas);

    for (int i = 1; i <= m_linhas; i++)
    {
        for (int j = 1; j <= n_colunas; j++)
        {
            float soma = 0;

            for (int k = 1; k <= m_colunas; k++)
            {
                float a = matrix_getelem(m, i, k);
                float b = matrix_getelem(n, k, j);
                soma += a * b;
            }

            if (soma != 0.0)
            {
                insere(result, m_linhas, n_colunas, i, j, soma);
            }
        }
    }

    return result;
}

int cont_linhas(Matrix *m)
{
    int linhas = 0;
    Matrix *aux = m;
    while (1) // conta a qntd de linhas da matriz
    {
        m = m->below;
        if (m->column != -1)
        {
            linhas++;
        }
        else
        {
            break;
        }
    }
    m = aux;
    aux = NULL;
    return linhas;
}

int cont_colunas(Matrix *m)
{
    int colunas = 0;
    Matrix *aux = m;
    while (1) // conta a qntd de colunas da matriz
    {
        m = m->right;
        if (m->line != -1)
        {
            colunas++;
        }
        else
        {
            break;
        }
    }
    m = aux;
    aux = NULL;
    return colunas;
}