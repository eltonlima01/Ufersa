/*
mplemente a estrutura de dados para a ´arvore bin´aria de busca. Por exemplo, em C:
Listing 1: Estrutura de um n´o da ´arvore bin´aria de busca
t y p e d e f s t r u c t No {
i n t dado ;
s t r u c t No* e s q u e r d o ;
s t r u c t No* d i r e i t o ;
} No ;
*/

typedef struct Node 
{
    int data;
    struct Node *left, *right;
} Node;