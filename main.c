#include <stdio.h>
#include "system_expert.h"

int main() {
    // Créer une base de connaissances
    BC baseConnaissances = creer_base_vide();

    // Créer une règle
    regle *maRegle1 = creer_regle();
    ajouter_proposition_premisse(maRegle1, 'A');
    ajouter_proposition_premisse(maRegle1, 'B');
    ajouter_proposition_premisse(maRegle1, 'C');
    creer_conclusion(maRegle1, 'D');

    regle *maRegle = creer_regle();
    ajouter_proposition_premisse(maRegle, 'D');
    creer_conclusion(maRegle, 'E');



    // Ajouter la règle à la base de connaissances
    ajouter_regle(&baseConnaissances, maRegle);
    ajouter_regle(&baseConnaissances, maRegle1);

    afficher_base_connaissances(baseConnaissances);


    Liste baseFaits = NULL;
    ajouter_proposition_premisse(&baseFaits, 'A');
    ajouter_proposition_premisse(&baseFaits, 'B');
    ajouter_proposition_premisse(&baseFaits, 'C');

    afficher_base_faits(baseFaits);

    // Créer une liste de conclusions
    Liste listeConclusions = NULL;

    // Appliquer le moteur d'inférence
    listeConclusions=  moteur_inference(&baseConnaissances, &baseFaits, listeConclusions);

    // Afficher les conclusions déduites
    afficher_liste_conclusions(listeConclusions);

    return 0;
}