#include "simulator.h"
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main (int argc, char **argv){
    /*int index;*/
    char *n_txt;
    char *m_txt;
    char *s_txt;
    char *p_txt;
    char *g_txt;
    char *e_txt;
    long long n = 10;
    double m = 10.0;
    double s = 1.0;
    double p = 0.0;
    long long g = 5;
    unsigned long int e = 0;

    int c;
    opterr = 0;

    full_exp *exp;

    /* parse all arguments */
    while ((c = getopt (argc, argv, "abc:")) != -1)
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
                s_txt = optarg;
                sscanf(p_txt, "%lf", &p);
                break;
            case 'g':
                g_txt = optarg;
                sscanf(g_txt, "%lld", &g);
                break;
            case 'e':
                g_txt = optarg;
                sscanf(e_txt, "%lu", &e);
                break;
            case '?':
                if (optopt == 'n' || optopt == 'm' || optopt == 's' || optopt == 'g' || optopt == 'p' || optopt == 'e')
                    fprintf (stderr, "Option -%c requires an argument.\n", optopt);
                else if (isprint (optopt))
                    fprintf (stderr, "Unknown option `-%c'.\n", optopt);
                else
                    fprintf (stderr,
                             "Unknown option character `\\x%x'.\n",
                             optopt);
                return 1;
            default:
                abort ();
            }

    /*initialize random number generator*/
    gsl_rng * myrng = gsl_rng_alloc (gsl_rng_taus);
    gsl_rng_set (myrng, e);
    
    /*set up pop to evolve*/
    exp = init_full_exp(n, g);
    rinit_full_exp(exp, m, s, p, myrng);

    /*do the experimental evolution*/
    /*evo_all_gens(exp);*/

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

