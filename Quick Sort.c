#include <stdio.h>

/*
–Escolher um elemento especial, chamado de Pivô;
–Posicionar todos os elementos menores ou iguais ao Pivô à sua esquerda e os maiores à sua direita;
–Chamar recursivamente a função para a parte esquerda e para a parte direita.
*/

int particiona(int A[], int b, int e) {
    int x, k;
    int posPivo = e;   // usando o ultimo; poderia ser outra estratégia, tipo usar o primeiro, o do meio entre 3 valores ou algum aleatorio
    k = b;             // k: posição de swap para o pivo
    for (int i = b; i < e; i++) {
        if (A[i] <= A[posPivo]) {
            x = A[i];
            A[i] = A[k];
            A[k] = x;
            k++;
        }
    }
    if (A[k] > A[posPivo]) {
        x = A[posPivo];
        A[posPivo] = A[k];
        A[k] = x;
        posPivo = k;
        k++;
    }
    return posPivo; //RETORNA-SE SEMPRE A POSIÇÃO ATUAL DO PIVÔ!
}

void quickSort(int A[], int b, int e) {
  if (b < e) {
    int posPivo = particiona(A, b, e); //vai retornar a posicao do pivô
    quickSort(A, b, posPivo - 1);
    quickSort(A, posPivo + 1, e);
  }
}

int main(void) {
    int n, k, b, e;
    int A[10] = {6, 10, 2, 4, 9, 3, 8, 1, 7, 5};
    n = 10; //tamanho do v
    b = 0;
    e = n;//-1
    quickSort(A, b, e);
    for (k = 0; k < 10; k++) {
        printf("%d ", A[k]);
    }
    return 0;
}