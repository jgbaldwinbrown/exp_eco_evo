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
    bool alive;
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
    my_indiv->alive = true;
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
    my_indiv->alive = true;
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

void reproduce_indiv(indiv *parent, indiv *child, double repro_stdev, double carn_trans_prob, const gsl_rng *myrng){
    double carn_rand = gsl_ran_flat(myrng, 0, 1);
    child->food_eaten = 0.0;
    child->size = gsl_ran_gaussian(myrng, repro_stdev) + parent->size;
    child->food_needed = child->size;
    if (carn_rand > carn_trans_prob){
        child->carnivore = parent->carnivore;
    } else {
        child->carnivore = !(parent->carnivore);
    }
}

void carn_eat(indiv *predator, indiv *prey){
    prey->alive = false;
    predator->food_eaten += prey->size;
}

void getshuf(long long *placeholder, long long placeholder_length, long long new_length, const gsl_rng *myrng){
    long long i;
    if (placeholder_length < new_length){
        placeholder = realloc(placeholder, sizeof(long long) * new_length);
    }
    for (i=0; i < new_length; i++){
        placeholder[i] = i;
        printf(" %lld",placeholder[i]);
    }
        printf("\n");
    gsl_ran_shuffle(myrng, placeholder, new_length, sizeof(long long));
    /*gsl_ran_shuffle(myrng, placeholder, sizeof(long long), new_length);*/
}

void carn_search_and_eat(generation *mygen, long long carn_index, const gsl_rng *myrng){
    long long i;
    indiv *mycarn = (mygen->population) + carn_index;
    indiv *myprey;
    long long *placeholder = (long long *)malloc(sizeof(long long) * mygen->pop_size);
    getshuf(placeholder, mygen->pop_size, mygen->pop_size, myrng);
    for (i=0; i<mygen->pop_size; i++){
        if (mycarn->food_eaten > mycarn->food_needed){
            break;
        }
        myprey = mygen->population + placeholder[i];
        if (myprey->alive && placeholder[i] != carn_index){
            carn_eat(mycarn, myprey);
        }
    }
    free(placeholder);
}

void all_carn_search_and_eat(generation *mygen, const gsl_rng *myrng){
    long long i;
    indiv *mycarn;
    long long *placeholder = (long long *)malloc(sizeof(long long) * mygen->pop_size);
    getshuf(placeholder, mygen->pop_size, mygen->pop_size, myrng);
    for (i=0; i < mygen->pop_size; i++){
        mycarn = mygen->population + placeholder[i];
        if (mycarn->alive && mycarn->carnivore){
            carn_search_and_eat(mygen, i, myrng);
        }
    }
    free(placeholder);
}

void reproduce_generation(generation *parent_gen, generation *child_gen, double repro_stdev, double carn_trans_prob, const gsl_rng *myrng){
    long long alive_num = 0;
    long long *placeholder = (long long *)malloc(sizeof(long long) * parent_gen->pop_size);
    long long *child_placeholder = (long long *)malloc(sizeof(long long) * child_gen->pop_size);
    long long i;
    
    for (i=0; i<parent_gen->pop_size; i++){
        if (parent_gen->population[i].alive){
            placeholder[alive_num] = i;
            alive_num++;
        }
    }
    gsl_ran_choose(myrng, placeholder, alive_num, child_placeholder, child_gen->pop_size, sizeof(long long));
    
    for (i=0; i<child_gen->pop_size; i++){
        reproduce_indiv(parent_gen->population + child_placeholder[i], child_gen->population + i, repro_stdev, carn_trans_prob, myrng);
    }
    
    free(placeholder);
    free(child_placeholder);
}

