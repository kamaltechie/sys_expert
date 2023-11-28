
#ifndef SYSTEM_EXPERT_SYSTEM_EXPERT_H
#define SYSTEM_EXPERT_SYSTEM_EXPERT_H

typedef struct {
    char data[100];
    char *suivant;
} premisse;

typedef struct {
    premisse *premisse;
    char *conclusion;
}regle;

creer_regle(char *premisse, char *conclusion);

#endif //SYSTEM_EXPERT_SYSTEM_EXPERT_H
