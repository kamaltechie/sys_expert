#include <stdio.h>
#include <stdlib.h>
#include "system_expert.h"


proposition *creer_proposition() {
    proposition *p = (proposition * ) malloc(sizeof(proposition));
    p->data = '\0';
    p->suivant = NULL;
    return p;
}

regle *creer_regle() {
    regle *r = (regle *) malloc(sizeof(regle));
    r->premisse = NULL;
    r->conclusion = '\0';
    return r;
}

ListeProposition ajouter_proposition_premisse(regle *r, char proposition) {
    ListeProposition nouvelleProposition = creer_proposition();
    if (nouvelleProposition != NULL) {
        nouvelleProposition->data = proposition;
        nouvelleProposition->suivant = NULL;

        // Si la prémisse est vide, la nouvelle proposition devient la première
        if (r->premisse == NULL) {
            r->premisse = nouvelleProposition;
        } else {
            // Sinon, parcourir la liste jusqu'à la fin et ajouter la nouvelle proposition en queue
            ListeProposition courant = r->premisse;
            while (courant->suivant != NULL) {
                courant = courant->suivant;
            }
            courant->suivant = nouvelleProposition;
        }
    }
    return nouvelleProposition;
}

void creer_conclusion(regle *r, char conclusion) {
    r->conclusion = conclusion;
}

int appartient_a_premisse(proposition *p, char proposition) {
    if (p == NULL) {
        return 0;  // La proposition n'a pas été trouvée
    }

    if (p->data == proposition) {
        return 1;  // La proposition a été trouvée
    }

    return appartient_a_premisse(p->suivant, proposition);
}

int supprimer_proposition_premisse(proposition **premisse, char proposition) {
    ListeProposition current = *premisse;
    ListeProposition previous = NULL;

    while (current != NULL) {
        if (current->data == proposition) {
            // Proposition found, remove the node
            if (previous == NULL) {
                // If the proposition is in the first node
                *premisse = current->suivant;
            } else {
                // If the proposition is in a node other than the first
                previous->suivant = current->suivant;
            }

            free(current);
            return 1;  // Proposition removed
        }

        previous = current;
        current = current->suivant;
    }

    return 0;  // Proposition not found
}

int premisse_est_vide(proposition *premisse) {
    return premisse == NULL;
}

char acceder_tete_premisse(proposition *premisse) {
    if (premisse != NULL) {
        return premisse->data;
    } else {
        return '\0';
    }
}

char acceder_conclusion_regle(regle *r) {
    return r->conclusion;
}

int main() {

}

