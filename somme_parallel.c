#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define SIZE 1000000  // Augmenter la taille du tableau à 1 million
#define REPEAT 10     // Répéter 10 fois pour capturer le temps

int main() {
    int i, j;
    int *array;
    long long sum_seq = 0, sum_par = 0;
    double start, end;

    // Allocation dynamique du tableau pour éviter des problèmes de taille sur la pile
    array = (int*) malloc(SIZE * sizeof(int));

    if (array == NULL) {
        printf("Erreur d'allocation mémoire.\n");
        return 1;
    }

    // Initialisation du tableau avec des valeurs aléatoires
    for (i = 0; i < SIZE; i++) {
        array[i] = rand() % 100;
    }

    // Somme séquentielle répétée
    start = omp_get_wtime();
    for (j = 0; j < REPEAT; j++) {
        sum_seq = 0;  // Réinitialiser la somme à chaque répétition
        for (i = 0; i < SIZE; i++) {
            sum_seq += array[i];
        }
    }
    end = omp_get_wtime();
    printf("Somme séquentielle: %lld\n", sum_seq);
    printf("Temps séquentiel: %f secondes\n", end - start);

    // Somme parallèle avec OpenMP répétée
    start = omp_get_wtime();
    for (j = 0; j < REPEAT; j++) {
        sum_par = 0;  // Réinitialiser la somme à chaque répétition
        #pragma omp parallel for reduction(+:sum_par)
        for (i = 0; i < SIZE; i++) {
            sum_par += array[i];
        }
    }
    end = omp_get_wtime();
    printf("Somme parallèle: %lld\n", sum_par);
    printf("Temps parallèle: %f secondes\n", end - start);

    // Libérer la mémoire
    free(array);

    return 0;
}


6
