#include "liste.h"

void initListe(Liste *l, int type, char *(*afficher)(Objet *), int (*comparer)(Objet *, Objet *))
{
    // ces element doivent pointer sur NULL pour eviter acces a des donnée indesirable
    l->premier = l->dernier = l->courant = NULL;
    // l->afficher pointe sur la fonction afficher qui depend selon le type des objets
    l->afficher = afficher;
    // l->afficher pointe sur la fonction afficher qui depend selon le type des objets
    l->comparer = comparer;
    // la liste est vide
    l->nbElt = 0;
    // la variable type nous renseigne sur l'ordre de la liste
    l->type = type;
}

Liste *creerListe(int type, char *(*afficher)(Objet *), int (*comparer)(Objet *, Objet *))
{
    // allocation de la memoire pour creer une nouvelle liste
    Liste *l = (Liste *)malloc(sizeof(Liste));
    // initialisation de la liste
    initListe(l, type, afficher, comparer);
    return l;
}

booleen listeVide(Liste *l)
{
    // cette fonction retourne vrai si le nombre d'element est nul
    // sinon elle retourne faux
    return l->nbElt == 0;
}

int nbElement(Liste *l)
{
    return l->nbElt;
}

static Element *creerElement()
{
    // retourne un pointeur vers un bloc de memoire
    // de taille Element
    return (Element *)malloc(sizeof(Element));
}

void insererEnTeteDeListe(Liste *l, Objet *objet)
{
    // creation d'un nouvel élément
    Element *nouveau = creerElement();
    // ajout de l'element a la tete de la liste
    nouveau->reference = objet;
    nouveau->suivant = l->premier;
    l->premier = nouveau;
    // verfication si l'élément dernier est NULL,
    // si oui cela signifie que la liste est vide
    // et qu'on vient d'inserer le premier element
    // donc cet element est aussi le dernier
    if (!l->dernier)
        l->dernier = nouveau;
    // incrementation du nombre d'element de la liste
    l->nbElt++;
}

static void insereApres(Liste *l, Element *precedent, Objet *objet)
{
    // si cette condition est vraie(l'element precedent est NULL),
    // on insere a la tete de la liste
    // sinon on ajoute un nouvel élément juste apres le precedent
    // on insere le nouvel élément entre l'élément precedent
    // et celui qui le suit
    if (!precedent)
        insererEnTeteDeListe(l, objet);
    else
    {
        Element *nouveau = creerElement();
        nouveau->reference = objet;
        nouveau->suivant = precedent->suivant;
        precedent->suivant = nouveau;
        if (precedent == l->dernier)
            l->dernier = nouveau;
        l->nbElt++;
    }
}

void insererEnFinDeListe(Liste *l, Objet *objet)
{
    // on insere après le dernier element de la liste
    insereApres(l, l->dernier, objet);
}

void ouvrirListe(Liste *l)
{
    l->courant = l->premier;
}

booleen finListe(Liste *l)
{
    // cette fonction retourne vrai si l'élément courant
    // est NULL sinon elle retourne faux
    return l->courant == NULL;
}

static Element *elementCourant(Liste *l)
{
    // cette fonction stock l'adresse de l'element
    // courant dans une varible ,la retourne et l'element
    // courant passe a l'élément qui le suit
    Element *ptc = l->courant;
    if (l->courant)
        l->courant = l->courant->suivant;
    return ptc;
}

Objet *objetCourant(Liste *l)
{
    // retourne la reference de l'element
    // retourner par la fonction elementcourant()
    Element *ptc = elementCourant(l);
    return ptc == NULL ? NULL : ptc->reference;
}

void listerListe(Liste *l)
{
    // cette fonction affiche chaque element
    // avec une boucle qui se repete tant que
    // la liste n'est pas a sa fin et fait appel
    // la fonction afficher de la liste et qui
    //  depend selon le type de l'objet
    ouvrirListe(l);
    while (!finListe(l))
    {
        Objet *objet = objetCourant(l);
        printf("%s->", l->afficher(objet));
    }
    printf("NULL");
}

