#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Déclaration des fonctions
void Menu();

void Jeu();

void ReglesDuJeu();

// Déclaration des variables globals
int score = 0;
int record = -1;
char meilleurJoueur[50];


// Fonction d'affichage du menu
void Menu() {
    printf("1: Jouer au jeu\n");
    printf("2: Regles du jeu\n");
    printf("3: Quitter\n");
    printf("Votre choix: ");
}

// Fonction pour sauvegarder le highscore dans le fichier
void SauvegarderRecord() {
    FILE *fichier;
    fichier = fopen("record.txt", "w");
    fprintf(fichier, "le record est de %d tentative et est detenu par %s\n", record, meilleurJoueur);
    fclose(fichier);
}

// Fonction du jeu
void Jeu() {
    char nom[50];

    printf("Entrez votre nom ou prenom: ");
    scanf("%49s", nom);
    printf("Bienvenue, %s ! Vous avez deja gagne %d fois.\n", nom, score);

    if (record > 0) {
        printf("le record actuel est de %d, detenu par %s.\n", record, meilleurJoueur);
    }
    printf("Un nombre entre 1 et 100 va etre genere aleatoirement, a toi de le deviner ^-^\n");


    int nbrsecret = 0;
    int tentatives = -1;
    int nbrtentatives = 0;

    // Génère un nombre aléatoire entre 1 et 100
    srand(time(NULL));
    nbrsecret = rand() % 100 + 1;


    // Boucle du jeu
    while (tentatives != nbrsecret) {
        printf("Entrez votre chiffre : ");
        scanf("%d", &tentatives);
        nbrtentatives++;

        if (tentatives < nbrsecret) {
            printf("le chiffre entre est trop petit\n");
        } else if (tentatives > nbrsecret) {
            printf("le chiffre entre est trop grand\n");
        } else {
            printf("bien joue %s, vous avez trouve en %d essais la reponse !\n", nom, nbrtentatives);
            score++;
            if (record == -1 || nbrtentatives < record) {
                // Je n'ai pas bien compris le bonus 1 mais j'ai fait en sorte que ça sauvegarde le nombre de tentative en tant que record pas le nombre de point obtenue
                printf("Bravo ! Tu a battu le record de tentatives\n");
                record = nbrtentatives;
                printf("Entrez votre Nom ou prenom pour le nouveau record:");
                scanf("%s", meilleurJoueur);
                SauvegarderRecord();
            }
        }
    }
}

// Fonction des règles du jeu
void ReglesDuJeu() {
    printf(
        "Un nombre aleatoire est genere entre 1 et 100. Votre objectif est de le deviner en recevant des indices apres chaque tentative. Bonne chance !\n");
}

// Fonction principale
int main() {
    int choix = 0;

    while (choix != 3) {
        Menu();
        scanf("%d", &choix);
        switch (choix) {
            case 1:
                Jeu();
                break;
            case 2:
                ReglesDuJeu();
                break;
            case 3:
                printf("Merci d'avoir joue.\n");
                break;
            default:
                printf("Veuillez choisir une option valable (1, 2 ou 3)\n");
        }
    }

    return 0;
}
