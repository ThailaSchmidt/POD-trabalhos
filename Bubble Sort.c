#include <stdio.h>

int main(void) {
    int i, j, k;
    int n = 10;
    int A[10] = {6, 10, 5, 4, 9, 3, 8, 1, 7, 2};
    for(i = n-1; i > 0; i--){
        int flag = 0;
        for(j = 0; j < i; j++){
            if(A[j] > A[j+1]){
                int x = A[j];
                A[j] = A[j+1];
                A[j+1] = x;
                flag = 1;
            }
        }
        if(!flag){
            break;
        }
    }
    for(k = 0; k < 10; k++){
        printf("%d ", A[k]);
    }
    return 0;
}
