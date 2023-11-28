#include <stdio.h>
#include <stdlib.h>
#ifndef SYSTEM_EXPERT_SYSTEM_EXPERT_H
#define SYSTEM_EXPERT_SYSTEM_EXPERT_H




typedef struct prop{
    char data;
    struct prop *suivant;
} proposition;

typedef struct {
    proposition *premisse;
    char conclusion;
}regle;

typedef struct {
    regle *regles;  // Tableau dynamique de règles
    int taille;     // Nombre de règles dans la base de connaissances
} BaseDeConnaissances;



regle *creer_regle();
proposition *creer_proposition();

#endif //SYSTEM_EXPERT_SYSTEM_EXPERT_H
