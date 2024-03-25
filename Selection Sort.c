#include <stdio.h>

/*
Selecionar o menor valor e trocá-lo com o elemento que está na primeira posição; em seguida, o segundo menor elemento é trocado com o que se encontra na segunda posição, e assim sucessivamente, até que reste apenas 1 elemento
*/

int main(void) {
    int i, j, n, x, k, minPos;
    int A[10] = {6, 10, 5, 4, 9, 3, 8, 1, 7, 2};
    n = 10;
    for(i = 0; i < n-1; i++){ //percorre o vetor
        minPos = i;
        for(j = i+1; j < n; j++) //procura o menor
            if(A[j] < A[minPos])
                minPos = j;
        //testar se o minPos já está na posição correta
        x = A[i];
        A[i] = A[minPos];
        A[minPos] = x;
    }
    for(k = 0; k < 10; k++) //print
        printf("%d ", A[k]);
  return 0;
}