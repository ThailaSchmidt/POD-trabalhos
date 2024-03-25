#include <stdio.h>

/*
O jogador mantém um conjunto de cartas ordenadas na mão e, ao “pescar” uma nova carta, deve abrir espaço entre as demais para inseri-la na posição correta, de modo a manter a ordenação do conjunto
*/

int main(void) {
    int k, i, j, n, p;
    int A[10] = {6, 10, 5, 4, 9, 3, 8, 1, 7, 2};
    n = 10;
    
    for (i = 1; i <= n-1; i++){
        p = A[i];
        j = i - 1;
        while (p < A[j]) { //Busca posição de inserção na parte ordenada.
            A[j+1] = A[j];  //Move o valor para a posição à sua direita (abre espaço)
            j--;
        }
        A[j+1] = p; //p é colocado na posição encontrada
        for(k = 0; k < 10; k++){
            printf("%d ", A[k]);
        }
        printf("\n");
}
    for(k = 0; k < 10; k++){
        printf("%d ", A[k]);
    }
    return 0;
}

