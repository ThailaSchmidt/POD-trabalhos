/*
-Dividir o vetor em duas partes;
–Ordenar recursivamente cada parte;
–Intercalar os dois segmentos ordenados, formando um novo segmento ordenado.
*/
#include <stdio.h>

void intercala(int A[], int begin, int quite, int end) {
    int i, j, k;
    int aux[end-begin+1];     // alocação de espaço para(fim-inicio+1)
    i = begin;               // posição atual no vetor da esquerda
    j = quite + 1;           // posição atual no vetor da direita
    k = 0;                   // posição atual no vetor auxiliar

    while (i <= quite && j <= end) {
        if (A[i] <= A[j]) {
            aux[k] = A[i];
            i++;
        } else {
            aux[k] = A[j];
            j++;
        }
        k++;
    }
    
    while (i <= quite) {
        aux[k] = A[i];
        k++;
        i++;
    }
    
    while (j <= end) {
        aux[k] = A[j];
        k++;
        j++;
    }
    
    for (k = begin; k <= end; k++) {
        A[k] = aux[k - begin];
    }
}

void mergeSort(int A[], int begin, int end) {
    if (begin < end) {
        int quite = (begin + end)/2;
        mergeSort(A, begin, quite);
        mergeSort(A, quite+1, end);
        intercala(A, begin, quite, end);
    }
}

int main(void) {
    int n, k, b, e;
    int A[10] = {6, 10, 5, 4, 9, 3, 8, 1, 7, 2};
    n = 10; //tamanho do v
    b = 0;
    e = n - b;
    n = (0 + 10)/2;
    mergeSort(A, b, e);
    for (k = 0; k < 10; k++) {
        printf("%d ", A[k]);
    }
    return 0;
}