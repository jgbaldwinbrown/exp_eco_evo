all: simple_test unit_tests/unit_rinit_indiv unit_tests/unit_rinit_gen unit_tests/unit_rinit_exp unit_tests/unit_reproduce_indiv unit_tests/unit_reproduce_generation unit_tests/unit_carn_eat unit_tests/unit_carn_search_and_eat unit_tests/unit_all_carn_search_and_eat unit_tests/unit_getshuf unit_tests/unit_all_herb_eat unit_tests/unit_all_starve unit_tests/unit_run_gen unit_tests/unit_run_exp big_test

simple_test: simple_test.c simulator.h
	gcc -Wall -I/opt/local/include -L/opt/local/lib -lgsl -lgslcblas -lm $< -o $@
unit_tests/unit_rinit_indiv: unit_tests/unit_rinit_indiv.c simulator.h
	gcc -Wall -I/Users/jbaldwin/Documents/git_repositories/exp_eco_evo -I/opt/local/include -L/opt/local/lib -lgsl -lgslcblas -lm $< -o $@
unit_tests/unit_rinit_gen: unit_tests/unit_rinit_gen.c simulator.h
	gcc -Wall -I/Users/jbaldwin/Documents/git_repositories/exp_eco_evo -I/opt/local/include -L/opt/local/lib -lgsl -lgslcblas -lm $< -o $@
unit_tests/unit_rinit_exp: unit_tests/unit_rinit_exp.c simulator.h
	gcc -Wall -I/Users/jbaldwin/Documents/git_repositories/exp_eco_evo -I/opt/local/include -L/opt/local/lib -lgsl -lgslcblas -lm $< -o $@
unit_tests/unit_reproduce_indiv: unit_tests/unit_reproduce_indiv.c simulator.h
	gcc -Wall -I/Users/jbaldwin/Documents/git_repositories/exp_eco_evo -I/opt/local/include -L/opt/local/lib -lgsl -lgslcblas -lm $< -o $@
unit_tests/unit_reproduce_generation: unit_tests/unit_reproduce_generation.c simulator.h
	gcc -Wall -I/Users/jbaldwin/Documents/git_repositories/exp_eco_evo -I/opt/local/include -L/opt/local/lib -lgsl -lgslcblas -lm $< -o $@
unit_tests/unit_carn_eat: unit_tests/unit_carn_eat.c simulator.h
	gcc -Wall -I/Users/jbaldwin/Documents/git_repositories/exp_eco_evo -I/opt/local/include -L/opt/local/lib -lgsl -lgslcblas -lm $< -o $@
unit_tests/unit_carn_search_and_eat: unit_tests/unit_carn_search_and_eat.c simulator.h
	gcc -Wall -I/Users/jbaldwin/Documents/git_repositories/exp_eco_evo -I/opt/local/include -L/opt/local/lib -lgsl -lgslcblas -lm $< -o $@
unit_tests/unit_all_carn_search_and_eat: unit_tests/unit_all_carn_search_and_eat.c simulator.h
	gcc -Wall -I/Users/jbaldwin/Documents/git_repositories/exp_eco_evo -I/opt/local/include -L/opt/local/lib -lgsl -lgslcblas -lm $< -o $@
unit_tests/unit_all_herb_eat: unit_tests/unit_all_herb_eat.c simulator.h
	gcc -Wall -I/Users/jbaldwin/Documents/git_repositories/exp_eco_evo -I/opt/local/include -L/opt/local/lib -lgsl -lgslcblas -lm $< -o $@
unit_tests/unit_all_starve: unit_tests/unit_all_starve.c simulator.h
	gcc -Wall -I/Users/jbaldwin/Documents/git_repositories/exp_eco_evo -I/opt/local/include -L/opt/local/lib -lgsl -lgslcblas -lm $< -o $@
unit_tests/unit_getshuf: unit_tests/unit_getshuf.c simulator.h
	gcc -Wall -I/Users/jbaldwin/Documents/git_repositories/exp_eco_evo -Wpedantic -I/opt/local/include -L/opt/local/lib -lgsl -lgslcblas -lm $< -o $@
unit_tests/unit_run_gen: unit_tests/unit_run_gen.c simulator.h
	gcc -Wall -I/Users/jbaldwin/Documents/git_repositories/exp_eco_evo -I/opt/local/include -L/opt/local/lib -lgsl -lgslcblas -lm $< -o $@
unit_tests/unit_run_exp: unit_tests/unit_run_exp.c simulator.h
	gcc -Wall -I/Users/jbaldwin/Documents/git_repositories/exp_eco_evo -I/opt/local/include -L/opt/local/lib -lgsl -lgslcblas -lm $< -o $@
big_test: big_test.c simulator.h
	gcc -Wall -I/opt/local/include -L/opt/local/lib -lgsl -lgslcblas -lm $< -o $@
