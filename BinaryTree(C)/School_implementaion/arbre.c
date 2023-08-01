#include "arbre.h"
#include "liste.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// definition de la fonction maximum
#define max(a, b) (((a) > (b)) ? (a) : (b))

// fonction de creation d'un nouveau noeud
Noeud *cNd(void *objet, Noeud *gauche, Noeud *droite)
{
    // allocation de la mémoire pour un nouveau neoud
    Noeud *nouveau = (Noeud *)malloc(sizeof(Noeud));
    // copie des adresse du noeuds droit et gauche
    nouveau->droite = droite;
    nouveau->gauche = gauche;
    // copie de l'adresse de l'objet
    nouveau->reference = objet;
    return nouveau;
}

// cette fonction cree un neoud dont les
// elements gauche et droit sont nuls
Noeud *cF(void *objet)
{
    return cNd(objet, NULL, NULL);
}

void initArbre(Arbre *A, Noeud *racine, char *(afficher)(void *), int (*comparer)(void *, void *))
{
    A->racine = racine;
    A->afficher = afficher;
    A->comparer = comparer;
}

// cette fonction retoune un pointeur vers une structure arbre
Arbre *creerArbre(Noeud *racine, char *(afficher)(void *), int (*comparer)(void *, void *))
{
    // allocation de mémoire pour une nouvelle structure arbre
    Arbre *A = (Arbre *)malloc(sizeof(Arbre));
    // initialisation de l'arbre créée
    initArbre(A, racine, afficher, comparer);
    return A;
}

// fonction permettant de parcourir l'arbre d'une maniere infixe
// c'est un fonction recursive
void Infixe(Noeud *racine, char *(*afficher)(void *))
{
    // cette fonction s'appelle elle meme jusqu'a l'atteinte
    // d'un noeud nul puis executes le code qui suit
    if (racine)
    {
        // on viste premierement le sous arbre gauche du chaque
        // noeud
        Infixe(racine->gauche, afficher);
        // puis on affiche la reference stocké dans le noeud
        printf("%s ", afficher(racine->reference));
        // dernièrement on visite le sous-arbre droit du noeud
        Infixe(racine->droite, afficher);
    }
    return;
}

// fonction permettant de parcourir l'arbre d'une maniere postfixe
// c'est un fonction recursive
void Postfixe(Noeud *racine, char *(*afficher)(void *))
{
    // cette fonction s'appelle elle meme jusqu'a l'atteinte
    // d'un noeud nul puis executes le code qui suit
    if (racine)
    {
        // premièrement on visite le sous-arbre gauche du noeud
        Postfixe(racine->gauche, afficher);
        // puis on visite le sous-arbre droit du noeud
        Postfixe(racine->droite, afficher);
        // et finalement on affiche la reference stocker dans ce noeud
        printf("%s ", afficher(racine->reference));
    }
    return;
}

void Prefixe(Noeud *racine, char *(*afficher)(void *))
{
    // cette fonction s'appelle elle meme jusqu'a l'atteinte
    // d'un noeud nul puis executes le code qui suit
    if (racine)
    {
        // on affiche d'abord le noeud lui-même
        printf("%s ", afficher(racine->reference));
        // puis on visite le sous-arbre gauche du noeud
        Prefixe(racine->gauche, afficher);
        // et enfin on visite le sous-arbre droit
        Prefixe(racine->droite, afficher);
    }
    return;
}

int Taille(Noeud *N)
{
    // cette fonction est une fonction recursive
    // qui returne 0 si le noeud est nul
    // sinon elle retourne 1 pour le noeud actuel plus la taille
    // de chaque sous-arbre
    return (N ? (1 + Taille(N->gauche) + Taille(N->droite)) : 0);
}

int Hauteur(Noeud *N)
{ /*Ici, nous appelons récursivement la fonction sur les sous-arbres gauche et droit du noeud actuel,
  puis nous retournons la hauteur la plus grande de ces sous-arbres plus 1 pour le noeud actuel.
  Cela garantit que nous calculons la hauteur de l'arbre entier en comptant
  le nombre de noeuds de l'arbre de la racine jusqu'à la feuille la plus profonde.*/
    if (N == NULL)
        return 0;
    return 1 + max(Hauteur(N->gauche), Hauteur(N->droite));
}

