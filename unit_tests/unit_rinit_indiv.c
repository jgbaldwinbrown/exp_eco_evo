#include <stdio.h>
#include <stdlib.h>
#include "../simulator.h"
#include <gsl/gsl_randist.h>
#include <gsl/gsl_rng.h>

int main(){
    indiv a;
    gsl_rng * myrng = gsl_rng_alloc (gsl_rng_taus);
    init_indiv(&a);
    rinit_indiv(&a, 5, 1, .5, myrng);
    gsl_rng_free(myrng);
    printf("%lf\n",a.size);
    printf("%lf\n",a.food_needed);
    printf("%lf\n",a.food_eaten);
    printf("%d\n",a.carnivore);
    return(0);
}
