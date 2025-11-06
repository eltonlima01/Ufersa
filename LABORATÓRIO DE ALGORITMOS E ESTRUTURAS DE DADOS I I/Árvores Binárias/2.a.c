typedef struct Aluno
{
    char nome [50];
    int matricula;
    float nota;
    struct Aluno *esquerdo, *direito;
} Aluno;