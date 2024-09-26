#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main() {
    int i;
    int n = 100000; // Modifiez cette valeur pour tester différentes tailles de tableau
    double max_value = 0.0, min_value = 11.0; // Initiaux pour la recherche de max/min
    double *array = (double*) malloc(n * sizeof(double));

    // Initialisation du tableau avec des valeurs aléatoires
    for (i = 0; i < n; i++)
        array[i] = (rand() % 10) + 1;  // Éviter les 0

    omp_set_num_threads(4); // Ajustez le nombre de threads ici

    double start_time = omp_get_wtime();

    // Calcul du maximum
    #pragma omp parallel for reduction(max:max_value)
    for (i = 0; i < n; i++) {
        if (array[i] > max_value) {
            max_value = array[i];
        }
    }

    // Calcul du minimum
    #pragma omp parallel for reduction(min:min_value)
    for (i = 0; i < n; i++) {
        if (array[i] < min_value) {
            min_value = array[i];
        }
    }

    double end_time = omp_get_wtime();

    printf("Le maximum des éléments est : %f\n", max_value);
    printf("Le minimum des éléments est : %f\n", min_value);
    printf("Temps d'exécution : %f secondes\n", end_time - start_time);

    free(array);
    return 0;
}
