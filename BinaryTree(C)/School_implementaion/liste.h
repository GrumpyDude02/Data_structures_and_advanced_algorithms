#ifndef LISTE_H
#define LISTE_H
typedef struct element
{
    void *donnee;
    struct element *suivant;
} element;

typedef enum
{
    false,
    true
} bool;

typedef struct
{
    element *premier;
    element *dernier;
    element *courant;
    int type;
    int nombre_ele;
    char *(*afficher)(void *);
    int (*comparer)(void *, void *);

} liste;
/*-----helper functions--------*/

element *nouveau_el(void *donee);
void ouvrir_liste(liste *l);
bool fin_liste(liste *l);
bool listeVide(liste *l);
int nbElement(liste *l);
static element *element_courant(liste *l);
void *objet_courant(liste *l);

/*-------------------------------------------------*/
void initListe(liste *l, int type, char *(*afficher)(void *), int (*comparer)(void *, void *));
liste *creer(int type, char *(*afficher)(void *), int (*comparer)(void *, void *));
void inserer_tete(liste *l, void *add);
void inserer_fin(liste *l, void *add);
void *retrait_tete(liste *l);
void *retrait_fin(liste *l);
void *retrait_par_reference(liste *l, void *objet);
void afficher_liste(liste *l);
void *chercher_objet(liste *l, void *objet);
void detruire_liste(liste *l);

#endif