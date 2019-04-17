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

void pr_carn_prop_full(generation *a){
    long long i;
    long long carncount = 0;
    double prop;
    for (i=0; i < a->pop_size; i++){
        if (a->population[i].carnivore){
            carncount++;
        }
    }
    prop = (double)carncount / (double)(a->pop_size);
    printf("carnivore_proportion: %lf\n", prop);
}

void pr_carn_prop_alive(generation *a){
    long long i;
    long long carncount = 0;
    long long alivecount = 0;
    double prop;
    for (i=0; i < a->pop_size; i++){
        if (a->population[i].carnivore && a->population[i].alive){
            carncount++;
        }
        if (a->population[i].alive){
            alivecount++;
        }
    }
    prop = (double)carncount / (double)(alivecount);
    printf("carnivore_proportion_alive: %lf\n", prop);
}

void pr_avg_sizes(generation *a){
    long long i;
    double carnsum = 0.0;
    long long carncount = 0;
    double carnavg = 0;
    double herbsum = 0.0;
    long long herbcount = 0;
    double herbavg = 0;
    for (i=0; i < a->pop_size; i++){
        if (a->population[i].carnivore){
            carncount++;
            carnsum += a->population[i].size;
        }
        else {
            herbcount++;
            herbsum += a->population[i].size;
        }
    }
    if (carncount > 0) {
        carnavg = (float)carnsum / (float)carncount;
    }
    if (herbcount > 0) {
        herbavg = (float)herbsum / (float)herbcount;
    }
    printf("carnivore_average_size: %lf; herbivore_average_size: %lf\n", carnavg, herbavg);
}

void pr_avg_sizes_alive(generation *a){
    long long i;
    double carnsum = 0.0;
    long long carncount = 0;
    double carnavg = 0;
    double herbsum = 0.0;
    long long herbcount = 0;
    double herbavg = 0;
    for (i=0; i < a->pop_size; i++){
        if (a->population[i].carnivore && a->population[i].alive){
            carncount++;
            carnsum += a->population[i].size;
        }
        else if (!(a->population[i].carnivore) && a->population[i].alive){
            herbcount++;
            herbsum += a->population[i].size;
        }
    }
    if (carncount > 0) {
        carnavg = (float)carnsum / (float)carncount;
    }
    if (herbcount > 0) {
        herbavg = (float)herbsum / (float)herbcount;
    }
    printf("carnivore_average_size: %lf; herbivore_average_size: %lf\n", carnavg, herbavg);
}

void prgen(generation *a){
    long long i;
    
    pr_carn_prop_full(a);
    pr_carn_prop_alive(a);
    pr_avg_sizes(a);
    pr_avg_sizes_alive(a);
    
    printf("carnivore:\n");
    for (i=0; i < a->pop_size; i++){
        printf(" %d", a->population[i].carnivore);
    }
    printf("\n");
    printf("size:\n");
    for (i=0; i < a->pop_size; i++){
        printf(" %lf", a->population[i].size);
    }
    printf("\n");
    printf("food_needed:\n");
    for (i=0; i < a->pop_size; i++){
        printf(" %lf", a->population[i].food_needed);
    }
    printf("\n");
    printf("alive:\n");
    for (i=0; i < a->pop_size; i++){
        printf(" %d", a->population[i].alive);
    }
    printf("\n");
    printf("food_eaten:\n");
    for (i=0; i < a->pop_size; i++){
        printf(" %lf", a->population[i].food_eaten);
    }
    printf("\n");
}

void prexp(full_exp *a){
    long long i;
    for (i=0; i < a->generation_number; i++){
        printf("Generation: %lld\n", i);
        prgen(a->exp_gens[i]);
    }
}

void prgen_table(generation *a, long long gen_number){
    long long i;
    
    for (i=0; i < a->pop_size; i++){
        /* print indiv's whole info */
        printf("%lld\t%lld\t%d\t%lf\t%lf\t%d\t%lf\n",
            gen_number,
            i,
            a->population[i].carnivore,
            a->population[i].size,
            a->population[i].food_needed,
            a->population[i].alive,
            a->population[i].food_eaten);
    }
}

void prexp_table(full_exp *a){
    long long i;
    for (i=0; i < a->generation_number; i++){
        prgen_table(a->exp_gens[i], i);
    }
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
    child->alive = parent->alive;
    if (carn_rand > carn_trans_prob){
        child->carnivore = parent->carnivore;
    } else {
        child->carnivore = !(parent->carnivore);
    }
}

void carn_eat(indiv *predator, indiv *prey){
    (predator->food_eaten) += (prey->size);
    prey->alive = false;
}

void getshuf(long long *placeholder, long long new_length, const gsl_rng *myrng){
    long long i;
    for (i=0; i < new_length; i++){
        placeholder[i] = i;
    }
    if (new_length > 0){
        gsl_ran_shuffle(myrng, placeholder, new_length, sizeof(long long));
    }
}

