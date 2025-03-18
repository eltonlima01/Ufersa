/*
7º Desenvolva uma função que receba como parâmetro os ponteiros de
dois vetores de 5 posições. O procedimento deverá imprimir na tela os
valores contidos nos dois vetores de forma crescente (Utilize ponteiros).
Exemplo:
Vetor 1 = 2, 5, 9, 8, 3
Vetor 2 = 7, 4, 1, 10, 6
Saída: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
*/

#include<stdio.h>

void f(int *pA, int *pZ);

int main(){

    int A[5] = {2, 5, 9, 8, 3}, Z[5] = {7, 4, 1, 10, 6};
    int *pA = A, *pZ = Z;

    f(pA, pZ);

    printf("Saída: %i, %i, %i, %i, %i, %i, %i, %i, %i, %i\n",
    Z[0], Z[1], Z[2], Z[3], Z[4], A[0], A[1], A[2], A[3], A[4]);

    return 0;
}

void f(int *pA, int *pZ){

    printf("Vetor 1: %i, %i, %i, %i, %i\n", pA[0], pA[1], pA[2], pA[3], pA[4]);

    printf("Vetor 2: %i, %i, %i, %i, %i\n", pZ[0], pZ[1], pZ[2], pZ[3], pZ[4]);

    int tmprr;

    for(int i=0; i<5; i++){

        for(int j=0; j<4; j++){

            if(pZ[j] > pZ[j+1]){

                tmprr = pZ[j+1];
                pZ[j+1] = pZ[j];
                pZ[j] = tmprr;

            }

            if(pA[j] > pA[j+1]){

                tmprr = pA[j+1];
                pA[j+1] = pA[j];
                pA[j] = tmprr;

            }

            for(int k = 0; k<4; k++){

                if(pZ[j+1] > pA[k]){

                    tmprr = pA[k];
                    pA[k] = pZ[j+1];
                    pZ[j+1] = tmprr;

                }

            }

        }

    }

}