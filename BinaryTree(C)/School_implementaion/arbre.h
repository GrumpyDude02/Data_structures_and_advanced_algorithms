#include <stdio.h>
#ifndef ARBRE_H
#define ARBRE_H
#include <liste.h>

typedef struct Noeud
{
    void *reference;
    struct Noeud *gauche;
    struct Noeud *droite;
} Noeud;

typedef struct
{
    Noeud *racine;
    char *(*afficher)(void *);
    int (*comparer)(void *, void *);
} Arbre;

// fonction de creation de noeuds
Noeud *cNd(void *objet, Noeud *gauche, Noeud *droite);

// fonction de creation de noeuds fils(noeuds dont le element sont NULL)
Noeud *cF(void *objet);

// parcours infixe
void Infixe(Noeud *racine, char *(*afficher)(void *));

// parcours prefixe
void Prefixe(Noeud *racine, char *(*afficher)(void *));

// parcours postfixe
void Postfixe(Noeud *racine, char *(*afficher)(void *));

// parecours en largeur(visite des element qui ont le même niveau)
void parcoursLargeur(Noeud *racine, char *(*afficher)(void *));

// fonction qui calcule la taille de l'arbre
int Taille(Noeud *N);

// fonction retourenant la hauteur de l'arbre
int Hauteur(Noeud *N);

// recherche d'un neoud a partir de sa reference
Noeud *trouverNoeud(Noeud *root, void *objet, int (*comparer)(void *, void *));

// initialisation de l'arbre
void initArbre(Arbre *A, Noeud *racine, char *(*afficher)(void *), int (*compare)(void *, void *));

// fonction qui cree un structure de donnée arbre
Arbre *creerArbre(Noeud *racine, char *(*afficher)(void *), int (*compare)(void *, void *));

// destruction de l'arbre
void detruireArbre(Noeud *);

bool esFeuille(Noeud *Racine);

int nbFeuille(Noeud *racine);

void listerFeuille(Noeud *racine, char *(*afficher)(void *));

bool egaliteArbre(Noeud *racine1, Noeud *racine2, int (*comparer)(void *, void *));

#endif