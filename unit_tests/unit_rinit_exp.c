#include <stdio.h>
#include <stdlib.h>
#include "../simulator.h"
#include <gsl/gsl_randist.h>
#include <gsl/gsl_rng.h>

int main(){
    full_exp  *a;
    gsl_rng * myrng = gsl_rng_alloc (gsl_rng_taus);
    a = init_full_exp(3,5);
    rinit_full_exp(a, 5, 1, .5, myrng);
    gsl_rng_free(myrng);
    printf("%lld\n", a->pop_size);
    printf("%lld\n", a->generation_number);
    printf("%lld\n", a->exp_gens[0]->pop_size);
    printf("%lf\n",a->exp_gens[0]->population[0].size);
    printf("%lf\n",a->exp_gens[0]->population[0].food_needed);
    printf("%lf\n",a->exp_gens[0]->population[0].food_eaten);
    printf("%d\n",a->exp_gens[0]->population[0].carnivore);
    free_exp(a);
    return(0);
}

