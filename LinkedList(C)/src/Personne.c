#include "Personne.h"
#include "liste.h"
#include <stdlib.h>
#include <string.h>

Personne *creerPersonne(char *nom, char *prenom)
{
    Personne *p = (Personne *)malloc(sizeof(Personne));
    strcpy(p->nom, nom);
    strcpy(p->prenom, prenom);
    return p;
}

char *ecrirePersonne(Objet *objet)
{
    char *output = (char *)malloc(sizeof(Personne));
    snprintf(output, sizeof(Personne), "%s %s", ((Personne *)objet)->nom, ((Personne *)objet)->prenom);
    return output;
}

int comparerPersonne(Objet *objet1, Objet *objet2)
{
    return strcmp(((Personne *)objet1)->nom, ((Personne *)objet2)->nom);
}