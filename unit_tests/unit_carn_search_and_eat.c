#include <stdio.h>
#include <stdlib.h>
#include "../simulator.h"
#include <gsl/gsl_randist.h>
#include <gsl/gsl_rng.h>

int main(){
    generation *a;
    gsl_rng * myrng = gsl_rng_alloc (gsl_rng_taus);
    a = init_generation(20);
    rinit_generation(a, 5, 1, .5, myrng);
    a->population[5].carnivore = true;

    prgen(a);

    printf("\n");
    carn_search_and_eat(a, 5, 0, myrng, 1.1);

    prgen(a);

    gsl_rng_free(myrng);
    printf("%lld\n", a->pop_size);
    printf("%lf\n",a->population[5].size);
    printf("%lf\n",a->population[5].food_needed);
    printf("%lf\n",a->population[5].food_eaten);
    printf("%d\n",a->population[5].carnivore);
    free_generation(a);
    return(0);
}

