#include <simulator.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main (int argc, char **argv){
    /*int index;*/
    char *n_txt;
    char *m_txt;
    char *s_txt;
    long long n = 10;
    long double m = 10;
    long double s = 1;
    long double g = 5;

    int c;
    opterr = 0;

    full_exp exp;

    /* parse all arguments */
    while ((c = getopt (argc, argv, "abc:")) != -1)
        switch (c)
            {
            case 'n':
                n_txt = optarg;
                n = sscanf(n_txt, "%Ld");
                break;
            case 'm':
                m_txt = optarg;
                m = sscanf(m_txt, "%Lf");
                break;
            case 's':
                s_txt = optarg;
                s = sscanf(s_txt, "%Lf");
                break;
            case 'g':
                g_txt = optarg;
                g = sscanf(g_txt, "%Ld");
                break;
            case '?':
                if (optopt == 'n' || optopt == 'm' || optopt == 's' || optopt == 'g')
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
    
    /*set up pop to evolve*/
    exp = init_full_exp(n, g, m, s);

    /*do the experimental evolution*/
    

    /*free the main data structure*/
    free_full_exp(exp);

    /*
    for (index = optind; index < argc; index++)
        printf ("Non-option argument %s\n", argv[index]);
    */
    return 0;
}

