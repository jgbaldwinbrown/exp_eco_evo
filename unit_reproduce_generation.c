#include <stdio.h>
#include <stdlib.h>
#include "simulator.h"
#include <gsl/gsl_randist.h>
#include <gsl/gsl_rng.h>

void prgen(generation *a){
    long long i;
    for (i=0; i < a->pop_size; i++){
        printf(" %d", a->population[i].carnivore);
    }
    printf("\n");
    for (i=0; i < a->pop_size; i++){
        printf(" %lf", a->population[i].size);
    }
    printf("\n");
    for (i=0; i < a->pop_size; i++){
        printf(" %lf", a->population[i].food_needed);
    }
    for (i=0; i < a->pop_size; i++){
        printf(" %d", a->population[i].alive);
    }
    printf("\n");
    for (i=0; i < a->pop_size; i++){
        printf(" %lf", a->population[i].food_eaten);
    }
}


int main(){
    generation *a;
    generation *b;
    gsl_rng * myrng = gsl_rng_alloc (gsl_rng_taus);
    a = init_generation(20);
    b = init_generation(20);
    rinit_generation(a, 5, 1, .1, myrng);
    a->population[5].carnivore = true;

    prgen(a);

    printf("\n");
    reproduce_generation(a, b, .1, .1, myrng);

    prgen(b);

    gsl_rng_free(myrng);
    free_generation(a);
    free_generation(b);
    return(0);
}

