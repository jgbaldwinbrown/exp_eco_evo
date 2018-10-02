
#include <stdio.h>
#include <stdlib.h>
#include "simulator.h"
#include <gsl/gsl_randist.h>
#include <gsl/gsl_rng.h>

int main(){
    size_t i;
    long long *placeholder = calloc(sizeof(long long),3);
    gsl_rng * myrng = gsl_rng_alloc (gsl_rng_taus);
    for (i=0; i<3; i++){
        printf(" %lld",placeholder[i]);
    }
    printf("\n");
    getshuf(placeholder, 3, 20, myrng);
    for (i=0; i<20; i++){
        printf(" %lld",placeholder[i]);
    }
    printf("\n");
    gsl_rng_free(myrng);
    return(0);
}
