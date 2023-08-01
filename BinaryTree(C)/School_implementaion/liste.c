#include "liste.h"
#include <stdio.h>
#include <stdlib.h>

/*-------------helper funtions---------------------*/
element *nouveau_el(void *donnee)
{
    element *nouveau = (element *)malloc(sizeof(element));
    nouveau->donnee = donnee;
    nouveau->suivant = NULL;
    return nouveau;
}

int nbElement(liste *l)
{
    return l->nombre_ele;
}

bool listeVide(liste *l)
{
    return l->nombre_ele == 0 ? true : false;
}

void ouvrir_liste(liste *l)
{
    l->courant = l->premier;
    return;
}

bool fin_liste(liste *l)
{
    return l->courant == NULL ? true : false;
}

static element *element_courant(liste *l)
{
    element *p = l->courant;
    if (l->courant != NULL)
        l->courant = l->courant->suivant;
    return p;
}

void *objet_courant(liste *l)
{
    element *p = element_courant(l);
    return p == NULL ? NULL : p->donnee;
}

/*-------------------------------------------------------------*/

void initListe(liste *l, int type, char *(*afficher)(void *), int (*comparer)(void *, void *))
{
    l->nombre_ele = 0;
    l->premier = l->dernier = l->courant = NULL;
    l->afficher = afficher;
    l->comparer = comparer;
    l->type = type;
}

liste *creer(int type, char *(*affich)(void *), int (*comparer)(void *, void *))
{
    liste *l = (liste *)malloc(sizeof(liste));
    initListe(l, type, affich, comparer);
    return l;
}

void inserer_tete(liste *l, void *add)
{
    element *nouveau = nouveau_el(add);
    nouveau->suivant = l->premier;
    l->premier = nouveau;
    l->nombre_ele++;
    if (l->dernier == NULL)
        l->dernier = l->premier;
}

void inserer_fin(liste *l, void *donnee)
{
    element *nouveau = nouveau_el(donnee);
    nouveau->donnee = donnee;
    if (l->premier == NULL)
    {
        l->premier = nouveau;
        l->dernier = l->premier;
        l->nombre_ele++;
        return;
    }
    l->nombre_ele++;
    l->dernier->suivant = nouveau;
    l->dernier = nouveau;
}

void *retrait_tete(liste *l)
{
    if (!l->premier)
    {
        printf("retrait impossible la liste est vide\n");
        return NULL;
    }
    element *temp = l->premier;
    l->premier = (*(*l).premier).suivant;
    l->nombre_ele--;
    if (!l->premier)
        l->dernier = l->premier;
    return temp->donnee;
}

void *retrait_fin(liste *l)
{
    if ((l)->premier == NULL)
    {
        printf("retrait impossible la liste est vide\n");
        return NULL;
    }
    ouvrir_liste(l);
    if (!l->courant->suivant)
    {
        l->premier = NULL;
        l->dernier = NULL;
        l->nombre_ele--;
        return l->courant->donnee;
    }
    element *t2;
    while (l->courant != l->dernier)
    {
        t2 = element_courant(l);
    }
    t2->suivant = NULL;
    l->dernier = t2;
    l->nombre_ele--;
    return l->courant->donnee;
}

void *retrait_par_reference(liste *l, void *objet)
{
    element *prev;
    if (l->premier == NULL)
    {
        printf("retrait impossible la liste est vide");
        return NULL;
    }
    if (l->comparer(l->premier->donnee, objet) == 0)
    {
        void *temp = retrait_tete(l);
        return temp;
    }
    ouvrir_liste(l);
    while (l->courant != l->dernier)
    {
        prev = l->courant;
        l->courant = l->courant->suivant;
        if (l->comparer(l->courant->donnee, objet) == 0)
        {
            prev->suivant = l->courant->suivant;
            return objet;
        }
    }
    return NULL;
}

void afficher_liste(liste *l)
{
    ouvrir_liste(l);
    while (l->courant != NULL)
    {
        l->afficher(l->courant->donnee);
        l->courant = l->courant->suivant;
    }
    printf("NULL\n");
    l->courant = NULL;
}

void *chercher_objet(liste *l, void *objet)
{
    ouvrir_liste(l);
    if (l->courant == NULL)
        return NULL;
    bool trouve = false;
    void *objet1;
    while (!fin_liste(l))
    {
        objet1 = objet_courant(l);
        if (l->comparer(objet, objet1) == 0)
            return objet1;
    }
    return NULL;
}

void detruire_liste(liste *l)
{
    ouvrir_liste(l);
    while (!fin_liste(l))
    {
        element *p = element_courant(l);
        free(p->donnee);
        free(p);
    }
}