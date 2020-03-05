#include <stdio.h>
#include <stdlib.h>
#include "../simulator.h"
#include <gsl/gsl_randist.h>
#include <gsl/gsl_rng.h>

int main(){
    indiv a;
    indiv b;
    indiv c;
    gsl_rng * myrng = gsl_rng_alloc (gsl_rng_taus);
    init_indiv(&a);
    init_indiv(&b);
    init_indiv(&c);
    rinit_indiv(&a, 5, 1, .5, myrng);
    reproduce_indiv(&a, &b, 1, .2, myrng);
    reproduce_indiv(&a, &c, 1, .2, myrng);
    gsl_rng_free(myrng);
    printf("%lf\n",a.size);
    printf("%lf\n",a.food_needed);
    printf("%lf\n",a.food_eaten);
    printf("%d\n",a.carnivore);
    printf("%lf\n",b.size);
    printf("%lf\n",b.food_needed);
    printf("%lf\n",b.food_eaten);
    printf("%d\n",b.carnivore);
    printf("%lf\n",c.size);
    printf("%lf\n",c.food_needed);
    printf("%lf\n",c.food_eaten);
    printf("%d\n",c.carnivore);
    return(0);
}
