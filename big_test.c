#include <stdio.h>
#include <stdlib.h>
#include "simulator.h"
#include <gsl/gsl_randist.h>
#include <gsl/gsl_rng.h>


int main(){
    long long i;
    full_exp *a;
    double food = 80;
    gsl_rng * myrng = gsl_rng_alloc (gsl_rng_taus);
    a = init_full_exp(10000,30);
    rinit_full_exp(a, 5, 1, .1, myrng);

    prgen(a->exp_gens[0]);
    printf("\n");

    run_full_exp(a, .1, .1, myrng, food, 0);
    
    for(i=0; i < a->generation_number; i++){
        prgen(a->exp_gens[i]);
    printf("\n");
    }

    gsl_rng_free(myrng);
    free_exp(a);
    return(0);
}

