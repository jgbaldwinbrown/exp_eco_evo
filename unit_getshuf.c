#include <stdio.h>
#include <stdlib.h>
#include "simulator.h"
#include <gsl/gsl_randist.h>
#include <gsl/gsl_rng.h>

void prll(long long *llarray, long long llarray_len){
    long long i;
    for (i=0; i<llarray_len; i++){
        printf(" %lld", llarray[i]);
    }
    printf("\n");
}

int main(){
    long long *placeholder = calloc(sizeof(long long),20);
    gsl_rng * myrng = gsl_rng_alloc (gsl_rng_taus);
    prll(placeholder, 20);
    getshuf(placeholder, 20, myrng);
    prll(placeholder, 20);
    printf("\n");
    gsl_rng_free(myrng);
    free(placeholder);
    return(0);
}
