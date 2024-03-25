#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void buildInput(char *f, int n) {
    FILE *fp;
    int i, rd;

    fp = fopen(f, "w");//abre o arquivo especificado

    for (i = 0; i < n; i++) {
        rd = rand() % 100;//aleatorio
        fprintf(fp, "%d ", rd);//fprintf é uma função utilizada para imprimir cadeia de caracteres formatadas em um fluxo.
    }

    fclose(fp);//fecha
}

void printI(char *inp) {
    FILE *fp;
    int rd;

    fp = fopen(inp, "r");

    while (fscanf(fp, "%d", &rd) != EOF) {
        printf("%d ", rd);
        
    }
    printf("\n");

    fclose(fp);
}

void externalSort(char *inp, int n) {
    FILE *fp;
    int i, j, rd, *array;

    fp = fopen(inp, "r");

    array = (int *) malloc(n * sizeof(int));

    for (i = 0; i < n; i++) {
        fscanf(fp, "%d", &array[i]);
    }

    fclose(fp);

    //bubble sort
    for (i = n - 1; i >= 1; i--) {
        for (j = 0; j < n - 1; j++) {
            if (array[j] > array[j+1]) {
                rd = array[j];
                array[j] = array[j+1];
                array[j+1] = rd;
            }
        }
    }

    fp = fopen(inp, "w");

    for (i = 0; i < n; i++) {
        fprintf(fp, "%d ", array[i]);
    }

    fclose(fp);
    free(array);
}

void intercalate(char *inp1, char *inp2, char *outputinp, int n) {
    FILE *fp1, *fp2, *out;
    int i, rd1, rd2;

    fp1 = fopen(inp1, "r");
    fp2 = fopen(inp2, "r");
    out = fopen(outputinp, "w");

    fscanf(fp1, "%d", &rd1);
    fscanf(fp2, "%d", &rd2);

    for (i = 0; i < n+1; i++) {
        if (rd1 < rd2) {
            fprintf(out, "%d ", rd1);
            fscanf(fp1, "%d", &rd1);
            if (feof(fp1)) {
                fprintf(out, "%d ", rd2);
                while (fscanf(fp2, "%d", &rd2) != EOF) {
                    fprintf(out, "%d ", rd2);
                }
                break;
            }
        } else {
            fprintf(out, "%d ", rd2);
            fscanf(fp2, "%d", &rd2);
            if (feof(fp2)) {
                fprintf(out, "%d ", rd1);
                while (fscanf(fp1, "%d", &rd1) != EOF) {
                    fprintf(out, "%d ", rd1);
                }
                break;
            }
        }
    }

    fclose(fp1);
    fclose(fp2);
    fclose(out);
}

int main() {
    buildInput("input.txt", 10);
    printf("Input 1: \n");
    printI("input.txt");    
    externalSort("input.txt", 10);
    printI("input.txt");
    printf("\n");
    printf("Input 2: \n");
    buildInput("input2.txt", 10);
    printI("input2.txt");
    externalSort("input2.txt", 10);
    printI("input2.txt");
    printf("\n");
    intercalate("input.txt", "input2.txt", "output.txt", 80);
    printf("Intercalados: \n");
    printI("output.txt");

    return 0;
}