void carn_search_and_eat(generation *mygen, long long carn_index, long long search_tries, const gsl_rng *myrng, double carn_size_prop){
    long long i;
    indiv *mycarn = (mygen->population) + carn_index;
    indiv *myprey;
    long long *placeholder = (long long *)malloc(sizeof(long long) * mygen->pop_size);
    getshuf(placeholder, mygen->pop_size, myrng);
    for (i=0; i<mygen->pop_size; i++){
        if (mycarn->food_eaten > mycarn->food_needed || (i >= search_tries)){
            break;
        }
        myprey = mygen->population + placeholder[i];
        /*printf("prey size: %lf; carn size: %lf; carn_size_prop: %lf; adjusted_prey_size: %lf\n", myprey->size, mycarn->size, carn_size_prop, myprey->size * carn_size_prop);*/
        if ((myprey->alive) && (placeholder[i] != carn_index) && !(myprey->carnivore) && (mycarn->size > (myprey->size * carn_size_prop))){
        /*if ((myprey->alive) && (placeholder[i] != carn_index) && !(myprey->carnivore)){*/
            carn_eat(mycarn, myprey);
        }
    }
    free(placeholder);
}

void all_carn_search_and_eat(generation *mygen, long long search_tries, const gsl_rng *myrng, double carn_size_prop){
    long long i;
    indiv *mycarn;
    long long *placeholder = (long long *)malloc(sizeof(long long) * mygen->pop_size);
    getshuf(placeholder, mygen->pop_size, myrng);
    for (i=0; i < mygen->pop_size; i++){
        mycarn = mygen->population + placeholder[i];
        if (mycarn->alive && mycarn->carnivore){
            carn_search_and_eat(mygen, placeholder[i], search_tries, myrng, carn_size_prop);
        }
    }
    free(placeholder);
}

int reproduce_generation(generation *parent_gen, generation *child_gen, double repro_stdev, double carn_trans_prob, const gsl_rng *myrng){
    long long alive_num = 0;
    long long *placeholder = (long long *)malloc(sizeof(long long) * parent_gen->pop_size);
    long long *child_placeholder = (long long *)malloc(sizeof(long long) * child_gen->pop_size);
    long long i;
    int alive = 1;
    
    for (i=0; i < parent_gen->pop_size; i++){
        if (parent_gen->population[i].alive){
            placeholder[alive_num] = i;
            alive_num++;
        }
    }
    if (alive_num > 0){
        gsl_ran_sample(myrng, child_placeholder, child_gen->pop_size, placeholder, alive_num, sizeof(long long));
        for (i=0; i<child_gen->pop_size; i++){
            reproduce_indiv(parent_gen->population + child_placeholder[i], child_gen->population + i, repro_stdev, carn_trans_prob, myrng);
        }
    }
    else {
        printf("all individuals dead!\n");
        alive = 0;
    }
    
    
    free(placeholder);
    free(child_placeholder);
    return(alive);
}

void all_herb_eat(generation *mygen, double food){
    long long i;
    long long herbnum = 0;
    double foodperherb;
    indiv *myherb;
    for (i=0; i < mygen->pop_size; i++){
        myherb = mygen->population + i;
        if (myherb->alive && !(myherb->carnivore)){
            herbnum++;
        }
    }
    foodperherb = ((double)food) / ((double)herbnum);
    for (i=0; i < mygen->pop_size; i++){
        myherb = mygen->population + i;
        if (myherb->alive && !(myherb->carnivore)){
            myherb->food_eaten += foodperherb;
        }
    }
}

void all_starve(generation *mygen){
    long long i;
    for (i=0; i < mygen->pop_size; i++){
        if(mygen->population[i].food_eaten < mygen->population[i].food_needed){
            mygen->population[i].alive = false;
        }
    }
}

int run_gen(generation *parent_gen, generation *child_gen, double repro_stdev, double carn_trans_prob, const gsl_rng *myrng, double food, long long search_tries, double carn_size_prop){
    /*carnivores eat,
    living herbivores eat,
    all starving occurs,
    all reprod occurs*/
    int alive = 1;
    
    /* carnivores eat */
    all_carn_search_and_eat(parent_gen, search_tries, myrng, carn_size_prop);

    /* living herbivores eat */
    all_herb_eat(parent_gen, food);
    
    /* all starving occurs */
    all_starve(parent_gen);

    /* all reprod occurs */
    alive = reproduce_generation(parent_gen, child_gen, repro_stdev, carn_trans_prob, myrng);
    return(alive);
}


long long run_full_exp(full_exp *myexp, double repro_stdev, double carn_trans_prob, const gsl_rng *myrng, double food, long long search_tries, double carn_size_prop){
    long long i;
    int alive = 1;
    for (i=0; i< (myexp->generation_number - 1); i++){
        alive = run_gen(myexp->exp_gens[i], myexp->exp_gens[i+1], repro_stdev, carn_trans_prob, myrng, food, search_tries, carn_size_prop);
        if (alive == 0){
            break;
        }
    }
    return(i);
}

