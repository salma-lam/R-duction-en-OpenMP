#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>  

#define TAILLE 10000

int main() {
    int tableau[TAILLE];
    int i;
    long long somme_sequentielle = 0;
    long long somme_parallele = 0;
    
    // Initialisation du tableau avec des valeurs aléatoires
    srand(time(NULL));  // Génération de nombres aléatoires en fonction de l'horloge système
    for (i = 0; i < TAILLE; i++) {
        tableau[i] = rand() % 100;  // Valeurs entre 0 et 99
    }

    // Version séquentielle
    double debut_seq = omp_get_wtime();
    for (i = 0; i < TAILLE; i++) {
        somme_sequentielle += tableau[i];
    }
    double fin_seq = omp_get_wtime();

    // Affichage de la somme séquentielle et du temps
    printf("Somme séquentielle : %lld\n", somme_sequentielle);
    printf("Temps d'exécution séquentiel : %f secondes\n", fin_seq - debut_seq);

    // Version parallèle avec OpenMP
    double debut_par = omp_get_wtime();
    #pragma omp parallel for reduction(+:somme_parallele)
    for (i = 0; i < TAILLE; i++) {
        somme_parallele += tableau[i];
    }
    double fin_par = omp_get_wtime();

    // Affichage de la somme parallèle et du temps
    printf("Somme parallèle : %lld\n", somme_parallele);
    printf("Temps d'exécution parallèle : %f secondes\n", fin_par - debut_par);

    return 0;
}

