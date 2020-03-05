#include <stdio.h>
#include <stdlib.h>
#include "../simulator.h"
#include <gsl/gsl_randist.h>
#include <gsl/gsl_rng.h>


int main(){
    generation *a;
    generation *b;
    gsl_rng * myrng = gsl_rng_alloc (gsl_rng_taus);
    a = init_generation(20);
    b = init_generation(20);
    rinit_generation(a, 5, 1, .1, myrng);
    a->population[5].carnivore = true;
    a->population[6].alive = false;
    a->population[17].alive = false;

    prgen(a);

    printf("\n");
    reproduce_generation(a, b, .1, .1, myrng);

    prgen(b);

    gsl_rng_free(myrng);
    free_generation(a);
    free_generation(b);
    return(0);
}

