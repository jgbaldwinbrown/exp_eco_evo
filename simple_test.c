#include "simulator.h"
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <gsl/gsl_randist.h>
#include <gsl/gsl_rng.h>

int main (int argc, char **argv){
    char usage_txt[] =
"usage: %s [options]\n"
"\n"
"argument   description\n"
"-n         Population size (default=10)\n"
"-m         Mean initial body size (default=10)\n"
"-s         Initial body size standard deviation (default=1)\n"
"-p         Initial probability of carnivore (default = 0)\n"
"-v         Standard deviation body size change (default = 1)\n"
"-f         Total food (default=120)\n"
"-q         Ratio of carnivore to herbivore for eating (default = 1)\n"
"-a         Number of tries carnivore has to eat (default = 2)\n"
"-t         Probability of carnivore-herbivore transition (default=0)\n"
"-g         Number of generations (default = 5)\n"
"-h         Random seed unsigned integer (default = 0)\n"
"-h         Print this help text\n";
    /*int index;*/
    char *n_txt;
    char *m_txt;
    char *s_txt;
    char *p_txt;
    char *g_txt;
    char *e_txt;
    char *v_txt;
    char *f_txt;
    char *q_txt;
    char *a_txt;
    char *t_txt;
    /* population size */
    long long n = 10;
    /* mean initial body size */
    double m = 10.0;
    /* initial body size standard deviation */
    double s = 1.0;
    /* initial probability of carnivore */
    double p = 0.0;
    /* stdev change upon reproduction */
    double v = 1.0;
    /* total food available */
    double f = 120;
    /* multiplicative amount that carn must be larger than herb to eat it */
    double q = 1.0;
    /* number of tries that carnivore has to eat */
    long long a = 2;
    /* probability of carn-herb transition */
    double t = 0.0;
    /* number of generations */
    long long g = 5;
    /* random seed */
    unsigned long int e = 0;
    long long gens_survived = 0;

    int c;
    opterr = 0;

    full_exp *exp;

    /* parse all arguments */
    while ((c = getopt (argc, argv, "n:m:s:p:g:e:v:f:q:a:t:h")) != -1)
        switch (c)
            {
            case 'n':
                n_txt = optarg;
                sscanf(n_txt, "%lld", &n);
                break;
            case 'm':
                m_txt = optarg;
                sscanf(m_txt, "%lf", &m);
                break;
            case 's':
                s_txt = optarg;
                sscanf(s_txt, "%lf", &s);
                break;
            case 'p':
                p_txt = optarg;
                sscanf(p_txt, "%lf", &p);
                break;
            case 'g':
                g_txt = optarg;
                sscanf(g_txt, "%lld", &g);
                break;
            case 'e':
                e_txt = optarg;
                sscanf(e_txt, "%lu", &e);
                break;
            case 'v':
                v_txt = optarg;
                sscanf(v_txt, "%lf", &v);
                break;
            case 'f':
                f_txt = optarg;
                sscanf(f_txt, "%lf", &f);
                break;
            case 'q':
                q_txt = optarg;
                sscanf(q_txt, "%lf", &q);
                break;
            case 'a':
                a_txt = optarg;
                sscanf(a_txt, "%lld", &a);
                break;
            case 't':
                t_txt = optarg;
                sscanf(t_txt, "%lf", &t);
                break;
            case 'h':
                printf(usage_txt, argv[0]);
                exit(0);
                break;
            case '?':
                if (optopt == 'n' || 
                    optopt == 'm' || 
                    optopt == 's' || 
                    optopt == 'g' || 
                    optopt == 'p' || 
                    optopt == 'e' || 
                    optopt == 'v' || 
                    optopt == 'f' || 
                    optopt == 'q' || 
                    optopt == 'a' || 
                    optopt == 't'){
                    fprintf (stderr, "Option -%c requires an argument.\n", optopt);
                } else if (isprint (optopt)){
                    fprintf (stderr, "Unknown option `-%c'.\n", optopt);
                } else {fprintf (stderr,
                             "Unknown option character `\\x%x'.\n",
                             optopt);
                }
                return 1;
            default:
                abort ();
            }

    /*initialize random number generator*/
    gsl_rng * myrng = gsl_rng_alloc (gsl_rng_taus);
    gsl_rng_set (myrng, e);
    
    /*set up pop to evolve*/
    /*
    exp = init_full_exp(n, g);
    rinit_full_exp(exp, m, s, p, myrng);
    */
    exp = init_full_exp(n,g);
    rinit_full_exp(exp, m, s, p, myrng);

    /*do the experimental evolution*/
    /*evo_all_gens(exp);*/
    gens_survived = run_full_exp(exp, v, t, myrng, f, a, q);
    /* printf("Generations survived: %lld\n", gens_survived); */
    prexp_table(exp);

    /*free the main data structure*/
    free_exp(exp);

    /*free gsl random number seed:*/
    gsl_rng_free(myrng);

    /*
    for (index = optind; index < argc; index++)
        printf ("Non-option argument %s\n", argv[index]);
    */
    return 0;
}

/*
int main(){
    full_exp *a;
    double food = 80000;
    long long gens_survived = 0;
    gsl_rng * myrng = gsl_rng_alloc (gsl_rng_taus);
    a = init_full_exp(10000,30);
    rinit_full_exp(a, 5, 1, .1, myrng);

    printf("\n");

    gens_survived = run_full_exp(a, .2, .1, myrng, food, 500, 1.1);

    printf("Generations survived: %lld\n", gens_survived);
    prexp(a);
    
    gsl_rng_free(myrng);
    free_exp(a);
    return(0);
}
*/
