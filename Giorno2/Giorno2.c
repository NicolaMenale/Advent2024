#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN_R 1024 // Lunghezza massima di una riga
#define MAX_LEN 1024 // Lunghezza massima di una riga

int main(){
    FILE *file = fopen("input.txt", "r");
    char riga[MAX_LEN_R]; // Buffer per la riga
    int numeri[MAX_LEN]; // Array per memorizzare i numeri letti
    int conteggio = 0; // Conteggio dei numeri letti

    if (file == NULL) {
        perror("Errore apertura file");
        return 1;
    }

    // Legge e processa ciascuna riga fino alla fine del file
    while (!feof(file)) {

    // Legge una riga dal file
    if (fgets(riga, MAX_LEN_R, file) != NULL) {
        // Usa sscanf per leggere i numeri dalla riga
        int valore;
        char *ptr = riga; // Puntatore per scansionare la riga

        // Legge i numeri fino alla fine della riga
        while (sscanf(ptr, "%d", &valore) == 1) {
            numeri[conteggio++] = valore; // Salva il numero nell'array
            // Sposta il puntatore per leggere il numero successivo
            while (*ptr != ' ' && *ptr != '\0') {
                ptr++;
            }
            // Salta gli spazi bianchi
            while (*ptr == ' ') {
                ptr++;
            }
        }

        // Stampa i numeri letti (puoi sostituire questa parte con la tua logica di elaborazione)
        printf("Numeri letti dalla riga:\n");
        for (int i = 0; i < conteggio; i++) {
            printf("%d ", numeri[i]);
        }
        printf("\n");
    }
        }


    fclose(file);
    return 0;
}