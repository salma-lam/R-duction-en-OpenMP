#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>  // Pour srand(time(NULL))

int main() {
    int i, n = 10000;
    double max_value = 0.0;  // Initialisation pour le maximum
    double min_value = 10.0; // Initialisation pour le minimum
    double *array = (double*) malloc(n * sizeof(double));

    // Initialisation du tableau avec des valeurs aléatoires
    srand(time(NULL));  // Ajout d'une graine pour la génération de nombres aléatoires
    for (i = 0; i < n; i++)
        array[i] = (rand() % 10) + 1;  // On évite les 0

    double start_time = omp_get_wtime();

    // Parallélisation pour le calcul du maximum et du minimum
    #pragma omp parallel
    {
        double temp_max = 0.0;       // Maximum temporaire pour chaque thread
        double temp_min = 10.0;      // Minimum temporaire pour chaque thread
        
        #pragma omp for
        for (i = 0; i < n; i++) {
            // Calculer le maximum et le minimum pour chaque élément
            if (array[i] > temp_max) {
                temp_max = array[i];
            }
            if (array[i] < temp_min) {
                temp_min = array[i];
            }
        }

        // Réduction des max et min
        #pragma omp critical
        {
            if (temp_max > max_value) {
                max_value = temp_max;
            }
            if (temp_min < min_value) {
                min_value = temp_min;
            }
        }
    }

    double end_time = omp_get_wtime();

    printf("Le maximum des éléments est : %f\n", max_value);
    printf("Le minimum des éléments est : %f\n", min_value);
    printf("Temps d'exécution : %f secondes\n", end_time - start_time);

    free(array);
    return 0;
}
