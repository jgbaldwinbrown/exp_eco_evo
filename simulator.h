#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <gsl/gsl_randist.h>
#include <gsl/gsl_rng.h>

typedef struct an_indiv {
    double size;
    double food_needed;
    double food_eaten;
    bool carnivore;
} indiv;

typedef struct a_generation {
    long long pop_size;
    indiv *population;
} generation;

typedef struct full_experiment {
    long long pop_size;
    long long generation_number;
    generation **exp_gens;
} full_exp;

/*--------------------------------------------------------------------------------*/
/* functions */

void init_indiv(indiv *my_indiv){
    my_indiv->size = 0.0;
    my_indiv->food_needed = 0.0;
    my_indiv->food_eaten = 0.0;
    my_indiv->carnivore = false;
}

void rinit_indiv(indiv *my_indiv, double mean, double stdev, double carnivore_prob, gsl_rng *myrng){
    my_indiv->size = gsl_ran_gaussian(myrng, stdev) + mean;
    my_indiv->food_needed = my_indiv->size;
    my_indiv->food_eaten = 0.0;
    double my_carnivore_perc = gsl_rng_uniform(myrng);
    if (my_carnivore_perc <= carnivore_prob){
        my_indiv->carnivore = true;
    } else {
        my_indiv->carnivore = false;
    }
}
    
generation *init_generation(long long pop_size){
    generation *my_generation = malloc(sizeof(generation));
    my_generation->pop_size = pop_size;
    my_generation->population = malloc(sizeof(indiv) * pop_size);
    return(my_generation);
}
    
void rinit_generation(generation *my_generation, double mean, double stdev, double carnivore_prob, gsl_rng *myrng){
    long long i;
    for (i=0; i<my_generation->pop_size; i++){
        rinit_indiv(&(my_generation->population[i]), mean, stdev, carnivore_prob, myrng);
    }
}

full_exp *init_full_exp(long long pop_size, long long generation_number){
    long long i;
    full_exp *my_experiment = malloc(sizeof(full_exp));
    my_experiment->pop_size = pop_size;
    my_experiment->generation_number = generation_number;
    my_experiment->exp_gens = malloc(sizeof(generation*) * generation_number);
    for (i=0; i<generation_number; i++){
        my_experiment->exp_gens[i] = init_generation(pop_size);
    }
    /*my_experiment->exp_gens = malloc(sizeof(generation) * generation_number);*/
    return(my_experiment);
}

void rinit_full_exp(full_exp *my_experiment, double mean, double stdev, double carnivore_prob, gsl_rng *myrng){
    long long i;
    for (i=0; i<my_experiment->generation_number; i++){
        rinit_generation(my_experiment->exp_gens[i], mean, stdev, carnivore_prob, myrng);
    }
}

void free_generation(generation *my_generation){
    free(my_generation->population);
    free(my_generation);
}

void free_exp(full_exp *my_experiment){
    long long i;
    for (i=0; i<my_experiment->generation_number; i++){
        free_generation(my_experiment->exp_gens[i]);
    }
    free(my_experiment);
}

