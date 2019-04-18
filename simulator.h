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
void init_indiv(indiv *my_indiv);
void rinit_indiv(indiv *my_indiv, double mean, double stdev, double carnivore_prob, gsl_rng *myrng);
generation *init_generation(long long pop_size);
void pr_carn_prop_full(generation *a);
void pr_carn_prop_alive(generation *a);
void pr_avg_sizes(generation *a);
void pr_avg_sizes_alive(generation *a);
void prgen(generation *a);
void prexp(full_exp *a);
void prgen_table(generation *a, long long gen_number);
void prexp_table(full_exp *a);
void rinit_generation(generation *my_generation, double mean, double stdev, double carnivore_prob, gsl_rng *myrng);
full_exp *init_full_exp(long long pop_size, long long generation_number);
void rinit_full_exp(full_exp *my_experiment, double mean, double stdev, double carnivore_prob, gsl_rng *myrng);
void free_generation(generation *my_generation);
void free_exp(full_exp *my_experiment);
void reproduce_indiv(indiv *parent, indiv *child, double repro_stdev, double carn_trans_prob, const gsl_rng *myrng);
void carn_eat(indiv *predator, indiv *prey);
void getshuf(long long *placeholder, long long new_length, const gsl_rng *myrng);
void carn_search_and_eat(generation *mygen, long long carn_index, long long search_tries, const gsl_rng *myrng, double carn_size_prop);
void all_carn_search_and_eat(generation *mygen, long long search_tries, const gsl_rng *myrng, double carn_size_prop);
int reproduce_generation(generation *parent_gen, generation *child_gen, double repro_stdev, double carn_trans_prob, const gsl_rng *myrng);
void all_herb_eat(generation *mygen, double food);
void all_starve(generation *mygen);
int run_gen(generation *parent_gen, generation *child_gen, double repro_stdev, double carn_trans_prob, const gsl_rng *myrng, double food, long long search_tries, double carn_size_prop);
long long run_full_exp(full_exp *myexp, double repro_stdev, double carn_trans_prob, const gsl_rng *myrng, double food, long long search_tries, double carn_size_prop);