Objet *chercherUnObjet(Liste *l, Objet *objetCherche)
{
    // la fonction retourne l'adresse de la reference de
    // l'objet qu'on souhaite trouver
    // on utilise une boucle qui se repete tant qu'on est pas
    // a la fin de liste et l'objet chercher n'est pas trouvé
    // si l'objet n'est pas trouvé la fonction retourne NULL
    booleen trouve = faux;
    Objet *objet;
    ouvrirListe(l);
    while (!finListe(l) && !trouve)
    {
        objet = objetCourant(l);
        trouve = l->comparer(objet, objetCherche) ? faux : vrai;
    }
    return trouve ? objet : NULL;
}

Objet *extraireEnTeteDeListe(Liste *l)
{
    // la fonction retourne l'adresse de l'objet
    // stocker dans le premier élément
    Element *extrait = l->premier;
    // verfication si la liste n'est pas vide
    if (!listeVide(l))
    {
        // l'element premier de la liste pointe sur l'element
        // qui le suit ,d'où le retrait de l'ancien premier element
        // de la liste
        l->premier = l->premier->suivant;
        if (!l->premier)
            l->dernier = NULL;
        // decrementation du nombre d'element
        l->nbElt--;
    }
    return extrait != NULL ? extrait->reference : NULL;
}

static Objet *extraireApres(Liste *l, Element *precedent)
{
    // la fonction verifie si l'element precedent pas NULL
    // si cette condition est satisfaite on retire
    // le premier élément de la liste
    // sinon retire l'element qui suit le precedents
    if (!precedent)
        return extraireEnTeteDeListe(l);
    else
    {
        Element *extrait = precedent->suivant;
        if (extrait)
        {
            // l'élément suivant du precedent doit pointer
            // sur l'élément qui suit celui qu'on souhaite extraire
            precedent->suivant = extrait->suivant;
            if (extrait == l->dernier)
                l->dernier = precedent;
            l->nbElt--;
        }
        return extrait != NULL ? extrait->reference : NULL;
    }
}

Objet *extraireEnFinDeListe(Liste *l)
{
    // retrait en fin de liste
    Objet *extrait;
    if (!listeVide(l))
        extrait = NULL;
    else if (l->premier == l->dernier)
        // si le premier est le dernier élément pointe sur la meme adresse
        // cela signifie que la liste n'a qu'un seul élement
        // donc on peut extraire en tete de liste
        extrait = extraireEnTeteDeListe(l);
    else
    {
        // on parcours la liste juasqu'a ce qu'on
        // arrive a l'avant dernier élément
        // et utilise la fonction extraire après
        Element *ptc = l->premier;
        while (ptc->suivant != l->dernier)
            ptc = ptc->suivant;
        extrait = extraireApres(l, ptc);
    }
    return extrait;
}

booleen extraireUnObjet(Liste *l, Objet *objet)
{
    // la fonction parcourt la liste jusqu'a ce qu'on trouve
    // l'objet cherché ,on utilise la fonction comparer
    // de la liste qui retourne 0 si les objets sont egaux
    Element *precedent = NULL;
    Element *ptc = NULL;
    booleen trouve = faux;
    ouvrirListe(l);
    while (!finListe(l) && !trouve)
    {
        precedent = ptc;
        ptc = elementCourant(l);
        trouve = objet == ptc->reference ? vrai : faux;
    }
    if (!trouve)
        return faux;
    Objet *extrait = extraireApres(l, precedent);
    return vrai;
}

void detruireListe(Liste *l)
{
    // on parcours la liste et utilise la fonction free
    // pour deallouer la memoire prise par chaque élément
    // de la liste puis on reinitialise la liste
    ouvrirListe(l);
    while (!finListe(l))
    {
        Element *ptc = elementCourant(l);
        free(ptc->reference);
        free(ptc);
    }
    initListe(l, l->type, l->afficher, l->comparer);
}