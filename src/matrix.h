struct matrix {
	struct matrix* right;   // aponta o proximo elemento diferente de zero na mesma linha
	struct matrix* below;   // aponta o proximo elemento diferente de zero na mesma coluna
	int line;
	int column;
	float info;
};

typedef struct matrix Matrix;