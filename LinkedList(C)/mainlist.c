#include "liste.h"

int menu_entier()
{
    printf("\n\nGESTION DE LISTE D'ENTIERS\n\n");
    printf("1-Creer une liste\n");
    printf("2-Insertion en tete de liste\n");
    printf("3-Insertion en fin de la liste\n");
    printf("4-Retrait en tete de la liste\n");
    printf("5-Retrait en fin de la liste\n");
    printf("6-Retrait d'un objet a partir de sa reference\n");
    printf("7-Afficher les objet de la liste\n");
    printf("8-Chercher un objet\n");
    printf("9-Destruction de la liste\n");
    printf("10-Fin\n");
    printf("Votre choix?:\n");
    int cod;
    scanf("%d", &cod);
    printf("\n");
    return cod;
}

// affichage des fonction
char* afficher_entier(void* objet)
{
    char* buffer = (char*)malloc(sizeof(int) * 8 + 1);
    // cette fonction de la bibliothèque standard de C convertit
    // un entier en chaine de caractères, elle prend comme
    // parametre l'entier, un tableau de caractères ou
    // la fonction stock les données issus de la conversion
    // le dernier parametre est la base
    itoa(*(int*)objet, buffer, 10);
    return buffer;
}

// fonction qui compare deux entiers
// si il sont égaux retourne 0
int comparer_entier(void* objet1, void* objet2)
{
    if (*(int*)objet1 == *(int*)objet2)
        return 0;
    else if (*(int*)objet1 > *(int*)objet2)
        return 1;
    else
        return -1;
}

int main(int argc, char** argv)
{
    // declaration des varibles
    int k, temp, * add;
    Objet* objet;
    Liste* l = NULL;
    do
    {
        // on doit verfier si la liste existe sinon
        // le reste du programme ne s'executera pas,
        // tant que la liste n'est pas creer
        k = menu_entier();
        // cette boucle se répéte tant que
        // la liste n'est pas creé
        while (k != 1 && !l)
        {
            // si le choix est 10 on quitte le programme
            // principale
            if (k == 10)
                return 0;
            printf("vous devez creer un liste");
            k = menu_entier();
        }
        switch (k)
        {
        case 1:
            if (l)
                printf("la liste deja cree.\n");
            else
                l = creerListe(0, afficher_entier, comparer_entier);
            break;
        case 2:
            // allocation de la mémoire pour l'entier qu'on souhaite
            // inserer,puis on stock son adresse dans le premier élément
            printf("entrer un entier:");
            add = (int*)malloc(sizeof(int));
            scanf("%d", add);
            insererEnTeteDeListe(l, add);
            printf("\nle premier element de la liste est: %d\n", *(int*)l->premier->reference);
            break;
        case 3:
            // allocation de la mémoire pour l'entier qu'on souhaite
            // inserer,puis on stock son adresse dans le dernier élément
            printf("entrer un entier:");
            add = (int*)malloc(sizeof(int));
            scanf("%d", add);
            insererEnFinDeListe(l, add);
            printf("\nle dernier element de la liste est: %d\n", *(int*)l->dernier->reference);
            break;
        case 4:
            // extraction du premier objet de la liste
            objet = extraireEnTeteDeListe(l);
            // si l'objet n'est pas NULL la fonction
            // affiche le message ci-dessous et libère
            // mémoire
            if (objet)
            {
                printf("objet retrait");
                free(objet);
            }
            // dans le cas contraire
            else
                printf("retrait impossible, la liste est vide");
            break;
        case 5:
            // extraction du dernier objet de la liste
            objet = extraireEnFinDeListe(l);
            // si l'objet n'est pas NULL la fonction
            // affiche le message ci-dessous et libère
            // mémoire
            if (objet)
            {
                printf("objet retrait");
                free(objet);
            }
            // si l'objet est NULL, ceci signifie
            // que l'objet rechercher n'existe pas dans la liste
            else
                printf("retrait impossible, la liste est vide");
            break;
        case 6:
            // demande a l'utilisateur d'entre un entier
            // a chercher
            printf("entrer un entier a supprimer:");
            scanf("%d", &temp);
            add = &temp;
            // on utilise la fonction chercher qui retourne
            //  l'adresse de l'objet s'il existe ,puis on passe
            // cette adresse comme parametre pour la fonction
            // extraireUnObjet() pour extraire l'objet
            if (extraireUnObjet(l, chercherUnObjet(l, (void*)add)))
                printf("Objet extrait");
            // si les deux fonction retourne NULL, cela signifie
            // l'objet recherché n'existe pas dans la liste
            else
                printf("l'objet ne figure pas dans la liste");
            break;
        case 7:
            listerListe(l);
            break;
        case 8:
            // rechreche d'un entier
            // on demande de l'utilisateur d'entre un entier
            printf("entrer un entier a chercher:");
            scanf("%d", &temp);
            add = &temp;
            // la fonction chercherUnObjet() retourne NULL si
            // l'objet n'est pas dans la liste sinon elle retourne son adresse
            objet = chercherUnObjet(l, (void*)add);
            // si l'objet est trouve on informe l'utilisateur que l'entier
            // existe dans la liste, sinon un message informant que l'objet n'est
            // pas dans la liste sera afficher
            printf((objet) ? "objet trouve" : "l'objet ne figure pas dans la liste");
            break;
        case 9:
            // destruction de la liste
            // et reinitialisation de cette dernière
            detruireListe(l);
            printf("Liste detruite");
            break;
        case 10:
            // condition mettant fin a l'exection de la boucle
            printf("Fin\n");
            // destruction de la liste
            detruireListe(l);
            // libertation de la mémoire prise par la liste
            free(l);
            break;
        default:
            printf("entrer un nombre entre 2-10");
            break;
        }
    } while (k != 10);
    return 0;
}