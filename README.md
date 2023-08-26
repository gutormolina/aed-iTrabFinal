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

Foram feitos todos os testes pedidos na definição do trabalho. Os resultados de bytes alocados e leaks para as matrizes de 100MB podem ser encontrados nos arquivos de leak, sendo:

- Matriz Esparsa:
```
==3932== HEAP SUMMARY:
==3932==     in use at exit: 0 bytes in 0 blocks
==3932==   total heap usage: 307,574 allocs, 307,574 frees, 9,843,360 bytes allocated
==3932== 
==3932== All heap blocks were freed -- no leaks are possible
```
`src/esparsaLeaks.txt`

- Matriz Normal:
```
==2969== HEAP SUMMARY:
==2969==     in use at exit: 0 bytes in 0 blocks
==2969==   total heap usage: 327,022 allocs, 327,022 frees, 10,465,696 bytes allocated
==2969== 
==2969== All heap blocks were freed -- no leaks are possible
```
`src/normalLeaks.txt`

## O que está funcionando:

Todas as funções propostas são funcionais e como pode ser visto nos arquivos de leak o programa não tem nenhum leak de memória.
