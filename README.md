Réduction en OpenMP

## Objectif
Cet exemple a pour but d'explorer l'utilisation des réductions en OpenMP pour différentes opérations telles que la somme, le produit, le maximum et le minimum. On va mésurer également l'efficacité de la parallélisation avec OpenMP pour ces opérations.

## Codes
Les codes sont organisés comme suit :

### Code 1 : Somme parallèle avec OpenMP
Ce code initialise un tableau d'entiers avec des valeurs aléatoires et utilise OpenMP pour calculer la somme des éléments en parallèle. Le calcul est parallélisé à l'aide de la clause `#pragma omp parallel for reduction(+:somme_parallele)`. Une comparaison des temps d'exécution entre la version séquentielle et parallèle sera effectuée.

### Code 2 : Produit parallèle avec OpenMP
Ce code modifie le programme pour calculer le produit des éléments du tableau. Le calcul est parallélisé à l'aide de la clause `#pragma omp parallel for reduction(*:produit_parallele)`.

### Code 3 : Maximum et Minimum parallèle
Ce code ajoute des boucles parallèles pour calculer le maximum et le minimum des éléments du tableau.

### Code 4 : Optimisation et discussion
Ce code modifie la taille du tableau et augmente le nombre de threads OpenMP pour observer l'impact sur les performances.

## Conclusion
La réduction en OpenMP s'avère être un outil puissant pour paralléliser efficacement des opérations qui accumulent des résultats à travers des boucles. 

## Prérequis
Avant de commencer, assurez-vous d'avoir installé un compilateur prenant en charge OpenMP et d'avoir configuré votre environnement de développement.

## Exécution
Pour exécuter ces codes, vous devez travailler avec MSYS2 MINGW64. Voici les étapes à suivre :

1. Ouvrez le terminal MSYS2 MINGW64.
2. Naviguez jusqu'au répertoire contenant votre fichier source `Code.c`.
3. Compilez le code avec la commande suivante :

   ```bash
   gcc -fopenmp -o Code Code.c
   ./Code

