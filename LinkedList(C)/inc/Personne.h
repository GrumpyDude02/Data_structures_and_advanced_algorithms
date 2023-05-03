#include "liste.h"
#ifndef PERSONNE_H
#define PERSONNE_H
typedef char ch15[16];
typedef struct
{
    ch15 nom;
    ch15 prenom;
} Personne;
Personne *creerPersonne(char *nom, char *prenom);
char *ecrirePersonne(Objet *objet);
int comparerPersonne(Objet *objet1, Objet *objet2);
#endif