#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tache_max 50

typedef struct
{
    int d, m, y;
} date;

typedef struct
{
    int identifiant;
    char titre[50];
    char description[50];
    char statut[50];
    date Date;
} tache;

int nombre_tache = 0;
tache liste_des_taches[tache_max];
int taches_completes = 0;
int taches_incompletes = 0;

void ajoute_une_tache()
{
    tache task;
    int statu, n, i;
    if (nombre_tache >= tache_max)
    {
        printf("La liste des taches est remplie.\n");
        return;
    }
    printf("Combien de taches voulez-vous entrer : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Entrez le titre de la tache:\n");
    scanf(" %[^\n]",liste_des_taches[i].titre);
    
        printf("Entrez la description de la tache:\n");
        scanf(" %[^\n]", liste_des_taches[i].description);

        do { printf("Entrez la date de la tache (dd mm years):\n");
        scanf("%d %d %d", &liste_des_taches[i].Date.d, &liste_des_taches[i].Date.m, &liste_des_taches[i].Date.y);
        } while ( liste_des_taches[i].Date.d < 1 || liste_des_taches[i].Date.d > 31 || liste_des_taches[i].Date.m < 1 || liste_des_taches[i].Date.m > 31 || liste_des_taches[i].Date.y < 2023);
        
        }
        

        do
        {
            printf("1 pour_faire, 2 en_train_a_faire, 3 finalise\n ");
            scanf(" %d", &statu);

            if (statu < 1 || statu > 3)
                printf("Option invalide, veuillez entrer un nombre valide\n");
            else
            {
                switch (statu)
                {
                case 1:
                    strcpy(liste_des_taches[nombre_tache].statut, "pour_faire");
                    break;
                case 2:
                    strcpy(liste_des_taches[nombre_tache].statut, "en_train_a_faire");
                    break;
                case 3:
                    strcpy(liste_des_taches[nombre_tache].statut, "finalise");
                    break;
                }
            }
        } while (statu < 1 || statu > 3);

        liste_des_taches[nombre_tache].identifiant = nombre_tache + 1;

        if (strcmp(liste_des_taches[nombre_tache].statut, "finalise") == 0)
        {
            taches_completes++;
        }
        else
        {
            taches_incompletes++;
        }

        nombre_tache++;
        printf("La tache a ete ajoutee avec succes.\n");
}
    
void afficher_les_taches()
{
    if (nombre_tache == 0)
    {
        printf("Aucune tache trouvee.\n");
        return;
    }

    printf("\nListe de toutes les taches:\n");
    for (int i = 0; i < nombre_tache; i++)
    {
        tache Tache = liste_des_taches[i];
        printf("Tache ID: %d\n", Tache.identifiant);
        printf("Tache titre: %s\n", Tache.titre);
        printf("Tache description: %s\n", Tache.description);
        printf("Tache Date: %d/%d/%d\n", Tache.Date.d, Tache.Date.m, Tache.Date.y);
        printf("Tache statut: %s\n", Tache.statut);
    }
}

void trier_alphabetique()
{
    int i, j;
    tache t;
    for (i = 0; i < nombre_tache; i++)
    {
        for (j = i + 1; j < nombre_tache; j++)
        {
            if (strcmp(liste_des_taches[i].titre, liste_des_taches[j].titre) > 0)
            {
                t = liste_des_taches[i];
                liste_des_taches[i] = liste_des_taches[j];
                liste_des_taches[j] = t;
            }
        }
    }
}

void editer_une_tache()
{
    int identifiant_a_editer;
    char nv_description[50];
    char nv_statut[50];
    int nv_d, nv_m, nv_y;

    printf("Entrez l'identifiant de la tache à éditer: ");
    scanf("%d", &identifiant_a_editer);

    if (identifiant_a_editer >= 1 && identifiant_a_editer <= nombre_tache)
    {
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

        // Mettre à jour les statistiques en fonction du nouveau statut
        if (strcmp(nv_statut, "finalise") == 0)
        {
            taches_completes++;
            taches_incompletes--;
        }
        else if (strcmp(liste_des_taches[identifiant_a_editer - 1].statut, "finalise") == 0)
        {
            taches_incompletes++;
            taches_completes--;
        }
    }
    else
    {
        printf("La tache n'existe pas pour être éditée.\n");
    }
}

void supprimer_une_tache()
{
    int ID_a_supprimer;
    printf("Entrez l'identifiant de la tache à supprimer: ");
    scanf("%d", &ID_a_supprimer);

    if (ID_a_supprimer >= 1 && ID_a_supprimer <= nombre_tache)
    {
        for (int i = ID_a_supprimer - 1; i < nombre_tache - 1; i++)
        {
            liste_des_taches[i] = liste_des_taches[i + 1];
        }
        nombre_tache--;

        // Mettre à jour les statistiques en fonction du statut supprimé
        if (strcmp(liste_des_taches[ID_a_supprimer - 1].statut, "finalise") == 0)
        {
            taches_completes--;
        }
        else
        {
            taches_incompletes--;
        }

        printf("La tache d'ID %d a été supprimée avec succès.\n", ID_a_supprimer);
    }
    else
    {
        printf("La tache à supprimer n'existe pas.\n");
    }
}

int rechercher_ID(int idt)
{
    for (int i = 0; i < nombre_tache; i++)
    {
        if (liste_des_taches[i].identifiant == idt)
        {
            return i;
        }
    }
    return -1;
}

void afficher_statistiques_taches()
{
    printf("Nombre total de taches : %d\n", nombre_tache);
    printf("Nombre de taches completes : %d\n", taches_completes);
    printf("Nombre de taches incompletes : %d\n", taches_incompletes);
}

int main()
{
    int choix;

    do
    {
        printf("\n***** Menu principal *****\n");
        printf("1 - Ajouter une nouvelle tache\n");
        printf("2 - Afficher les taches\n");
        printf("3 - Trier par ordre alphabetique\n");
        printf("4 - Editer une tache\n");
        printf("5 - Supprimer une tache\n");
        printf("6 - Rechercher par identifiant\n");
        printf("7 - Afficher les statistiques des taches\n");
        printf("8 - Quitter\n");
        printf("Choisissez une option : ");

        scanf("%d", &choix);

        switch (choix)
        {
        case 1:
            ajoute_une_tache();
            break;
        case 2:
            afficher_les_taches();
            break;
        case 3:
            trier_alphabetique();
            break;
        case 4:
            editer_une_tache();
            break;
        case 5:
            supprimer_une_tache();
            break;
        case 6:
        {
            int idt;
            printf("Entrez l'identifiant à rechercher : ");
            scanf("%d", &idt);
            int index = rechercher_ID(idt);
            if (index != -1)
            {
                printf("La tache d'identifiant %d se trouve à la position %d.\n", idt, index);
            }
            else
            {
                printf("Tache non trouvée.\n");
            }
            break;
        }
        case 7:
            afficher_statistiques_taches();
            break;
        case 8:
            exit(0);
        default:
            printf("Option invalide. Veuillez réessayer.\n");
        }
    } while (choix != 8);

    return 0;
}
