#include <stdio.h>
#include <stdlib.h>
#include "../simulator.h"
#include <gsl/gsl_randist.h>
#include <gsl/gsl_rng.h>

int main(){
    generation *a;
    gsl_rng * myrng = gsl_rng_alloc (gsl_rng_taus);
    a = init_generation(5);
    rinit_generation(a, 5, 1, .5, myrng);
    gsl_rng_free(myrng);
    printf("%lld\n", a->pop_size);
    printf("%lf\n",a->population[0].size);
    printf("%lf\n",a->population[0].food_needed);
    printf("%lf\n",a->population[0].food_eaten);
    printf("%d\n",a->population[0].carnivore);
    free_generation(a);
    return(0);
}

