# aed-iTrabFinal
Repositório contendo o trabalho final da disciplina de Algoritmos e Estrutura de Dados I.

## Alunos:
- Augusto Ramos Molina // armolina@inf.ufpel.edu.br
- Bruna Camily Domingues Novack // bcdnovack@inf.ufpel.edu.br

## Caracterização do Problema:
Desenvolver um código de uma Matriz Esparsa em C. O código precisa ter as seguintes funções: 
- Matrix* matrix_create(void);
- void matrix_destroy(Matrix* m);
- void matrix_print(Matrix* m);
- Matrix* matrix_add(Matrix* m, Matrix* n);
- Matrix* matrix_multiply(Matrix* m, Matrix* n);
- Matrix* matrix_transpose(Matrix* m);
- float matrix_getelem(Matrix* m, int x, int y);
- void matrix_setelem(Matrix* m, int x, int y, float elem);

Devem ser realizados dois testes, sendo um deles com uma matriz gigante (cerca de 100mb), para comparar as diferenças na execução entre uma matriz espersa e uma normal.

## Casos testados:

## O que está funcionando:

Todas as funções propostas são funcionais e como pode ser visto no arquivo ```src/valgrind-out.txt```, o programa não tem nenhum leak de memória.
