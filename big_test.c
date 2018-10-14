#include <stdio.h>
#include <stdlib.h>
#include "simulator.h"
#include <gsl/gsl_randist.h>
#include <gsl/gsl_rng.h>


int main(){
    full_exp *a;
    double food = 80;
    gsl_rng * myrng = gsl_rng_alloc (gsl_rng_taus);
    a = init_full_exp(10000,30);
    rinit_full_exp(a, 5, 1, .1, myrng);

    printf("\n");

    run_full_exp(a, .1, .1, myrng, food, 1);

    prexp(a);
    
    gsl_rng_free(myrng);
    free_exp(a);
    return(0);
}

