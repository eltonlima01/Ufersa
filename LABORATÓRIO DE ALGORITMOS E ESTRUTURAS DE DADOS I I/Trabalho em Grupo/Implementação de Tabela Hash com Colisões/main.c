/*
Implemente uma estrutura de tabela hash em C ou C++, com suporte a
inserção, busca e remoção. Teste duas estratégias de colisão: encadeamento separado e sondagem linear.
Compare o desempenho de ambas em termos de tempo e número de colisões.
*/

#include <stdio.h>

#define MENU printf ("====================\n1 - Insert in table\n2 - Show table\n3 - Remove from table\n4 - Exit\n====================\n[Input]: ");

typedef struct hash
{
    int key;
    char free;
} hash;

const int lenght = 10;

int hashing (int n);
void init_table (hash table []);
void show_table (hash table []);
void insert_table (hash table [], int pos, int n);
int search_table (hash table [], int n);
void remove_table (hash table [], int n);

void main ()
{
    hash table [lenght];
    init_table (table);

    short int option;
    int position, n, i;

    do
    {
        MENU;
        scanf ("%hi", &option);

        switch (option)
        {
            case 1:
                printf ("[1 - Insert in table]\n[Input]: ");
                scanf ("%i", &n);

                position = hashing (n);

                insert_table (table, position, n);
            break;

            case 2:
            puts ("[2 - Show table]");
                show_table (table);
            break;

            case 3:
                printf ("[3 - Remove from table]\n[Input]: ");
                scanf ("%i", &n);

                remove_table (table, n);
            break;
        }
    }
    while (option != 4);
}

int hashing (int n)
{
    return n % lenght;
}

void init_table (hash table [])
{
    for (int i = 0; i < lenght; i++)
    {
        table [i].free = 'F';
    }
}

void show_table (hash table [])
{
    for (int i = 0; i < lenght; i++)
    {
        (table [i].free == 'O') ? printf ("[%i]", table [i].key) : printf ("[ ]");
    }

    putchar ('\n');
}


void insert_table (hash table [], int pos, int n)
{
    int i = 0;

    while ((i < lenght) && (table [(pos + i) % lenght].free != 'F') && (table [(pos + i) % lenght].free != 'R'))
    {
        i++;
    }

    if (i < lenght)
    {
        table [(pos + i) % lenght].key = n;
        table [(pos + i) % lenght].free = 'O';
    }
    else
    {
        puts ("[ERROR::Full table]");
    }
}

int search_table (hash table [], int n)
{
    int i = 0,
    pos = hashing (n);

    while ((i < lenght) && (table [(pos + i) % lenght].free != 'F') && (table [(pos + i) % lenght].key != n))
    {
        i++;
    }

    if ((table [(pos + i) % lenght].key == n) && (table [(pos + i) % lenght].free != 'R'))
    {
        return (pos + i) % lenght;
    }
    else
    {
        return lenght;
    }
}

void remove_table (hash table [], int n)
{
    int position = search_table (table, n);

    if (position < lenght)
    {
        table [position].free = 'R';
    }
    else
    {
        printf ("[ERROR::No elements in %i]\n", position);
    }
}