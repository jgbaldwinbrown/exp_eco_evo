
#include <stdio.h>
#include <stdlib.h>
#include "simulator.h"
#include <gsl/gsl_randist.h>
#include <gsl/gsl_rng.h>

int main(){
    indiv a;
    indiv b;
    gsl_rng * myrng = gsl_rng_alloc (gsl_rng_taus);
    init_indiv(&a);
    init_indiv(&b);
    rinit_indiv(&a, 5, 1, 1.0, myrng);
    rinit_indiv(&b, 3, 1, 0.0, myrng);
    printf("a, before:\n");
    printf("%lf\n",a.size);
    printf("%lf\n",a.food_needed);
    printf("%lf\n",a.food_eaten);
    printf("%d\n",a.carnivore);
    printf("%d\n",a.alive);
    printf("b, before:\n");
    printf("%lf\n",b.size);
    printf("%lf\n",b.food_needed);
    printf("%lf\n",b.food_eaten);
    printf("%d\n",b.carnivore);
    printf("%d\n",b.alive);
    carn_eat(&a, &b);
    gsl_rng_free(myrng);
    printf("a, after:\n");
    printf("%lf\n",a.size);
    printf("%lf\n",a.food_needed);
    printf("%lf\n",a.food_eaten);
    printf("%d\n",a.carnivore);
    printf("%d\n",a.alive);
    printf("b, after:\n");
    printf("%lf\n",b.size);
    printf("%lf\n",b.food_needed);
    printf("%lf\n",b.food_eaten);
    printf("%d\n",b.carnivore);
    printf("%d\n",b.alive);
    return(0);
}
