#include <stdio.h>
#include <stdlib.h>
#ifndef SYSTEM_EXPERT_SYSTEM_EXPERT_H
#define SYSTEM_EXPERT_SYSTEM_EXPERT_H

typedef struct prop{
    char data;
    struct prop *suivant;
} proposition;

typedef proposition *ListeProposition;

typedef struct {
    ListeProposition premisse;
    char conclusion;
} regle;

typedef struct Elem {
    regle *data;
    struct Elem *suivant;
} element;

typedef element *BC;

typedef struct ElemConclusion {
    char conclusion;
    struct ElemConclusion *suivant;
} elementConclusion;

typedef elementConclusion *ListeConclusion;


regle *creer_regle();
proposition *creer_proposition();
void ajouter_proposition_premisse(regle *r, char proposition);
void creer_conclusion(regle *r, char conclusion);
int appartient_a_premisse(proposition *p, char proposition);
int supprimer_proposition_premisse(proposition **premisse, char proposition);
int premisse_est_vide(proposition *premisse);
char acceder_tete_premisse(proposition *premisse);
char acceder_conclusion_regle(regle *r);
BC creer_base_vide();
void ajouter_regle(BC *base, regle *nouvelleRegle);
regle *acceder_tete_base(BC base);
ListeConclusion ajouter_conclusion_liste(ListeConclusion liste, char conclusion);
void afficher_liste_conclusions(ListeConclusion liste);
ListeConclusion moteur_inference(BC baseConnaissances, ListeProposition baseFaits, ListeConclusion listeConclusions);


#endif //SYSTEM_EXPERT_SYSTEM_EXPERT_H
