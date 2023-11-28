#include <stdio.h>
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




int main() {

}

