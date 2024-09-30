#include <stdio.h>
#include <string.h>

// Définition de la structure Contact
struct Contact {
    char nom[50];
    char telephone[20];
    char email[50];
    int i;
};

// Variables globales
struct Contact contacts[100];  // Tableau pour stocker les contacts
int nombre_contacts = 0;  // Nombre actuel de contacts

// Fonction pour ajouter un contact
void ajouter_contact() {
    printf("Entrez le nom: ");
    scanf("%s", contacts[nombre_contacts].nom);
    printf("Entrez le numero de telephone: ");
    scanf("%s", contacts[nombre_contacts].telephone);
    printf("Entrez l'adresse e-mail: ");
    scanf("%s", contacts[nombre_contacts].email);
    nombre_contacts++;
    printf("Contact ajoute avec succes !\n");
}

// Fonction pour afficher tous les contacts
void afficher_contacts() {
    if (nombre_contacts == 0) {
        printf("Aucun contact a afficher.\n");
    } else {
        for ( i = 0; i < nombre_contacts; i++) {
            printf("Nom: %s\n", contacts[i].nom);
            printf("Telephone: %s\n", contacts[i].telephone);
            printf("E-mail: %s\n", contacts[i].email);
            printf("----------------------\n");
        }
    }
}

// Fonction pour rechercher un contact par nom
void rechercher_contact() {
    char nom_recherche[50];
    printf("Entrez le nom a rechercher: ");
    scanf("%s", nom_recherche);
    for (int i = 0; i < nombre_contacts; i++) {
        if (strcmp(contacts[i].nom, nom_recherche) == 0) {
            printf("Nom: %s\n", contacts[i].nom);
            printf("Telephone: %s\n", contacts[i].telephone);
            printf("E-mail: %s\n", contacts[i].email);
            return;
        }
    }
    printf("Contact non trouvé.\n");
}

// Fonction pour modifier un contact
void modifier_contact() {
    char nom_recherche[50];
    printf("Entrez le nom du contact a modifier: ");
    scanf("%s", nom_recherche);
    for (int i = 0; i < nombre_contacts; i++) {
        if (strcmp(contacts[i].nom, nom_recherche) == 0) {
            printf("Entrez le nouveau numero de telephone: ");
            scanf("%s", contacts[i].telephone);
            printf("Entrez la nouvelle adresse e-mail: ");
            scanf("%s", contacts[i].email);
            printf("Contact modifie avec succes !\n");
            return;
        }
    }
    printf("Contact non trouve.\n");
}

// Fonction pour supprimer un contact
void supprimer_contact() {
    char nom_recherche[50];
    printf("Entrez le nom du contact a supprimer: ");
    scanf("%s", nom_recherche);
    for (int i = 0; i < nombre_contacts; i++) {
        if (strcmp(contacts[i].nom, nom_recherche) == 0) {
            for (int j = i; j < nombre_contacts - 1; j++) {
                contacts[j] = contacts[j + 1];  // Decaler les contacts restants
            }
            nombre_contacts--;
            printf("Contact supprime avec succes !\n");
            return;
        }
    }
    printf("Contact non trouve.\n");
}

// Fonction principale
int main() {
    int choix;
    do {
        printf("\nSysteme de Gestion de Contacts\n");
        printf("1. Ajouter un contact\n");
        printf("2. Afficher tous les contacts\n");
        printf("3. Rechercher un contact\n");
        printf("4. Modifier un contact\n");
        printf("5. Supprimer un contact\n");
        printf("6. Quitter\n");
        printf("Entrez votre choix: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouter_contact();
                break;
            case 2:
                afficher_contacts();
                break;
            case 3:
                rechercher_contact();
                break;
            case 4:
                modifier_contact();
                break;
            case 5:
                supprimer_contact();
                break;
            case 6:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide. Veuillez reessayer.\n");
        }
    } while (choix != 6);

    return 0;
}