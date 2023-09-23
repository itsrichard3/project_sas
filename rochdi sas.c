#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tache_max 50

typedef struct {
    int d, m, y;
} date;

typedef struct {
    int identifiant;
    char titre[50];
    char description[50];
    char statut[50];
    date Date;
} tache;

int nombre_tache = 0;
tache liste_des_taches[tache_max];

void ajoute_une_tache() {
    tache task;
    int statu;
    if (nombre_tache >= tache_max) {
        printf("La liste des taches est remplie.\n");
        return;
    }

    printf("Entrez le titre de la tache:\n");
    scanf(" %[^\n]", liste_des_taches[nombre_tache].titre);

    printf("Entrez la description de la tache:\n");
    scanf(" %[^\n]", liste_des_taches[nombre_tache].description);

    printf("Entrez la date de la tache (dd mm years):\n");
    scanf("%d %d %d", &liste_des_taches[nombre_tache].Date.d, &liste_des_taches[nombre_tache].Date.m, &liste_des_taches[nombre_tache].Date.y);
    

    do{
    printf("1 pour_faire ,2 entrien_a_faire,3 finalise \n ");
    scanf(" %d",&statu );

    if(statu<1 || statu>3  ) printf ("option invalide,veuillez entre un nombre \n");
    else{

        switch (statu){

case 1:
strcpy(task.statut,"pour_faire");
break;
case 2:
strcpy(task.statut,"entrien_a_faire");
break;
case 3:
strcpy(task.statut,"finalise");
break;
        }

    }

    } while (statu<1 || statu>3);

    liste_des_taches[nombre_tache].identifiant = nombre_tache + 1;
    
    nombre_tache++;

    printf("La tache a ete ajoutee avec succes.\n");
    
}

void ajout_Plus(int n) {
    int i;
    for (i = 0; i < n; i++)
        ajoute_une_tache();
}

void afficher_les_taches() {
    if (nombre_tache == 0) {
        printf("Aucune tache trouvée.\n");
        return;
    }

    printf("\nListe de toutes les taches:\n");
    for (int i = 0; i < nombre_tache; i++) {
        tache Tache = liste_des_taches[i];
        printf("Tache ID: %d\n", Tache.identifiant);
        printf("Tache titre: %s\n", Tache.titre);
        printf("Tache description: %s\n", Tache.description);
        printf("Tache Date: %d/%d/%d\n", Tache.Date.d, Tache.Date.m, Tache.Date.y);
        printf("Tache statut: %s\n", Tache.statut);
    }
}

void trier_alphabetique() {
    int i, j;
    tache t;
    for (i = 0; i < nombre_tache; i++) {
        for (j = i + 1; j < nombre_tache; j++) {
            if (strcmp(liste_des_taches[i].titre, liste_des_taches[j].titre) > 0) {
                t = liste_des_taches[i];
                liste_des_taches[i] = liste_des_taches[j];
                liste_des_taches[j] = t;
            }
        }
    }
}

void editer_une_tache() {
    int identifiant_a_editer;
    char nv_description[50];
    char nv_statut[50];
    int nv_d, nv_m, nv_y;

    printf("Entrez l'identifiant de la tache à éditer: ");
    scanf("%d", &identifiant_a_editer);

    if (identifiant_a_editer >= 1 && identifiant_a_editer <= nombre_tache) {
        printf("Entrez une nouvelle description de la tache d'identifiant %d :\n", liste_des_taches[identifiant_a_editer - 1].identifiant);
        scanf(" %[^\n]", nv_description);

        printf("Entrez un nouveau statut de la tache d'identifiant %d :\n", liste_des_taches[identifiant_a_editer - 1].identifiant);
        scanf(" %[^\n]", nv_statut);

        printf("Entrez la nouvelle date de la tache d'identifiant %d (jj mm aaaa):\n", liste_des_taches[identifiant_a_editer - 1].identifiant);
        scanf("%d %d %d", &nv_d, &nv_m, &nv_y);

        strcpy(liste_des_taches[identifiant_a_editer - 1].description, nv_description);
        strcpy(liste_des_taches[identifiant_a_editer - 1].statut, nv_statut);
        liste_des_taches[identifiant_a_editer - 1].Date.d = nv_d;
        liste_des_taches[identifiant_a_editer - 1].Date.m = nv_m;
        liste_des_taches[identifiant_a_editer - 1].Date.y = nv_y;

        printf("La tache d'identifiant %d a été éditée avec succès.\n", identifiant_a_editer);
    } else {
        printf("La tache n'existe pas pour être éditée.\n");
    }
}

void supprimer_une_tache() {
    int ID_a_supprimer;
    printf("Entrez l'identifiant de la tache à supprimer: ");
    scanf("%d", &ID_a_supprimer);

    if (ID_a_supprimer >= 1 && ID_a_supprimer <= nombre_tache) {
        for (int i = ID_a_supprimer - 1; i < nombre_tache - 1; i++) {
            liste_des_taches[i] = liste_des_taches[i + 1];
        }
        nombre_tache--;
        printf("La tache d'ID %d a été supprimée avec succès.\n", ID_a_supprimer);
    } else {
        printf("La tache à supprimer n'existe pas.\n");
    }
}

int rechercher_ID(int idt) {
    for (int i = 0; i < nombre_tache; i++) {
        if (liste_des_taches[i].identifiant == idt) {
            return i;
        }
    }
    return -1;
}

int main() {
    int choix;

    do {
        printf("\n***** Menu principal *****\n");
        printf("1 - Ajouter une nouvelle tache\n");
        printf("2 - Ajouter plusieurs taches\n");
        printf("3 - Afficher les taches\n");
        printf("4 - Trier par ordre alphabétique\n");
        printf("5 - Editer une tache\n");
        printf("6 - Supprimer une tache\n");
        printf("7 - Rechercher par identifiant\n");
        printf("8 - Quitter\n");
        printf("Choisissez une option : ");

        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajoute_une_tache();
                break;
            case 2:
                ajout_Plus(2);
                break;
            case 3:
                afficher_les_taches();
                break;
            case 4:
                trier_alphabetique();
                break;
            case 5:
                editer_une_tache();
                break;
            case 6:
                supprimer_une_tache();
                break;
            case 7: {
                int idt;
                printf("Entrez l'identifiant à rechercher : ");
                scanf("%d", &idt);
                int index = rechercher_ID(idt);
                if (index != -1) {
                    printf("La tache d'identifiant %d se trouve à la position %d.\n", idt, index);
                } else {
                    printf("Tache non trouvée.\n");
                }
                break;
            }
            case 8:
                exit(0);
            default:
                printf("Option invalide. Veuillez réessayer.\n");
        }
    } while (choix != 8);

    return 0;
}

