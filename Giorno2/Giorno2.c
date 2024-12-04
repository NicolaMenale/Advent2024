#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_LEN_R 1024 // Lunghezza massima di una riga
#define MAX_LEN 8 // Lunghezza massima di una riga

bool Crescente(int numeri[], int count){
    for (int i = 0; i < count - 1; i++) {
        if (numeri[i] > numeri[i + 1] || numeri[i] == numeri[i + 1]) {
            return false; // Trovato un elemento fuori ordine
        }
    }
    return true; // Tutti gli elementi sono in ordine crescente
}

bool Decrescente(int numeri[], int count){
    for (int i = 0; i < count - 1; i++) {
        if (numeri[i] < numeri[i + 1] || numeri[i] == numeri[i + 1]) {
            return false; // Trovato un elemento fuori ordine
        }
    }
    return true; // Tutti gli elementi sono in ordine crescente
}

bool Differenza(int numeri[], int count){
    for (int i = 0; i < count - 1; i++) {
        if (abs(numeri[i] - numeri[i + 1]) > 3) {
            return false; // Trovato un elemento fuori ordine
        }
    }
    return true; // Tutti gli elementi sono in ordine crescente
}

int main(){
    FILE *file = fopen("input.txt", "r");
    char riga[MAX_LEN_R]; // Buffer per la riga
    int numeri[MAX_LEN]; // Array per memorizzare i numeri letti
    int conteggio = 0; // Conteggio dei numeri letti
    int count=0, i = 0, risultato = 0;
    
    while (fgets(riga, MAX_LEN_R, file) != NULL) {
        for (i = 0; i < 8; i++)
        {
            numeri[i] = 0;
        }
        count = 0;

        sscanf(riga,"%d %d %d %d %d %d %d %d", &numeri[0], &numeri[1], &numeri[2], &numeri[3], &numeri[4], &numeri[5], &numeri[6], &numeri[7]);

        for (i = 0; i < 8; i++)
        {
            if (numeri[i] != 0)
            {
                count++;
            }    
        }
        
        for (i = 0; i < 8; i++)
        {
            printf("%d ", numeri[i]);
        }
        printf("count:%d \n", count);
        
        if (Crescente(numeri, count)) {
            if (Differenza(numeri, count))
            {
                risultato++;
            }
        } else if (Decrescente(numeri, count)) {
            if (Differenza(numeri, count))
            {
                risultato++;
            }
        }
        else{
            printf("Sbagliato\n");
        }
    }

    printf("Risultato: %d", risultato);

    fclose(file);
    return 0;
}