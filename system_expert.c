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

void ajouter_proposition_premisse(regle *r, char proposition) {
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
            return 1;
        }

        previous = current;
        current = current->suivant;
    }

    return 0;
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

BC creer_base_vide() {
    return NULL;
}

void ajouter_regle(BC *base, regle *nouvelleRegle) {
    // Créer un nouvel élément pour la règle
    element *nouvelElement = (element *)malloc(sizeof(element));
    nouvelElement->data = nouvelleRegle;
    nouvelElement->suivant = NULL;

    if (*base == NULL) {
        *base = nouvelElement;
    } else {
        // Sinon, parcourir la base jusqu'à la fin et ajouter le nouvel élément en queue
        element *courant = *base;
        while (courant->suivant != NULL) {
            courant = courant->suivant;
        }
        courant->suivant = nouvelElement;
    }
}

regle *acceder_tete_base(BC base) {
    if (base != NULL) {
        return base->data;
    } else {
        return NULL;
    }
}

void afficher_conclusion(char conclusion) {
    printf("Conclusion : %c\n", conclusion);
}

ListeConclusion ajouter_conclusion_liste(ListeConclusion liste, char conclusion) {
    elementConclusion *nouvelElement = (elementConclusion *)malloc(sizeof(elementConclusion));
    nouvelElement->conclusion = conclusion;
    nouvelElement->suivant = liste;
    return nouvelElement;
}

void afficher_liste_conclusions(ListeConclusion liste) {
    printf("Liste de conclusions : ");
    while (liste != NULL) {
        printf("%c ", liste->conclusion);
        liste = liste->suivant;
    }
    printf("\n");
}

ListeConclusion moteur_inference(BC baseConnaissances, ListeProposition baseFaits, ListeConclusion listeConclusions) {
    while (baseFaits != NULL) {
        printf("a");
        BC baseConnaissancesCourante = baseConnaissances;

        while (baseConnaissancesCourante != NULL) {
            printf("b");
            proposition *premisse = baseConnaissancesCourante->data->premisse;
            int premisseVraie = 1;

            while (premisse != NULL) {
                printf("c");
                if (!appartient_a_premisse(baseFaits, premisse->data)) {
                    premisseVraie = 0;
                    break;
                }
                printf("d");
                premisse = premisse->suivant;
            }
            printf("k");
            if (premisseVraie) {
                // Ajouter la conclusion à la liste de conclusions
                printf("e");
                listeConclusions = ajouter_conclusion_liste(listeConclusions, baseConnaissancesCourante->data->conclusion);

                // Ajouter la conclusion à la base de faits
                ajouter_proposition_premisse(baseFaits, baseConnaissancesCourante->data->conclusion);

                // Supprimer les propositions de la prémisse de la base de faits
                proposition *premisseCourante = baseConnaissancesCourante->data->premisse;
                while (premisseCourante != NULL) {
                    supprimer_proposition_premisse(baseFaits, premisseCourante->data);
                    premisseCourante = premisseCourante->suivant;
                }
            }

            baseConnaissancesCourante = baseConnaissancesCourante->suivant;
        }
    }
    return listeConclusions;
}
int main() {
    // Créer une base de connaissances
    BC baseConnaissances = creer_base_vide();

    // Créer une règle
    regle *maRegle = creer_regle();
    ajouter_proposition_premisse(maRegle, 'A');
    ajouter_proposition_premisse(maRegle, 'B');
    ajouter_proposition_premisse(maRegle, 'C');
    creer_conclusion(maRegle, 'D');

    // Ajouter la règle à la base de connaissances
    ajouter_regle(&baseConnaissances, maRegle);


    ListeProposition baseFaits = NULL;
    ajouter_proposition_premisse(&baseFaits, 'A');
    ajouter_proposition_premisse(&baseFaits, 'B');

    // Créer une liste de conclusions
    ListeConclusion listeConclusions = NULL;
    printf("ffffffffff");
    // Appliquer le moteur d'inférence
    listeConclusions=  moteur_inference(baseConnaissances, baseFaits, listeConclusions);
    printf("dddddddd");

    // Afficher les conclusions déduites
    afficher_liste_conclusions(listeConclusions);

    return 0;
}

