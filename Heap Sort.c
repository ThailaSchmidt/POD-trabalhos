#include <stdio.h>

void createHeap(int A[], int i, int n){
    int max = i;
    int left = 2 * i + 1; // filho da esquerda de i 
    int right = 2 * i + 2;// filho da direita de i 
    if (left < n && A[left] > A[i])
        max = left;
    
    if (right < n && A[right] > A[max])
        max = right;
    
    if (max != i){
        int x = A[i];
        A[i]=A[max];
        A[max]=x;
        createHeap(A, max, n);
    }
}

void heapSort(int A[], int n){
    for(int k = n/2-1; k >= 0; k--){ //Para todas as subárvores com filhos, da última para a primeira
        createHeap(A, k, n); //Organiza o heap daquela subárvore
    }
    for (int k = 0; k < 10; k++) {
        printf("%d ", A[k]);
    }
    
    printf("\nReorganiza: \n");
    for(int k = n-1; k >= 0; k--){
        int x = A[0];
        A[0]=A[k];
        A[k]=x;
        for (int k = 0; k < 10; k++) {
            printf("%d ", A[k]);
        }
        printf("\n");
        createHeap(A, 0, k); //Reorganiza o heap deixando os já ordenados de fora
    }
}

int main(void) {
    int k, i, n;
    int A[10] = {6, 10, 5, 4, 9, 3, 8, 1, 7, 2};
    n = 10; //tamanho de A
    i = 0;
    heapSort(A, n);
    for (k = 0; k < 10; k++) {
        printf("%d ", A[k]);
    }
    return 0;
}