Noeud *trouverNoeud(Noeud *root, void *objet, int (*comparer)(void *, void *))
{
    /*Ici, nous comparons d'abord la valeur du noeud actuel avec la valeur que nous recherchons.
    Si elles correspondent, nous retournons le noeud. Sinon, nous appelons récursivement
    la fonction sur les sous-arbres gauche et droit du noeud actuel et retournons le premier noeud
    trouvé qui correspond à la valeur recherchée. Si aucun neoud n'est trouvé la fonction retourne
    NULL*/
    if (!root)
    {
        return NULL;
    }
    if (comparer((void *)root->reference, objet) == 0)
        return root;
    Noeud *temp;
    if (temp = trouverNoeud((void *)root->gauche, objet, comparer))
        return temp;
    if (temp = trouverNoeud((void *)root->droite, objet, comparer))
        return temp;
}

void parcoursLargeur(Noeud *racine, char *(*afficher)(void *))
{
    // pour parcourir un arbre en largeur on utilise une structure de donnée file
    // on initialise d'abord la liste puis insere le premier noeud dans la file
    liste *l = creer(0, NULL, NULL);
    inserer_tete(l, racine);
    while (!listeVide(l))
    {
        // dans cette boucle on affiche la valeur stocker dans le noeud,
        // puis on insere dans la file les element gauche et droitde ce noeud dans la
        // file s'il ne sont pas NULL.Cette technique va nous permettre d'afficher les
        // les valeur des noeud qui sont inserés en premier dans la liste. Si la file est
        // vide, cela veut dire que la fonction a affiché toute le valeurs presentes dans l'arbre.
        Noeud *extrait = (Noeud *)retrait_tete(l);
        printf("%s ", afficher(extrait->reference));
        if (extrait->gauche)
            inserer_fin(l, extrait->gauche);
        if (extrait->droite)
            inserer_fin(l, extrait->droite);
    }
    detruire_liste(l);
}

void detruireArbre(Noeud *racine)
{
    // fonction recursive permettant de libérer la memoire prise par l'arbre
    // on appel la fonction recursivement sur les sous-arbres du noeuds actuel
    // puis on libère la mémoire prise par le noeud lui-même
    if (racine)
    {
        detruireArbre(racine->gauche);
        detruireArbre(racine->droite);
        free(racine);
    }
    return;
}

void inserer_arbre_gene(Noeud *racine, void *objet, int (*comparer)(void *, void *), _Bool isMale, void *objet_a_inserer)
{
    Noeud *trouve = trouverNoeud(racine, objet, comparer);
    if (trouve)
    {
        if (isMale)
        {
            if (trouve->gauche)
            {
                printf("emplacement invalide");
                return;
            }
            else
            {
                trouve->gauche = cF(objet_a_inserer);
                return;
            }
        }
        else
        {
            if (trouve->droite)
            {
                printf("emplacement invalide");
                return;
            }
            else
            {
                trouve->droite = cF(objet_a_inserer);
                return;
            }
        }
    }
    printf("element introuvable");
    return;
}

bool estFeuille(Noeud *Racine)
{
    (!Racine->gauche && !Racine->droite) ? true : false;
}

int nbFeuille(Noeud *racine)
{
    if (!racine)
        return 0;
    else if (estFeuille(racine))
        return 1;
    else
        return (nbFeuille(racine->gauche) + nbFeuille(racine->droite));
}

void listerFeuille(Noeud *racine, char *(*afficher)(void *))
{
    if (racine)
    {
        if (estFeuille(racine))
            printf("%s", afficher(racine->reference));
        else
        {
            listerFeuille(racine->gauche, afficher);
            listerFeuille(racine->droite, afficher);
        }
    }
}

bool egaliteArbre(Noeud *racine1, Noeud *racine2, int (*comparer)(void *, void *))
{
    bool res = false;
    if (racine1 == NULL && racine2 == NULL)
        res = true;
    else if (racine1 && racine2)
    {
        if (comparer(racine1->reference, racine2->reference) == 0)
        {
            if (egaliteArbre(racine1->gauche, racine2->gauche, comparer))
                res = egaliteArbre(racine1->droite, racine2->droite, comparer);
        }
    }
    return res;
}
