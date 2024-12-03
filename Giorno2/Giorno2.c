#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN_R 1024 // Lunghezza massima di una riga
#define MAX_LEN 1024 // Lunghezza massima di una riga

int main(){
    FILE *file = fopen("input.txt", "r");
    char riga[MAX_LEN_R]; // Buffer per la riga
    int numeri[MAX_LEN]; // Array per memorizzare i numeri letti
    int conteggio = 0; // Conteggio dei numeri letti

    while (fgets(riga, MAX_LEN_R, file) != NULL) {
        sscanf(riga,"%d %d %d %d %d %d %d %d", numeri[0], numeri[1], numeri[2], numeri[3], numeri[4], numeri[5], numeri[6], numeri[7]);

        //controli crescenti o decrescenti


    }

    fclose(file);
    return 0;
}