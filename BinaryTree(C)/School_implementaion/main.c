#include "arbre.h"
#include "liste.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *afficher_chaine(void *objet)
{
    return (char *)objet;
}

int comparer_chaine(void *objet1, void *objet2)
{
    return strcmp(((char *)objet1), ((char *)objet2));
}

Arbre *ArbreGene(char *(*afficher)(void *), int (*comparer)(void *, void *))
{
    Noeud *root = cNd("Samir", cNd("Kamal", cNd("Yassine", NULL, cNd("Hind", NULL, cF("Yasmine"))), cNd("Sarah", cF("Karim"), NULL)), NULL);
    return creerArbre(root, afficher, comparer);
}

Arbre *ArbreArtithmetique(char *(*afficher)(void *), int (*comparer)(void *, void *))
{
    Noeud *racine = cNd("-", cNd("*", cNd("+", cF("a"), cF("b")), cNd("-", cF("c"), cF("d"))), cF("e"));
    return creerArbre(racine, afficher, comparer);
}

int menuArbre()
{
    printf("\n \n Gestion D'arbres \n \n ");
    printf("\n \n Arbres Binaires \n \n");
    printf("0 - Fin du Programme\n");
    printf("1- Creation de l'arbre Genealogique \n");
    printf("2- Creation de l'arbre de l'expression arithmetique \n");
    printf("3- Parcours Prefixe \n");
    printf("4- Parcours Infixe \n");
    printf("5- Parcours Postifxe \n");
    printf("6- Trouver Noeud \n");
    printf("7- Taille \n");
    printf("8- Hauter \n");
    printf("9- Parcours en Largeur \n");
    printf("\n");
    printf("Votre choix ?");
    int cod;
    scanf("%d", &cod);
    getchar();
    printf("\n");
    return cod;
}

int main(int argc, char *argv[])
{
    // la structure de ce fonction et similaire aux structure des
    // programmes precedents
    int a;
    // initialisation d'un pointer sur sturcture arbre vers NULL
    // durant tout ce programme on va verfier si la variable A n'est pas NULL
    Arbre *A = NULL;
    do
    {
        // appel de la fonction du menu pour la premiére fois
        a = menuArbre();
        switch (a)
        {
        case 1:
            // si A est NULL, on peut creé un nouvel arbre genealogique
            if (!A)
                A = ArbreGene(afficher_chaine, comparer_chaine);
            // si A n'est pas NULL, cela siginifie que l'arbre a été déjà creéé
            else
                printf("Arbre deja cree");
            break;
        case 2:
            // si A est NULL, on peut creé un nouvel arbre genealogique
            if (!A)
                A = ArbreArtithmetique(afficher_chaine, comparer_chaine);
            // si A n'est pas NULL, cela siginifie que l'arbre a été déjà creéé
            else
                printf("Arbre deja cree");
            break;
        case 3:
            // parcours infixe de l'arbre
            if (A)
            {
                printf("parcours prefixe:\n");
                Postfixe(A->racine, A->afficher);
            }
            else
                printf("Vous devez creer un arbre\n");
            break;
        case 4:
            if (A)
            {
                printf("parcours infixe:\n");
                Infixe(A->racine, A->afficher);
            }
            else
            {
                printf("Vous devez creer un arbre\n");
            }
            break;
        case 5:
            if (A)
            {
                printf("parcours postfixe:\n");
                Postfixe(A->racine, A->afficher);
            }
            else
                printf("Vous devez creer un arbre\n");
            break;
        case 6:
            char *t = (char *)malloc(sizeof(char) * 15);
            scanf("%14s", t);
            if (trouverNoeud(A->racine, t, comparer_chaine))
                printf("element: %s trouvee\n", t);
            else
                printf("l'element n'existe pas dans la liste\n");
            free(t);
            break;
        case 7:
            if (A)
                printf("la taille de l'arbre est :%d\n", Taille(A->racine));
            else
                printf("Vous devez creer un arbre");
            break;
        case 8:
            if (A)
                printf("La hauteur de l'arbre est: %d", Hauteur(A->racine));
            else
                printf("VOuse devez creer un arbre");
            break;
        case 9:
            if (A)
            {
                printf("Parcours en largeur:\n");
                parcoursLargeur(A->racine, A->afficher);
            }
            else
                printf("Vous devez creer un arbre");
            break;
        case 0:
            if (A)
            {
                detruireArbre(A->racine);
                free(A);
            }
            break;
        default:
            printf("entrer un nombre valide\n");
            break;
        }
    } while (a != 0);
    return 0;
}
