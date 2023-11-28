#include <stdio.h>
import "system_expert.h"

creer_regle(char *premisse, char *conclusion) {
    regle *r = malloc(sizeof(regle));
    r->premisse = malloc(sizeof(premisse));
    r->premisse->data = premisse;
    r->conclusion = conclusion;
    return r;
}




int main() {

}

