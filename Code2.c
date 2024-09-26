#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>  

#define TAILLE 10  // Pour un tableau de taille 10

int main() {
    int tableau[TAILLE];
    int i;
    long long produit_sequentiel = 1; // Initialisé à 1 pour le produit
    long long produit_parallele = 1;   // Initialisé à 1 pour le produit
    
    // Initialisation du tableau avec des valeurs aléatoires
    srand(time(NULL));  // Génération de nombres aléatoires en fonction de l'horloge système
    for (i = 0; i < TAILLE; i++) {
        tableau[i] = (rand() % 10) + 1;  // Valeurs entre 1 et 10 pour éviter les zéros
    }

    // Affichage des valeurs du tableau
    printf("Exemples de valeurs dans le tableau : ");
    for (i = 0; i < TAILLE; i++) {
        printf("%d ", tableau[i]);
    }
    printf("\n");

    // Version séquentielle
    double debut_seq = omp_get_wtime();
    for (i = 0; i < TAILLE; i++) {
        produit_sequentiel *= tableau[i];
    }
    double fin_seq = omp_get_wtime();

    // Affichage du produit séquentiel et du temps
    printf("Produit séquentiel : %lld\n", produit_sequentiel);
    printf("Temps d'exécution séquentiel : %f secondes\n", fin_seq - debut_seq);

    // Version parallèle avec OpenMP
    double debut_par = omp_get_wtime();
    #pragma omp parallel for reduction(*:produit_parallele)
    for (i = 0; i < TAILLE; i++) {
        produit_parallele *= tableau[i];
    }
    double fin_par = omp_get_wtime();

    // Affichage du produit parallèle et du temps
    printf("Produit parallèle : %lld\n", produit_parallele);
    printf("Temps d'exécution parallèle : %f secondes\n", fin_par - debut_par);

    return 0;
}
