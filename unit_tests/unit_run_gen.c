#include <stdio.h>
#include <stdlib.h>
#include "simulator.h"
#include <gsl/gsl_randist.h>
#include <gsl/gsl_rng.h>


int main(){
    generation *a;
    generation *b;
    double food = 80;
    gsl_rng * myrng = gsl_rng_alloc (gsl_rng_taus);
    a = init_generation(20);
    b = init_generation(20);
    rinit_generation(a, 5, 1, .1, myrng);
    a->population[5].carnivore = true;

    prgen(a);
    printf("\n");
    prgen(b);
    printf("\n");

    run_gen(a, b, .1, .1, myrng, food, 5, 1.1);

    prgen(a);
    printf("\n");
    prgen(b);
    printf("\n");

    gsl_rng_free(myrng);
    free_generation(a);
    free_generation(b);
    return(0);
}

