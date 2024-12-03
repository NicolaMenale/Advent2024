#include <stdio.h>
#include <stdlib.h>

// Funzione per scambiare due elementi
void scambia(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Funzione per partizionare l'array
int partiziona(int array[], int inizio, int fine) {
    int pivot = array[fine]; // Scegliamo l'ultimo elemento come pivot
    int i = inizio - 1;      // Indice per elementi più piccoli del pivot

    for (int j = inizio; j < fine; j++) {
        if (array[j] <= pivot) { // Elemento più piccolo o uguale al pivot
            i++;
            scambia(&array[i], &array[j]); // Spostiamo l'elemento nella posizione corretta
        }
    }
    scambia(&array[i + 1], &array[fine]); // Mettiamo il pivot nella posizione corretta
    return i + 1; // Restituisce l'indice del pivot
}

// Funzione ricorsiva per il QuickSort
void quicksort(int array[], int inizio, int fine) {
    if (inizio < fine) {
        // Dividiamo l'array in due partizioni
        int indicePivot = partiziona(array, inizio, fine);

        // Ordiniamo ricorsivamente le due partizioni
        quicksort(array, inizio, indicePivot - 1); // Parte sinistra
        quicksort(array, indicePivot + 1, fine);  // Parte destra
    }
}

int main(){
    int number1, number2, i=0, j=0, risultato, parziale, count=0;
    int array1[1000];
    int array2[1000];

    FILE *file;

    file = fopen("input.txt", "r");

    printf("Numeri letti dal file:\n");
    while (fscanf(file, "%d   %d", &number1, &number2) == 2) {
        array1[i]=number1;
        array2[i]=number2;
        i++;
    }

    quicksort(array1, 0, 1000 - 1);
    quicksort(array2, 0, 1000 - 1);

    printf("Ordinato 1");
    for (i = 0; i < 1000; i++)
    {
        printf("1)%d\n", array1[i]);
    }

    for (i = 0; i < 1000; i++)
    {
        parziale = array1[i] - array2[i];
        risultato = risultato + abs(parziale);
    }

    printf("1) Risultato: %d\n", risultato);
    
    risultato = 0;
    for (i = 0; i < 1000; i++){
        for (j = 0; j < 1000; j++)
        {
            count = 0;
            if (array1[i] == array2[j])
            {
                count++;
            }
            risultato = risultato + (array1[i] * count);
        }
    }

    printf("2) Risultato: %d", risultato);

    fclose(file);
}

