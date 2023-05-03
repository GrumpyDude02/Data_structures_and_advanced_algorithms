#include <stdio.h>
#include <stdlib.h>
#ifndef LISTE_H
#define LISTE_H
// definition du type booleen et Objet en tant que void
#define vrai 1
#define faux 0
typedef void Objet;
typedef int booleen;

// structure element
typedef struct Element
{
    void *reference;
    struct Element *suivant;
} Element;

// structure Liste
typedef struct
{
    Element *premier;
    Element *dernier;
    Element *courant;
    int nbElt;
    int type;
    char *(*afficher)(Objet *);
    int (*comparer)(Objet *, Objet *);
} Liste;

// initialisation de la liste
void initListe(Liste *l, int type, char *(*afficher)(Objet *), int (*comparer)(Objet *, Objet *));

// allocation et creation de la liste
Liste *creerListe(int type, char *(*afficher)(Objet *), int (*comparer)(Objet *, Objet *));

// fonction qui verifie si la liste est vide
booleen listeVide(Liste *l);

// nombre d'elements dans la liste
int nbElement(Liste *l);

// fonction de creation de nouveaux elements on ne peut l'appeler que dans liste.c
static Element *creerElement();

// insertion d'un nouvel element a la tete de la liste
void insererEnTeteDeListe(Liste *, Objet *);

/*insertion après un element dont l'adresse est connue
cette fonction n'est utilisable que dans liste.c*/
static void insereApres(Liste *l, Element *precedent, Objet *objet);

// insertion d'un nouvel element a la fin de la liste
void insererEnFinDeListe(Liste *, Objet *);

// fonction qui affect l'adresse du premier element de la liste a l'element courant
void ouvrirListe(Liste *l);

// fonction qui verifie si l'element courant est a la fin de la liste
booleen finListe(Liste *li);

// fonction qui retourne l'adresse de l'element courant
// cette fonction n'est utilisable que dans liste.c
static Element *elementCourant(Liste *l);

// fonction qui retourne la reference de l'element courant
Objet *objetCourant(Liste *);

// fonction d'affichage de tous les élément de la liste
void listerListe(Liste *l);

// fonction qui permet de chercher des objets de la liste
// si cet objet ne figure pas dans la liste, la fonction retourne NULL
Objet *chercherUnObjet(Liste *l, Objet *objetCherche);

// fonction permettant l'extraction ou la suppression d'un element
Objet *extraireEnTeteDeListe(Liste *l);

// fonction d'extraction d'element apres un element d'adresse connue,
// cette fonction n'est utilisable que dans liste.c
static Objet *extraireApres(Liste *l, Element *precedent);

// extraction du dernier element de la liste
Objet *extraireEnFinDeListe(Liste *l);

booleen extraireUnObjet(Liste *li, Objet *objet);

// fonction permettant la liberation du bloc memoire alloué a la liste
// ainsi que tous ses element
void detruireListe(Liste *l);

#endif